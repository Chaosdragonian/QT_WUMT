#include "mymodel.h"
#include "checkupdate.h"
//#include <qstandarditemmodel.h>
MyModel::MyModel(QObject *parent) :QAbstractTableModel
{

}

int MyModel::rowCount(const QModelIndex &/*parent*/) const
{
	checkupdate check;
	int row = check.historyNum();
	return row;
}
int MyModel::columnCount(const QModelIndex &/*parent*/) const
{
	return 2;
}

int MyModel::parent(const QModelIndex &child) const
{
	return
}
QVariant MyModel::data(const QModelIndex &index, int role) const
{

	int row = index.row();
	int col = index.column();
	checkupdate check;
	QStringList datalist = check.history();
	qDebug()<<QString("row %1, col%2, role%3")
			  .arg(row).arg(col).arg(role);
	switch(role){
	case Qt::DisplayRole:
		for(int i =0; i < row; i+=2){
			qDebug()<<QString(datalist[i],datalist[i+1])<<endl;
			return QString(datalist[i],datalist[i+1]);
		}
		break;
	}

	return QVariant();
}
