#include "nodotop.h"

NodoTop::NodoTop(std::string nombre, short int victorias)
{
    this->nombre = nombre;
    this->victorias = victorias;
    this->siguiente = NULL;
    this->anterior = NULL;
}
