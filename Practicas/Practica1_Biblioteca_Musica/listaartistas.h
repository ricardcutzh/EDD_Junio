#ifndef LISTAARTISTAS_H
#define LISTAARTISTAS_H
#include "nodoartista.h"
#include "artista.h"
#include "listaalbumes.h"

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
private:
    int elementos;
    bool estaVacia();
};

#endif // LISTAARTISTAS_H
