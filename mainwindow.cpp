#include "mainwindow.h"
#include "ui_mainwindow.h"
extern int cameraFlag;//开/关摄像头采集数据线程
extern int serialFlag;//开/关串口读取线程
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #337ab7;"); // 设置背景颜色
    ui->label_11_title->setStyleSheet("background-color: green; color: white; border: 2px solid darkblue; border-radius: 5px;");
    ui->label_date->setStyleSheet("QLabel {"
                                  "    background-color: #2e6da4;"  // 背景颜色
                                  "    color: white;"                // 文本颜色
                                  "    font-size: 18px;"             // 字体大小
                                  "    border: 2px solid black;"     // 边框
                                  "    border-radius: 10px;"        // 边框圆角
                                  "    padding: 5px;"               // 内边距
                                  "}");
    ui->pb_admlogin->setStyleSheet("QPushButton {"
                                   "    background-color: #3d8ebe;"   // 背景颜色
                                   "    border: 1px solid #2e6da4;"    // 边框样式
                                   "    color: white;"                // 文本颜色
                                   "    font-size: 16px;"             // 字体大小
                                   "    border-radius: 5px;"          // 边框圆角
                                   "    padding: 5px 10px;"           // 内边距
                                   "}");
    ui->pb_exit->setStyleSheet("QPushButton {"
                               "    background-color: #3d8ebe;"   // 背景颜色
                               "    border: 1px solid #2e6da4;"    // 边框样式
                               "    color: white;"                // 文本颜色
                               "    font-size: 16px;"             // 字体大小
                               "    border-radius: 5px;"          // 边框圆角
                               "    padding: 5px 10px;"           // 内边距
                               "}");
    ui->pb_userlogin->setStyleSheet("QPushButton {"
                                    "    background-color: #3d8ebe;"   // 背景颜色
                                    "    border: 1px solid #2e6da4;"    // 边框样式
                                    "    color: white;"                // 文本颜色
                                    "    font-size: 16px;"             // 字体大小
                                    "    border-radius: 5px;"          // 边框圆角
                                    "    padding: 5px 10px;"           // 内边距,文字跟按钮边框的水平、垂直间距
                                    "}");
    ui->pb_L->setStyleSheet("QPushButton {"
                            "    background-color: #3d8ebe;"   // 背景颜色
                            "    border: 1px solid #2e6da4;"    // 边框样式
                            "    color: white;"                // 文本颜色
                            "    font-size: 16px;"             // 字体大小
                            "    border-radius: 5px;"          // 边框圆角
                            "    padding: 1px 1px;"           // 内边距,文字跟按钮边框的水平、垂直间距
                            "}");
    ui->pb_R->setStyleSheet("QPushButton {"
                            "    background-color: #3d8ebe;"   // 背景颜色
                            "    border: 1px solid #2e6da4;"    // 边框样式
                            "    color: white;"                // 文本颜色
                            "    font-size: 16px;"             // 字体大小
                            "    border-radius: 5px;"          // 边框圆角
                            "    padding: 1px 1px;"           // 内边距,文字跟按钮边框的水平、垂直间距
                            "}");
    //初始化摄像头对象
    mycamera=new camera();
    mycamera->cameraInit();
    mycamera->setLabel(ui->label_show);
    mycamera->start();

    //初始化串口对象
    myserial=new serial(this);

    connect(myserial,SIGNAL(mySignal(int)),this,SLOT(cardidfun(int)));
     myserial->start();
    //初始化数据库
    mysqlite=new sqlite3();
    mysqlite->openSqlite("cars.db");//创建并打开数据库
    mysqlite->createTable();

    //关联http请求
    connect(&myManager,SIGNAL(finished(QNetworkReply *)),this,SLOT(netReply(QNetworkReply *)));

    //初始化一个管理员对话框
    adminDialog=new class adminDialog();
    carspace=new class CarSpaceDialog();

    // 创建一个定时器，每秒更新一次时间
    mytimer=new QTimer(this);
    mytimer->start(1000); // 每1000毫秒（1秒）触发一次定时器

    // 连接定时器的timeout信号到槽函数，用于更新时间
    QObject::connect(mytimer, &QTimer::timeout, [=]() {
        // 获取当前系统日期和时间
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString currentDateTimeString = currentDateTime.toString("yyyy-MM-dd\nhh:mm:ss"); // 格式化日期和时间字符串

        // 更新标签文本显示当前日期和时间
        ui->label_date->setText(currentDateTimeString);
    });

    myadver=new Advertisement(ui->label_adv);
    myadver->startAdvertising(2000);


    p_lab=new QLabel*[20];
    p_lab[0]=ui->label;
    p_lab[1]=ui->label_2;
    p_lab[2]=ui->label_3;
    p_lab[3]=ui->label_4;
    p_lab[4]=ui->label_5;
    p_lab[5]=ui->label_6;
    p_lab[6]=ui->label_7;
    p_lab[7]=ui->label_8;
    p_lab[8]=ui->label_9;
    p_lab[9]=ui->label_10;
    p_lab[10]=ui->label_11;
    p_lab[11]=ui->label_12;
    p_lab[12]=ui->label_13;
    p_lab[13]=ui->label_14;
    p_lab[14]=ui->label_15;
    p_lab[15]=ui->label_16;
    p_lab[16]=ui->label_17;
    p_lab[17]=ui->label_18;
    p_lab[18]=ui->label_19;
    p_lab[19]=ui->label_20;
 
    setLabelColor();

    // 连接按钮1和按钮2的clicked信号到handleButtonClicked槽函数
    connect(ui->pb_L, SIGNAL(clicked()),this, SLOT(handleButtonClicked()));
    connect(ui->pb_R, SIGNAL(clicked()),this, SLOT(handleButtonClicked()));
    ui->widget_2->hide();
}

