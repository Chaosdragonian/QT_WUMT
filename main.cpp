#include "mainwindow.h"
#include <QApplication>
#ifdef WIN32
#include <qt_windows.h>
#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
