#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H
#include <nodomatriz.h>
#include <pieza.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <listalinealizacion.h>
#include <QLabel>
#include <QPixmap>
using namespace std;

class MatrizOrtogonal
{
public:
    ListaLinealizacion *linea;
    int negros;
    int blancos;
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
    void alinearTitulos(std::ofstream &archivo, NodoMatriz *r);
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
    //LINEALIZACIÓN
    void creaNuevaLinealizacion(std::string tipo);
    void linealizaPorColumnas(int nivel);
    void linealizaPorFilas(int nivel);
    //REPINTAR MATRIZ DE LABELS
    NodoMatriz *nodoEnNivelN(int nivel, NodoMatriz *inicio);
    void pintaMatrizLabels(QLabel *mat[8][8], int nivel);
    //ME DEVUELVE EL PRIMER NODO QUE COINCIDE CON LA ENTRADA DEL MOVIMIENTO
    NodoMatriz *buscaNodo(std::string tipoPieza, std::string color);
    //MOVIMIENTO DE PIEZAS
    bool muevePeon(NodoMatriz *origen, int xDest, int yDest, int zDest, string color, int codigo);
    int validaPeon(NodoMatriz *ori, int xDest, int yDest, int zDest, string color);
    bool existeElNodoDestino(int x, int y, int z);
    bool enCasillaDestinoHayPiezaColor(int x, int y, int z, std::string color);
    bool buscaPeonValido(std::string tipopieza, std::string color, int xdes, int ydes, int zdes);
    bool EsDelColorContrario(std::string color, int x, int y, int z);
    bool mueveCualquierPieza(NodoMatriz *ori, int xdest, int ydest, int zdest);
    //ALFIL
    bool bucaAlfilValido(std::string tipopieza, std::string color, int xdest, int ydest, int zdest);
    int validaAlfil(NodoMatriz *ori, int xdest, int ydest, int zdest, string color);
    //CABALLO
    bool buscaCaballo(std::string tipopieza, std::string color, int xdest, int ydest, int zdest);
    bool validaCaballo(NodoMatriz *ori,std::string color, int xdest, int ydest, int zdest);
    //TORRE
    bool buscaTorre(std::string tipopieza, std::string color, int xdest, int ydest, int zdest);
    //REY
    bool buscaRey(std::string tipopieza, std::string color, int xdest, int ydest, int zdest);
    //REYNA
    bool buscaReyna(std::string tipopieza, std::string color, int xdest, int ydest, int zdest);
    void calculaGanador();
    int cuentaReinas();
};

#endif // MATRIZORTOGONAL_H
