#ifndef CHECKUPDATE_H
#define CHECKUPDATE_H
#include <QString>
#include <QObject>
#include <qtablewidget.h>



class checkupdate : public QObject
{

public:

	QStringList update();
	void history(QTableWidget*);
	//int updateNum();
	int historyNum();
};

#endif // CHECKUPDATE_H
