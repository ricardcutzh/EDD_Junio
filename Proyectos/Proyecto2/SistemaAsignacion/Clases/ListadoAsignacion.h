#ifndef LISTADOASIGNACION_H
#define LISTADOASIGNACION_H
#include "NodoAsignacion.h"
#include <fstream>
class ListadoAsignacion
{
    public:
        NodoAsignacion *root;
        int elementos;
        int limite;
        ListadoAsignacion(int limite);
        void asignarEstudiante(Estudiante *estudiante , float zona, float exfinal);
        bool cupoLleno();
        bool desasignarEstudianteDecurso(int carnet);
        void graficarAsignacion(std::ofstream &archivo, std::string nombre);
		NodoAsignacion *buscarAsignacion(int idAlumno);
		std::string htmlAsignacion();
		std::string cursosAsignadosPorEstudiante(int carnet, std::string curso);
		std::string AsignadosACurso(int curs);
		std::string aproRepro(std::string curso);
    protected:

    private:
        bool estaVacia();
};

#endif // LISTADOASIGNACION_H
