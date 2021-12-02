#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName( "Mecanica de Precison DyG srl" );
    QApplication::setOrganizationDomain( "mpdyg.com.ar" );
    QApplication::setApplicationName( "ModBusSniffer" );


    MainWindow w;
    w.show();
    return a.exec();
}
