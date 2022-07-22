#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QMouseEvent>
#include <stdio.h>

Plotter::Plotter(QWidget *parent) : QWidget{parent}{
   clique = false;
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(1); //largura da caneta

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0,391,391);

    for(int i=0; i<391; i=i+10){
        for(int j=0; j<391; j=j+10){
            painter.drawRect(i, j, 10, 10);
        }
    }

    for(int x = 0; x<this->objs.size() ;x++){
        if(objs[x].z == this->z){
            pen.setColor(QColor(objs[x].r,objs[x].g,objs[x].b));
            brush.setColor(QColor(objs[x].r,objs[x].g,objs[x].b));
            brush.setStyle(Qt::SolidPattern);
            painter.setPen(pen);
            painter.setBrush(brush);
            painter.drawRect((float) objs[x].x*10+2.5,(float)objs[x].y*10+2.5,7,7);
            sculptor -> setColor(objs[x].r/255.0,objs[x].g/255.0,objs[x].b/255.0,1);
            sculptor -> putVoxel(objs[x].x,objs[x].y,objs[x].z);
        }
    }
}

void Plotter::mousePressEvent(QMouseEvent *ev){
    clique = true;
    if(ev->x() < 450 && ev->y() <450){
        draw(ev->x(),ev->y());
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *ev){
    clique = false;
}

void Plotter::mouseMoveEvent(QMouseEvent *ev){
    if((ev->x() < 450 && ev->y() <450 )&& clique){
        draw(ev->x(),ev->y());
    }
}

void Plotter::draw(int x, int y){
    Obj o;
    o.b = this->b;
    o.g = this->g;
    o.r = this->r;
    o.x = x/10;
    o.y = y/10;
    o.z = this->z;
    this -> objs.push_back(o);
    repaint();
}

void Plotter::setZValue(int z_){
    this -> z = z_;
    repaint();
}

void Plotter::setRValue(int r_){
    this -> r = r_;
}

void Plotter::setGValue(int g_){
    this -> g = g_;
}

void Plotter::setBValue(int b_){
    this -> b = b_;
}

void Plotter::recebeDesenho(Sculptor *sculptor){
    this -> sculptor = sculptor;
}
