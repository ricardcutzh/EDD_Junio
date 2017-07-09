#ifndef CATEDRATICO_H
#define CATEDRATICO_H
#include "string"

class Catedratico
{
    public:
        int id;
        std::string nombre;
        std::string direccion;
        Catedratico(int id, std::string nombre, std::string direccion);
        //virtual ~Catedratico();

    protected:

    private:
};

#endif // CATEDRATICO_H
