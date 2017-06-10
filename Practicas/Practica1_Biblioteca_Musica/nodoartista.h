#ifndef NODOARTISTA_H
#define NODOARTISTA_H
#include<string>
#include"artista.h"
#include"listaalbumes.h"

class NodoArtista
{
public:
    Artista *artista;//ARTISTA QUE SE ALMACENA EN EL NODO
    ListaAlbumes *albumes;//UNA REFERENCIA HACIA UNA LISTA DE ALBUMES ASOCIADOS AL ARTISTA
    NodoArtista *siguiente;//PUNTERO SIGUIENTE
    NodoArtista *anterior;//PUNTERO ANTERIOR
    NodoArtista(Artista *artista, ListaAlbumes *albums);//CONSTRUCTOR
    NodoArtista();//CONSTRUCTOR (AUX)
};

#endif // NODOARTISTA_H
