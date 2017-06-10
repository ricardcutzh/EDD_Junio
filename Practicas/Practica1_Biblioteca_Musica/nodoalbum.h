#ifndef NODOALBUM_H
#define NODOALBUM_H
#include "album.h"
#include <listacanciones.h>


class NodoAlbum
{
public:
    NodoAlbum *siguiente;
    NodoAlbum *anterior;
    Album *album;
    ListaCanciones *songs;
    NodoAlbum();
    NodoAlbum(Album *album, ListaCanciones *songs);
};

#endif // NODOALBUM_H
