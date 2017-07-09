#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "NodoHash.h"
#include <iostream>
#include <string>

class TablaHash
{
    public:
        NodoHash **nodos;
        //NodoHash *aux;
        int m;
        int totalDatos;
        float ocupacion;
        TablaHash();
        void insertarEnTablaHash(Estudiante *estudiante);
        Estudiante *buscarEnTablaHash(int index);
        int dispersionDoble(int carnet, int i, int iteracion);
        int funcionDeDispersion(int carnet);
        NodoHash *buscarEstudiante(int carnet);
        void editarEstudiante(int carnet, std::string nombre, std::string direccion);
        bool eliminar(int carnet);
        void verTabla();
    protected:

    private:
        float calculaOcupacion();
        void insertaDispersion(int index, Estudiante *estudiante);
        int calculaIndexCorrecto(int index, int i);
        void rehashTabla();
        void calculaNuevaM();
};

#endif // TABLAHASH_H
