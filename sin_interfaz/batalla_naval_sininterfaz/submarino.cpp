#include "submarino.h"

submarino::submarino()
{

}

submarino::submarino(int x, int y, char orientacion, int tamanio):barco(x, y, orientacion, tamanio)
{

}

bool submarino::registrarHit(int x, int y)
{
    if(this->getOrientacion() == 'H'){
        if(y != this->getPosY()){
            return false;
        }
        else{
            for(int i = 0; i < this->getTamanio(); i++){
                if(x == this->getPosX()+i){
                    this->hits[i] = this->hits[i] = true;
                    this->actualizarEstado();
                    return true;
                }
            }
            return false;
        }
    }
    else{
        if(x != this->getPosX()){
            return false;
        }
        else{
            for(int i = 0; i < this->getTamanio(); i++){
                if(y == this->getPosY()+i){
                    this->hits[i] = this->hits[i] = true;
                    this->actualizarEstado();
                    return true;
                }
            }
            return false;
        }
    }
}

void submarino::actualizarEstado()
{
    if(this->hits[1] == true)
        this->setHundido(true);
}

submarino::~submarino()
{

}
