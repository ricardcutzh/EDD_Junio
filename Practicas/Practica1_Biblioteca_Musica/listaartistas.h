#ifndef LISTAARTISTAS_H
#define LISTAARTISTAS_H
#include "nodoartista.h"
#include "artista.h"
#include "listaalbumes.h"
#include <fstream>

class ListaArtistas
{
public:
    NodoArtista *primero;
    ListaArtistas();
    void insertar_artista(Artista *newArtist, ListaAlbumes *albums);
    bool yaExisteArtista(std::string nombre);
    NodoArtista* buscaArtista(std::string nombre);
    bool eliminar_artista(std::string nombre);
    int count();
    void escribeArtistas(std::ofstream &archivo);
    void enlistaArtistasDOT(std::ofstream &archivo);
private:
    int elementos;
    bool estaVacia();
    void sameRank(std::ofstream &archivo);
};

#endif // LISTAARTISTAS_H
