#include "frminj.h"
#include "ui_frminj.h"

frminj::frminj(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frminj)
{
    ui->setupUi(this);
}

frminj::~frminj()
{
    delete ui;
}
