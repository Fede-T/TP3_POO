#include "tablero.h"
#include <iostream>
using namespace std;

int tablero::getBarcosHundidos() const
{
    return barcosHundidos;
}

void tablero::setBarcosHundidos(int newBarcosHundidos)
{
    barcosHundidos = newBarcosHundidos;
}

tablero::tablero()
{

}

void tablero::inicializarTablero(int filas, int columnas)
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

tablero::tablero(int filas, int columnas)
{
    this->inicializarTablero(filas, columnas);
}

void tablero::actualizarRadar(int x, int y, bool golpe)
{
    if(golpe == true){
        this->mapa[x][y] = 'h';
    }else{
        this->mapa[x][y] = 'A';
    }
}

bool verificarBorde(int x, int y, int filas, int columnas){
    if(x < 0 || x >= filas){
        return false;
    }else if(y < 0 || y >= columnas){
        return false;
    }
    return true;
}

bool verificarLados(int x, int y,  char** map, int filas, int columnas){
    if(verificarBorde(x+1, y, filas, columnas)){
        if(map[x+1][y] != '-') return false;   //verificamos arriba
    }
    if(verificarBorde(x-1, y, filas, columnas)){
        if(map[x-1][y] != '-') return false;   //verificamos abajo
    }
    if(verificarBorde(x, y+1, filas, columnas)){
        if(map[x][y+1] != '-') return false;   //verificamos derecha
    }
    if(verificarBorde(x, y-1, filas, columnas)){
        if(map[x][y-1] != '-') return false;   //verificamos izquierda
    }
    return true;
}

bool tablero::verificarPos(int tipo, int x, int y, char orie){
    int auxT;
    switch(tipo){
    case 0: auxT = 5; break;     //portaaviones
    case 1: auxT = 4; break;    //destructor
    case 4: auxT = 1; break;    //lancha
    default: auxT = 3; break;   //sub o crucero
    }


    if(orie == 'H'){
        for(int i = 0; i < auxT; i++){
            if(verificarBorde(x, y+i, this->filas, this->columnas) == false){
                return false;
            }else{
                if(this->mapa[x][y+i] != '-'){
                    return false;
                }else{
                    if(verificarLados(x, y+i, this->mapa, this->filas, this->columnas) == false){
                        return false;
                    }
                }
            }
        }
    }else{
        for(int i = 0; i < auxT; i++){
            if(verificarBorde(x+i, y, this->filas, this->columnas) == false){
                return false;
            }else{
                if(this->mapa[x+i][y] != '-'){
                    return false;
                }else{
                    if(verificarLados(x+i, y, this->mapa, this->filas, this->columnas) == false){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void tablero::colocarBarco(int tipo, int x, int y, char orientacion)
{
    int tam;
    switch (tipo) {
    case 0:
        this->barcos.push_back(new portaaviones(x, y, orientacion, 5));
        tam = 5;
        break;
    case 1:
        this->barcos.push_back(new destructor(x, y, orientacion, 4));
        tam = 4;
        break;
    case 2:
        this->barcos.push_back((new submarino(x, y, orientacion, 3)));
        tam = 3;
        break;
    case 3:
        this->barcos.push_back(new crucero(x, y, orientacion, 3));
        tam = 3;
        break;
    case 4:
        this->barcos.push_back(new lancha(x, y, orientacion, 1));
        tam = 1;
        break;
    default:
        break;
    }

    if(tipo == 4){
        if(orientacion == 'H'){
            this->mapa[x][y] = 'L';
        }else{
            this->mapa[x][y] = 'l';
        }
    }else{
        if(orientacion == 'H'){
            this->mapa[x][y] = 'C';
            for(int i = 1; i < tam-1; i++){
                this->mapa[x][y+i] = 'B';
            }
            this->mapa[x][y+tam-1] = 'F';
        }else{
            this->mapa[x][y] = 'U';
            for(int i = 1; i < tam-1; i++){
                this->mapa[x+i][y] = 'b';
            }
            this->mapa[x+tam-1][y] = 'D';
        }
    }

}

void actualizarOceano(char** map, int x, int y){
    char a;
    switch(map[x][y]){
    case '-': a = 'A'; break;
    case 'B': a = 'X'; break;
    case 'b': a = 'x'; break;
    case 'C': a = 'c'; break;
    case 'F': a = 'f'; break;
    case 'U': a = 'u'; break;
    case 'D': a = 'd'; break;
    case 'L': a = 'G'; break;
    case 'l': a = 'g'; break;
    }
    map[x][y] = a;
}

bool tablero::recibirDisparo(int x, int y)
{
    for(int i = 0; i < this->barcos.size(); i++){
        if(this->barcos[i]->registrarHit(x, y) == true){
            actualizarOceano(this->mapa, x, y);
            if(this->barcos[i]->getHundido()==true)
                this->barcosHundidos++;
            return true;
        }
    }
    actualizarOceano(this->mapa, x, y);
    return false;
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
