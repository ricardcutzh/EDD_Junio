#ifndef NODO_H
#define NODO_H
#include <string>


class Nodo
{
public:
    Nodo(std::string palabra);
    std::string palabra;
    Nodo *siguiente;
    Nodo *anterior;
};

#endif // NODO_H
