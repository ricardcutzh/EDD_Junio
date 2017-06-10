#include "cancion.h"

Cancion::Cancion(std::string name, float valoracion, std::string PATH)
{
    this->nombre = name;
    this->valoracion = valoracion;
    this->PATH = PATH;
}
