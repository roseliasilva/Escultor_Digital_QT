#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent):

    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    escultor = new Sculptor(50,50,50);
    emit enviaDesenho(escultor);

    // Conexões sliders e lcd's das cores
    connect(ui->Slider_R,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(cor_R(int)));
    connect(ui->Slider_G,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(cor_G(int)));
    connect(ui->Slider_B,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(cor_B(int)));

    // Conexões sliders e lcd´s do cubo
    connect(ui->Slider_X,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(dimx_cubo(int)));
    connect(ui->Slider_Y,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(dimy_cubo(int)));
    connect(ui->Slider_Z,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(dimz_cubo(int)));

    // Conexões slider e lcd da esfera
    connect(ui->Slider_R_2,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(r_esfera(int)));

    // Conexões sliders e lcd's da elipse
    connect(ui->Slider_rx,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(rx_elipse(int)));
    connect(ui->Slider_ry,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(ry_elipse(int)));
    connect(ui->Slider_rz,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(rz_elipse(int)));

    // Conexão slider e lcd do plano Z
    connect(ui->Slider_planoZ,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(plano_Z(int)));

    // Conexão Slider's e botões
    connect(ui->cubo,
            SIGNAL(clicked(bool)),
            this,
            SLOT(alpha()));
    connect(ui->apagarcubo,
            SIGNAL(clicked(bool)),
            this,
            SLOT(noAlpha()));
    connect(ui->esfera,
            SIGNAL(clicked(bool)),
            this,
            SLOT(alpha()));
    connect(ui->apagaresfera,
            SIGNAL(clicked(bool)),
            this,
            SLOT(noAlpha()));
    connect(ui->elipse,
            SIGNAL(clicked(bool)),
            this,
            SLOT(alpha()));
    connect(ui->apagarelipse,
            SIGNAL(clicked(bool)),
            this,
            SLOT(noAlpha()));

}

MainWindow::~MainWindow(){
    escultor -> writeOFF("desenho.off");
    delete ui;
}

void MainWindow::botaoCubo(){
    // interligar o botão com os sliders definidos no grupBox: Cubo
}

void MainWindow::botaoApagaCubo(){
    //cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
}

void MainWindow::botaoEsfera(){
    //putSphere(int xcenter, int ycenter, int zcenter, int radius);
}

void MainWindow::botaoApagaEsfera(){
    //cutSphere(int xcenter, int ycenter, int zcenter, int radius)
}

void MainWindow::botaoElipse(){
    //putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
}

void MainWindow::botaoApagaElipse(){
    //cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
}

void MainWindow::cor_R(int value_){
    ui -> lcd_R -> display(value_);
    ui -> widget -> setRValue(value_);
    ui -> widget_2 -> setRValue(value_);
    escultor -> Red(value_/255.0);
}

void MainWindow::cor_G(int value_){
    ui -> lcd_G -> display(value_);
    ui -> widget -> setGValue(value_);
    ui -> widget_2 -> setGValue(value_);
    escultor -> Green(value_/255.0);
}

void MainWindow::cor_B(int value_){
    ui -> lcd_B -> display(value_);
    ui -> widget -> setBValue(value_);
    ui -> widget_2 -> setBValue(value_);
    escultor -> Blue(value_/255.0);
}

void MainWindow::dimx_cubo(int value_){
    ui -> lcd_X -> display(value_);
}

void MainWindow::dimy_cubo(int value_){
    ui -> lcd_Y -> display(value_);
}

void MainWindow::dimz_cubo(int value_){
    ui -> lcd_Z -> display(value_);
}

void MainWindow::r_esfera(int value_){
    ui -> lcd_R_2 -> display(value_);
}

void MainWindow::rx_elipse(int value_){
    ui -> lcd_rx -> display(value_);
}

void MainWindow::ry_elipse(int value_){
    ui -> lcd_ry -> display(value_);
}

void MainWindow::rz_elipse(int value_){
    ui -> lcd_rz -> display(value_);
}

void MainWindow::plano_Z(int value_){
    ui -> lcd_planoZ-> display(value_);
}

void MainWindow::alpha(){
    escultor -> Alpha(true);
}

void MainWindow::noAlpha(){
    escultor -> Alpha(false);
}
