//#include "stdafx.h"
#include "NodoSalon.h"

NodoSalon::NodoSalon(Salon * salon)
{
	this->salon = salon;
	this->siguiente = NULL;
}

NodoSalon::~NodoSalon()
{
}
