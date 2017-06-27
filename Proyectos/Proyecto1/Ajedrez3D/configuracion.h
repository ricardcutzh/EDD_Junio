#ifndef CONFIGURACION_H
#define CONFIGURACION_H
#include "jugador.h"


class Configuracion
{
public:
    std::string pl1;
    std::string pl2;
    bool Tiempo;
    int time;
    Configuracion(bool Tiempo, std::string pl1, std::string pl2);
};

#endif // CONFIGURACION_H
