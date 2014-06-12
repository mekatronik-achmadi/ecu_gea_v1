#include "interface.h"
#include "dial_display.h"
#include "ui_interface.h"

int val_tps=0;
int val_rpm=0;
int val_inj=0;
int val_ign=0;
int val_map=0;
int val_temp=0;
int id_rpm;
int id_tps;

int defaultTPS[2]={195,1395};

int defaultInj[cdata][cdata]={
  {	44,	26,	13,	 4,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0},
  {	26,	29,	33,	35,	37,	40,	42,	44,	51,	55,	57,	59},
  {	28,	30,	34,	37,	39,	41,	43,	45,	52,	56,	59,	61},
  {	29,	32,	36,	38,	40,	43,	45,	47,	54,	58,	60,	62},
  {	36,	38,	43,	45,	48,	50,	52,	54,	61,	65,	68,	70},
  {	38,	40,	44,	46,	48,	51,	54,	56,	63,	67,	70,	74},
  {	40,	42,	47,	48,	50,	52,	57,	57,	62,	70,	72,	74},
  {	42,	45,	50,	52,	55,	57,	62,	62,	69,	75,	77,	80},
  {	44,	47,	51,	53,	56,	59,	62,	62,	74,	79,	82,	84},
  {	45,	48,	52,	55,	57,	59,	64,	64,	74,	81,	82,	84},
  {	47,	49,	54,	97,	97,	97,	97,	97,	88,	88,	88,	88},
  {	48,	50,	57,	97,	97,	97,	97,	97,	88,	88,	88,	88}
};

int defaultIgn[cdata][cdata]={
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30},
  {	10,	15,	15,	18,	20,	22,	25,	25,	27,	27,	30,	30}
};

interface::interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);

    ui->tblInj->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblInj->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tblIgn->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblIgn->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tabAll->addTab(new dial_display,"Display");

    my_port = new QSerialPort(this);
    tmrdatareq = new QTimer(this);
    tmrdatareq->stop();
    connect(my_port,SIGNAL(readyRead()),this,SLOT(read_data()));
    connect(tmrdatareq,SIGNAL(timeout()),this,SLOT(req_data()));

}

interface::~interface()
{
    delete ui;
}

void interface::mydelay(int millisecondsToWait){
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
        while( QTime::currentTime() < dieTime ){
            QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
        };
        return;
}

void interface::on_actionQuit_triggered()
{
    QApplication::quit();
}

void interface::on_actionInfoQt_triggered()
{
    QApplication::aboutQt();
}

void interface::on_btnOpen_clicked()
{
    QString dev_name="/dev/";
    dev_name += ui->cmbPort->currentText();

    if(ui->btnOpen->text()=="Open"){

        my_port->setPortName(dev_name);

        if(my_port->open(QIODevice::ReadWrite)){
            my_port->setBaudRate(QSerialPort::Baud38400,QSerialPort::AllDirections);
            my_port->setDataBits(QSerialPort::Data8);
            my_port->setStopBits(QSerialPort::OneStop);
            my_port->setFlowControl(QSerialPort::NoFlowControl);
            my_port->setParity(QSerialPort::NoParity);
            QMessageBox::information(this,"success","port success on "+dev_name );
            ui->btnOpen->setText("Close");
        }
        else{
            QMessageBox::critical(this,"Failed","port failed on "+dev_name);
            ui->btnOpen->setText("Open");
        }
    }

    else{
        if(my_port->isOpen()){
            my_port->close();
        }
        ui->btnOpen->setText("Open");
    }
}

