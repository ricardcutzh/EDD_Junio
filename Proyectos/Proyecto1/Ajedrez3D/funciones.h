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
#endif // FUNCIONES_H
