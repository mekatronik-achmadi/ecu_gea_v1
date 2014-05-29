#include "qtinterface.h"
#include "ui_qtinterface.h"

qtinterface::qtinterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qtinterface)
{
    ui->setupUi(this);
}

qtinterface::~qtinterface()
{
    delete ui;
}

void qtinterface::on_actionAboutQt_triggered()
{
    QApplication::aboutQt();
}

void qtinterface::on_btnOpen_clicked()
{
    ui->txtInfo->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
//         qDebug() << "Name        : " << info.portName();
//         qDebug() << "Description : " << info.description();
//         qDebug() << "Manufacturer: " << info.manufacturer();

//         // Example use QSerialPort
//         QSerialPort serial;
//         serial.setPort(info);
//         if (serial.open(QIODevice::ReadWrite))
//             serial.close();
        ui->txtInfo->appendPlainText("Name        : " + info.portName() + "\r\n");
        ui->txtInfo->appendPlainText("Description : " + info.description() + "\r\n");
        ui->txtInfo->appendPlainText("Manufacturer: " + info.manufacturer() + "\r\n");
     }
}
