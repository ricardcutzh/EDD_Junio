#ifndef PIEZA_H
#define PIEZA_H
#include<string>


//CLASE DE LA PIEZA
class Pieza
{
public:
    std::string tipo;
    std::string PATH;
    Pieza(std::string tipo, std::string PATH);
};

#endif // PIEZA_H
