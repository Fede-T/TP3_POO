#ifndef BATALLANAVAL_H
#define BATALLANAVAL_H
#include "tablero.h"

struct jugadorBase{
    int numeroJugador;
    tablero radar;
    tablero oceano;
};

struct config{
    bool vsIA;
    int n;
    int cantp;
    int cantd;
    int cantc;
    int cants;
    int cantl;
};

class batallaNaval
{
private:
    int filas;
    int columnas;
    bool vsIA;
    jugadorBase jugador1;
    jugadorBase jugador2;

    int ganador = 0;

public:
    int cantBarcos[5]={0,0,0,0,0};
    int cantBarcosTotal = 0;

public:
    batallaNaval(){};
    int getN(){return this->filas;}
    void inicializarMapa(int filas, int columnas);
    char getPosMapa(int i, int j, int jugador, char mapa);
    void definirCantBarcos(int port, int dest, int subm, int cruc, int lanc);
    bool verificarPosicion(int tipo, int x, int y, char orie, int jugador);
    bool colocarAleatorioporTipo(int tipo, int cant, int jugador);
    void mostrarTablero(int jugador);
    void colocarBarco(int tipo, int x, int y, char orientacion, int jugador);
    void moverLanchas(int jugador);
    void iaDispara(int jugadorDisparo);
    bool realizarDisparo(int x, int y, int jugador);
    bool verificarGanador();
    int getCantBarcosTotal() const;
    void setCantBarcosTotal(int newCantBarcosTotal);
    bool getVsIA() const;
    void setVsIA(bool newVsIA);
};

#endif // BATALLANAVAL_H
