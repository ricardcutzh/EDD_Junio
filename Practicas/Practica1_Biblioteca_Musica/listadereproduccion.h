#ifndef LISTADEREPRODUCCION_H
#define LISTADEREPRODUCCION_H
#include<nodorep.h>
#include<cancion.h>
#include<fstream>
#include<iostream>


class ListaDeReproduccion
{
public:
    NodoRep *raiz;
    std::string tipolista;
    int elementos;
    ListaDeReproduccion(std::string tipolista);
    void addToPlaylist(std::string nombre, std::string path);
    void Pop();
    void Desencolar();
    bool grafica();
private:
    bool estaVacio();
    void graficaListaDoble(std::ofstream &archivo);
    void graficaCola(std::ofstream &archivo);
    void graficaPila(std::ofstream &archivo);
};

#endif // LISTADEREPRODUCCION_H
