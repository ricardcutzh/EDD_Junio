//#include "stdafx.h"
#include "ListaSalones.h"

//CONSTRUCTOR DE LA LISTA
ListaSalones::ListaSalones()
{
	Salon *r = new Salon(0, 0);
	this->root = new NodoSalon(r);
	this->elementos = 0;
}
//DESTRUCTOR DE LA LISTA
ListaSalones::~ListaSalones()
{
}

//AGREGAR A LA LISTA DE SALONES
void ListaSalones::addToList(Salon * n)
{
	NodoSalon *nuevo = new NodoSalon(n);
	if (estaVacia())
	{
		this->root->siguiente = nuevo;
		this->elementos = this->elementos + 1;
	}
	else
	{
		int tipo = 0;
		NodoSalon *aux = this->root->siguiente;
		/*while (aux->siguiente!=NULL)
		{
			if (nuevo->salon->numSalon < aux->siguiente->salon->numSalon)
			{
				tipo = 1;
				break;
			}
			aux = aux->siguiente;
		}
		if (tipo == 1)
		{
			nuevo->siguiente = aux->siguiente;
			aux->siguiente = nuevo;
			this->elementos++;
		}
		if (tipo == 0)
		{
			aux->siguiente = nuevo;
			this->elementos++;
		}*/
		while (aux->siguiente!=NULL)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
		this->elementos++;
	}

}


//ACTUALIZA LA INFORMACI�N DE UN SALON EN ESPEC�FICO
bool ListaSalones::updateClassroom(int numSalon, int capacidad, int nuNumero)
{
	if (!estaVacia())
	{
		NodoSalon *aux = this->root->siguiente;
		while (aux!=NULL)
		{
			if (aux->salon->numSalon == numSalon)
			{
				aux->salon->numSalon = nuNumero;
				aux->salon->capacidad = capacidad;
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

//ELIMINA UN SALON DE LA LISTA
bool ListaSalones::deleteClassroom(int numSalon)
{
	if (!estaVacia())
	{
		NodoSalon *aux = this->root;
		NodoSalon *elim = NULL;
		while (aux->siguiente != NULL)
		{
			if (aux->siguiente->salon->numSalon == numSalon)
			{
				elim = aux->siguiente;
				break;
			}
			aux = aux->siguiente;
		}
		if (elim != NULL)
		{
			aux->siguiente = elim->siguiente;
			delete elim;
			this->elementos--;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//BUSCA UN SALON EN LA LISTA Y DEVUELVE SU REFERENCIA
Salon * ListaSalones::searchClassroom(int numSalon)
{
	if (!estaVacia())
	{
		NodoSalon *aux = this->root->siguiente;
		while (aux!=NULL)
		{
			if (aux->salon->numSalon == numSalon)
			{
				return aux->salon;
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

//SE ENCARGA DE GRAFICAR LOS SALONES EN LISTA
void ListaSalones::graficaSalon(std::ofstream & archivo, std::string edificio)
{
	if (!estaVacia())
	{
		NodoSalon *aux = this->root->siguiente;
		while (aux!=NULL)
		{
			//archivo << "\"" << edificio << ": " << aux->salon->numSalon << " | Cap: " << aux->salon->capacidad << "\";" << std::endl;
			if (aux->siguiente != NULL)
			{
				archivo << "\"" << edificio << ": " << aux->salon->numSalon << " | Cap: " << aux->salon->capacidad << "\"->\"" << edificio << ": "  << aux->siguiente->salon->numSalon << " | Cap: " << aux->siguiente->salon->capacidad << "\";" << std::endl;
			}
			aux = aux->siguiente;
		}
	}
}

//VERIFICA SI LA LISTA ESTA VAC�A
bool ListaSalones::estaVacia()
{
	return this->elementos == 0 ? true : false;
}
