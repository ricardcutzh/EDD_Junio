#ifndef NODOTOP_H
#define NODOTOP_H
#include "string"


class NodoTop
{
public:
    std::string nombre;
    short int victorias;
    NodoTop *siguiente;
    NodoTop *anterior;
    NodoTop(std::string nombre, short int victorias);
};

#endif // NODOTOP_H
