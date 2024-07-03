import requests
import csv
import pandas as pd

# 保存csv
path = '今日股票趋势.csv'

def parse(res):
    with open(path, mode="a", encoding='utf-8', newline="") as file:
        csv_f = csv.DictWriter(file, fieldnames=['股票代码', '股票名称', '当前价', '涨跌额', '涨跌幅'])
        for data in res['data']['list']:
            # 股票代码
            symbol = data['symbol']
            # 股票名称
            name = data['name']
            # 当前价
            current = data['current']
            # 涨跌额
            chg = data['chg']
            if chg:
                if float(chg) > 0:
                    chg = "+" + str(chg)
                else:
                    chg = str(chg)
            # 涨跌幅
            percent = str(data['percent']) + "%"

            shares_dict = {'股票代码': symbol, '股票名称': name, '当前价': current,
                           '涨跌额': chg, '涨跌幅': percent}

            csv_f.writerow(shares_dict)

def spider():
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/102.0.0.0 Safari/537.36"
    }
    # 写入表头
    with open(path, mode="w", encoding='utf-8', newline="") as file:
        csv_f = csv.DictWriter(file, fieldnames=['股票代码', '股票名称', '当前价', '涨跌额', '涨跌幅'])
        csv_f.writeheader()

    for i in range(1, 10):
        print("=========正在爬取第" + str(i) + "页数据==========")
        # 拼接url，注意要使用 str
        url = "https://xueqiu.com/service/v5/stock/screener/quote/list?page=" + str(
            i) + "&size=30&order=desc&order_by=amount&exchange=CN&market=CN&type=sha&_=1601168743543"
        # 数据返回格式为json，所以要使用.json()，方便之后的数据获取
        response = requests.get(url=url, headers=headers).json()
        parse(response)

if __name__ == '__main__':
    spider()
