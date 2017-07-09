#include "Horario.h"

Horario::Horario(int codigo, std::string rango, std::string dia, Salon *refSalon, Catedratico *refCatedra, Curso *refCurso)
{
    this->codigo = codigo;
    this->rango = rango;
    this->dia = dia;
    this->refSalon = refSalon;
    this->refCurso = refCurso;
    this->refCatedra = refCatedra;
    this->asigandos = new ListadoAsignacion(this->refSalon->capacidad);
}
