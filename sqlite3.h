#ifndef SQLITE3_H
#define SQLITE3_H
#include<QString>
#include <QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
class sqlite3
{
public:
    sqlite3();//构造函数安装数据库驱动（sqlite）
    ~sqlite3();
    int openSqlite(QString filename);//打开数据库，没有就创建
    int createTable();//创建表格
    int insertInfo();//管理员插入，获取管理员界面横向输入框的信息
    int deleteInfo();//管理员删除信息
    int updateInfo(QString cardid,int pos, float balace,int statime,int endtime);//更新对应车辆的位置信息，和余额
    int insertInfo(QString cardid,QString platenum,float balance,QString tabname);//向数据库中carstable表格插入数据
    int insertInfo(QString cardid=" ",QString platenum=" ",float balance=0,int pos=0,int statime=0,int endtime=0);
    float deleteInfo(QString cardid,float value);//车辆出库删除,更新余额
    int compareInfo(QString cardid, QString platenum);//插入或者删除之前判断卡号与车牌号一一对应
    int getposInfo(QString cardid);//获取admintable表格中的对应车号车位信息
    int insertInfo(int pos,QString plate,int status);//插入表格spacetable数据
    int updateInfo(QString plate,int status);//根据车牌更新车位表格
    int deleteInfo(QString platenum);//删除车位表中的对应车牌的信息

private:
    QSqlDatabase base1;//记录当前车位停车情况的数据库连接
    QSqlDatabase base2;//记录已经注册过的车辆信息（包含余额）的数据库连接，只有在车辆出库的时候才刷新相应的信息
    bool ret;

};

#endif // SQLITE3_H
