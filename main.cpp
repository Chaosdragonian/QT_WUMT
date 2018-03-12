#include "mainwindow.h"
#include <QApplication>
#ifdef WIN32
#include <qt_windows.h>
#include <qapplication.h>
#include <qtableview.h>
#include "mymodel.h"

#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	QTableView v;
	MyModel myModel(0);
	v.setModel(&myModel);
	v.show();
    return a.exec();
}
