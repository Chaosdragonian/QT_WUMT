#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewwidget.h"
#include "checkupdate.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::MainWindow)
 //   m_MainView(new ViewWidget)
{

    ui->setupUi(this);
	//setCentralWidget(pushButton);
	//setCentralWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	checkupdate check;
	QString view = check.update();
	ui->label->setText(view);
	ui->pushButton->setEnabled(false);

}

void MainWindow::on_pushButton_2_clicked()
{
	checkupdate check;
	QString view = check.history();
	ui->label->setText(view);
	ui->pushButton_2->setEnabled(false);
}
