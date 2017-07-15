//#include "stdafx.h"
#include "ListaUsuarios.h"
#include <ostream>
#include <iostream>
#include <fstream>

//CONSTRUCTOR
ListaUsuarios::ListaUsuarios()
{
	Usuario *super = new Usuario(0, "Admin", "Admin", "sudo");
	this->root = new NodoUsuario(super);
	this->elementos = 0;
}


ListaUsuarios::~ListaUsuarios()
{
}

//METODOS
//AGREGA LOS NODOS A LA LISTA DE USUARIOS DE MANERA ORDENADA
void ListaUsuarios::addToList(Usuario *us)
{
	NodoUsuario *nuevo = new NodoUsuario(us);
	if (estaVacia())
	{
		this->root->siguiente = nuevo;
		nuevo->anterior = this->root;
		this->elementos++;
	}
	else
	{
		int tipo = 0;
		NodoUsuario *aux = this->root->siguiente;
		while (aux!=NULL)
		{
			if (nuevo->user->id < aux->user->id)
			{
				tipo = 1;
				break;
			}
			if (aux->siguiente == NULL)
			{
				break;
			}
			aux = aux->siguiente;
		}
		if (tipo == 1)//SI EL ID ES MENOR LO PONE ANTES
		{
			aux->anterior->siguiente = nuevo;
			nuevo->anterior = aux->anterior;
			nuevo->siguiente = aux;
			aux->anterior = nuevo;
			this->elementos++;
		}
		else//DE LO CONTRARIO LO PONE DESPUES
		{
			aux->siguiente = nuevo;
			nuevo->anterior = aux;
			this->elementos++;
		}
	}

}

//ELIMINA LOS USUARIOS DE LA LISTA
bool ListaUsuarios::deleteUser(int id)
{
	if (!estaVacia())
	{
		bool eliminado = false;
		NodoUsuario *aux = this->root->siguiente;
		while (aux != NULL)
		{
			if (aux->user->id == id)
			{
				eliminado = true;
				break;
			}
			else
			{
				aux = aux->siguiente;
			}
		}
		if (eliminado)
		{
			aux->anterior->siguiente = aux->siguiente;
			if (aux->siguiente != NULL)
			{
				aux->siguiente->anterior = aux->anterior;
			}
			this->elementos = this->elementos-1;
		}
		delete aux;
		return eliminado;
	}
	else
	{
		return false;
	}
}

//BUSCA UN USUARIO EN LA LISTA Y DEVUELVE SU REFERENCIA
NodoUsuario * ListaUsuarios::buscarUsuario(int id)
{
	if (!estaVacia())
	{
		NodoUsuario *aux = this->root->siguiente;
		while (aux!=NULL)
		{
			if (aux->user->id == id)
			{
				return aux;
			}
			aux = aux->siguiente;
		}
		return NULL;
	}
	else
	{
		return NULL;
	}
}

Usuario * ListaUsuarios::buscarUsuarioNom(std::string nombre, std::string password)
{
	if (!estaVacia())
	{
		NodoUsuario *aux = this->root->siguiente;
		while (aux != NULL)
		{
			if (aux->user->nombre == nombre && aux->user->password == password)
			{
				return aux->user;
			}
			aux = aux->siguiente;
		}
		return NULL;
	}
	else
	{
		return NULL;
	}
}

//METODO ENCARGADO DE GRAFICAR LA LISTA DE USUARIOS
bool ListaUsuarios::writeGraph()
{
	this->contador = this->contador + 1;
	std::ofstream archivo;
	archivo.open(generaNombreImagen()+".dot");
	if (archivo.fail())
	{
		return false;
	}
	else
	{
		archivo << "digraph g{" << std::endl;
		archivo << "node [shape=box];" << std::endl;
		archivo << "label=\"Usuarios en Sistema\";" << std::endl;
		NodoUsuario *aux = this->root->siguiente;
		while (aux!=NULL)
		{
			archivo << "\"Usuario: " << aux->user->nombre << " | Id: " << aux->user->id << " | Tipo: " << aux->user->tipo << "\";" << std::endl;
			if (aux->siguiente != NULL)
			{
				archivo << "\"Usuario: " << aux->user->nombre << " | Id: " << aux->user->id << " | Tipo: " << aux->user->tipo << "\"->\"Usuario: " << aux->siguiente->user->nombre << " | Id: " << aux->siguiente->user->id << " | Tipo: " << aux->siguiente->user->tipo << "\";" << std::endl;
			}
			if (aux->anterior != NULL && aux->anterior!= this->root)
			{
				archivo << "\"Usuario: " << aux->user->nombre << " | Id: " << aux->user->id << " | Tipo: " << aux->user->tipo << "\"->\"Usuario: " << aux->anterior->user->nombre << " | Id: " << aux->anterior->user->id << " | Tipo: " << aux->anterior->user->tipo << "\";" << std::endl;
			}
			aux = aux->siguiente;
		}
		archivo << "}";
		archivo.close();
		return true;
	}
}

//SE ENCARGA DE ACTUALIZAR LA INFORMACIÓN DEL USUARIO
bool ListaUsuarios::updateUser(int id, std::string nombre, std::string password, std::string tipo)
{
	if (!estaVacia())
	{
		NodoUsuario *aux = this->root->siguiente;
		while (aux!=NULL)
		{
			if (id == aux->user->id)
			{
				aux->user->nombre = nombre;
				aux->user->password = password;
				aux->user->tipo = tipo;
				return true;
			}
			aux = aux->siguiente;
		}
		return false;
	}
	else
	{
		return false;
	}
}

//METODO ENCARGADO DE HACERME EL LOGIN
bool ListaUsuarios::autentica(std::string nombre, std::string password)
{
	NodoUsuario *aux = this->root;
	while (aux!=NULL)
	{
		if (aux->user->nombre.compare(nombre) == 0 && aux->user->password.compare(password) == 0)
		{
			return true;
		}
		aux = aux->siguiente;
	}
	return false;
}

//VERIFICA SI LA LISTA ESTA VACÍA
bool ListaUsuarios::estaVacia()
{
	return this->elementos == 0 ? true : false;
}

//GENERA EL NOMBRE DIFERENTE A CADA IMAGEN
std::string ListaUsuarios::generaNombreImagen()
{
	return "Usuarios\\Usuarios_" + std::to_string(this->contador);
}