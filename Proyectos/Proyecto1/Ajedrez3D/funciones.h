#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "jugador.h"
#include <string>
#include <abbplayers.h>
#include "nodojugador.h"
#include <nodotop.h>
#include <listatopplayers.h>
#include <matrizortogonal.h>
#include <nodomatriz.h>
#include <pieza.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <QLabel>
#include <QPixmap>
//AQUI DECLARARE MIS PROTOTIPOS DE FUNCIONES
void inicializaArbol();
bool leerArchivoDeJugadores(std::string ruta);
void insertaDatos(std::string nombre, std::string pg, std::string pp);
bool graficameArbol();
bool graficameListaTops();
bool eliminaJugador(std::string nombre);
bool verSiArbolEstaVacio();
int getTreeHeight();
void generaTops();
void generaTopsR(NodoJugador *raiz);
void inicializarMatriz();
void insertaNivel0Negros();
void insertaNivel0Blancos();
void insertarNivel1Negros();
void insertarNivel1Blancos();
void insertarNivel2Negros();
void insertarNivel2Blancos();
bool generaGrafoMatriz(int nivel);
bool matrizVacia();
void realizaLinealizacion(int nivel, std::string tipo);
bool realizaGrafoLinealizacion();
void limpiaLinealizacion();
void actualizarTablero(QLabel *l0[8][8], QLabel *l1[8][8], QLabel *l2[8][8]);
void despintaTableros(QLabel *mat[8][8]);
bool muevePieza(std::string entrada, std::string color);
std::string devuelvemeTipoDePieza(std::string inicial);
int indice(std::string l);
void calculaFuncionGanador();
int cantidadNegros();
int cantidadBlancos();
int cantidadDeDamas();
#endif // FUNCIONES_H
