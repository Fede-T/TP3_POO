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
    int barcosHundidos = 0;
protected:
    vector <barco*> barcos;
public:
    tablero();
    void inicializarTablero(int filas, int columnas);
    tablero(int filas, int columnas);
    void actualizarRadar(int x, int y, bool golpe);
    bool verificarPos(int tipo, int x, int y, char orie);
    void colocarBarco(int tipo, int x, int y, char orientacion);
    bool recibirDisparo(int x, int y);
    int contarBarcosHundidos();
    void moverLanchas();
    void escTablero();
    char getPosTablero(int i, int j){return this->mapa[i][j];}
    ~tablero();
    int getBarcosHundidos() const;
    void setBarcosHundidos(int newBarcosHundidos);
};

#endif // TABLERO_H
