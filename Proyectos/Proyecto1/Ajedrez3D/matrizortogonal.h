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
    NodoMatriz *existeInterseccion(int x, int y);
    NodoMatriz *insertaEnCuboOrdenado(NodoMatriz *inicio, NodoMatriz *nuevo);
    NodoMatriz *creaNodoPiso(int x, int y);
    void insertarEnMatriz(int x, int y, int z, Pieza *pieza);
    //ELIMINAR
    bool EliminarGeneral(int x, int y, int z);
    bool EliminarDeMatriz(int x, int y, int z);
    bool EliminarDeMatriz3D(int x, int y, int z);
    int numeroDeDatosEnColumnas(NodoMatriz *col);
    int numeroDeDatosEnFilas(NodoMatriz *fil);
    NodoMatriz *punteroEliminarDesdeFila(NodoMatriz *fila, int x, int y, int z);
    NodoMatriz *punteroEliminarDesdeColumna(NodoMatriz *col, int x, int y, int z);
};

#endif // MATRIZORTOGONAL_H
