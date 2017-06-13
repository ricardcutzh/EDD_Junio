#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
#include <listaalbumes.h>
#include <listaartistas.h>
#include <listacanciones.h>
#include <nodoalbum.h>
#include <nodoartista.h>
#include <nodocancion.h>
#include <album.h>
#include <artista.h>
#include <cancion.h>
#include <nodotop.h>
#include <top.h>
#include <string>
#include <fstream>
using namespace std;

//ARCHIVO DE CABECERA DONDE DEFINIRE LAS FUNCIONES A IMPLEMENTAR EN LA INTERFAZ GRAFICA

//VARIABLES GLOBALES

//METODOS
void inserta_datos(std::string arti, std::string album, std::string cancion ,std::string valoracion, std::string path);
void liberarLista();
void crearNuevaLista();
//FUNCIONES
bool leerArchivoEntrada(std::string ruta);
bool escribeBiblioteca();
#endif // FUNCIONES_H