void interface::read_data(){
    QByteArray rawdata=my_port->readAll();
    ui->txtCommData->insertPlainText(rawdata);

    if(ui->txtCommData->toPlainText().isEmpty()){return;}

    if(data_target==TPSFull_target){ui->txtTPSFull->setText(ui->txtCommData->toPlainText());}
    else if(data_target==TPSOff_target){ui->txtTPSOff->setText(ui->txtCommData->toPlainText());}
    else if(data_target==TPSRead_target){tps_get(ui->txtCommData->toPlainText());}
    else if(data_target==parse_target){parse_data(ui->txtCommData->toPlainText());}
    else if(data_target==INJRead_target){inj_get(ui->txtCommData->toPlainText());}
    else if(data_target==IGNRead_target){ign_get(ui->txtCommData->toPlainText());}
}

void interface::req_data(){
    ui->txtCommData->clear();
    data_target=parse_target;
    QByteArray dataReq="data\n";
    my_port->write(dataReq);
}

void interface::on_btnMonitor_clicked()
{
    if(ui->btnMonitor->text()=="Monitor"){
        if(!my_port->isOpen()){return;}

        tmrdatareq->start(100);
        ui->btnMonitor->setText("Setting");
    }
    else{
        tmrdatareq->stop();
        ui->btnMonitor->setText("Monitor");
    }
}

void interface::parse_data(QString strInput){
    QStringList strVal= strInput.split(",");

    if(strVal.count()<8){return;}

    val_rpm=strVal[0].toInt();
    val_tps=strVal[1].toInt();
    val_inj=strVal[2].toInt();
    val_ign=strVal[4].toInt();
    id_rpm=strVal[6].toInt();
    id_tps=strVal[7].toInt();

    val_map=0;
    val_temp=0;

    ui->tblInj->setCurrentCell(id_rpm,id_tps);
    ui->tblIgn->setCurrentCell(id_rpm,id_tps);
}

void interface::on_btnTPSFullGet_clicked()
{
    ui->txtCommData->clear();
    data_target=TPSFull_target;
    QByteArray tps_req_data="tps_val\n";
    my_port->write(tps_req_data);
}

void interface::on_btnTPSOffGet_clicked()
{
    ui->txtCommData->clear();
    data_target=TPSOff_target;
    QByteArray tps_req_data="tps_val\n";
    my_port->write(tps_req_data);
}

void interface::on_btnTPSSet_clicked()
{
    ui->txtCommData->clear();
    data_target=no_target;

    QByteArray dataTPS;
    dataTPS="save_tps";

    dataTPS+=" ";
    dataTPS+= ui->txtTPSOff->text();

    dataTPS+=" ";
    dataTPS+=ui->txtTPSFull->text();

    dataTPS+="\n";

    my_port->write(dataTPS);
}

void interface::on_btnTPSGet_clicked()
{
    ui->txtCommData->clear();
    data_target=TPSRead_target;
    QByteArray tps_req_data="read_tps\n";
    my_port->write(tps_req_data);
}

void interface::tps_get(QString strInput){
    QStringList strVal= strInput.split(",");

    if(strVal.count()<2){return;}

    ui->txtTPSOff->setText(strVal[0]);
    ui->txtTPSFull->setText(strVal[1]);

}

void interface::on_actionDefault_triggered()
{
    int i,j;

    ui->txtTPSOff->setText(QString::number(defaultTPS[0]));
    ui->txtTPSFull->setText(QString::number(defaultTPS[1]));

    for(i=0;i<cdata;i++){
        for(j=0;j<cdata;j++){
            QTableWidgetItem* tbl_item = new QTableWidgetItem();
            tbl_item->setText(QString::number(defaultInj[i][j]));
            ui->tblInj->setItem(i,j,tbl_item);
        }
    }

    for(i=0;i<cdata;i++){
        for(j=0;j<cdata;j++){
            QTableWidgetItem* tbl_item = new QTableWidgetItem();
            tbl_item->setText(QString::number(defaultIgn[i][j]));
            ui->tblIgn->setItem(i,j,tbl_item);
        }
    }

}

