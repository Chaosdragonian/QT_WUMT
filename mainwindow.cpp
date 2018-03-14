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


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	
	ui->pushButton->setEnabled(false);

}

void MainWindow::on_pushButton_2_clicked()
{
	checkupdate check;
	int i = check.historyNum();
	ui->TableWidget->setRowCount(i);
	ui->TableWidget->setColumnCount(2);
	check.history(ui->TableWidget);
	ui->TableWidget->setVisible(true);
	ui->pushButton_2->setEnabled(false);
}
