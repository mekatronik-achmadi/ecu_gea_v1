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

int defaultInjec[2]={5,200};

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

//    ui->tblInj->setCurrentCell(11,2);
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
    QString dev_name="";
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


            ui->btnMonitor->setEnabled(true);
            ui->txtCommData->setEnabled(true);
            ui->txtTPSFull->setEnabled(true);
            ui->txtTPSOff->setEnabled(true);
            ui->btnTPSFullGet->setEnabled(true);
            ui->btnTPSOffGet->setEnabled(true);
            ui->btnTPSGet->setEnabled(true);
            ui->btnTPSSet->setEnabled(true);
            ui->btnIgnGet->setEnabled(true);
            ui->btnIgnSet->setEnabled(true);
            ui->tblIgn->setEnabled(true);
            ui->btnInjGet->setEnabled(true);
            ui->btnInjSet->setEnabled(true);
            ui->tblInj->setEnabled(true);
            ui->txtBaseMs->setEnabled(true);
            ui->txtOpenMs->setEnabled(true);
            ui->btnInjecGet->setEnabled(true);
            ui->btnInjecSet->setEnabled(true);
            ui->txtIAC->setEnabled(true);
            ui->btnIACUp->setEnabled(true);
            ui->btnIACDown->setEnabled(true);
            ui->cmbPort->setEnabled(false);
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


        ui->btnMonitor->setEnabled(false);
        ui->txtCommData->setEnabled(false);
        ui->txtTPSFull->setEnabled(false);
        ui->txtTPSOff->setEnabled(false);
        ui->btnTPSFullGet->setEnabled(false);
        ui->btnTPSOffGet->setEnabled(false);
        ui->btnTPSGet->setEnabled(false);
        ui->btnTPSSet->setEnabled(false);
        ui->btnIgnGet->setEnabled(false);
        ui->btnIgnSet->setEnabled(false);
        ui->tblIgn->setEnabled(false);
        ui->btnInjGet->setEnabled(false);
        ui->btnInjSet->setEnabled(false);
        ui->tblInj->setEnabled(false);
        ui->txtBaseMs->setEnabled(false);
        ui->txtOpenMs->setEnabled(false);
        ui->btnInjecGet->setEnabled(false);
        ui->btnInjecSet->setEnabled(false);
        ui->txtIAC->setEnabled(false);
        ui->btnIACUp->setEnabled(false);
        ui->btnIACDown->setEnabled(false);
        ui->cmbPort->setEnabled(true);

        ui->btnOpen->setText("Open");
    }
}

void interface::read_data(){
    QByteArray rawdata=my_port->readAll();
    ui->txtCommData->insertPlainText(rawdata);

    if(ui->txtCommData->toPlainText().isEmpty()){return;}

    if(data_target==TPSFull_target){tps_full(ui->txtCommData->toPlainText());}
    else if(data_target==TPSOff_target){tps_off(ui->txtCommData->toPlainText());}
    else if(data_target==TPSRead_target){tps_get(ui->txtCommData->toPlainText());}
    else if(data_target==parse_target){parse_data(ui->txtCommData->toPlainText());}
    else if(data_target==INJRead_target){inj_get(ui->txtCommData->toPlainText());}
    else if(data_target==IGNRead_target){ign_get(ui->txtCommData->toPlainText());}
    else if(data_target==INJECRead_target){injec_get(ui->txtCommData->toPlainText());}
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

        ui->btnTPSGet->setEnabled(false);
        ui->btnTPSSet->setEnabled(false);
        ui->btnTPSFullGet->setEnabled(false);
        ui->btnTPSOffGet->setEnabled(false);
        ui->btnIgnGet->setEnabled(false);
        ui->btnIgnSet->setEnabled(false);
        ui->btnInjGet->setEnabled(false);
        ui->btnInjSet->setEnabled(false);
        ui->txtBaseMs->setEnabled(false);
        ui->txtOpenMs->setEnabled(false);
        ui->btnInjecGet->setEnabled(false);
        ui->btnInjecSet->setEnabled(false);
        ui->txtIAC->setEnabled(false);
        ui->btnIACUp->setEnabled(false);
        ui->btnIACDown->setEnabled(false);
        ui->btnOpen->setEnabled(false);
        ui->actionSave->setEnabled(false);
        ui->actionLoad->setEnabled(false);
        ui->actionDefault->setEnabled(false);
    }
    else{
        tmrdatareq->stop();

        ui->btnMonitor->setText("Monitor");

        ui->btnTPSGet->setEnabled(true);
        ui->btnTPSSet->setEnabled(true);
        ui->btnTPSFullGet->setEnabled(true);
        ui->btnTPSOffGet->setEnabled(true);
        ui->btnIgnGet->setEnabled(true);
        ui->btnIgnSet->setEnabled(true);
        ui->btnInjGet->setEnabled(true);
        ui->btnInjSet->setEnabled(true);
        ui->txtBaseMs->setEnabled(true);
        ui->txtOpenMs->setEnabled(true);
        ui->btnInjecGet->setEnabled(true);
        ui->btnInjecSet->setEnabled(true);
        ui->txtIAC->setEnabled(true);
        ui->btnIACUp->setEnabled(true);
        ui->btnIACDown->setEnabled(true);
        ui->btnOpen->setEnabled(true);
        ui->actionSave->setEnabled(true);
        ui->actionLoad->setEnabled(true);
        ui->actionDefault->setEnabled(true);
    }
}

