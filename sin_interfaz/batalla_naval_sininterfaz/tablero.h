#ifndef TABLERO_H
#define TABLERO_H


class tablero
{
private:
    char **mapa;
    int filas;
    int columnas;
public:
    tablero(int filas, int columnas);
};

#endif // TABLERO_H
