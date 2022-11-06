#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int cantidad = 5;
    this->labels = new QPushButton**[cantidad];
    this->labels2 = new QPushButton**[cantidad];
    for (int i = 0; i < cantidad; i++) {
        this->labels[i] = new QPushButton*[cantidad];
        this->labels2[i] = new QPushButton*[cantidad];
        for (int j = 0; j < cantidad; j++) {

            this->labels[i][j] = new QPushButton();
            this->labels[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            this->labels2[i][j] = new QPushButton();
            this->labels2[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            this->ui->radarVisual->addWidget(this->labels[i][j], i, j);
            this->ui->oceanoVisual->addWidget(this->labels2[i][j], i, j);

        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

