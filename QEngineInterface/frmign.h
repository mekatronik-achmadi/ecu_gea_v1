#ifndef FRMIGN_H
#define FRMIGN_H

#include <QWidget>

namespace Ui {
class frmign;
}

class frmign : public QWidget
{
    Q_OBJECT

public:
    explicit frmign(QWidget *parent = 0);
    ~frmign();

private:
    Ui::frmign *ui;
};

#endif // FRMIGN_H
