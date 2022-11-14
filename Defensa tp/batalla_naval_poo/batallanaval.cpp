#include "batallanaval.h"
#include <stdio.h>
#include <ctime>
#include <stdlib.h>

bool batallaNaval::getVsIA() const
{
    return vsIA;
}

void batallaNaval::setVsIA(bool newVsIA)
{
    vsIA = newVsIA;
}

int batallaNaval::getGanador() const
{
    return ganador;
}

void batallaNaval::inicializarMapa(int filas, int columnas)
{
    this->filas = filas;
    this->columnas = columnas;

    this->jugador1.numeroJugador = 1;
    this->jugador1.radar.inicializarTablero(filas, columnas);
    this->jugador1.oceano.inicializarTablero(filas, columnas);

    this->jugador2.numeroJugador = 2;
    this->jugador2.radar.inicializarTablero(filas, columnas);
    this->jugador2.oceano.inicializarTablero(filas, columnas);
}

char batallaNaval::getPosMapa(int i, int j, int jugador, char mapa)
{
    if(jugador == 1){
        if(mapa == 'R'){
            return this->jugador1.radar.getPosTablero(i,j);
        }else{
            return this->jugador1.oceano.getPosTablero(i,j);
        }
    }
    if(jugador == 2){
        if(mapa == 'R'){
            return this->jugador2.radar.getPosTablero(i,j);
        }else{
            return this->jugador2.oceano.getPosTablero(i,j);
        }
    }

    return '-';
}

void batallaNaval::definirCantBarcos(int port, int dest, int subm, int cruc, int lanc)
{
    this->cantBarcos[0] = port; this->cantBarcosTotal += port;
    this->cantBarcos[1] = dest; this->cantBarcosTotal += dest;
    this->cantBarcos[2] = subm; this->cantBarcosTotal += subm;
    this->cantBarcos[3] = cruc; this->cantBarcosTotal += cruc;
    this->cantBarcos[4] = lanc; this->cantBarcosTotal += lanc;


    this->cantBarcos2[0] = port;
    this->cantBarcos2[1] = dest;
    this->cantBarcos2[2] = subm;
    this->cantBarcos2[3] = cruc;
    this->cantBarcos2[4] = lanc;
}

bool batallaNaval::verificarPosicion(int tipo, int x, int y, char orie, int jugador)
{
    if(jugador == 1){
        if(this->jugador1.oceano.verificarPos(tipo, x, y, orie)){
            return true;
        }else{
            return false;
        }
    }else if(jugador == 2){
        if(this->jugador2.oceano.verificarPos(tipo, x, y, orie)){
            return true;
        }else{
            return false;
        }
    }
    return false;
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
            yr = rand()% this->filas;
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

void batallaNaval::colocarBarco(int tipo, int x, int y, char orientacion, int jugador)
{
    if(jugador == 1){
        this->jugador1.oceano.colocarBarco(tipo, x, y, orientacion);
    }else{
        this->jugador2.oceano.colocarBarco(tipo, x, y, orientacion);
    }
}

void batallaNaval::moverLanchas(int jugador)
{
    if(jugador == 1){
        this->jugador1.oceano.moverLanchas();
    }else if(jugador == 2){
        this->jugador2.oceano.moverLanchas();
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
    if(this->jugador1.oceano.contarBarcosHundidos() >= this->cantBarcosTotal){
        this->ganador = 2;
        return true;
    }else if(this->jugador2.oceano.contarBarcosHundidos() >= this->cantBarcosTotal){
        this->ganador = 1;
        return true;
    }
    return false;
}
