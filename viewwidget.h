#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>

class ViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ViewWidget(QWidget *parent = nullptr);

signals:

public slots:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // VIEWWIDGET_H
