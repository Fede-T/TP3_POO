#include <iostream>
#include "batallanaval.h"
using namespace std;

int main()
{
    batallaNaval juego(10, 10, true, true);
    juego.colocarAleatorioporTipo(1, 2, 1);
    juego.mostrarTablero(1);
    //verificar que no se salga de los bordes
    return 0;
}
