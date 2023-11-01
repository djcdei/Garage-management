#include "sqlite3.h"

sqlite3::sqlite3()//构造函数安装数据库驱动
{
    if (QSqlDatabase::contains("dh_sql_default_connection"))
    {
        base1 = QSqlDatabase::database("dh_sql_default_connection");
        qDebug() << "contains";
    }
    else
    {
        base1 = QSqlDatabase::addDatabase("QSQLITE", "dh_sql_default_connection");
        base1.setDatabaseName("cars.db");
    }
}

sqlite3::~sqlite3()
{
    base1.close();
}

int sqlite3::openSqlite(QString filename)//打开数据库
{
    if(filename=="cars.db")
    {
        if(!base1.open())
        {
            printf("打开数据库%s失败:%s\n",filename.toUtf8().data(),base1.lastError().text().toUtf8().data());
            return -1;
        }
    }
    else
    {
        printf("数据库不存在，请检查一下名字\n");
    }
    return 0;
}

int sqlite3::createTable()//创建表格
{
    // 打开数据库连接
    if (!base1.open())
    {
        qDebug() << "无法打开数据库连接:" << base1.lastError();
            return -1;
    }

    // 使用参数绑定和预处理语句
    QSqlQuery myquery(base1);
    QString queryStr = QString("SELECT name FROM sqlite_master WHERE type='table' AND name='carstable'");
    if (myquery.exec(queryStr))//不能单独就执行这句代码，这行代码返回真代表执行成功，会造成误解，最好再加一层判断
    {
        if (myquery.next())//往下一行遍历查询是否有carstable
        {
            // 表格已经存在
            printf("表格carstable已经存在\n");
        }
        else
        {
            // 表格不存在
            // 执行创建表格操作
            QString createCmd = QString("CREATE TABLE carstable (id TEXT UNIQUE, plate_info TEXT, balance FLOAT)");
            int ret = myquery.exec(createCmd);
            if (!ret)
            {
                qDebug() << "创建表格carstable失败" << myquery.lastError();
            }
        }
    }
    else
    {
        // 查询执行失败
        qDebug() << "查询失败" << myquery.lastError();
    }
    queryStr = QString("SELECT name FROM sqlite_master WHERE type='table' AND name='admintable'");
    if (myquery.exec(queryStr))
    {
        if (myquery.next())
        {
            // 表格已经存在
            printf("表格admintable已经存在\n");
        }
        else
        {
            // 表格不存在
            // 执行创建表格操作
            QString createCmd = QString("CREATE TABLE admintable (id TEXT, plate_info TEXT, balance FLOAT,position INT,statime INT,endtime INT)");
            int ret = myquery.exec(createCmd);
            if (!ret)
            {
                qDebug() << "创建表格admintable失败" << myquery.lastError();
            }
        }
    }
    else
    {
        // 查询执行失败
        qDebug() << "查询失败" << myquery.lastError();
    }
     queryStr = QString("SELECT name FROM sqlite_master WHERE type='table' AND name='spacetable'");
    if (myquery.exec(queryStr))//不能单独就执行这句代码，这行代码返回真代表执行成功，会造成误解，最好再加一层判断
    {
        if (myquery.next())//往下一行遍历查询是否有spacetable
        {
            // 表格已经存在
            printf("表格spacetable已经存在\n");
        }
        else
        {
            // 表格不存在
            // 执行创建表格操作
            QString createCmd = QString("CREATE TABLE spacetable (plate TEXT UNIQUE,pos INT UNIQUE,status INT)");//车位（唯一），车牌号,车位状态
            int ret = myquery.exec(createCmd);
            if (!ret)
            {
                qDebug() << "创建表格spacetable失败" << myquery.lastError();
            }
        }
    }
    else
    {
        // 查询执行失败
        qDebug() << "查询失败" << myquery.lastError();
    }
    base1.close();
    return 0;
}

