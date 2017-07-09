//#include "stdafx.h"
#include "NodoEdificio.h"

NodoEdificio::NodoEdificio()
{
	this->nombre = "Root";
	this->salones = NULL;
	this->siguiente = NULL;
	this->anterior = NULL;
}

NodoEdificio::NodoEdificio(std::string nombre)
{
	this->nombre = nombre;
	this->siguiente = NULL;
	this->anterior = NULL;
	this->salones = new ListaSalones();
}

NodoEdificio::~NodoEdificio()
{
}
