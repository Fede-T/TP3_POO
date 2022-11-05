#ifndef BATALLANAVAL_H
#define BATALLANAVAL_H
#include "tablero.h"

struct jugadorBase{
    bool ia;
    tablero radar;
    tablero oceano;
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

public:
    batallaNaval(int filas, int columnas, bool j1_es_ia, bool j2_es_ia);
    void definirCantBarcos(int port, int dest, int subm, int cruc, int lanc);

};

#endif // BATALLANAVAL_H
