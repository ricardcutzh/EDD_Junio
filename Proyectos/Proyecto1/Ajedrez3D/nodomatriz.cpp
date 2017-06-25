#include "nodomatriz.h"
//CONSTRUCTOR DE MI NODO
NodoMatriz::NodoMatriz(int x, int y, int z, Pieza *pieza, bool EsPiso)
{
    this->EsPiso = EsPiso;
    this->x = x;
    this->y = y;
    this->z = z;
    this->pieza = pieza;
    this->siguiente = NULL;
    this->anterior = NULL;
    this->arriba = NULL;
    this->abajo = NULL;
    this->adelante = NULL;
    this->atras = NULL;
}

//DESTRUCTOR DEL NODO
NodoMatriz::~NodoMatriz()
{
    delete this->siguiente;
    delete this->anterior;
    delete this->arriba;
    delete this->abajo;
    delete this->adelante;
    delete this->atras;
}
