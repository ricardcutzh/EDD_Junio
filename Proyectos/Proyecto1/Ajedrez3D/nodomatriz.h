#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>
#include <pieza.h>

class NodoMatriz
{
public:
    bool EsPiso;
    int x;
    int y;
    int z;
    //PUNTEROS 2D
    NodoMatriz *siguiente;
    NodoMatriz *anterior;
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    //PUNTEROS 3D
    NodoMatriz *adelante;
    NodoMatriz *atras;
    //PIEZA
    Pieza *pieza;
    NodoMatriz(int x, int y, int z, Pieza *pieza, bool EsPiso);
    //~NodoMatriz();
};

#endif // NODOMATRIZ_H
