#ifndef LISTAALBUMES_H
#define LISTAALBUMES_H
#include "nodoalbum.h"
#include "album.h"
#include "listacanciones.h"

class ListaAlbumes
{
public:
    NodoAlbum *primero;
    ListaAlbumes();
    void insertar(Album *newAlbum, ListaCanciones *listado);
    bool eliminar(std::string nombre);
    bool yaExisteAlbum(std::string nombre);
    NodoAlbum *buscaAlbum(std::string nombre);
    float valoracionArtista();
    int count();
private:
    bool estaVacia();
    int elementos;
};

#endif // LISTAALBUMES_H
