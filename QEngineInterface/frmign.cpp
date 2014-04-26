#include "frmign.h"
#include "ui_frmign.h"

frmign::frmign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmign)
{
    ui->setupUi(this);
}

frmign::~frmign()
{
    delete ui;
}
