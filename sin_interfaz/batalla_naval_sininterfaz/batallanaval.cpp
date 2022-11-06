#include "batallanaval.h"
#include <stdio.h>
#include <ctime>
#include <stdlib.h>

batallaNaval::batallaNaval(int filas, int columnas, bool j1_es_ia, bool j2_es_ia)
{
    this->filas = filas;
    this->columnas = columnas;

    this->jugador1.ia = j1_es_ia;
    this->jugador1.numeroJugador = 1;
    this->jugador1.radar.inicializarTablero(filas, columnas);
    this->jugador1.oceano.inicializarTablero(filas, columnas);

    this->jugador2.ia = j2_es_ia;
    this->jugador2.numeroJugador = 2;
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

bool batallaNaval::colocarAleatorioporTipo(int tipo, int cant, int jugador)
{
    srand(time(NULL));
    int xr, yr;
    char orand;
    bool a;

    for(int i = 0; i < cant; i++){
        a = false;
        while(a == false){
            xr = rand()% this->filas;
            yr = rand()% this->columnas;
            if((rand()% 2) == 0)
                orand = 'H';
            else
                orand = 'V';

            if(jugador == 1){
                if(this->jugador1.oceano.verificarPos(tipo, xr, yr, orand)){
                    this->jugador1.oceano.colocarBarco(tipo, xr, yr, orand);
                    a = true;
                }
            }else if(jugador == 2){
                if(this->jugador2.oceano.verificarPos(tipo, xr, yr, orand)){
                    this->jugador2.oceano.colocarBarco(tipo, xr, yr, orand);
                    a = true;
                }
            }
        }
    }
    return true;
}

void batallaNaval::mostrarTablero(int jugador)
{
    if(jugador == 1){
        this->jugador1.oceano.escTablero();
    }else{
        this->jugador2.oceano.escTablero();
    }
}

void batallaNaval::iaDispara(int jugadorDisparo)
{
    srand(time(NULL));
    int xr, yr;
    xr = rand()% this->filas;
    yr = rand()% this->columnas;
    this->realizarDisparo(xr, yr, jugadorDisparo);

}

bool batallaNaval::realizarDisparo(int x, int y, int jugador)
{
    bool golp = false;
    if(jugador == 1){
        golp = this->jugador2.oceano.recibirDisparo(x, y);
        this->jugador1.radar.actualizarRadar(x, y, golp);
    }else if(jugador == 2){
        golp = this->jugador1.oceano.recibirDisparo(x, y);
        this->jugador2.radar.actualizarRadar(x, y, golp);
    }

    return golp;
}

bool batallaNaval::verificarGanador()
{
    if(this->jugador1.oceano.getBarcosHundidos() >= this->cantBarcosTotal){
        this->ganador = 2;
        return true;
    }else if(this->jugador2.oceano.getBarcosHundidos() >= this->cantBarcosTotal){
        this->ganador = 1;
        return true;
    }
    return false;
}
