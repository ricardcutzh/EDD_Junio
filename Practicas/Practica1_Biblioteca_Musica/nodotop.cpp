#include "nodotop.h"

NodoTop::NodoTop(std::string nombre, float valoracion)
{
    this->nombre = nombre;
    this->valoracion = valoracion;
    this->sig = NULL;
    this->ant = NULL;
}
