#include "frmign.h"
#include "ui_frmign.h"

extern int val_ignoffdeg;

frmign::frmign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmign)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(setDisplay()));
    timer.start(100);
}

frmign::~frmign()
{
    delete ui;
}

void frmign::setDisplay(){
    ui->lcdIgnOffDeg->display(QString::number(val_ignoffdeg));
}

