#pragma once
#include<string>
#include"ListaSalones.h"
#include"Salon.h"
#include"NodoSalon.h"
class NodoEdificio
{
public:
	std::string nombre;
	ListaSalones *salones;
	NodoEdificio *anterior;
	NodoEdificio *siguiente;
	NodoEdificio();
	NodoEdificio(std::string nombre);
	~NodoEdificio();
};

