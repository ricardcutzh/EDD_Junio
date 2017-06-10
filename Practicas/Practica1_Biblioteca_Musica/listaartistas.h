#ifndef LISTAARTISTAS_H
#define LISTAARTISTAS_H
#include "nodoartista.h"

class ListaArtistas
{
public:
    NodoArtista *primero;
    ListaArtistas();

private:
    int elementos;
    bool estaVacia();
};

#endif // LISTAARTISTAS_H
