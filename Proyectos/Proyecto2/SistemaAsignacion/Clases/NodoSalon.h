#pragma once
#include "Salon.h"
class NodoSalon
{
public:
	Salon *salon;
	NodoSalon *siguiente;
	NodoSalon(Salon *salon);
	~NodoSalon();
};

