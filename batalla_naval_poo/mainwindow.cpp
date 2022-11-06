#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QString>
#include <qDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Dialog* dialogo = new Dialog(this);
    this->inicializarSprites();
    this->iniciarMapas(10);
    this->inicializarMessageBox();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inicializarJuego()
{

}

void MainWindow::inicializarMessageBox()
{
    this->seleccionCarga.setWindowTitle("Nueva partida");
    this->seleccionCarga.setText("¿Quiere comenzar una nueva partida\no continuar si existiera una?");
    this->seleccionCarga.addButton("Nueva partida", QMessageBox::YesRole);
    this->seleccionCarga.addButton("Cargar partida", QMessageBox::NoRole);
    this->seleccionCarga.setIcon(QMessageBox::NoIcon);

    this->seleccionPvp.setWindowTitle("Seleccion jugadores");
    this->seleccionPvp.setText("¿Le gustaria jugar contra otro\njugador o contra la IA?");
    this->seleccionPvp.addButton("2 jugadores", QMessageBox::YesRole);
    this->seleccionPvp.addButton("vs IA", QMessageBox::NoRole);
    this->seleccionPvp.setIcon(QMessageBox::NoIcon);

    this->comienzo.setWindowTitle("Comenzar");
    this->comienzo.setText("Presione continuar para\ncomenzar la partida.");
    this->comienzo.addButton("Continuar", QMessageBox::AcceptRole);
    this->comienzo.setIcon(QMessageBox::NoIcon);

    this->comienzo.setWindowTitle("Comenzar");
    this->comienzo.setText("Presione continuar para\ncomenzar la partida.");
    this->comienzo.addButton("Continuar", QMessageBox::AcceptRole);
    this->comienzo.setIcon(QMessageBox::NoIcon);

    this->cambioTurno.setWindowTitle("Turno terminado");
    this->cambioTurno.setText("Tu turno terminó\nPresiona ok para comenzar el turno\ndel proximo jugador.");
    this->cambioTurno.addButton(QMessageBox::Ok);
    this->cambioTurno.setIcon(QMessageBox::NoIcon);

    this->Ganador.setWindowTitle("¡Tenemos un ganador!");
    this->Ganador.setText("El ganador es el jugador: ");
    this->Ganador.addButton(QMessageBox::Ok);
    this->Ganador.setIcon(QMessageBox::NoIcon);
}

void MainWindow::iniciarMapas(int cant)
{
    this->mapaRadar = new QPushButton**[cant];
    this->mapaOceano = new QPushButton**[cant];
    for(int i = 0; i < cant; i++){
        this->mapaRadar[i] = new QPushButton*[cant];
        this->mapaOceano[i] = new QPushButton*[cant];
        for(int j = 0; j < cant; j++){
            this->mapaRadar[i][j] = new QPushButton();
            this->mapaRadar[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            this->mapaOceano[i][j] = new QPushButton();
            this->mapaOceano[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            this->mapaRadar[i][j]->setStyleSheet("border-image:url(:/sprites/" + this->buscarSprite('-') + ");");
            this->mapaOceano[i][j]->setStyleSheet("border-image:url(:/sprites/" + this->buscarSprite('-') + ");");
            this->ui->radarVisual->addWidget(this->mapaRadar[i][j], i, j);
            this->ui->oceanoVisual->addWidget(this->mapaOceano[i][j], i, j);
        }
    }
}

void MainWindow::inicializarSprites()
{
    QString nombre;
    this->charSprites.push_back('-');
    nombre = "agua_calma.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('A');
    nombre = "agua_disparada.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('B');
    nombre = "barco_horizontal_medio";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('b');
    nombre = "barco_vertical_medio.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('C');
    nombre = "barco_horizontal_cola.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('F');
    nombre = "barco_horizontal_frente.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('U');
    nombre = "barco_vertical_frente.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('D');
    nombre = "barco_vertical_cola.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('X');
    nombre = "barco_horizontal_medio_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('x');
    nombre = "barco_vertical_medio_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('c');
    nombre = "barco_horizontal_cola_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('f');
    nombre = "barco_horizontal_frente_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('u');
    nombre = "barco_vertical_frente_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('d');
    nombre = "barco_vertical_cola_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('L');
    nombre = "lancha_horizontal.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('l');
    nombre = "lancha_vertical.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('G');
    nombre = "lancha_horizontal_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('g');
    nombre = "lancha_vertical_golpe.jpg";
    this->nombreSprites.push_back(nombre);

    this->charSprites.push_back('h');
    nombre = "equis.jpg";
    this->nombreSprites.push_back(nombre);
}

QString MainWindow::buscarSprite(char c)
{
    QString a;
    for(int i = 0; i < this->charSprites.size(); i++){
        if(this->charSprites[i] == c){
            a = this->nombreSprites[i];
            return a;
        }
    }
    return "";
}