void interface::parse_data(QString strInput){
    QStringList strVal= strInput.split(",");

    if(strVal.count()<9){return;}

    val_rpm=strVal[0].toInt();
    val_tps=strVal[1].toInt();
    val_inj=strVal[2].toInt();
    val_ign=strVal[4].toInt();
    id_rpm=strVal[7].toInt();
    id_tps=strVal[8].toInt();

    val_map=0;
    val_temp=0;

    ui->tblInj->setCurrentCell(id_tps,id_rpm);
    ui->tblIgn->setCurrentCell(id_tps,id_rpm);
}

void interface::on_btnTPSFullGet_clicked()
{
    ui->txtCommData->clear();
    data_target=TPSFull_target;
    QByteArray tps_req_data="tps_val\n";
    my_port->write(tps_req_data);
}

void interface::tps_full(QString strInput){
    int tpsfull=strInput.toInt();
    ui->txtTPSFull->setText(QString::number(tpsfull));
}

void interface::on_btnTPSOffGet_clicked()
{
    ui->txtCommData->clear();
    data_target=TPSOff_target;
    QByteArray tps_req_data="tps_val\n";
    my_port->write(tps_req_data);
}

void interface::tps_off(QString strInput){
    int tpsoff=strInput.toInt();
    ui->txtTPSOff->setText(QString::number(tpsoff));
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

    ui->txtBaseMs->setText(QString::number(defaultInjec[0]));
    ui->txtOpenMs->setText(QString::number(defaultInjec[1]));

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

void interface::on_btnInjecSet_clicked()
{
    ui->txtCommData->clear();
    data_target=no_target;

    QByteArray dataInjec;
    dataInjec="save_injec";

    dataInjec+=" ";
    dataInjec+= ui->txtBaseMs->text();

    dataInjec+=" ";
    dataInjec+= ui->txtOpenMs->text();

    dataInjec+="\n";

    my_port->write(dataInjec);
}

void interface::on_btnInjecGet_clicked()
{
    ui->txtCommData->clear();
    data_target=INJECRead_target;
    QByteArray injec_req_data="read_injec\n";
    my_port->write(injec_req_data);
}

void interface::injec_get(QString strInput){
    QStringList strVal= strInput.split(",");

    if(strVal.count()<2){return;}

    ui->txtBaseMs->setText(strVal[0]);
    ui->txtOpenMs->setText(strVal[1]);
}

void interface::on_btnIACUp_clicked()
{
    ui->txtCommData->clear();
    data_target=no_target;
    int IACval=ui->txtIAC->text().toInt();
    QByteArray iac_up_req_data="iac_up";
    iac_up_req_data += " ";
    iac_up_req_data += QString::number(IACval).toUtf8();
    iac_up_req_data += "\n";
    my_port->write(iac_up_req_data);
}

void interface::on_btnIACDown_clicked()
{
    ui->txtCommData->clear();
    data_target=no_target;
    int IACval=ui->txtIAC->text().toInt();
    QByteArray iac_down_req_data="iac_down";
    iac_down_req_data += " ";
    iac_down_req_data += QString::number(IACval).toUtf8();
    iac_down_req_data += "\n";
    my_port->write(iac_down_req_data);
}

void interface::on_actionSave_triggered()
{
    QString filename;
    QString filesave=QFileDialog::getSaveFileName(this,"save data","","Gea Tuning data (*.gea)");

    if(filesave.isEmpty()){return;}

    QStringList filenameparse = filesave.split(".");

    if(filenameparse.count()==2){
        filename=filenameparse[0];
    }
    else if(filenameparse.count()==1){
        filename=filesave;
    }

    filename += ".gea";

    QFile filestream(filename);
    if(!filestream.open(QFile::WriteOnly|QFile::Text|QFile::Truncate)){
        QMessageBox::critical(this,"Failed","File failed to save");
        return;
    }

    QTextStream filewrite(&filestream);

    filewrite<<ui->txtTPSOff->text()<<","<<ui->txtTPSFull->text()<<endl;
    filestream.flush();

    filewrite<<ui->txtBaseMs->text()<<","<<ui->txtOpenMs->text()<<endl;
    filestream.flush();

    int i;

    for(i=0;i<cdata;i++){
        filewrite<<ui->tblInj->item(i,0)->text()<<",";
        filewrite<<ui->tblInj->item(i,1)->text()<<",";
        filewrite<<ui->tblInj->item(i,2)->text()<<",";
        filewrite<<ui->tblInj->item(i,3)->text()<<",";
        filewrite<<ui->tblInj->item(i,4)->text()<<",";
        filewrite<<ui->tblInj->item(i,5)->text()<<",";
        filewrite<<ui->tblInj->item(i,6)->text()<<",";
        filewrite<<ui->tblInj->item(i,7)->text()<<",";
        filewrite<<ui->tblInj->item(i,8)->text()<<",";
        filewrite<<ui->tblInj->item(i,9)->text()<<",";
        filewrite<<ui->tblInj->item(i,10)->text()<<",";
        filewrite<<ui->tblInj->item(i,11)->text()<<endl;
        filestream.flush();
    }

    for(i=0;i<cdata;i++){
        filewrite<<ui->tblIgn->item(i,0)->text()<<",";
        filewrite<<ui->tblIgn->item(i,1)->text()<<",";
        filewrite<<ui->tblIgn->item(i,2)->text()<<",";
        filewrite<<ui->tblIgn->item(i,3)->text()<<",";
        filewrite<<ui->tblIgn->item(i,4)->text()<<",";
        filewrite<<ui->tblIgn->item(i,5)->text()<<",";
        filewrite<<ui->tblIgn->item(i,6)->text()<<",";
        filewrite<<ui->tblIgn->item(i,7)->text()<<",";
        filewrite<<ui->tblIgn->item(i,8)->text()<<",";
        filewrite<<ui->tblIgn->item(i,9)->text()<<",";
        filewrite<<ui->tblIgn->item(i,10)->text()<<",";
        filewrite<<ui->tblIgn->item(i,11)->text()<<endl;
        filestream.flush();
    }

    filestream.close();
}

void interface::on_actionLoad_triggered()
{
    QString filename;
    QString fileopen=QFileDialog::getOpenFileName(this,"load data","","Gea Tuning data (*.gea)");
    if(fileopen.isEmpty()){return;}
    filename=fileopen;

    QFile filestream(filename);

    if(!filestream.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::critical(this,"Failed","File failed to open");
        return;
    }

    QTextStream fileread(&filestream);
    ui->txtCommData->clear();

    while(!fileread.atEnd()){
        QString received=fileread.readAll();
        ui->txtCommData->insertPlainText(received);
    }

    filestream.flush();
    filestream.close();

    QStringList datalines = ui->txtCommData->toPlainText().split("\n");

    QString tpsline= datalines[0];
    QStringList lsttpsline = tpsline.split(",");
    ui->txtTPSOff->setText(lsttpsline[0]);
    ui->txtTPSFull->setText(lsttpsline[1]);

    QString injecline = datalines[1];
    QStringList lstinjecline = injecline.split(",");
    ui->txtBaseMs->setText(lstinjecline[0]);
    ui->txtOpenMs->setText(lstinjecline[1]);

    int i,j;

    for(i=0;i<cdata;i++){
        QString injline = datalines[2+i];
        QStringList lstinjline = injline.split(",");
        for(j=0;j<cdata;j++){
            QTableWidgetItem* tbl_item = new QTableWidgetItem();
            tbl_item->setText(lstinjline[j]);
            ui->tblInj->setItem(i,j,tbl_item);
        }
    }

    for(i=0;i<cdata;i++){
        QString ignline = datalines[14+i];
        QStringList lstignline = ignline.split(",");
        for(j=0;j<cdata;j++){
            QTableWidgetItem* tbl_item = new QTableWidgetItem();
            tbl_item->setText(lstignline[j]);
            ui->tblIgn->setItem(i,j,tbl_item);
        }
    }

    ui->txtCommData->clear();
}
