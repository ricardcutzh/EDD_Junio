#ifndef CURSO_H
#define CURSO_H
#include <string>

class Curso
{
    public:
        int codigo;
        std::string nombre;
        int semestre;
        int creditos;
        Curso(int codigo, std::string nombre, int semestre, int creditos);

    protected:

    private:
};

#endif // CURSO_H
