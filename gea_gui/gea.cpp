#include "gea.h"
#include "ui_gea.h"

gea::gea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gea)
{
    ui->setupUi(this);
}

gea::~gea()
{
    delete ui;
}
