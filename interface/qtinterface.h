#ifndef QTINTERFACE_H
#define QTINTERFACE_H

#include <QMainWindow>

#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class qtinterface;
}

class qtinterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit qtinterface(QWidget *parent = 0);
    ~qtinterface();

private slots:
    void on_actionAboutQt_triggered();

    void on_btnOpen_clicked();

private:
    Ui::qtinterface *ui;
};

#endif // QTINTERFACE_H
