#include "frminj.h"
#include "ui_frminj.h"

extern int val_injdurdeg;
extern int val_injoffdeg;
extern float val_injvol;

frminj::frminj(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frminj)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(setDisplay()));
    timer.start(100);
}

frminj::~frminj()
{
    delete ui;
}

void frminj::setDisplay(){
    ui->lcdInjDurDeg->display(QString::number(val_injdurdeg));
    ui->lcdInjOffDeg->display(QString::number(val_injoffdeg));
}