int sqlite3::insertInfo(QString cardid, QString platenum, float balance,QString tabname)//只能给carstable插入信息
{
    // 打开数据库连接
    if (!base1.open())
    {
        qDebug() << "无法打开数据库连接:" << base1.lastError();

            return -1;
    }

    // 使用参数绑定和预处理语句
    QSqlQuery myquery(base1);
    QString cmd=QString("insert into %1 values('%2','%3','%4')").arg(tabname).arg(cardid).arg(platenum).arg(balance);
    ret=myquery.exec(cmd);
    if(!ret)
    {
        printf("插入cartable失败:%s\n",myquery.lastError().text().toUtf8().data());
        base1.close();
        return -1;
    }
    printf("插入carstable成功\n");
    base1.close();
    return 0;
}

//给admintable插入信息
int sqlite3::insertInfo(QString cardid, QString platenum, float balance, int pos, int statime, int endtime)
{
    // 检查数据库连接是否已经打开
    if (!base1.isOpen())
    {
        qDebug() << "数据库连接未打开";

        return -1;
    }

    QSqlQuery query(base1);
    query.prepare("INSERT INTO admintable (id, plate_info, balance, position, start_time, end_time) "
                  "VALUES (:id, :plate_info, :balance, :position, :start_time, :end_time)");

    query.bindValue(":id", cardid);
    query.bindValue(":plate_info", platenum);
    query.bindValue(":balance", balance);
    query.bindValue(":position", pos);
    query.bindValue(":start_time", statime);
    query.bindValue(":end_time", endtime);

    if (query.exec())
    {
        // 插入成功
        base1.close();
        return 0;
    }
    else
    {
        // 插入失败，打印错误信息
        qDebug() << "插入数据到admintable表格失败: " << query.lastError().text();
                                                        base1.close();
        return -1; // 或者返回其他错误代码
    }

}


float sqlite3::deleteInfo(QString cardid, float value) {
    float balance = 0.0;

    // 校验参数
    if (cardid.isEmpty()) {
        qDebug() << "无效的参数：cardid 为空";
        return -1;
    }

    // 打开数据库连接
    if (!base1.open()) {
        qDebug() << "无法打开数据库连接:" << base1.lastError().text();
        return -1;
    }

    // 删除记录
    QSqlQuery deleteQuery(base1);
    deleteQuery.prepare("DELETE FROM carstable WHERE id = :id");
    deleteQuery.bindValue(":id", cardid);

    if (!deleteQuery.exec()) {
        qDebug() << "删除失败:" << deleteQuery.lastError().text();
        base1.close();
        return -1;
    }

    // 查询余额
    QSqlQuery selectQuery(base1);
    selectQuery.prepare("SELECT balance FROM admintable WHERE id = :id");
    selectQuery.bindValue(":id", cardid);

    if (selectQuery.exec() && selectQuery.next()) {
        balance = selectQuery.value(0).toFloat();
        qDebug() << "当前余额为:" << balance;
    } else {
        qDebug() << "未找到匹配的记录或查询出错：" << selectQuery.lastError().text();
    }
    // 关闭数据库连接
    base1.close();
    // 返回余额变化
    return balance - value;
}


int sqlite3::compareInfo(QString cardid, QString platenum)
{
    int result;
    // 打开数据库连接
    if (!base1.open())
    {
        qDebug() << "无法打开数据库连接:" << base1.lastError();

        result = -1;
    }

    QSqlQuery query(base1);
    QString sqlQuery =QString( "SELECT * FROM admintable WHERE id = '%1' AND plate_info = '%2'").arg(cardid).arg(platenum);

    if (query.exec(sqlQuery))
    {
        while (query.next())
        {
            // 找到匹配的记录
            qDebug() << "Found matching record";
            qDebug() << "id:" << query.value(0).toString();
            qDebug() << "platenum:" << query.value(1).toString();
            result = 1;
        }

        if (result != 1)
        {
            // 没有找到匹配的记录
            qDebug() << "No matching record found";
            result = 0;
        }
    }
    else
    {
        // 查询执行失败
        qDebug() << "查询失败:" << query.lastError();
        result = -1;
    }
    base1.close();
    return result;
}

