#include "nodojugador.h"

//CONSTRUCTOR DEL NODO JUGADOR
NodoJugador::NodoJugador(Jugador *player)
{
    this->player = player;
    this->left = NULL;
    this->right = NULL;
}

//DESTRUCTOR DEL NODO
NodoJugador::~NodoJugador()
{
    delete this->player;
    delete this->right;
    delete this->left;
}
