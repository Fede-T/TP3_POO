#ifndef CRUCERO_H
#define CRUCERO_H

#include "barco.h"

class crucero : protected barco
{
public:
    crucero();
    crucero(int x, int y, char orientacion, int tamanio);
    bool registrarHit(int x, int y);
    void actualizarEstado();
    ~crucero();
};

#endif // CRUCERO_H
