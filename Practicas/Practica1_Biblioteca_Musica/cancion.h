#ifndef CANCION_H
#define CANCION_H
#include<string>


class Cancion
{
public:
    std::string nombre;
    float valoracion;
    std::string PATH;
    Cancion(std::string name, float valoracion, std::string PATH);
};

#endif // CANCION_H
