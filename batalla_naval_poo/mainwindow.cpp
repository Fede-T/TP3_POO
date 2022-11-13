#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QString>
#include <qDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->showMaximized();
    this->inicializarMessageBox();
    config settings;
    this->seleccionCarga.exec();
    int respuesta = this->seleccionCarga.buttonRole(this->seleccionCarga.clickedButton());
    if(respuesta == QMessageBox::NoRole){
        settings = this->cargarConfiguraciones();
        this->inicializarJuego(settings);
    }else if(respuesta == QMessageBox::YesRole){
        Dialog* dialogo = new Dialog(this);
        dialogo->show();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

config MainWindow::cargarConfiguraciones()
{
    qDebug() << "carga de configs";
    config sin_datos = {true , -1, -1, -1, -1, -1, -1};
    return sin_datos;
}

void MainWindow::taparMapas()
{
    int n = this->juego.getN();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            this->mapaRadar[i][j]->setStyleSheet(this->buscarSprite('-'));
            this->mapaOceano[i][j]->setStyleSheet(this->buscarSprite('-'));
        }
    }
}

void MainWindow::inicializarJuego(config configuraciones)
{
    if(configuraciones.n < 0){
        qDebug() << "configuraciones no funcionan, ver inicializar juego";
        QTimer::singleShot(250, qApp, SLOT(quit()));
    }

    this->inicializarSprites();
    this->iniciarMapas(configuraciones.n);
    this->juego.inicializarMapa(configuraciones.n, configuraciones.n);
    this->juego.definirCantBarcos(configuraciones.cantp, configuraciones.cantd, configuraciones.cants, configuraciones.cantc, configuraciones.cantl);

    this->ui->turno->setText(QString::number(this->jug));
    for(int i = 0; i < 5; i++){
        if(this->juego.cantBarcos[i] != 0){
            switch (i){
            case 0:
                this->ui->instruccionesLabel->setText("Ingrese la posicion de un portaaviones.");
                break;
            case 1:
                this->ui->instruccionesLabel->setText("Ingrese la posicion de un destructor.");
                break;
            case 2:
                this->ui->instruccionesLabel->setText("Ingrese la posicion de un submarino.");
                break;
            case 3:
                this->ui->instruccionesLabel->setText("Ingrese la posicion de un crucero.");
                break;
            case 4:
                this->ui->instruccionesLabel->setText("Ingrese la posicion de un lancha.");
                break;
            default:
                this->ui->instruccionesLabel->setText("Ingrese un ...");
            }
            break;
        }
    }

}

void MainWindow::setGuia(int jugador, char mapa)
{
    int n = this->juego.getN();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mapa == 'R'){
                this->guiaRadar[i][j] = this->juego.getPosMapa(i, j, jugador, mapa);
            }else{
                this->guiaOceano[i][j] = this->juego.getPosMapa(i, j, jugador, mapa);
            }
            qDebug() << guiaOceano[i][j];
        }
        qDebug() << "\n";
    }

}

void MainWindow::actualizarSprites(char mapa)
{
    QString nombre;

    int n = this->juego.getN();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mapa == 'R'){

                nombre = this->buscarSprite(this->getPosGuia(i, j, 'R'));
                this->mapaRadar[i][j]->setStyleSheet(nombre);
            }else if(mapa == 'O'){
                nombre = this->buscarSprite(this->getPosGuia(i, j, 'O'));
                this->mapaOceano[i][j]->setStyleSheet(nombre);
            }
        }
    }
}

char MainWindow::getPosGuia(int i, int j, char tipo)
{
    if(tipo == 'R'){
        return this->guiaRadar[i][j];
    }
    else{
        return this->guiaOceano[i][j];
    }
}

