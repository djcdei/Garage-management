#include "carspacedialog.h"
#include "ui_carspacedialog.h"

CarSpaceDialog::CarSpaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarSpaceDialog)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("background-color: red; color: white; border: 2px solid darkblue; border-radius: 5px;");
    ui->pb_back->setStyleSheet("QPushButton {"
                               "    background-color: #3d8ebe;"   // 背景颜色
                               "    border: 1px solid #2e6da4;"    // 边框样式
                               "    color: white;"                // 文本颜色
                               "    font-size: 16px;"             // 字体大小
                               "    border-radius: 5px;"          // 边框圆角
                               "    padding: 5px 10px;"           // 内边距,文字跟按钮边框的水平、垂直间距
                               "}");
    mysqlite=new class sqlite3();
    QSignalMapper *btMapper;
    btMapper=new QSignalMapper;
    //定义一个按钮组间的指针数组
    p_bt=new QPushButton*[20];
    QPushButton *mybt[20]{ui->pb_1,ui->pb_2,ui->pb_3,ui->pb_4,ui->pb_5,ui->pb_6,ui->pb_7,ui->pb_8,ui->pb_9,ui->pb_10,ui->pb_11,ui->pb_12,ui->pb_13,ui->pb_14,ui->pb_15,ui->pb_16,ui->pb_17,ui->pb_18,ui->pb_19,ui->pb_20};
    p_bt[0] = ui->pb_1;
    p_bt[1] = ui->pb_2;
    p_bt[2] = ui->pb_3;
    p_bt[3] = ui->pb_4;
    p_bt[4] = ui->pb_5;
    p_bt[5] = ui->pb_6;
    p_bt[6] = ui->pb_7;
    p_bt[7] = ui->pb_8;
    p_bt[8] = ui->pb_9;
    p_bt[9] = ui->pb_10;
    p_bt[10]=ui->pb_11;
    p_bt[11]=ui->pb_12;
    p_bt[12]=ui->pb_13;
    p_bt[13]=ui->pb_14;
    p_bt[14]=ui->pb_15;
    p_bt[15]=ui->pb_16;
    p_bt[16]=ui->pb_17;
    p_bt[17]=ui->pb_18;
    p_bt[18]=ui->pb_19;
    p_bt[19]=ui->pb_20;
    for(int i=0;i<20;i++)
    {
        //将按钮的点击信号与btMapper的map()函数绑定，map()函数不需要我们实现
        connect(mybt[i],SIGNAL(clicked(bool)),btMapper,SLOT(map()));
        btMapper->setMapping(mybt[i],i);//将i设置为信号触发时的参数值
    }
    //再将btMapper的mapped(int)信号与自己定义的槽函数绑定，参数为i值
    connect(btMapper,SIGNAL(mapped(int)),this,SLOT(buttonSlot(int)));
}

CarSpaceDialog::~CarSpaceDialog()
{
    delete[] p_bt;
    delete ui;
}

void CarSpaceDialog::setPlatenum(QString _platenum)
{
    qDebug()<<"传进来的车牌号:"<<platenum;
    this->platenum=_platenum;
}


void CarSpaceDialog::setPbColor()
{
    printf("刷新按钮颜色\n");
    if (QSqlDatabase::contains("dh_sql_default_connection"))
    {
        mybase = QSqlDatabase::database("dh_sql_default_connection");
        qDebug() << "contains";
    }
    else
    {
       mybase = QSqlDatabase::addDatabase("QSQLITE", "dh_sql_default_connection");
       mybase.setDatabaseName("cars.db");
    }
     QSqlQuery query(mybase);
    for(int i=0;i<20;i++)//先复位按钮的样式
    {
       p_bt[i]->setStyleSheet("background-color: green; color: white; border: 2px solid darkblue; border-radius: 5px;");
    }
    originalStyle = ui->pb_1->styleSheet();//保留原有样式
    if (query.exec("SELECT pos FROM spacetable"))
     {
        while (query.next())
        {
            int spaceNumber = query.value(0).toInt();
            printf("已停车位:%d\n",spaceNumber);
            p_bt[spaceNumber-1]->setStyleSheet(originalStyle+"background-color: red;");
        }

    }
    else
    {
        qDebug() << "查询出错：" << query.lastError().text();
    }
    mybase.close(); // 关闭数据库连接
}

int CarSpaceDialog::getPosition()
{
    return this->position;
}




void CarSpaceDialog::on_pb_back_clicked()
{
    //this->hide();
    QDialog::close();
}

void CarSpaceDialog::buttonSlot(int num)
{
    switch (num)
    {
    case 0:
        printf("按下第一个按钮\n");
        if(!mysqlite->insertInfo(1,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                // 保留原样式的同时改变背景颜色
                ui->pb_1->setStyleSheet(originalStyle+"background-color: red;");
                this->position=1;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 1:
        printf("按下第二个按钮\n");
        if(!mysqlite->insertInfo(2,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                // 保留原样式的同时改变背景颜色
                ui->pb_2->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=2;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 2:
        printf("按下第三个按钮\n");
        if(!mysqlite->insertInfo(3,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_3->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=3;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 3:
        printf("按下第四个按钮\n");
        if(!mysqlite->insertInfo(4,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_4->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=4;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 4:
        printf("按下第五个按钮\n");
        if(!mysqlite->insertInfo(5,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_5->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=5;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 5:
        printf("按下第六个按钮\n");
        if(!mysqlite->insertInfo(6,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_6->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=6;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 6:
        printf("按下第七个按钮\n");
        if(!mysqlite->insertInfo(7,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_7->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=7;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 7:
        printf("按下第八个按钮\n");
        if(!mysqlite->insertInfo(8,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_8->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=8;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 8:
        printf("按下第九个按钮\n");
        if(!mysqlite->insertInfo(9,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_9->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=9;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 9:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(10,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_10->setStyleSheet(originalStyle+"background-color: red;");
                 this->position=10;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 10:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(11,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_11->setStyleSheet(originalStyle+"background-color: red;");
                this->position=11;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 11:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(12,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_12->setStyleSheet(originalStyle+"background-color: red;");
                this->position=12;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 12:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(13,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_13->setStyleSheet(originalStyle+"background-color: red;");
                this->position=13;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 13:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(14,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_14->setStyleSheet(originalStyle+"background-color: red;");
                this->position=14;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 14:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(15,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_15->setStyleSheet(originalStyle+"background-color: red;");
                this->position=15;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 15:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(16,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_16->setStyleSheet(originalStyle+"background-color: red;");
                this->position=16;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 16:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(17,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_17->setStyleSheet(originalStyle+"background-color: red;");
                this->position=17;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 17:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(18,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_18->setStyleSheet(originalStyle+"background-color: red;");
                this->position=18;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 18:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(19,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_19->setStyleSheet(originalStyle+"background-color: red;");
                this->position=19;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;
    case 19:
        printf("按下第十个按钮\n");
        if(!mysqlite->insertInfo(20,platenum,1))//车位号、车牌号、状态
        {   printf("空的\n");
            int result = QMessageBox::question(this, "Message", "Are you sure?",QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes); // 默认选中Yes
            if (result == QMessageBox::Yes)
            {
                // 用户点击了确认按钮
                ui->pb_20->setStyleSheet(originalStyle+"background-color: red;");
                this->position=20;
            }
            else if(result==QMessageBox::No)
            {
                mysqlite->deleteInfo(platenum);
            }
        }
        else
        {
            QMessageBox::warning(this,"error","这个车位满了");
        }
        break;

    default:
        break;
    }
}

