#ifndef PORTAAVIONES_H
#define PORTAAVIONES_H

#include "barco.h"

class portaaviones : public barco
{
public:
    portaaviones();
    portaaviones(int x, int y, char orientacion, int tamanio);
    bool disparar(int x, int y);
    void actualizarEstado();
    ~portaaviones();
};

#endif // PORTAAVIONES_H
