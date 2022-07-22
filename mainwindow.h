#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @file mainwindow.h
 * @authors Quelita Míriam e Rosélia Nascimento
 * @since 07/2022
 * @brief Classe Main Window
 */

#include "sculptor.h"
#include <QMainWindow>
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    Sculptor *escultor;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    /**
     * @brief Botão Cubo: Essa função interliga o botão cubo com os sliders definidos no grupBox: Cubo
     */
    void botaoCubo();
    /**
     * @brief Botão ApagaCubo: Essa função interliga o botão para apagar o cubo com os sliders definidos no grupBox: Cubo
     */
    void botaoApagaCubo();
    /**
     * @brief Botão Esfera: Essa função interliga o botão esfera com os sliders definidos no grupBox: Esfera
     */
    void botaoEsfera();
    /**
     * @brief Botão ApagaEsfera: Essa função interliga o botão para apagar a esfera com os sliders definidos no grupBox: Esfera
     */
    void botaoApagaEsfera();
    /**
     * @brief Botão Elipse: Essa função interliga o botão elipse com os sliders definidos no grupBox: Elipse
     */
    void botaoElipse();
    /**
     * @brief Botão ApagaElipse: Essa função interliga o botão para apagar elipse com os sliders definidos no grupBox: Elipse
     */
    void botaoApagaElipse();

    /**
     * @brief Função para cor RED: Essa função trabalha com o sistema de cor RGB para o desenho.
     * Ela conecta os sliders e lcd's da cor Red com o widegt. Quando acionado pode ser combinado com as demais cores.
     * @param value_
     */
    void cor_R(int value_);
    /**
     * @brief Função para cor GREEN: Essa função trabalha com o sistema de cor RGB para o desenho.
     * Ela conecta os sliders e lcd's da cor Green com o widegt. Quando acionado pode ser combinado com as demais cores.
     * @param value_
     */
    void cor_G(int value_);
    /**
     * @brief Função para cor BLUE: Essa função trabalha com o sistema de cor RGB para o desenho.
     * Ela conecta os sliders e lcd's da cor Blue com o widegt. Quando acionado pode ser combinado com as demais cores.
     * @param value_
     */
    void cor_B(int value_);
    /**
     * @brief Função para transparência: Essa função trabalha com a transparência das cores do desenho.
     * Quando acionado insere as cores no desenho com transparência 1.
     */
    void alpha();
    /**
     * @brief Função para retirar a transparência: Essa função trabalha com a transparência das cores do desenho.
     * Quando acionado retira as cores no desenho com transparência 1.
     */
    void noAlpha();

    /**
     * @brief Função que recebe dimensão x do Cubo.
     * @param value_
     */
    void dimx_cubo(int value_);
    /**
     * @brief Função que recebe dimensão y do Cubo.
     * @param value_
     */
    void dimy_cubo(int value_);
    /**
     * @brief Função que recebe dimensão z do Cubo.
     * @param value_
     */
    void dimz_cubo(int value_);
    /**
     * @brief Função que recebe raio da esfera.
     * @param value_
     */
    void r_esfera(int value_);
    /**
     * @brief Função que recebe raio para o eixo x de uma Elipse.
     * @param value_
     */
    void rx_elipse(int value_);
    /**
     * @brief Função que recebe raio para o eixo y de uma Elipse.
     * @param value_
     */
    void ry_elipse(int value_);
    /**
     * @brief Função que recebe raio para o eixo z de uma Elipse.
     * @param value_
     */
    void rz_elipse(int value_);
    /**
     * @brief Função que percorre o eixo x, ou seja, mostra a visão a partir de outros planos.
     * @param value_
     */
    void plano_Z(int value_);

private:
    Ui::MainWindow *ui;

signals:
    /**
     * @brief Sinal que faz uma ligação entre funções para envia o desenho.
     * @param *sculptor
     */
    void enviaDesenho(Sculptor *escultor);
};
#endif // MAINWINDOW_H
