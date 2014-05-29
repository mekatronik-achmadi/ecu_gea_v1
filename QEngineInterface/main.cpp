#include "gea.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gea mygea;
    frmrpm myfrmrpm;
    frmtps myfrmtps;
    frmclk myfrmclk;
//    frmign myfrmign;
//    frminj myfrminj;

    mygea.setWindowTitle("Main App");
//    myfrmrpm.setWindowTitle("RPM");
//    myfrmtps.setWindowTitle("TPS");
//    myfrmclk.setWindowTitle("Clock");
//    myfrmign.setWindowTitle("Ignition");
//    myfrminj.setWindowTitle("Injection");    myfrmrpm.setWindowTitle("RPM");
//    myfrmtps.setWindowTitle("TPS");
//    myfrmclk.setWindowTitle("Clock");

    //http://qt-project.org/doc/qt-5/qt.html#WindowFlags-typedef

    Qt::WindowFlags winflag;

    winflag |= Qt::CustomizeWindowHint;
    winflag |= Qt::WindowTitleHint;

    mygea.setWindowFlags(winflag | Qt::Dialog);
//    myfrmrpm.setWindowFlags(winflag );
//    myfrmtps.setWindowFlags(winflag );
//    myfrmclk.setWindowFlags(winflag );
//    myfrmign.setWindowFlags(winflag );
//    myfrminj.setWindowFlags(winflag );

    mygea.show();
//    myfrmrpm.show();
//    myfrmtps.show();
//    myfrmclk.show();
//    myfrmign.show();
//    myfrminj.show();
    QHBoxLayout *mylayout=new QHBoxLayout;

    mylayout->addWidget(myfrmclk);
    mylayout->addWidget(myfrmtps);
    mylayout->addWidget(myfrmrpm);

    QWidget *mywin= new QWidget;
    mywin->setWindowTitle("Display");

    mywin->setLayout(mylayout);
    mywin->show();

    return a.exec();
}
