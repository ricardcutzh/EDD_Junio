#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

class Estudiante
{
    public:
        int carnet;
        std::string nombre;
        std::string direccion;
        Estudiante(int carnet, std::string nombre, std::string direccion);

    protected:

    private:
};

#endif // ESTUDIANTE_H
