#ifndef SUBMARINO_H
#define SUBMARINO_H

#include "barco.h"

class submarino : public barco
{
public:
    submarino();
    submarino(int x, int y, char orientacion, int tamanio);
    bool registrarHit(int x, int y);
    void verificar();
    void actualizarEstado();
    int getTipo() {return 2;}
    void moverse(char mov){};
    ~submarino();
};

#endif // SUBMARINO_H
