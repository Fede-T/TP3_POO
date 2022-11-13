#ifndef CRUCERO_H
#define CRUCERO_H

#include "barco.h"

class crucero : public barco
{
public:
    crucero();
    crucero(int x, int y, char orientacion, int tamanio);
    bool registrarHit(int x, int y);
    void actualizarEstado();
    int getTipo() {return 3;}
    void moverse(char mov){};
    ~crucero();
};

#endif // CRUCERO_H
