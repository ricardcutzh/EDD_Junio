#ifndef ABBPLAYERS_H
#define ABBPLAYERS_H
#include "nodojugador.h"
#include "jugador.h"
#include <fstream>
#include <iostream>
class ABBPlayers
{
public:
    short int nodosHoja;
    short int nodosRama;
    bool insertado;
    bool eliminado;
    NodoJugador *root;
    ABBPlayers();
    ~ABBPlayers();
    bool insertarABB(Jugador *nuevo);
    bool eliminarABB(std::string nombre);
    bool graphTree();
    int TreeHeight();
    bool vacio();
private:
    void actualizarArbol();
    int obtenerAltura(NodoJugador *subarb);
    void evaluaArbol(NodoJugador *raiz);
    bool EsHoja(NodoJugador *raiz);
    NodoJugador *insertarABBP(NodoJugador *raiz, Jugador *nuevo);
    NodoJugador *eliminarABBP(NodoJugador *subarbol, std::string nombre);
    NodoJugador *replace(NodoJugador *actual);
    void graphTreeP(std::ofstream &archivo, NodoJugador *raiz);
};

#endif // ABBPLAYERS_H
