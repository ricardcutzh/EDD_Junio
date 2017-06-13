#ifndef LISTACANCIONES_H
#define LISTACANCIONES_H
#include "nodocancion.h"
#include "cancion.h"
#include <fstream>


class ListaCanciones
{
public:
    NodoCancion *first;//PUNTERO PRIMERO
    NodoCancion *last;//PUNTERO AL ULTIMO
    ListaCanciones();
    //METODOS
    void insertar_cancion(Cancion *newSong);
    bool eliminar_cancion(std::string nombre);
    int count();
    float valoracionAlbum();
    void escribeLista(std::ofstream &archivo);
private:
    int elementos;
    bool estaVacia();
};

#endif // LISTACANCIONES_H
