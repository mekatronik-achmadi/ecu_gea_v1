#ifndef GEA_H
#define GEA_H

#define cdata 11

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

#include "frmrpm.h"
#include "frmtps.h"
#include "frmclk.h"
#include "frmign.h"
#include "frminj.h"
#include "dial_meter.h"

#include "qextserialport.h"

namespace Ui {
class gea;
}

class gea : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit gea(QWidget *parent = 0);
    ~gea();
    
private slots:
    void on_actionQuit_triggered();
    void on_actionAboutQt_triggered();
    void startStopComm(void);
    void pollSerial(void);
    void sendRequest(void);
    void on_cmdRun_clicked();
    void setInjOff(void);
    void getInjOff(void);
    void setInjDur(void);
    void getInjDur(void);
    void setIgnOff(void);
    void getIgnOff(void);
    void setTPS(void);
    void getTPS(void);
    void mydelay(int millisecondsToWait);
    void load_default(void);

    void on_cmdSetInjOff_clicked();

    void on_cmdGetInjOff_clicked();

    void on_cmdSetInjDur_clicked();

    void on_cmdGetInjDur_clicked();

    void on_cmdSetIgnOff_clicked();

    void on_cmdGetIgnOff_clicked();

    void on_cmdSetTPS_clicked();

    void on_cmdGetTPS_clicked();

    void on_cmdOnGet_clicked();

    void on_cmdOffGet_clicked();

    void on_actionDefault_triggered();

private:
    Ui::gea *ui;
    QextSerialPort *port;
    QTimer timer;
    QTimer dataTimer;
    QString deviceName;
    QStringList tblHeader;
};

#endif // GEA_H

