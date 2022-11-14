#ifndef PORTAAVIONES_H
#define PORTAAVIONES_H

#include "barco.h"

class portaaviones : public barco
{
public:
    portaaviones();
    portaaviones(int x, int y, char orientacion, int tamanio);
    bool registrarHit(int x, int y);
    void actualizarEstado();
    int getTipo() {return 0;}
    void moverse(char mov){};
    ~portaaviones();
};

#endif // PORTAAVIONES_H
