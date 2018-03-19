#include <QtWidgets>
#include <QHeaderView>
#include <qtableview.h>
#include <qtablewidget.h>
#include <qheaderview.h>
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
	checkupdate check;
	int i = check.updateNum();
	ui->TableWidget->setRowCount(i);
	ui->TableWidget->setColumnCount(2);
	ui->TableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Title"));
	ui->TableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Date"));
	ui->TableWidget->verticalHeader()->hide();
	check.update(ui->TableWidget);
	ui->TableWidget->setVisible(true);
	//ui->pushButton->setEnabled(false);

}

void MainWindow::on_pushButton_2_clicked()
{
	checkupdate check;
	int i = check.historyNum();
	ui->TableWidget->setRowCount(i);
	ui->TableWidget->setColumnCount(2);
	ui->TableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Title"));
	ui->TableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Date"));
	ui->TableWidget->verticalHeader()->hide();
	check.history(ui->TableWidget);
	ui->TableWidget->setVisible(true);
	//ui->pushButton_2->setEnabled(false);
}
