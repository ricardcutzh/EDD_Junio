//#include "stdafx.h"
#include "Usuario.h"


Usuario::Usuario(int id, std::string nombre, std::string password, std::string tipo)
{
	this->id = id;
	this->nombre = nombre;
	this->password = password;
	this->tipo = tipo;
}

Usuario::~Usuario()
{
}
