#include "viewwidget.h"
#include <QPainter>


ViewWidget::ViewWidget(QWidget *parent) : QWidget(parent)
{

}

void ViewWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    //set brush

  //  painter.setBrush(Qt::);

    painter.drawRect(this->rect());
    painter.end();

}
