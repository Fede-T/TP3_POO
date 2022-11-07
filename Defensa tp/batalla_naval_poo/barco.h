#ifndef BARCO_H
#define BARCO_H
#include <vector>
#include <iostream>
using namespace std;

class barco
{
private:
    int posX;
    int posY;
    char orientacion;
    int tamanio;
    bool hundido = false;
protected:
    vector<bool> hits;
public:
    barco();
    barco(int x, int y, char orientacion, int tam);
    virtual bool registrarHit(int x, int y) = 0;
    virtual void actualizarEstado() = 0;
    ~barco();
    int getPosX() const;
    void setPosX(int newPosX);
    int getPosY() const;
    void setPosY(int newPosY);
    char getOrientacion() const;
    void setOrientacion(char newOrientacion);
    int getTamanio() const;
    void setTamanio(int newTamanio);
    bool getHundido() const;
    void setHundido(bool newHundido);
    const vector<bool> &getHits() const;
    void setHits(const vector<bool> &newHits);
};

#endif // BARCO_H
