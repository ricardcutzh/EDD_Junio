#include "nodocancion.h"

NodoCancion::NodoCancion(Cancion *song)//NODO CANCION ALMACENA UNA CANCIÓN
{
    this->song = song;
    this->next = NULL;
}

