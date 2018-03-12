#include <QtWidgets>
#include <QHeaderView>
#include <qtableview.h>
#include <qtablewidget.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkupdate.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)


{

	ui->setupUi(this);
}
	//   m_MainView(new ViewWidget)


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	checkupdate check;
	//QStringList view = check.update();
	ui->pushButton->setEnabled(false);

}

void MainWindow::on_pushButton_2_clicked()
{
	ui->pushButton_2->setEnabled(false);
}