void interface::on_btnInjSet_clicked()
{
    int i=0,j=0;

    ui->txtCommData->clear();

    for(i=0;i<cdata;i++){
        for(j=0;j<cdata;j++){

            ui->tblInj->setCurrentCell(i,j);

            ui->txtCommData->clear();

            data_target=no_target;

            QByteArray dataInj;

            dataInj="save_inj";
            dataInj+= " ";

            dataInj+= QString::number(i).toUtf8();
            dataInj+= " ";

            dataInj+= QString::number(j).toUtf8();
            dataInj+= " ";

            dataInj+= ui->tblInj->item(i,j)->text().toUtf8();
            dataInj+= "\n";

            my_port->write(dataInj);

            mydelay(100);
        }
    }

    QMessageBox::information(this,"Success","Injection Table written Successfully");
}

void interface::on_btnInjGet_clicked()
{
    int i=0,j=0;

    ui->txtCommData->clear();

    for(i=0;i<cdata;i++){
        for(j=0;j<cdata;j++){

            ui->tblInj->setCurrentCell(i,j);

            ui->txtCommData->clear();
            data_target=INJRead_target;

            QByteArray dataInj="read_inj";
            dataInj+= " ";

            dataInj+= QString::number(i).toUtf8();
            dataInj+= " ";

            dataInj+= QString::number(j).toUtf8();
            dataInj+= "\n";

            my_port->write(dataInj);
            waitComm=1;

            while(waitComm==1){mydelay(100);}
        }
    }
    QMessageBox::information(this,"Success","Injection Table loaded Successfully");
}

void interface::inj_get(QString strInput){
    QStringList strVal= strInput.split(",");

    if(strVal.count()<3){return;}

    int i=0,j=0;
    i=strVal[0].toInt();
    j=strVal[1].toInt();
    QTableWidgetItem* tbl_item = new QTableWidgetItem();
    tbl_item->setText(strVal[2]);
    ui->tblInj->setItem(i,j,tbl_item);
    waitComm=0;
}

void interface::on_btnIgnSet_clicked()
{
    int i=0,j=0;

    ui->txtCommData->clear();

    for(i=0;i<cdata;i++){
        for(j=0;j<cdata;j++){

            ui->tblIgn->setCurrentCell(i,j);

            ui->txtCommData->clear();

            data_target=no_target;

            QByteArray dataIgn;

            dataIgn="save_ign";
            dataIgn+= " ";

            dataIgn+= QString::number(i).toUtf8();
            dataIgn+= " ";

            dataIgn+= QString::number(j).toUtf8();
            dataIgn+= " ";

            dataIgn+= ui->tblIgn->item(i,j)->text().toUtf8();
            dataIgn+= "\n";

            my_port->write(dataIgn);

            mydelay(100);
        }
    }

    QMessageBox::information(this,"Success","Ignition Table written Successfully");
}

void interface::on_btnIgnGet_clicked()
{
    int i=0,j=0;

    ui->txtCommData->clear();

    for(i=0;i<cdata;i++){
        for(j=0;j<cdata;j++){

            ui->tblIgn->setCurrentCell(i,j);

            ui->txtCommData->clear();
            data_target=IGNRead_target;

            QByteArray dataIgn="read_ign";
            dataIgn+= " ";

            dataIgn+= QString::number(i).toUtf8();
            dataIgn+= " ";

            dataIgn+= QString::number(j).toUtf8();
            dataIgn+= "\n";

            my_port->write(dataIgn);
            waitComm=1;

            while(waitComm==1){mydelay(100);}
        }
    }
    QMessageBox::information(this,"Success","Ignition Table loaded Successfully");
}

void interface::ign_get(QString strInput){
    QStringList strVal= strInput.split(",");

    if(strVal.count()<3){return;}

    int i=0,j=0;
    i=strVal[0].toInt();
    j=strVal[1].toInt();
    QTableWidgetItem* tbl_item = new QTableWidgetItem();
    tbl_item->setText(strVal[2]);
    ui->tblIgn->setItem(i,j,tbl_item);
    waitComm=0;
}