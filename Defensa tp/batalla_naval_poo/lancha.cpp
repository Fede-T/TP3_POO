#include "lancha.h"

lancha::lancha()
{

}

lancha::lancha(int x, int y, char orientacion, int tamanio):barco(x, y, orientacion, tamanio)
{

}

bool lancha::registrarHit(int x, int y)
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

void lancha::moverse(char mov)
{
    switch (mov) {
    case 'U':
        this->setPosX(this->getPosX()-1);
        break;
    case 'D':
        this->setPosX(this->getPosX()+1);
        break;
    case 'L':
        this->setPosY(this->getPosY()-1);
        break;
    case 'R':
        this->setPosY(this->getPosY()+1);
        break;
    }
}

void lancha::actualizarEstado()
{
    if(this->hits[0] == true)
        this->setHundido(true);
}

lancha::~lancha()
{

}
