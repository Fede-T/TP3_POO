#ifndef SUBMARINO_H
#define SUBMARINO_H

#include "barco.h"

class submarino : public barco
{
public:
    submarino();
    submarino(int x, int y, char orientacion, int tamanio);
    bool disparar(int x, int y);
    void verificar();
    void actualizarEstado();
    ~submarino();
};

#endif // SUBMARINO_H
