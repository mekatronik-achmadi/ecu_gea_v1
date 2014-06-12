#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QTableWidgetItem>

#define no_target 0
#define parse_target 1
#define TPSFull_target 2
#define TPSOff_target 3
#define TPSRead_target 4
#define INJRead_target 5
#define IGNRead_target 6

#define cdata 12

namespace Ui {
class interface;
}

class interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = 0);
    ~interface();

private slots:
    void mydelay(int millisecondsToWait);

    void on_actionQuit_triggered();

    void on_actionInfoQt_triggered();

    void on_btnOpen_clicked();

    void read_data();

    void req_data();

    void parse_data(QString strInput);

    void on_btnMonitor_clicked();

    void on_btnTPSFullGet_clicked();

    void on_btnTPSOffGet_clicked();

    void on_btnTPSSet_clicked();

    void on_btnTPSGet_clicked();

    void tps_get(QString strInput);

    void on_actionDefault_triggered();

    void on_btnInjSet_clicked();

    void on_btnInjGet_clicked();

    void inj_get(QString strInput);

    void on_btnIgnSet_clicked();

    void on_btnIgnGet_clicked();

    void ign_get(QString strInput);

private:
    Ui::interface *ui;
    QSerialPort* my_port;
    QTimer* tmrdatareq;
    int data_target;
    int waitComm;
};

#endif // INTERFACE_H
