#include "qtinterface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtinterface w;
    w.show();

    return a.exec();
}
