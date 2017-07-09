//#include "stdafx.h"
#include "NodoUsuario.h"

/*NodoUsuario::~NodoUsuario()
{
}*/

NodoUsuario::NodoUsuario(Usuario *user)
{
	this->user = user;
	this->siguiente = NULL;
	this->anterior = NULL;
}