void MainWindow::inicializarMessageBox()
{
    this->seleccionCarga.setWindowTitle("Nueva partida");
    this->seleccionCarga.setText("¿Quiere comenzar una nueva partida\no continuar si existiera una?");
    this->seleccionCarga.addButton("Nueva partida", QMessageBox::YesRole);
    this->seleccionCarga.addButton("Cargar partida", QMessageBox::NoRole);
    this->seleccionCarga.setIcon(QMessageBox::NoIcon);

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

    this->ErrorColocacion.setWindowTitle("Coordenadas incorrectas...");
    this->ErrorColocacion.setText("Coordenadas incorrectas,\nreingrese las coordenadas del barco");
    this->ErrorColocacion.addButton(QMessageBox::Ok);
    this->ErrorColocacion.setIcon(QMessageBox::NoIcon);
}

void MainWindow::iniciarMapas(int cant)
{
    this->mapaRadar = new QPushButton**[cant];
    this->mapaOceano = new QPushButton**[cant];
    this->guiaRadar = new char*[cant];
    this->guiaOceano = new char*[cant];
    for(int i = 0; i < cant; i++){
        this->mapaRadar[i] = new QPushButton*[cant];
        this->mapaOceano[i] = new QPushButton*[cant];
        this->guiaRadar[i] = new char[cant];
        this->guiaOceano[i] = new char[cant];
        for(int j = 0; j < cant; j++){
            this->guiaRadar[i][j] = '-';
            this->guiaOceano[i][j] = '-';
            this->mapaRadar[i][j] = new QPushButton();
            this->mapaRadar[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
            this->mapaOceano[i][j] = new QPushButton();
            this->mapaOceano[i][j]->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

            this->mapaRadar[i][j]->setStyleSheet(this->buscarSprite('-'));
            this->mapaOceano[i][j]->setStyleSheet(this->buscarSprite('-'));
            this->ui->radarVisual->addWidget(this->mapaRadar[i][j], i, j);
            this->ui->oceanoVisual->addWidget(this->mapaOceano[i][j], i, j);
        }
    }
}

void MainWindow::inicializarSprites()
{
    QString nombre;
    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('-');
    nombre += "agua_calma.jpg";
    nombre += ");";
    this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('A');
    nombre += "agua_disparada.jpg";
    nombre += ");";
    this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('B');
    nombre += "barco_horizontal_medio.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('b');
    nombre += "barco_vertical_medio.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('C');
    nombre += "barco_horizontal_cola.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('F');
    nombre += "barco_horizontal_frente.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('U');
    nombre += "barco_vertical_frente.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('D');
    nombre += "barco_vertical_cola.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('X');
    nombre += "barco_horizontal_medio_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('x');
    nombre += "barco_vertical_medio_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('c');
    nombre += "barco_horizontal_cola_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('f');
    nombre += "barco_horizontal_frente_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('u');
    nombre += "barco_vertical_frente_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('d');
    nombre += "barco_vertical_cola_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('L');
    nombre += "lancha_horizontal.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('l');
    nombre += "lancha_vertical.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('G');
    nombre += "lancha_horizontal_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('g');
    nombre += "lancha_vertical_golpe.jpg";
    nombre += ");";
        this->nombreSprites.push_back(nombre);

    nombre ="border-image:url(:/sprites/";
    this->charSprites.push_back('h');
    nombre += "equis.jpg";
    nombre += ");";
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

void MainWindow::on_btnColocar_clicked()
{

}


void MainWindow::on_btnTerminarTurno_clicked()
{
    if(this->juego.getVsIA()){

    }else{
        this->taparMapas();
        this->ui->btnTerminarTurno->setEnabled(false);
        this->cambioTurno.exec();
        this->cambiarJugador();
        this->ui->turno->setText(QString::number(this->jug));
    }
}


void MainWindow::on_btnRandom_clicked()
{
    this->ui->btnRandom->setEnabled(false);
    for(int i = 0; i < 5; i++){
        this->juego.colocarAleatorioporTipo(i, this->juego.cantBarcos[i], this->jug);
        this->setGuia(this->jug, 'O');
        this->actualizarSprites('O');
    }
    this->ui->btnTerminarTurno->setEnabled(true);
}

