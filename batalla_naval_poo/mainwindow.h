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
    void inicializarJuego();
    void inicializarMessageBox();
    void iniciarMapas(int cant);
    void inicializarSprites();
    QString buscarSprite(char c);

private:

    QMessageBox seleccionCarga;
    QMessageBox seleccionPvp;
    QMessageBox comienzo;
    QMessageBox cambioTurno;
    QMessageBox Ganador;
    //falta  dialog para settings

    vector <char> charSprites;
    vector <QString> nombreSprites;

    QPushButton*** mapaRadar;
    QPushButton*** mapaOceano;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
