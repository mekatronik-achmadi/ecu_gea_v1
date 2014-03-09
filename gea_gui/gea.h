#ifndef GEA_H
#define GEA_H

#include <QMainWindow>

namespace Ui {
class gea;
}

class gea : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit gea(QWidget *parent = 0);
    ~gea();
    
private:
    Ui::gea *ui;
};

#endif // GEA_H
