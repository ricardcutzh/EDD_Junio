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
bool generaGrafoMatriz(int nivel);
#endif // FUNCIONES_H
