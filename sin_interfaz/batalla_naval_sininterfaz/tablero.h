#ifndef TABLERO_H
#define TABLERO_H
#include <vector>
#include "barco.h"
#include "portaaviones.h"
#include "destructor.h"
#include "submarino.h"
#include "crucero.h"
#include "lancha.h"
using namespace std;

class tablero
{
private:
    char **mapa;
    int filas;
    int columnas;
protected:
    int cantBarcos[5]={0,0,0,0,0};
    vector <barco*> barcos;
public:
    tablero(int filas, int columnas);
    void actualizarRadar(int x, int y, bool golpe);
    bool verificarPos(int tipo, int x, int y, char orie);
    void colocarBarco(int tipo, int x, int y, char orientacion);
    bool recibirDisparo(int x, int y);
    void escTablero();
    ~tablero();
};

#endif // TABLERO_H
