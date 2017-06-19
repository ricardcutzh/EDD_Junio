#include "jugador.h"

//CONSTRUCTOR
Jugador::Jugador(std::string nombre, short p_gan, short p_per)
{
    this->nombre = nombre;
    this->p_ganadas = p_gan;
    this->p_perdidas = p_per;
}

//DESTRUCTOR
Jugador::~Jugador()
{
    //destructor
}
