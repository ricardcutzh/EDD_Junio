#ifndef PIEZA_H
#define PIEZA_H
#include<string>


//CLASE DE LA PIEZA
class Pieza
{
public:
    std::string tipo;
    std::string PATH;
    std::string color;
    Pieza(std::string tipo, std::string PATH);
};

#endif // PIEZA_H
