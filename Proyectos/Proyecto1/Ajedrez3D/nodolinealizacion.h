#ifndef NODOLINEALIZACION_H
#define NODOLINEALIZACION_H
#include <string>

class NodoLinealizacion
{
public:
    std::string nombrePieza;
    NodoLinealizacion *siguiente;
    NodoLinealizacion(std::string nombrePieza);
};

#endif // NODOLINEALIZACION_H
