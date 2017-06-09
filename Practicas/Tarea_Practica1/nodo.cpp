#include "nodo.h"
#include <string>

//CONSTRUCTOR DEL NODO
Nodo::Nodo(std::string palabra)
{
    this->siguiente = NULL;
    this->anterior = NULL;
    this->palabra = palabra;
}
