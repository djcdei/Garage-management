#ifndef PARKINGSPACE_H
#define PARKINGSPACE_H

#include <QWidget>

namespace Ui {
class Parkingspace;
}

class Parkingspace : public QWidget
{
    Q_OBJECT

public:
    explicit Parkingspace(QWidget *parent = nullptr);
    ~Parkingspace();

private slots:
    void on_pb_exit_clicked();

private:
    Ui::Parkingspace *ui;
};

#endif // PARKINGSPACE_H
