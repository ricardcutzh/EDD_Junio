#include "nodoalbum.h"

NodoAlbum::NodoAlbum(Album *album, ListaCanciones *songs)
{
    this->album = album;
    this->songs = songs;
    this->siguiente = NULL;
    this->anterior = NULL;
}

NodoAlbum::NodoAlbum()
{
    this->siguiente = NULL;
    this->anterior =  NULL;
}
