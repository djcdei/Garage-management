#ifndef CARSPACE_H
#define CARSPACE_H
#include<QString>
#include <QWidget>

namespace Ui {
class CarSpace;
}

class CarSpace : public QWidget
{
    Q_OBJECT

public:
    explicit CarSpace(QWidget *parent = nullptr);
    ~CarSpace();
   void setPlatenum(QString _platenum);

private slots:
    void on_pb_back_clicked();

private:
    Ui::CarSpace *ui;
    QString platenum;

};

#endif // CARSPACE_H
