#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <QString>
#include <QMessageBox>
#include "dialog.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    config cargarConfiguraciones();
    void inicializarJuego(config configuraciones);
    void setGuia(int jugador, char mapa /*R o O*/);
    void actualizarSprites(char mapa);
    char getPosGuia(int i, int j, char tipo);
    void inicializarMessageBox();
    void iniciarMapas(int cant);
    void inicializarSprites();
    QString buscarSprite(char c);

private slots:
    void on_btnColocar_clicked();

private:
    int indexTipo = 0;
    int jug = 1;
    int cantBarcosColocados = 0;
    batallaNaval juego;
    QMessageBox seleccionCarga;
    QMessageBox comienzo;
    QMessageBox cambioTurno;
    QMessageBox Ganador;
    QMessageBox ErrorColocacion;

    vector <char> charSprites;
    vector <QString> nombreSprites;

    char** guiaRadar;
    char** guiaOceano;

    QPushButton*** mapaRadar;
    QPushButton*** mapaOceano;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H