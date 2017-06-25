#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H
#include <nodomatriz.h>
#include <pieza.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class MatrizOrtogonal
{
public:
    NodoMatriz *raiz;
    std::string letras[9] = {"root","H","G","F","E","D","C","B","A"};
    MatrizOrtogonal();
    ~MatrizOrtogonal();
    //METODOS
    bool matrizVacia();
    bool existeColumna(int x);
    bool existeFila(int y);
    NodoMatriz *crearCabeceraColumnas(int x);
    NodoMatriz *crearCabecerasFilas(int y);
    NodoMatriz *encuentraFila(int y);
    NodoMatriz *encuentraColumna(int x);
    NodoMatriz *recorreFila(NodoMatriz *nodoB, NodoMatriz* nuevo);
    NodoMatriz *recorreColumna(NodoMatriz *nodoB, NodoMatriz* nuevo);
    NodoMatriz *colocaEnFilaConPosicionCorrecta(NodoMatriz *nodoB, NodoMatriz *nuevo);
    NodoMatriz *colocaEnColumnaConPosicionCorrecta(NodoMatriz *nodoB, NodoMatriz *nuevo);
    bool generaDotMatriz(int nivel);
    void apuntaEncabezadosFila(std::ofstream &archivo, int nivel);
    void apuntaEncabezadosColumnas(std::ofstream &archivo, int nivel);
    std::string buscaFilaDatoEnNivelN(NodoMatriz *inicio, int nivel);
    std::string buscaColumnaDatoEnNivelN(NodoMatriz *inicio, int nivel);
    std::string DatoEnNiveN(NodoMatriz *inicio, int n);
    void alinearPorNiveles(std::ofstream &archivo, NodoMatriz *fil, int nivel);
    NodoMatriz *encuentraElSiguienteQueNoEsPiso(NodoMatriz *inicio);
    NodoMatriz *encuentraElAnteriorQueNoEsPiso(NodoMatriz *inicio);
    NodoMatriz *encuentraElArribaQueNoEsPiso(NodoMatriz *inicio);
    NodoMatriz *encuentraElAbajoQueNoEsPiso(NodoMatriz *inicio);
    void escribeMatrizSegunNiveles(std::ofstream &archivo, NodoMatriz *fil, int nivel);
};

#endif // MATRIZORTOGONAL_H
