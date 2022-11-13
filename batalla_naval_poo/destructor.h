#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

#include "barco.h"

class destructor : public barco
{
public:
    destructor();
    destructor(int x, int y, char orientacion, int tamanio);
    bool registrarHit(int x, int y);
    void actualizarEstado();
    int getTipo() {return 1;}
    ~destructor();
};

#endif // DESTRUCTOR_H
