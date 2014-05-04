#include "gea.h"
#include "ui_gea.h"

#define delay_val 250

int val_rpm;
int val_tps;
int val_injdurdeg;
int val_injoffdeg;
int val_ignoffdeg;

gea::gea(QWidget *parent) :
    QMainWindow(parent),port(0),
    ui(new Ui::gea)
{
    ui->setupUi(this);
    connect(ui->cmdOpen,SIGNAL(clicked()),this,SLOT(startStopComm()));
    connect(&dataTimer,SIGNAL(timeout()),this,SLOT(sendRequest()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(pollSerial()));
    timer.start(100);

    ui->tblInjOff->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblInjOff->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tblInjDur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblInjDur->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tblIgnOff->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblIgnOff->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tblHeader<<"0";tblHeader<<"10";tblHeader<<"20";tblHeader<<"30";tblHeader<<"40";tblHeader<<"50";
    tblHeader<<"60";tblHeader<<"70";tblHeader<<"80";tblHeader<<"90";tblHeader<<"100";

    ui->tblInjOff->setHorizontalHeaderLabels(tblHeader);
    ui->tblInjDur->setHorizontalHeaderLabels(tblHeader);

    tblHeader.clear();
    tblHeader<<"500";tblHeader<<"1000";tblHeader<<"1500";tblHeader<<"2000";tblHeader<<"2500";tblHeader<<"3000";
    tblHeader<<"3500";tblHeader<<"4000";tblHeader<<"4500";tblHeader<<"5000";tblHeader<<"5500";

    ui->tblIgnOff->setHorizontalHeaderLabels(tblHeader);
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
            ui->cmdRun->setText("Start");
            ui->cmdGetIgnOff->setEnabled(true);
            ui->cmdGetInjDur->setEnabled(true);
            ui->cmdGetInjOff->setEnabled(true);
            ui->cmdGetTPS->setEnabled(true);
            ui->cmdSetIgnOff->setEnabled(true);
            ui->cmdSetInjDur->setEnabled(true);
            ui->cmdSetInjOff->setEnabled(true);
            ui->cmdSetTPS->setEnabled(true);
            ui->cmdOnGet->setEnabled(true);
            ui->cmdOffGet->setEnabled(true);
        }
    }
}

