#include "Horario.h"

Horario::Horario(int codigo, std::string rango, std::string dia, Salon *refSalon, Catedratico *refCatedra, Curso *refCurso, int semestre, int year, std::string edif)
{
    this->codigo = codigo;
    this->rango = rango;
    this->dia = dia;
    this->refSalon = refSalon;
    this->refCurso = refCurso;
    this->refCatedra = refCatedra;
	this->semestre = semestre;
	this->year = year;
	this->edif = edif;
    this->asigandos = new ListadoAsignacion(this->refSalon->capacidad);
}

