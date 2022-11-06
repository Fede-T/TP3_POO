#ifndef BATALLANAVAL_H
#define BATALLANAVAL_H
#include "tablero.h"

struct jugadorBase{
    int numeroJugador;
    bool ia;
    tablero radar;
    tablero oceano;
};

struct config{
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
    jugadorBase jugador1;
    jugadorBase jugador2;
    int cantBarcosTotal = 0;
    int cantBarcos[5]={0,0,0,0,0};
    int ganador = 0;

public:
    batallaNaval(int filas, int columnas, bool j1_es_ia, bool j2_es_ia);
    void definirCantBarcos(int port, int dest, int subm, int cruc, int lanc);
    bool colocarAleatorioporTipo(int tipo, int cant, int jugador);
    void mostrarTablero(int jugador);
    //void colocarBarco(int x, int y, char o);
    void iaDispara(int jugadorDisparo);
    bool realizarDisparo(int x, int y, int jugador);
    bool verificarGanador();
};

#endif // BATALLANAVAL_H
