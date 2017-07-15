#ifndef LISTACURSOS_H
#define LISTACURSOS_H
#include "Curso.h"
#include "NodoCurso.h"


class ListaCursos
{
    public:
        NodoCurso *root;
		int contador = 0;
        int elementos;
        ListaCursos();
        void addCourseToList(Curso *n);
        bool deleteCourse(int codigo);
        bool updateCourse(int codigo, std::string nombre, int semestre, int creditos);
		Curso *buscarCurso(int codigo);
        bool graphCourseList();
		std::string generaNombreImagen();
    protected:
    private:
        bool estaVacia();
};

#endif // LISTACURSOS_H
