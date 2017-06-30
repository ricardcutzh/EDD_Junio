#ifndef LISTALINEALIZACION_H
#define LISTALINEALIZACION_H
#include <nodolinealizacion.h>
#include "string"
#include <iostream>
#include <stdlib.h>
#include <fstream>

class ListaLinealizacion
{
public:
    NodoLinealizacion *first;
    std::string tipo;
    int elementos;
    ListaLinealizacion(std::string tipo);
    ~ListaLinealizacion();
    void agregar(NodoLinealizacion *nuevo);
    void eliminarPrimero();
    bool generaElGrafo();
    void verLista();
};

#endif // LISTALINEALIZACION_H
