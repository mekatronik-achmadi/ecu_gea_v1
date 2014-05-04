#include "gea.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gea mygea;
    frmrpm myfrmrpm;
    frmtps myfrmtps;
//    frmclk myfrmclk;
    frmign myfrmign;
    frminj myfrminj;

    mygea.setWindowTitle("Main App");
    myfrmrpm.setWindowTitle("RPM");
    myfrmtps.setWindowTitle("TPS");
//    myfrmclk.setWindowTitle("Clock");
    myfrmign.setWindowTitle("Ignition");
    myfrminj.setWindowTitle("Injection");

    //http://qt-project.org/doc/qt-5/qt.html#WindowFlags-typedef

    Qt::WindowFlags winflag;

    winflag |= Qt::CustomizeWindowHint;
    winflag |= Qt::WindowTitleHint;

    mygea.setWindowFlags(winflag | Qt::Dialog);
    myfrmrpm.setWindowFlags(winflag );
    myfrmtps.setWindowFlags(winflag );
//    myfrmclk.setWindowFlags(winflag );
    myfrmign.setWindowFlags(winflag );
    myfrminj.setWindowFlags(winflag );

    mygea.show();
    myfrmrpm.show();
    myfrmign.show();
//    myfrmclk.show();
    myfrmtps.show();
    myfrminj.show();
    
    return a.exec();
}
