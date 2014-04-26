#ifndef FRMINJ_H
#define FRMINJ_H

#include <QWidget>

namespace Ui {
class frminj;
}

class frminj : public QWidget
{
    Q_OBJECT

public:
    explicit frminj(QWidget *parent = 0);
    ~frminj();

private:
    Ui::frminj *ui;
};

#endif // FRMINJ_H
