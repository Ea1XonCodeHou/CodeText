import mysql.connector
import pandas as pd
import requests
import time

requests.packages.urllib3.disable_warnings(requests.packages.urllib3.exceptions.InsecureRequestWarning)

# 连接到 MySQL 数据库
def connect_db():
    try:
        return mysql.connector.connect(
            host="localhost",
            user="root",
            password="Hyc20040825",
            database="stocksinformtion"
        )
    except mysql.connector.Error as err:
        print(f"Error: {err}")
        exit(1)

# 获取股票数据
def fetch_data():
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.0.0 Safari/537.36"
    }
    all_data = []
    for i in range(1, 10):
        print(f"=========正在爬取第 {i} 页数据==========")
        url = f"https://xueqiu.com/service/v5/stock/screener/quote/list?page={i}&size=30&order=desc&order_by=amount&exchange=CN&market=CN&type=sha&_=1601168743543"
        response = requests.get(url=url, headers=headers, verify=False).json()
        all_data.extend(parse(response))
    return all_data

# 解析股票数据
def parse(res):
    updated_data = []
    for data in res['data']['list']:
        shares_dict = {
            '股票代码': data['symbol'],
            '股票名称': data['name'],
            '当前价': data['current'],
            '涨跌额': data['chg'],
            '涨跌幅': f"{data['percent']}%"
        }
        updated_data.append(shares_dict)
    return updated_data

# 更新数据库
def update_db(data, cursor):
    sql_clear = "DELETE FROM basicstocks"
    cursor.execute(sql_clear)
    for row in data:
        sql_insert = """
        INSERT INTO basicstocks (id_BasicStocks, NameOfStocks, CurrentPrice, ChangeData, Changeamplitude) 
        VALUES (%s, %s, %s, %s, %s)
        """
        values = (
            str(row['股票代码']),
            str(row['股票名称']),
            float(row['当前价']) if row['当前价'] is not None else None,
            float(str(row['涨跌额']).replace('+', '')) if row['涨跌额'] is not None else None,
            str(row['涨跌幅'])
        )
        cursor.execute(sql_insert, values)

if __name__ == '__main__':
    while True:
        data = fetch_data()
        mydb = connect_db()
        cursor = mydb.cursor()
        update_db(data, cursor)
        mydb.commit()
        cursor.close()
        mydb.close()
        print("数据更新完成，等待30秒进行下一次更新...")
        time.sleep(30)
