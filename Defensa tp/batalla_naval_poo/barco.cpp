#include "barco.h"

const vector<bool> &barco::getHits() const
{
    return hits;
}

void barco::setHits(const vector<bool> &newHits)
{
    hits = newHits;
}

barco::barco()
{

}

barco::barco(int x, int y, char orientacion, int tam)
{
    posX = x;
    posY = y;
    this->orientacion = orientacion;
    this->tamanio = tam;
    for (int i = 0; i < this->tamanio; i++)
        this->hits.push_back(false);
}

barco::~barco()
{

}

int barco::getPosX() const
{
    return posX;
}

void barco::setPosX(int newPosX)
{
    posX = newPosX;
}

int barco::getPosY() const
{
    return posY;
}

void barco::setPosY(int newPosY)
{
    posY = newPosY;
}

char barco::getOrientacion() const
{
    return orientacion;
}

void barco::setOrientacion(char newOrientacion)
{
    orientacion = newOrientacion;
}

int barco::getTamanio() const
{
    return tamanio;
}

void barco::setTamanio(int newTamanio)
{
    tamanio = newTamanio;
}

bool barco::getHundido() const
{
    return hundido;
}

void barco::setHundido(bool newHundido)
{
    hundido = newHundido;
}
