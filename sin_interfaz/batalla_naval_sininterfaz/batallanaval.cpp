#include "batallanaval.h"

batallaNaval::batallaNaval(int filas, int columnas, bool j1_es_ia, bool j2_es_ia)
{
    this->filas = filas;
    this->columnas = columnas;

    this->jugador1.ia = j1_es_ia;
    this->jugador1.radar.inicializarTablero(filas, columnas);
    this->jugador1.oceano.inicializarTablero(filas, columnas);

    this->jugador2.ia = j2_es_ia;
    this->jugador2.radar.inicializarTablero(filas, columnas);
    this->jugador2.oceano.inicializarTablero(filas, columnas);
}

void batallaNaval::definirCantBarcos(int port, int dest, int subm, int cruc, int lanc)
{
    this->cantBarcos[0] = port; this->cantBarcosTotal += port;
    this->cantBarcos[1] = dest; this->cantBarcosTotal += dest;
    this->cantBarcos[2] = subm; this->cantBarcosTotal += subm;
    this->cantBarcos[3] = cruc; this->cantBarcosTotal += cruc;
    this->cantBarcos[4] = lanc; this->cantBarcosTotal += lanc;
}
