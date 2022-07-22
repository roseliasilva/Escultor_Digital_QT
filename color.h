#ifndef COLOR_H
#define COLOR_H

/**
 * @file color.h
 * @authors Quelita Míriam e Rosélia Nascimento
 * @since 07/2022
 * @brief Classe Color
 */

#include <QWidget>

class Color : public QWidget
{
    Q_OBJECT
public:
    int r=0, g=0, b=0;
    explicit Color(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void draw();

public slots:
    /**
     * @brief Função que altera os valores da cor RED.
     * @param r_
     */
    void setRValue(int r_);
    /**
     * @brief Função que altera os valores da cor GREEN.
     * @param g_
     */
    void setGValue(int g_);
    /**
     * @brief Função que altera os valores da cor BLUE.
     * @param b_
     */
    void setBValue(int b_);

signals:

};

#endif // COLOR_H
