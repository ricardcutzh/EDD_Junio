#ifndef NODOTOP_H
#define NODOTOP_H
#include <string>



class NodoTop
{
public:
    std::string nombre;
    float valoracion;
    NodoTop *sig;
    NodoTop *ant;
    NodoTop(std::string nombre, float valoracion);
};

#endif // NODOTOP_H
