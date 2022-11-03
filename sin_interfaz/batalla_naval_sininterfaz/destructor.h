#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

#include "barco.h"

class destructor : public barco
{
public:
    destructor();
    destructor(int x, int y, char orientacion, int tamanio);
    bool disparar(int x, int y);
    void actualizarEstado();
    ~destructor();
};

#endif // DESTRUCTOR_H
