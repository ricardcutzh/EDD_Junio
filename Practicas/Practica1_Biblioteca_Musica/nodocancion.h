#ifndef NODOCANCION_H
#define NODOCANCION_H
#include <string>
#include "cancion.h"


class NodoCancion
{
public:

    NodoCancion(Cancion*song);
    Cancion* song;
    NodoCancion *next;
};


#endif // NODOCANCION_H
