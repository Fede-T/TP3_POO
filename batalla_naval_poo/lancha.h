#ifndef LANCHA_H
#define LANCHA_H

#include "barco.h"

class lancha : public barco
{
public:
    lancha();
    lancha(int x, int y, char orientacion, int tamanio);
    bool registrarHit(int x, int y);
    void moverse(char mov);
    void actualizarEstado();
    int getTipo() {return 4;}
    ~lancha();
};

#endif // LANCHA_H
