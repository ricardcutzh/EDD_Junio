#include "nodoartista.h"
#include "listaalbumes.h"
NodoArtista::NodoArtista()
{
    this->siguiente = NULL;
    this->anterior = NULL;
    //AUXILIAR
}

NodoArtista::NodoArtista(Artista *artista, ListaAlbumes *albums)
{
    this->artista = artista;
    this->albumes = albums;
    this->siguiente = NULL;
    this->anterior = NULL;
}
