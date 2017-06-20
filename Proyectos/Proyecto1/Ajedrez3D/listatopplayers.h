#ifndef LISTATOPPLAYERS_H
#define LISTATOPPLAYERS_H
#include <nodotop.h>
#include <fstream>
#include <iostream>

class ListaTopPlayers
{
public:
    NodoTop *raiz;
    int elementos;
    ListaTopPlayers();
    ~ListaTopPlayers();
    bool yaExiste(std::string nombre);
    void add(NodoTop *nuevo);
    void eliminaUltimo();
    void escribirDotTop(std::ofstream &archivo);
    void sameRank(std::ofstream &archivo);
};

#endif // LISTATOPPLAYERS_H
