#ifndef GEA_H
#define GEA_H

#include <QMainWindow>
#include <QTimer>
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
    void parsingString(void);

    void on_cmdRun_clicked();

private:
    Ui::gea *ui;
    QextSerialPort *port;
    QTimer timer;
    QTimer dataTimer;
    QString deviceName;

    int flagRun;
    QString strData;
    QString strTxtData;
    QStringList strLstData;

    QStringList strVariable;

    QString strTPS;
    int vstrTPS;

    QString strRPM;
    int vstrRPM;

    QString strInjDurDeg;
    int vstrInjDurDeg;

    QString strInjOffDeg;
    int vstrInjOffDeg;

    QString strInjDurTick;
    int vstrInjDurTick;
    float vInjVol;

    QString strIgnOffDeg;
    int vstrIgnOffDeg;

};

#endif // GEA_H

