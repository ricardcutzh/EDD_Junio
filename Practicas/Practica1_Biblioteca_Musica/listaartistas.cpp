#include "listaartistas.h"

ListaArtistas::ListaArtistas()
{
    this->primero = new NodoAlbum();//CABEZA QUE VA A SOSTENER MI LISTA (ROOT)
    this->elementos = 0;
}

//METODOS PRIVADOS:
bool ListaArtistas::estaVacia()
{
    if(this->elementos == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//METODOS PUBLICOS:
