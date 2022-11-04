#include <iostream>
#include "tablero.h"
using namespace std;

int main()
{
    tablero a(10,10);
    a.colocarBarco(0, 0, 0, 'H');
    a.colocarBarco(4, 0, 8, 'H');
    a.colocarBarco(1, 3, 1, 'H');
    a.colocarBarco(2, 2, 8, 'V');
    a.colocarBarco(3, 6, 1, 'H');
    a.colocarBarco(2, 7, 7, 'V');
    a.colocarBarco(4, 8, 2, 'H');
    a.escTablero();
    return 0;
}