int sqlite3::getposInfo(QString cardid)
{
    // 打开数据库连接
    if (!base1.open())
    {
        qDebug() << "无法打开数据库连接:" << base1.lastError();
        return -1;
    }

    QSqlQuery query(base1);

    // 使用参数绑定和预处理语句来执行查询
    query.prepare("SELECT position FROM admintable WHERE id = :cardid");
    query.bindValue(":cardid", cardid);

    if (query.exec())
    {
       if (query.next())
        {
            // 找到匹配的记录，获取 position 信息
            int position = query.value(0).toInt();
            return position;
        }
        else
        {
            // 没有找到匹配的记录
            qDebug() << "No matching record found";
            return -1; // 或者返回适当的错误代码
        }
    }
    else
    {
        // 查询执行失败
        qDebug() << "查询失败:" << query.lastError();
        return -1; // 或者返回适当的错误代码
    }
}

int sqlite3::insertInfo(int pos, QString plate, int status)//通过选择的车位号，和当前要停的车牌号，判断车位表里面是否有相对应的行，有就说明该车位已经满了，没有就可以插入（停车）
{
    // 打开数据库连接
    if (!base1.open())
    {
        qDebug() << "无法打开数据库连接:" << base1.lastError();
            return -1;
    }
    QSqlQuery query(base1);
    QString cmd=QString("insert into spacetable values('%1','%2','%3')").arg(plate).arg(pos).arg(status);
    ret=query.exec(cmd);
    if(!ret)
    {
        printf("插入失败:%s\n",query.lastError().text().toUtf8().data());
        return 1;
    }
    printf("插入spacetable成功\n");
    base1.close();
    return 0;
}

int sqlite3::updateInfo(QString plate, int status)//根据库车牌更新车位信息
{
    // 打开数据库连接
    if (!base1.open())
    {
        qDebug() << "无法打开数据库连接:" << base1.lastError();
            return -1;
    }
    QSqlQuery query(base1);
    QString cmd=QString("UPDATE admintable SET position = '%1' WHERE plate_info = '%2'").arg(status).arg(plate);
    ret =query.exec(cmd);
    if(!ret)
    {
            printf("更新位置失败\n");
            return -1;
    }
    base1.close();
    return 0;
}



int sqlite3::updateInfo(QString cardid,int pos,float balace,int statime,int endtime)//更新表格adintable的信息，入库更新位置，余额，出库更新位置，余额
{
    // 打开数据库连接
    if (!base1.open())
    {
        qDebug() << "无法打开数据库连接:" << base1.lastError();
            return -1;
    }
    QSqlQuery query(base1);
    QString cmd=QString("UPDATE admintable SET balance = '%1', position = '%2',statime = '%3',endtime = '%4' WHERE id = '%5'").arg(balace).arg(pos).arg(statime).arg(endtime).arg(cardid);
    ret=query.exec(cmd);
    if(!ret)
    {
        printf("更新卡余额失败:%s\n",query.lastError().text().toUtf8().data());
        return -1;
    }
    printf("更新admintable成功\n");
    base1.close();
    return 0;
}

int sqlite3::deleteInfo(QString platenum)//删除车位表中对应的车牌
{
    // 打开数据库连接
    if (!base1.open())
    {
            qDebug() << "无法打开数据库连接:" << base1.lastError();
                return -1;
    }

    // 使用参数绑定和预处理语句
    QSqlQuery myquery(base1);
    QString cmd=QString("delete from spacetable where plate = '%1'").arg(platenum);
    ret= myquery.exec(cmd);
    if(!ret)
    {
        printf("删除失败:%s\n",myquery.lastError().text().toUtf8().data());
        return -1;
    }
    printf("删除车位:%s成功\n",platenum.toUtf8().data());
    base1.close();
    return 0;
}
