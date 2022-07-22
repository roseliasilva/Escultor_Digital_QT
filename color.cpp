#include "color.h"
#include <QPainter>
#include <QBrush>
#include <stdio.h>

Color::Color(QWidget *parent) : QWidget{parent}{

}

void Color::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(r, g, b));

    painter.setBrush(brush);
    painter.drawRect(0,0, width(), height());
}

void Color::setRValue(int r_){
    this->r = r_;
    repaint();
}

void Color::setGValue(int g_){
    this->g = g_;
    repaint();
}

void Color::setBValue(int b_){
    this->b = b_;
    repaint();
}
