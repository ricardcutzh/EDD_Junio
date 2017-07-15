#ifndef HORARIO_H
#define HORARIO_H
#include "ListadoAsignacion.h"
#include "string"
#include "Salon.h"
#include "Curso.h"
#include "Catedratico.h"

class Horario
{
    public:
        int codigo;
        std::string rango;
        std::string dia;
        Salon *refSalon;
        Curso *refCurso;
        Catedratico *refCatedra;
		int semestre;
		int year;
		std::string edif;
        ListadoAsignacion *asigandos;
        Horario(int codigo, std::string rango, std::string dia, Salon *refSalon, Catedratico *refCatedra, Curso *refCurso, int semestre, int year, std::string edif);
    protected:

    private:
};

#endif // HORARIO_H
