#include <iostream>
#include "batallanaval.h"
using namespace std;

int main()
{
    batallaNaval juego(10, 10, true, true);
    juego.colocarAleatorioporTipo(0, 2, 1);
    juego.colocarAleatorioporTipo(1, 2, 1);
    juego.colocarAleatorioporTipo(2, 2, 1);
    juego.colocarAleatorioporTipo(3, 2, 1);
    juego.colocarAleatorioporTipo(4, 2, 1);
    juego.mostrarTablero(1);

    return 0;
}
