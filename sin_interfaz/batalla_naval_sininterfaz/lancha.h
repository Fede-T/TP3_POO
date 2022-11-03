#ifndef LANCHA_H
#define LANCHA_H

#include "barco.h"

class lancha : public barco
{
public:
    lancha();
    lancha(int x, int y, char orientacion, int tamanio);
    bool disparar(int x, int y);
    void moverse(char mov);
    void actualizarEstado();
    ~lancha();
};

#endif // LANCHA_H
