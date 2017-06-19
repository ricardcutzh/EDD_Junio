#ifndef NODOJUGADOR_H
#define NODOJUGADOR_H
#include"jugador.h"

class NodoJugador
{
public:
    Jugador *player;
    NodoJugador *left;
    NodoJugador *right;
    NodoJugador(Jugador *player);
    ~NodoJugador();
};

#endif // NODOJUGADOR_H
