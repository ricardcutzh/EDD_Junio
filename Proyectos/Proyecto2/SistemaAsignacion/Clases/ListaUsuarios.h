#pragma once
#include "NodoUsuario.h"
#include "Usuario.h"
class ListaUsuarios
{
public:
	NodoUsuario *root;
	int elementos;
	ListaUsuarios();
	~ListaUsuarios();
	//METODOS A UTILIZAR
	void addToList(Usuario *us);
	bool deleteUser(int id);
	NodoUsuario *buscarUsuario(int id);
	bool writeGraph();
	bool updateUser(int id, std::string nombre, std::string password, std::string tipo);
private:
	bool estaVacia();
};

