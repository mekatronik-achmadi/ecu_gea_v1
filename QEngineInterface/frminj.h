#ifndef FRMINJ_H
#define FRMINJ_H

#include <QWidget>
#include "gea.h"

namespace Ui {
class frminj;
}

class frminj : public QWidget
{
    Q_OBJECT

public:
    explicit frminj(QWidget *parent = 0);
    ~frminj();

private slots:
    void setDisplay(void);

private:
    Ui::frminj *ui;
    QTimer timer;
};

#endif // FRMINJ_H
