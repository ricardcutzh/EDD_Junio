#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

class Jugador
{
public:
    short int p_ganadas;
    short int p_perdidas;
    std::string nombre;
    Jugador(std::string nombre, short int p_gan, short int p_per);
    ~Jugador();
};

#endif // JUGADOR_H
