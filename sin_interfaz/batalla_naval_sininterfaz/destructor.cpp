#include "destructor.h"

destructor::destructor()
{

}

destructor::destructor(int x, int y, char orientacion, int tamanio):barco(x, y, orientacion, tamanio)
{

}

bool destructor::disparar(int x, int y)
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

void destructor::actualizarEstado()
{
    bool a = true;
    for(int i = 0; i < this->getTamanio(); i++){
        if(this->hits[i] == false)
            a = false;
    }

    this->setHundido(a);
}

destructor::~destructor()
{

}
