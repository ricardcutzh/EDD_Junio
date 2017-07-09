//#include "stdafx.h"
#include "ListaEdificios.h"
#include <fstream>

//CONSTRUCTOR
ListaEdificios::ListaEdificios()
{
	this->elementos = 0;
	this->root = new NodoEdificio();
}

//DESTRUTOR
ListaEdificios::~ListaEdificios()
{
}

//AGREGA ELEMENTOS A LA LISTA
void ListaEdificios::addToList(NodoEdificio * nuevo)
{
	if (estaVacia())
	{
		this->root->siguiente = nuevo;
		nuevo->anterior = this->root;
		nuevo->siguiente = this->root;
		this->root->anterior = nuevo;
		this->elementos++;
	}
	else
	{
		NodoEdificio *aux = this->root->siguiente;
		while (aux->siguiente != this->root)
		{
			aux = aux->siguiente;
		}
		nuevo->siguiente = aux->siguiente;
		aux->siguiente->anterior = nuevo;
		aux->siguiente = nuevo;
		nuevo->anterior = aux;
		this->elementos++;
	}
}

//ELIMINA ELEMENTOS DE LA LISTA DE EDIFICIOS
bool ListaEdificios::deleteEdificio(std::string nombre)
{
    if(!estaVacia())
    {
        NodoEdificio *aux = this->root->siguiente;
        NodoEdificio *elim = NULL;
        while(aux!=this->root)
        {
            if(aux->nombre.compare(nombre)==0)
            {
                elim = aux;
                break;
            }
            aux = aux->siguiente;
        }
        if(elim!=NULL)
        {
            elim->anterior->siguiente = elim->siguiente;
            elim->siguiente->anterior = elim->anterior;
            delete elim;
            this->elementos = this->elementos-1;
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

//BUSCA EL ELEMENTO EN LA LISTA Y RETORNA SU REFERENCIA
NodoEdificio * ListaEdificios::buscarEdificio(std::string nombre)
{
    if(!estaVacia())
    {
        NodoEdificio *aux = this->root->siguiente;
        while(aux!=this->root)
        {
            if(aux->nombre.compare(nombre)==0)
            {
                return aux;
            }
            aux = aux->siguiente;
        }
        return NULL;
    }
	return NULL;
}

//GRAFICA LA ESTRUCTURA QUE ALMACENA LOS EDIFICIOS EN MEMORIA
bool ListaEdificios::GraficarEdificios()
{
    std::ofstream archivo;
    archivo.open("Edificios.dot");
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        archivo << "digraph g {" << std::endl;
        archivo << "label=\"Edificios\";" << std::endl;
        archivo << "node [shape=box];" << std::endl;
        NodoEdificio *aux = this->root->siguiente;
        int contador = 0;
        while(aux!=this->root)
        {
            archivo << "\"Edificio: " << aux->nombre << "\";" << std::endl;
            if(aux->siguiente == this->root)
            {
                archivo << "\"Edificio: " << aux->nombre << "\"->\"Edificio: " << this->root->siguiente->nombre << "\";" << std::endl;
            }
            else
            {
                archivo << "\"Edificio: " << aux->nombre << "\"->\"Edificio: " << aux->siguiente->nombre << "\";" << std::endl;
            }
            if(aux->anterior == this->root)
            {
                archivo << "\"Edificio: " << aux->nombre << "\"->\"Edificio: " << this->root->anterior->nombre << "\";" << std::endl;
            }
            else
            {
                archivo << "\"Edificio: " << aux->nombre << "\"->\"Edificio: " << aux->anterior->nombre << "\";" << std::endl;
            }
            if(aux->salones->elementos>0)
            {
                archivo << "\"Edificio: " << aux->nombre << "\"->\"" << aux->nombre << ": " << aux->salones->root->siguiente->salon->numSalon << "\"" << std::endl;
                archivo << "subgraph cluster_" << contador << "{" << std::endl;
                archivo << "rank=same;" << std::endl;
                archivo << "label=\"Salones\"" << std::endl;
                aux->salones->graficaSalon(archivo, aux->nombre);
                archivo << "}" << std::endl;
            }
            contador = contador+1;
            aux = aux->siguiente;
        }
        archivo << "}" << std::endl;
        archivo.close();
        return true;
    }
}

//VERIFICA SI LA LISTA ESTA VACÍA
bool ListaEdificios::estaVacia()
{
	return this->elementos == 0 ? true : false;
}
