#include "gea.h"
#include "ui_gea.h"

int val_rpm;
int val_tps;
int val_injdurdeg;
int val_injoffdeg;
int val_injvol;
int val_ignoffdeg;

gea::gea(QWidget *parent) :
    QMainWindow(parent),port(0),
    ui(new Ui::gea)
{
    ui->setupUi(this);
    flagRun=0;
    connect(ui->cmdOpen,SIGNAL(clicked()),this,SLOT(startStopComm()));
    connect(&dataTimer,SIGNAL(timeout()),this,SLOT(sendRequest()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(pollSerial()));
    timer.start(100);
}

gea::~gea()
{
    delete ui;
}

void gea::on_actionQuit_triggered()
{
    QApplication::quit();
}

void gea::on_actionAboutQt_triggered()
{
    if (port){
        if(port->isOpen()){
            port->close();
        }
        delete port;
        port = NULL;
    }
    QApplication::aboutQt();
}

void gea::startStopComm(){

    if(ui->cmdOpen->text()=="Open"){
        if (port){
            if(port->isOpen()){
                port->close();
            }
            delete port;
            port = NULL;
        }
        else{
            deviceName = ui->cmbPort->currentText();
            QString device;
            device = QString("/dev/");
            device += deviceName;
            port = new QextSerialPort(device, QextSerialPort::Polling);
            port->setBaudRate(BAUD38400);
            port->setDataBits(DATA_8);
            port->setParity(PAR_NONE);
            port->setStopBits(STOP_1);
            port->setFlowControl(FLOW_OFF);
            port->setTimeout(100);

            if (!port->open(QIODevice::ReadWrite)){
                delete port;
                port = NULL;
                QString s("Cannot open port ");
                s += device;
                QMessageBox::critical(this,"Error",s);
            }
            else{
                ui->cmdOpen->setText("Close");
                dataTimer.start();
            }
        }
    }
    else if(ui->cmdOpen->text()=="Close"){
        if (port){
            if(port->isOpen()){
                port->close();
            }
            delete port;
            port = NULL;
            ui->cmdOpen->setText("Open");
            dataTimer.stop();
            flagRun=0;
            ui->cmdRun->setText("Start");
        }
    }
}

void gea::sendRequest(){
    if(!port) return;

    if(flagRun==1){
        strTxtData=ui->txtData->toPlainText();
        strLstData=strTxtData.split("\n");
        strData=strLstData[1];
        ui->lblData->setText(strData);
        parsingString();
    }

    ui->txtData->clear();

    port->putChar('d');
    port->putChar('a');
    port->putChar('t');
    port->putChar('a');
    port->putChar('\r');

}

void gea::pollSerial(){
    if (!port) return;
    QByteArray bytes = port->readAll();
    bytes.replace("\r", "");
    if (bytes.isEmpty()) return;
    if (bytes.contains(8)){
        for (int i=0;i<bytes.count();i++){
            char ch = bytes.at(i);
            if (ch == 8){
                QString s = ui->txtData->toPlainText();
                s.chop(1);
                ui->txtData->setPlainText(s);
            }
            else{
                QString s(ch);
                ui->txtData->insertPlainText(s);
            }
            ui->txtData->moveCursor(QTextCursor::End);
        };
    }
    else{
        ui->txtData->moveCursor(QTextCursor::End);
        ui->txtData->insertPlainText(bytes);
    }
    ui->txtData->ensureCursorVisible();
}

void gea::parsingString(){
    strVariable=strData.split(",");

    strTPS=strVariable[1];
    vstrTPS=strTPS.toInt();
    val_tps= 100*vstrTPS/1450;

    strRPM=strVariable[0];
    vstrRPM=strRPM.toInt();
    val_rpm=vstrRPM;

    strInjDurDeg=strVariable[5];
    vstrInjDurDeg=strInjDurDeg.toInt();
    val_injdurdeg=vstrInjDurDeg;

    strInjOffDeg=strVariable[7];
    vstrInjOffDeg=strInjOffDeg.toInt();
    val_injoffdeg=vstrInjOffDeg;

    strInjDurTick=strVariable[6];
    vstrInjDurTick=strInjDurTick.toInt();
    val_injvol=(float) 40*(vstrInjDurTick/1000)*(val_rpm/60);

    strIgnOffDeg=strVariable[4];
    vstrIgnOffDeg=strIgnOffDeg.toInt();
    val_ignoffdeg=vstrIgnOffDeg;
}

void gea::on_cmdRun_clicked()
{
    if(!port)return;

    if(flagRun==0){flagRun=1;ui->cmdRun->setText("Stop");}
    else if(flagRun==1){flagRun=0;ui->cmdRun->setText("Start");}
}
