#ifndef PLOTTER_H
#define PLOTTER_H

/**
 * @file plotter.h
 * @authors Quelita Míriam e Rosélia Nascimento
 * @since 07/2022
 * @brief Classe Plotter
 */

#include <QWidget>
#include "sculptor.h"

/**
  * @brief Struct que comporta as propriedades necessárias para permitir colorir o widget.
  */
struct Obj{
    int r, g, b, a;
    int x, y, z;
};

class Plotter : public QWidget{
    Q_OBJECT
public:
    std::vector<Obj> objs;
    Sculptor *sculptor;
    int r=0, g=0, b=0;
    int z=1;
    explicit Plotter(QWidget *parent = nullptr);

    /**
      * @brief Função do Qt Creator para pintar no widget.
      * @param *event, ponteiro para receber o evento.
      */
    void paintEvent(QPaintEvent *event);
    /**
      * @brief Função do Qt Creator para pressionar o mouse no widget.
      * @param *ev, ponteiro para receber o evento.
      */
    void mousePressEvent(QMouseEvent *ev);
    /**
      * @brief Função do Qt Creator para soltar o mouse e parar o click no widget.
      * @param *ev, ponteiro para receber o evento.
      */
    void mouseReleaseEvent(QMouseEvent *ev);
    /**
      * @brief Função do Qt Creator para mover o mouse no widget.
      * @param *ev, ponteiro para receber o evento.
      */
    void mouseMoveEvent(QMouseEvent *ev);
    /**
      * @brief Função para desenhar no widget.
      * @param x, y, posições do widget para aplicar as necessidades do voxel.
      */
    void draw(int x,int y);

public slots:
    /**
      * @brief Função para alterar o valor do plano z
      * @param z, valor do plano.
      */
    void setZValue(int z);
    /**
      * @brief Função para alterar o valor da cor RED.
      * @param r_, nova cor vermelha.
      */
    void setRValue(int r_);
    /**
      * @brief Função para alterar o valor da cor GREEN.
      * @param g_, nova cor verde.
      */
    void setGValue(int g_);
    /**
     * @brief Função para alterar o valor da cor BLUE.
     * @param b_, nova cor azul.
     */
    void setBValue(int b_);
    /**
     * @brief Função para receber o desenho do widget.
     * @param *sculptor
     */
    void recebeDesenho(Sculptor *sculptor);

private:
    bool clique;

};

#endif // PLOTTER_H
