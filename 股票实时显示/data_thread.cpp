#include "data_thread.h"
data_thread::data_thread(QObject *parent) : QThread(parent)
{
}
void data_thread::run()
{

}
QStringList Widget::download_file(QString fn)
{
    //f12--代码 f14-名称 f2-最新价 f3-涨跌幅 f4-涨跌额
    /*
    cmd = {
        "沪深京A股": "f3&fs=m:0+t:6,m:0+t:80,m:1+t:2,m:1+t:23,m:0+t:81+s:2048",
        "上证A股": "f3&fs=m:1+t:2,m:1+t:23",
        "深证A股": "f3&fs=m:0+t:6,m:0+t:80",
        "北证A股": "f3&fs=m:0+t:81+s:2048",
        "新股": "f26&fs=m:0+f:8,m:1+f:8",
        "创业板": "f3&fs=m:0+t:80",
        "科创板": "f3&fs=m:1+t:23",
        "沪股通": "f26&fs=b:BK0707",
        "深股通": "f26&fs=b:BK0804",
        "B股": "f3&fs=m:0+t:7,m:1+t:3",
        "风险警示板": "f3&fs=m:0+f:4,m:1+f:4",
    }*/
    /*  map[0]="f3&fs=m:0+t:6,m:0+t:80,m:1+t:2,m:1+t:23,m:0+t:81+s:2048";
    map[1]= "f3&fs=m:1+t:2,m:1+t:23";
    map[2]= "f3&fs=m:0+t:6,m:0+t:80";
    map[3]="f3&fs=m:0+t:81+s:2048";
    map[4]="f26&fs=m:0+f:8,m:1+f:8";
    map[5]="f3&fs=m:0+t:80";
    map[6]= "f3&fs=m:1+t:23";*/

    //两种类型 1.double  2.中文(代码)
    QString text;
    for(int i=0;i<=200;i++){
        QString url_str="https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn="+QString::number(i)+"&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=1720082624725";
        QNetworkAccessManager manager;
        QEventLoop loop;
        QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
        QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
        loop.exec();
        text.append(reply->readAll());
    }
    //  (f12 f14-qreg) f15-f16-f17-qregdouble
    QString qreg='\"'+fn+"\":\"(.*?)\"";//对于反斜杠要用转义字符表示
    QString qregdouble='\"'+fn+"\":(\\d+\\.\\d+)";
    if(fn!="f12"&&fn!="f14")qreg=qregdouble;
    QRegularExpression re(qreg);
    //用next函数实现跳转从而全局匹配
    QStringList strlist;
    auto pos=re.globalMatch(text);
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto  tmp=match.captured(0).mid(fn.size()+3);
        if(fn=="f12"||fn=="f14")tmp=tmp.mid(1,tmp.size()-2);
        strlist.append(tmp);
    }
    return strlist;
}
