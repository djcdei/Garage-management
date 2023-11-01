#include "carspace.h"
#include "ui_carspace.h"

CarSpace::CarSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarSpace)
{
    ui->setupUi(this);
}

CarSpace::~CarSpace()
{
    delete ui;
}

void CarSpace::setPlatenum(QString _platenum)
{
    this->platenum=_platenum;
}

void CarSpace::on_pb_back_clicked()
{
    this->close();
}

