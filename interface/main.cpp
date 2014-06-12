#include "interface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface w;
    w.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    w.show();

    return a.exec();
}
