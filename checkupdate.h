#ifndef CHECKUPDATE_H
#define CHECKUPDATE_H
#include <QString>
#include <QObject>

class checkupdate : public QObject
{

public:

	QString update();
	QString history();


};

#endif // CHECKUPDATE_H
