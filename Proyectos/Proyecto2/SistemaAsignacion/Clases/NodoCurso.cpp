#include "NodoCurso.h"

NodoCurso::NodoCurso(Curso *curso)
{
    this->curso = curso;
    this->siguiente = NULL;
}
