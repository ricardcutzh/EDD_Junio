#pragma once
#include<string>
#include "Usuario.h"
class NodoUsuario
{
public:
	Usuario *user;
	NodoUsuario *siguiente;
	NodoUsuario *anterior;
	NodoUsuario(Usuario *user);
	//~NodoUsuario();
};

