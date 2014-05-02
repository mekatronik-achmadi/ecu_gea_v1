#ifndef FRMIGN_H
#define FRMIGN_H

#include <QWidget>
#include "gea.h"

namespace Ui {
class frmign;
}

class frmign : public QWidget
{
    Q_OBJECT

public:
    explicit frmign(QWidget *parent = 0);
    ~frmign();

private slots:
    void setDisplay(void);

private:
    Ui::frmign *ui;
    QTimer timer;
};

#endif // FRMIGN_H
