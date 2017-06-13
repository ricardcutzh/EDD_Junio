#ifndef LISTAALBUMES_H
#define LISTAALBUMES_H
#include "nodoalbum.h"
#include "album.h"
#include "listacanciones.h"
#include <fstream>

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
    void escribirAlbumes(std::ofstream &archivo);
private:
    bool estaVacia();
    int elementos;
    void sameRank(std::ofstream &archivo);
};

#endif // LISTAALBUMES_H
