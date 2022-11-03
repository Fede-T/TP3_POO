#include "tablero.h"
#include <iostream>
using namespace std;

tablero::tablero(int filas, int columnas)
{
    this->filas = filas;
    this->columnas = columnas;
    this->mapa = new char*[filas];
    for(int i = 0; i < filas; i++){
        this->mapa[i] = new char[columnas];
    }

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            this->mapa[i][j] = '-';
        }
    }
}

void tablero::actualizarRadar(int x, int y, bool golpe)
{
    if(golpe == true){
        this->mapa[x][y] = 'X';
    }else{
        this->mapa[x][y] = 'A';
    }
}

bool verificarLados(int x, int y,  char** map){
    bool a = true;
    if(map[x+1][y] != '-') a = false;   //verificamos arriba
    if(map[x-1][y] != '-') a = false;   //verificamos abajo
    if(map[x][y+1] != '-') a = false;   //verificamos derecha
    if(map[x][y-1] != '-') a = false;   //verificamos izquierda
    return a;
}

bool tablero::verificarPos(int tipo, int x, int y, char orie){
    int auxT;
    switch(tipo){
    case 0: auxT = 5; break;     //portaaviones
    case 1: auxT = 4; break;    //destructor
    case 4: auxT = 1; break;    //lancha
    default: auxT = 3; break;   //sub o crucero
    }

    bool verif = true;

    if(orie == 'H'){
        for(int i = 0; i < auxT; i++){
            if(this->mapa[x][y+i] == '-'){
                if(verificarLados(x, y, this->mapa) == false){
                    verif = false;
                }
            }
        }
    }else{
        for(int i = 0; i < auxT; i++){
            if(this->mapa[x+i][y] == '-'){
                if(verificarLados(x, y, this->mapa) == false){
                    verif = false;
                }
            }
        }
    }

    return verif;
}

void tablero::colocarBarco(int tipo, int x, int y, char orientacion)
{
    switch (tipo) {
    case 0:
        this->barcos.push_back(new portaaviones(x, y, orientacion, 5));
        break;
    case 1:
        this->barcos.push_back(new destructor(x, y, orientacion, 4));
        break;
    case 2:
        this->barcos.push_back((new submarino(x, y, orientacion, 3)));
        break;
    case 3:
        this->barcos.push_back(new crucero(x, y, orientacion, 3));
        break;
    case 4:
        this->barcos.push_back(new lancha(x, y, orientacion, 1));
        break;
    default:
        break;
    }
    this->cantBarcos[tipo]++;

    int tam = this->barcos[this->barcos.size()]->getTamanio();
    char o = this->barcos[this->barcos.size()]->getOrientacion();

    if(o == 'H'){
        for(int i = 0; i < tam; i++){
            this->mapa[x][y+i] = 'B';
        }
    }else{
        for(int i = 0; i < tam; i++){
            this->mapa[x+i][y] = 'B';
        }
    }

}

bool tablero::recibirDisparo(int x, int y)
{

}

void tablero::escTablero()
{
    for(int i = 0; i < this->filas; i++){
        for(int j = 0; j < this->columnas; j++){
            cout<<this->mapa[i][j];
        }
        cout<<endl;
    }
}

tablero::~tablero()
{

}
