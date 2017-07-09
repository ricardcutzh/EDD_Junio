#ifndef NODOCURSO_H
#define NODOCURSO_H
#include "Curso.h"

class NodoCurso
{
    public:
        Curso *curso;
        NodoCurso *siguiente;
        NodoCurso(Curso *curso);

    protected:

    private:
};

#endif // NODOCURSO_H
