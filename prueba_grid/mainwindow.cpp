#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int f = 5;
    int c = 6;

    this->mapa = new QPushButton**[f];
    for(int i = 0; i < f; i++){
        this->mapa[i] = new QPushButton*[c];
        for(int j = 0; j < c; j++){
            this->mapa[i][j] = new QPushButton();
            this->mapa[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            this->ui->prueba->addWidget(this->mapa[i][j], i, j);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

