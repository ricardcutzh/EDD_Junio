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
	int contador = 0;
	//METODOS A UTILIZAR
	void addToList(Usuario *us);
	bool deleteUser(int id);
	NodoUsuario *buscarUsuario(int id);
	Usuario *buscarUsuarioNom(std::string nombre, std::string password);
	bool writeGraph();
	bool updateUser(int id, std::string nombre, std::string password, std::string tipo);
	bool autentica(std::string nombre, std::string password);
	std::string generaNombreImagen();
private:
	bool estaVacia();
};

