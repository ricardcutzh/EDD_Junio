#include "nodorep.h"

NodoRep::NodoRep(std::string nombre, std::string path)
{
    this->nombre = nombre;
    this->path = path;
    this->sig = NULL;
    this->ant = NULL;
}
