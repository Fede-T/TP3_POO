#include "tablero.h"

tablero::tablero(int filas, int columnas)
{
    this->filas = filas;
    this->columnas = columnas;
    this->mapa = new char*[filas];
    for(int i = 0; i < filas; i++){
        this->mapa[i] = new char[columnas];
    }
}