void gea::sendRequest(){

    if(!port) return;

    ui->txtData->clear();

    QByteArray dataReq="data\r";
    port->write(dataReq);

    mydelay(delay_val);

    QString strData=ui->txtData->toPlainText();

    QStringList strVariable=strData.split(",");

    QString strTPS=strVariable[1];
    int vstrTPS=strTPS.toInt();
    val_tps= vstrTPS;

    QString strRPM=strVariable[0];
    int vstrRPM=strRPM.toInt();
    val_rpm=vstrRPM;

    QString strInjDurDeg=strVariable[4];
    int vstrInjDurDeg=strInjDurDeg.toInt();
    val_injdurdeg=vstrInjDurDeg;

    QString strInjOffDeg=strVariable[5];
    int vstrInjOffDeg=strInjOffDeg.toInt();
    val_injoffdeg=vstrInjOffDeg;

    QString strIgnOffDeg=strVariable[3];
    int vstrIgnOffDeg=strIgnOffDeg.toInt();
    val_ignoffdeg=vstrIgnOffDeg;
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

void gea::on_cmdRun_clicked(){
    if(!port)return;

    if(ui->cmdRun->text()=="Start"){
        dataTimer.start();
        ui->cmdRun->setText("Stop");
        ui->cmdGetIgnOff->setEnabled(false);
        ui->cmdGetInjDur->setEnabled(false);
        ui->cmdGetInjOff->setEnabled(false);
        ui->cmdGetTPS->setEnabled(false);
        ui->cmdSetIgnOff->setEnabled(false);
        ui->cmdSetInjDur->setEnabled(false);
        ui->cmdSetInjOff->setEnabled(false);
        ui->cmdSetTPS->setEnabled(false);
        ui->cmdOnGet->setEnabled(false);
        ui->cmdOffGet->setEnabled(false);
    }
    else if(ui->cmdRun->text()=="Stop"){
        dataTimer.stop();
        ui->cmdRun->setText("Start");
        ui->cmdGetIgnOff->setEnabled(true);
        ui->cmdGetInjDur->setEnabled(true);
        ui->cmdGetInjOff->setEnabled(true);
        ui->cmdGetTPS->setEnabled(true);
        ui->cmdSetIgnOff->setEnabled(true);
        ui->cmdSetInjDur->setEnabled(true);
        ui->cmdSetInjOff->setEnabled(true);
        ui->cmdSetTPS->setEnabled(true);
        ui->cmdOnGet->setEnabled(true);
        ui->cmdOffGet->setEnabled(true);
    }
}

void gea::mydelay(int millisecondsToWait){
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
        while( QTime::currentTime() < dieTime ){
            QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
        };
        return;
}

void gea::setTPS(){
    if(!port)return;

    QByteArray dataTPS;
    dataTPS="save_tps";

    dataTPS+=" ";
    dataTPS+= ui->txtOffTPS->text();

    dataTPS+=" ";
    dataTPS+=ui->txtOnTPS->text();

    dataTPS+="\r";

    port->write(dataTPS);

}

void gea::getTPS(){
    if(!port)return;

    QByteArray reqTPS="read_tps\r";
    port->write(reqTPS);

    mydelay(delay_val);

    QString dataTPS=ui->txtData->toPlainText();

    QStringList lstTPS=dataTPS.split(",");

    ui->txtOffTPS->setText(lstTPS[0]);
    ui->txtOnTPS->setText(lstTPS[1]);
}

void gea::setInjOff(){
    if(!port)return;

    int i;

    QByteArray dataInjOff="save_injoff";
    for(i=0;i<4;i++){
        dataInjOff+=" ";
        dataInjOff+=ui->tblInjOff->item(0,i)->text();
    }
    port->write(dataInjOff);
    mydelay(delay_val);

    dataInjOff="";
    for(i=4;i<8;i++){
        dataInjOff+=" ";
        dataInjOff+=ui->tblInjOff->item(0,i)->text();
    }
    port->write(dataInjOff);
    mydelay(delay_val);

    dataInjOff="";
    for(i=8;i<cdata;i++){
        dataInjOff+=" ";
        dataInjOff+=ui->tblInjOff->item(0,i)->text();
    }
    port->write(dataInjOff);
    mydelay(delay_val);

    dataInjOff="\r";
    port->write(dataInjOff);
}

void gea::getInjOff(){
    if(!port)return;

    QByteArray reqInjOff="read_injoff\r";
    port->write(reqInjOff);

    mydelay(delay_val);

    QString dataInjOff=ui->txtData->toPlainText();

    QStringList lstInjOff=dataInjOff.split(",");

    int i;

    for(i=0;i<cdata;i++){
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(lstInjOff[i]);
        ui->tblInjOff->setItem(0,i,item);
    }
}

void gea::setInjDur(){
    if(!port)return;

    int i;

    QByteArray dataInjDur="save_injdur";
    for(i=0;i<4;i++){
        dataInjDur+=" ";
        dataInjDur+=ui->tblInjDur->item(0,i)->text();
    }
    port->write(dataInjDur);
    mydelay(delay_val);

    dataInjDur="";
    for(i=4;i<8;i++){
        dataInjDur+=" ";
        dataInjDur+=ui->tblInjDur->item(0,i)->text();
    }
    port->write(dataInjDur);
    mydelay(delay_val);

    dataInjDur="";
    for(i=8;i<cdata;i++){
        dataInjDur+=" ";
        dataInjDur+=ui->tblInjDur->item(0,i)->text();
    }
    port->write(dataInjDur);
    mydelay(delay_val);

    dataInjDur="\r";
    port->write(dataInjDur);
}

void gea::getInjDur(){
    if(!port)return;

    QByteArray reqInjDur="read_injdur\r";
    port->write(reqInjDur);

    mydelay(delay_val);

    QString dataInjDur=ui->txtData->toPlainText();

    QStringList lstInjDur=dataInjDur.split(",");

    int i;

    for(i=0;i<cdata;i++){
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(lstInjDur[i]);
        ui->tblInjDur->setItem(0,i,item);
    }
}

void gea::setIgnOff(){
    if(!port)return;

    int i;

    QByteArray dataIgnOff="save_ignoff";
    for(i=0;i<4;i++){
        dataIgnOff+=" ";
        dataIgnOff+=ui->tblIgnOff->item(0,i)->text();
    }
    port->write(dataIgnOff);
    mydelay(delay_val);

    dataIgnOff="";
    for(i=4;i<8;i++){
        dataIgnOff+=" ";
        dataIgnOff+=ui->tblIgnOff->item(0,i)->text();
    }
    port->write(dataIgnOff);
    mydelay(delay_val);

    dataIgnOff="";
    for(i=8;i<cdata;i++){
        dataIgnOff+=" ";
        dataIgnOff+=ui->tblIgnOff->item(0,i)->text();
    }
    port->write(dataIgnOff);
    mydelay(delay_val);

    dataIgnOff="\r";
    port->write(dataIgnOff);
}

void gea::getIgnOff(){
    if(!port)return;

    QByteArray reqIgnOff="read_ignoff\r";
    port->write(reqIgnOff);

    mydelay(delay_val);

    QString dataIgnOff=ui->txtData->toPlainText();

    QStringList lstIgnOff=dataIgnOff.split(",");

    int i;

    for(i=0;i<cdata;i++){
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(lstIgnOff[i]);
        ui->tblIgnOff->setItem(0,i,item);
    }
}

void gea::on_cmdSetInjOff_clicked()
{
    ui->txtData->clear();
    setInjOff();
}

void gea::on_cmdGetInjOff_clicked()
{
    ui->txtData->clear();
    getInjOff();
}

void gea::on_cmdSetInjDur_clicked()
{
    ui->txtData->clear();
    setInjDur();
}

void gea::on_cmdGetInjDur_clicked()
{
    ui->txtData->clear();
    getInjDur();
}

void gea::on_cmdSetIgnOff_clicked()
{
    ui->txtData->clear();
    setIgnOff();
}

void gea::on_cmdGetIgnOff_clicked()
{
    ui->txtData->clear();
    getIgnOff();
}

void gea::on_cmdSetTPS_clicked()
{
    ui->txtData->clear();
    setTPS();
}

void gea::on_cmdGetTPS_clicked()
{
    ui->txtData->clear();
    getTPS();
}

void gea::on_cmdOnGet_clicked()
{
    ui->txtData->clear();

    if(!port)return;

    QByteArray reqTPS="tps_val\r";
    port->write(reqTPS);

    mydelay(delay_val);

    ui->txtOnTPS->setText(ui->txtData->toPlainText());
}

void gea::on_cmdOffGet_clicked()
{
    ui->txtData->clear();

    if(!port)return;

    QByteArray reqTPS="tps_val\r";
    port->write(reqTPS);

    mydelay(delay_val);

    ui->txtOffTPS->setText(ui->txtData->toPlainText());

}

void gea::load_default(){
    int i;

    QString dataTPS="195,1395";
    QStringList lstTPS=dataTPS.split(",");
    ui->txtOffTPS->setText(lstTPS[0]);
    ui->txtOnTPS->setText(lstTPS[1]);

//    QString dataInjOff="10,12,14,16,18,20,25,25,25,25,25";
    QString dataInjOff="30,30,35,35,40,40,45,45,50,50,55";
    QStringList lstInjOff=dataInjOff.split(",");
    for(i=0;i<cdata;i++){
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(lstInjOff[i]);
        ui->tblInjOff->setItem(0,i,item);
    };

//    QString dataInjDur="25,30,35,40,45,50,55,60,65,70,75";
    QString dataInjDur="25,35,35,45,45,55,55,65,65,75,75";
    QStringList lstInjDur=dataInjDur.split(",");
    for(i=0;i<cdata;i++){
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(lstInjDur[i]);
        ui->tblInjDur->setItem(0,i,item);
    };

//    QString dataIgnOff="10,12,15,18,19,20,21,21,23,23,21";
    QString dataIgnOff="11,14,16,18,20,22,24,26,28,30,32";
    QStringList lstIgnOff=dataIgnOff.split(",");
    for(i=0;i<cdata;i++){
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(lstIgnOff[i]);
        ui->tblIgnOff->setItem(0,i,item);
    }
}

void gea::on_actionDefault_triggered()
{
    load_default();
}
