#include "admindialog.h"
#include "ui_admindialog.h"

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
    ui->widget_4->setStyleSheet("background-color: #337ab7;"); // 设置背景颜色
    ui->widget_2->setStyleSheet("background-color: #337ab7;"); // 设置背景颜色
    ui->pb_login->setStyleSheet("QPushButton {"
                                "    background-color: #3d8ebe;"   // 背景颜色
                                "    border: 1px solid #2e6da4;"    // 边框样式
                                "    color: white;"                // 文本颜色
                                "    font-size: 16px;"             // 字体大小
                                "    border-radius: 5px;"          // 边框圆角
                                "    padding: 5px 10px;"           // 内边距,文字跟按钮边框的水平、垂直间距
                                "}");
    ui->pb_back2->setStyleSheet("QPushButton {"
                                "    background-color: #3d8ebe;"   // 背景颜色
                                "    border: 1px solid #2e6da4;"    // 边框样式
                                "    color: white;"                // 文本颜色
                                "    font-size: 16px;"             // 字体大小
                                "    border-radius: 5px;"          // 边框圆角
                                "    padding: 5px 10px;"           // 内边距,文字跟按钮边框的水平、垂直间距
                                "}");
    ui->pb_back->setStyleSheet("QPushButton {"
                               "    background-color: #3d8ebe;"   // 背景颜色
                               "    border: 1px solid #2e6da4;"    // 边框样式
                               "    color: white;"                // 文本颜色
                               "    font-size: 16px;"             // 字体大小
                               "    border-radius: 5px;"          // 边框圆角
                               "    padding: 5px 10px;"           // 内边距,文字跟按钮边框的水平、垂直间距
                               "}");
    //初始化表格列表框
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"卡号"<<"车牌号"<<"余额"<<"车位"<<"入库时间"<<"出库时间");
    ui->widget->hide();


    if (QSqlDatabase::contains("dh_sql_default_connection"))
    {
        mybase = QSqlDatabase::database("dh_sql_default_connection");
        qDebug() << "contains";
        printf("数据库存在\n");
    }
    else
    {  
        mybase = QSqlDatabase::addDatabase("QSQLITE", "dh_sql_default_connection");
        mybase.setDatabaseName("cars.db");
    }
    updateTablewidgetData();
}

adminDialog::~adminDialog()
{
    delete ui;
}

void adminDialog::updateTablewidgetData()
{
    qDebug() << "开始更新列表框";

    if (!mybase.open())
    {
        qDebug() << "无法打开数据库连接：" << mybase.lastError().text();
            return;
    }

    QSqlQuery query(mybase);

    if (query.exec("SELECT * FROM admintable"))
    {
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        QSqlRecord record = query.record();
        int rowCount = 0; // 用于跟踪当前行数

        while (query.next())
        {
            ui->tableWidget->insertRow(rowCount); // 插入新行

            bool validData = true;

            for (int col = 0; col < record.count(); col++)
            {
                QVariant data = query.value(col);

                if (!data.isValid())
                {
                    qDebug() << "列值无效";
                    validData = false;
                    break;
                }

                QTableWidgetItem *columnItem = new QTableWidgetItem();//每有一个有效列值，就创建一个QTableWidgetItem对象
                columnItem->setData(Qt::DisplayRole, data);
                ui->tableWidget->setItem(rowCount, col, columnItem);//将创建的QTableWidgetItem对象插入表格(行数，列数，对象)
            }

            if (validData)
            {
                rowCount++; // 仅在数据有效时增加行数
            }
        }
    }
    else
    {
        qDebug() << "查询出错：" << query.lastError().text();
    }

    mybase.close();
}



void adminDialog::on_pb_back_clicked()//返回主界面
{
    QDialog::close();
}


void adminDialog::on_pb_login_clicked()
{
 //获取单行输入框的文本内容
    QString account=ui->lineEdit_account->text();
    QString password=ui->lineEdit_password->text();
    if(account=="gec"&&password=="123456")
    {
        if(QMessageBox::information(this,"！","密码正确")==QMessageBox::Ok)
        {

            ui->widget->show();
        }
    }
    else
    {
        QMessageBox::critical(this,"error","账号或密码错误");
    }

}

void adminDialog::on_pb_back2_clicked()//返回隐藏车辆信息界面
{
    ui->widget->hide();
}


void adminDialog::on_tableWidget_itemChanged(QTableWidgetItem *item)//输入框改变之后的处理槽函数
{
    //获取当前改变了的表格框的内容，更新至数据库
    if(!item)
    {
        qDebug()<<" changed item file";
        return ;
    }

    int row = item->row(); // 获取行号
    QTableWidgetItem *firstitem=ui->tableWidget->item(row,0);
    int col = item->column(); // 获取列号,根据列号来判断哪一个类型的数据改变了
    if (!mybase.isOpen())
    {
        if(!mybase.open())
            qDebug() << "无法打开数据库连接：" << mybase.lastError().text();
            return;
    }

    QSqlQuery query(mybase);
    QString cmd;

    // 添加更多列和类型的映射
    switch (col)
    {
    case 0:
        qDebug()<<"第一列";
        cmd=QString("UPDATE admintable SET id = '%1' WHERE id = '%2'").arg(item->text()).arg(firstitem->text());
        break;
    case 1:
        qDebug()<<"第二列";
        cmd=QString("UPDATE admintable SET plate_info = '%1' WHERE id = '%2'").arg(item->text()).arg(firstitem->text());
        break;
    case 2:
        qDebug()<<"第三列";
        cmd=QString("UPDATE admintable SET balance = '%1' WHERE id = '%2'").arg(item->text()).arg(firstitem->text());
        break;
    case 3:
        qDebug()<<"第四列";
        cmd=QString("UPDATE admintable SET position = '%1' WHERE id = '%2'").arg(item->text()).arg(firstitem->text());
        break;
    case 4:
        qDebug()<<"第五列";
        cmd=QString("UPDATE admintable SET statime = '%1' WHERE id = '%2'").arg(item->text()).arg(firstitem->text());
        break;
    case 5:
        qDebug()<<"第六列";
        cmd=QString("UPDATE admintable SET endtime = '%1' WHERE id = '%2'").arg(item->text()).arg(firstitem->text());
        break;
    default:
        break;
    }
    int ret=query.exec(cmd);
    if(!ret)
    {
        printf("更新位置失败\n");
        return ;
    }
   // QMessageBox::critical(this,"管理员","修改成功");
}