MainWindow::~MainWindow()
{
    mycamera->quit();
    mycamera->wait();
    mycamera->cameraClose();
    myserial->quit();
    myserial->wait();
    myadver->stopAdvertising();
    if (mytimer) {
        mytimer->stop();
        mytimer->deleteLater();
    }
    printf("0\n");
    if(myserial!=nullptr)
        delete myserial;
    printf("1\n");
    if(mycamera!=nullptr)
        delete mycamera;
    printf("2\n");
    if(myadver!=nullptr)
        delete myadver;
    printf("3\n");
    delete ui;
    printf("4\n");
}



void MainWindow::on_pb_exit_clicked()//退出按键
{
    cameraFlag=0;
    serialFlag=0;
    QApplication::quit();
}

void MainWindow::cardidfun(int value)//自己定义的槽函数，刷卡之后拍照，发送http请求
{
    cardid=QString::number(value,16);
    qDebug()<<"id:"<<cardid;
    /*调用数据库类，对这个卡进行增删操作，并且将车牌拍照，上传阿里云API*/
    myimage= mycamera->camerPthoto();
    QByteArray byteAr;
    QBuffer buf(&byteAr);
    myimage.save(&buf,"JPG");
    //第一步初始化http请求
    QUrl myUrl("http://ocrcp.market.alicloudapi.com/rest/160601/ocr/ocr_vehicle_plate.json");
    QNetworkRequest myRequest(myUrl);
    QString appCode="APPCODE 800d7be2cf5042d2b364a4ba1c9b5a9c";
    QString host="ocrcp.market.alicloudapi.com";
    myRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    myRequest.setRawHeader("Authorization",appCode.toLocal8Bit());
    myRequest.setRawHeader("Host",host.toLocal8Bit());
    //创建json对象（json格式需要根据你找的API提供的格式来创建）
    QJsonObject jsonObj;
    jsonObj.insert("image",byteAr.toBase64().data());
    jsonObj.insert("configure","{\"multi_crop\":ture}");
    //创建jsondocument对象保存刚才创建的json对象
    QJsonDocument jsonDoc=QJsonDocument(jsonObj);
    //把json数据转化成post函数需要的QByteArry类型
    QByteArray post_data=jsonDoc.toJson(QJsonDocument::Compact);
    myManager.post(myRequest,post_data);//
}


void MainWindow::on_pb_admlogin_clicked()//管理员登录界面
{
    cameraFlag=0;
    serialFlag=0;
    myadver->stopAdvertising();
    adminDialog->updateTablewidgetData();
    adminDialog->exec();
    printf("管理员界面退出了\n");
    cameraFlag=1;
    serialFlag=1;
    usleep(10000);
    mycamera->start();
    usleep(10000);
    myserial->start();
    usleep(10000);
    myadver->startAdvertising(2000);
}


