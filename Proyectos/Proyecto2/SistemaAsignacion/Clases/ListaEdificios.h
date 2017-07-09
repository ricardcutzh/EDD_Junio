#pragma once
#include "NodoEdificio.h"
#include "ListaSalones.h"
class ListaEdificios
{
public:
	NodoEdificio *root;
	int elementos;
	ListaEdificios();
	~ListaEdificios();
	void addToList(NodoEdificio *nuevo);
	bool deleteEdificio(std::string nombre);
	NodoEdificio *buscarEdificio(std::string nombre);
	bool GraficarEdificios();
private:
	bool estaVacia();
};

