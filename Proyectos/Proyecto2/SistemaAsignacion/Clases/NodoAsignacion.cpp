#include "NodoAsignacion.h"

NodoAsignacion::NodoAsignacion(Estudiante *estudiante, float zona, float exfinal)
{
    this->estudiante = estudiante;
    this->exFinal = exfinal;
    this->zona = zona;
    this->siguiente = NULL;
}