void MainWindow::netReply(QNetworkReply *rep)//自己关联的http请求回复函数
{
    qDebug()<<10;
    QByteArray buf=rep->readAll();
    rep->deleteLater();
    //printf("回复请求%s\n",buf.data());
     // 获取 plates 字段 (它是一个数组)
    QString jsonString=buf;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());

    QJsonObject rootObject = jsonDoc.object();
    QJsonValue platesValue = rootObject["plates"];
    if (!platesValue.isArray())
    {
        qDebug() << "plates is not an array";
    }
    else
    {
        QJsonArray platesArray = platesValue.toArray();
        for (int i = 0; i < platesArray.size(); ++i)
        {
            QJsonObject plate = platesArray[i].toObject();
            qDebug() << "车型: " << plate["cls_name"].toString();
            QJsonObject roi = plate["roi"].toObject();
            qDebug() << "车牌号: " << plate["txt"].toString();
            platenum=plate["txt"].toString();
        }
        if(mysqlite->compareInfo(cardid,platenum)==1)//
        {
            if(!mysqlite->insertInfo(cardid,platenum,88,"carstable"))
            {
                printf("入库\n");
                //选择车位界面
               // cardialog->exec();
                starttime=time(NULL);//记录入库时间
                //打开一个窗口，让用户选择车位,阻塞打开，这个界面主要用于选择车位
                carspace->setPlatenum(platenum);
                carspace->setPbColor();
                cameraFlag=0;
                serialFlag=0;
                usleep(10000);
                myadver->stopAdvertising();
                carspace->exec();
                printf("车位选择界面退出了\n");
                position=carspace->getPosition();
                setLabelColor();
                usleep(10000);
                cameraFlag=1;
                serialFlag=1;
                mycamera->start();
                usleep(10000);
                myserial->start();
                usleep(10000);
                myadver->startAdvertising(2000);
                //更新admintable表格数据
                mysqlite->updateInfo(platenum,position);
            }
            else
            {
                printf("出库\n");
                endtime=time(NULL);//记录出库时间
                //根据车牌号或者id号获取当前余额，并从carstable表格删除，以便下一次入库插入
                balance = mysqlite->deleteInfo(cardid,endtime-starttime);
                printf("时间差:%d\n",endtime-starttime);
                printf("更新余额:%.2f\n",balance);
                //更新admintable表格数据
                mysqlite->updateInfo(cardid,0,balance,starttime,endtime);
                //删除车位表中对应的车
                mysqlite->deleteInfo(platenum);//出库，根据车牌号把车位表相应的行删除，相当于这个车位可以继续用了              
                setLabelColor();
                QString str=QString("出库成功\n扣除余额:%1\n当前余额:%2").arg(endtime-starttime).arg(balance);
                QMessageBox::information(this,"message",str);
            }
        }
        else
        {
            printf("警告！！！卡号跟车牌号不匹配，请先绑定\n");
        }
    }
}


QString MainWindow::getPlatenum()//获取当前车牌号，由选者车牌界面调用
{
    return this->platenum;
}




void MainWindow::on_pb_userlogin_clicked()//用户登录
{

}

void MainWindow::setLabelColor()
{
    QSqlDatabase mybase;
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
    for(int i=0;i<20;i++)
    {
       p_lab[i]->setStyleSheet("background-color: green; color: white; border: 2px solid darkblue; border-radius: 5px;");
    }
    originalStyle=ui->label->styleSheet();
    if (query.exec("SELECT pos FROM spacetable"))
    {
       if (query.first()) // 检查是否有结果
       {
            int cnt = 0; // 初始化 cnt 为0
            do
            {
                int spaceNumber = query.value(0).toInt();
                printf("已停车位:%d\n", spaceNumber);
                p_lab[spaceNumber - 1]->setStyleSheet(originalStyle + "background-color:red;");
                cnt++;
            } while (query.next());
            QString str = QString("%1/20").arg(cnt);
            ui->label_11_title->setText("车位信息:" + str);
        }
        else
        {
            // 没有结果，设置 cnt 为0
            int cnt = 0;
            QString str = QString("%1/20").arg(cnt);
            ui->label_11_title->setText("车位信息:" + str);
        }
    }
    else
    {
    qDebug() << "查询出错：" << query.lastError().text();
    }

    mybase.close(); // 关闭数据库连接

}

void MainWindow::handleButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (button == ui->pb_R)
    {
        qDebug() << "左切";
        if(ui->widget_2->isHidden())
            ui->widget_2->show();
        else
            QMessageBox::warning(this,"注意","已经到最后一页了!");
    }
    else if (button == ui->pb_L)
    {
        qDebug() << "右切";
        // 执行右切的操作
        if(ui->widget_2->isHidden())
            QMessageBox::warning(this,"注意","这是第一页!");
        else
            ui->widget_2->hide();
    }
}


