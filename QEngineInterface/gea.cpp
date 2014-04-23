#include "gea.h"
#include "ui_gea.h"

gea::gea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gea)
{
    ui->setupUi(this);
    ui->tblTPS->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblTPS->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblTPS->setHorizontalHeaderItem(0,new QTableWidgetItem("0"));
    ui->tblTPS->setHorizontalHeaderItem(1,new QTableWidgetItem("250"));
    ui->tblTPS->setHorizontalHeaderItem(2,new QTableWidgetItem("500"));
    ui->tblTPS->setHorizontalHeaderItem(3,new QTableWidgetItem("750"));
    ui->tblTPS->setHorizontalHeaderItem(4,new QTableWidgetItem("1000"));
    ui->tblTPS->setHorizontalHeaderItem(5,new QTableWidgetItem("1250"));
    ui->tblTPS->setHorizontalHeaderItem(6,new QTableWidgetItem("1500"));
    ui->tblTPS->setVerticalHeaderItem(0,new QTableWidgetItem("dur"));
    ui->tblTPS->setVerticalHeaderItem(1,new QTableWidgetItem("off"));

}

gea::~gea()
{
    delete ui;
}
