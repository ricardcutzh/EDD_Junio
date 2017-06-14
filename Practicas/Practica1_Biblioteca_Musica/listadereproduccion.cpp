#include "listadereproduccion.h"
#include <iostream>
#include<sstream>

ListaDeReproduccion::ListaDeReproduccion(std::string tipolista)
{
    this->raiz = new NodoRep("root","root");
    this->elementos = 0;
    this->tipolista = tipolista;
}

//AÑADE A LA LISTA DE REPRODUCCIÓN
void ListaDeReproduccion::addToPlaylist(std::string nombre, std::string path)
{
    NodoRep *nuevo = new NodoRep(nombre, path);
    if(estaVacio())
    {
        this->raiz->sig = nuevo;
        nuevo->ant = this->raiz;
        nuevo->sig = this->raiz;
        this->raiz->ant = nuevo;
        this->elementos++;
    }
    else
    {
        NodoRep *aux = this->raiz->sig;
        while(aux->sig!=NULL)
        {
            aux = aux->sig;
        }
        aux->sig->ant = nuevo;
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
        nuevo->ant = aux;
        this->elementos++;
    }
}

//VER SI LA LISTA ESTA VACIA
bool ListaDeReproduccion::estaVacio()
{
    if(this->elementos == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//METODO PARA SACAR COMO PILA
void ListaDeReproduccion::Pop()
{
    if(!estaVacio())
    {
        NodoRep *aux = this->raiz->ant;
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        free(aux);
        aux = 0;
        this->elementos--;
    }
}

//  COMPORTA COMO COLA
void ListaDeReproduccion::Desencolar()
{
    if(!estaVacio())
    {
        NodoRep *aux = this->raiz->sig;
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        free(aux);
        aux = 0;
        this->elementos--;
    }
}

bool ListaDeReproduccion::grafica()
{
    if(!estaVacio())
    {
        std::ofstream archivo;
        archivo.open("Playlist.dot",std::ios::out);
        if(archivo.fail())
        {
            return false;
        }
        if(this->tipolista.compare("LDE")==0)
        {
            //GRAFICA LA LISTA DOBLE
            graficaListaDoble(archivo);
            archivo.close();
            return true;
        }
        else if(this->tipolista.compare("STACK")==0)
        {
            //GRAFICA PILA
            graficaPila(archivo);
            archivo.close();
            return true;
        }
        else if(this->tipolista.compare("QUEUE")==0)
        {
            //GRAFICA COLA
            graficaCola(archivo);
            archivo.close();
            return true;
        }
        else
        {
            archivo.close();
            return false;
        }
    }
    else
    {
        return false;
    }
}

void ListaDeReproduccion::graficaListaDoble(std::ofstream &archivo)
{
    archivo << "digraph G{" << std::endl;
    archivo << "node [shape=box];" <<std::endl;
    //CONECTO EL PRIMERO CON EL ULTIMO
    archivo << "\"Song: "<< this->raiz->ant->nombre << "\"->\"Song: " << this->raiz->sig->nombre << "\";" << std::endl;
    archivo << "\"Song: "<< this->raiz->sig->nombre << "\"->\"Song: " << this->raiz->ant->nombre << "\";" << std::endl;
    NodoRep *aux = this->raiz->sig;
    while(aux!=this->raiz)
    {
        if(aux->ant!=this->raiz)
        {
            archivo << "\"Song: " << aux->nombre << "\"->\"Song: " << aux->ant->nombre << "\";" << std::endl;
        }
        if(aux->sig!=this->raiz)
        {
            archivo << "\"Song: " << aux->nombre << "\"->\"Song: " << aux->sig->nombre << "\";" << std::endl;
        }
        aux = aux->sig;
    }
    archivo << "}" << std::endl;
}

void ListaDeReproduccion::graficaPila(std::ofstream &archivo)
{
    archivo << "digraph G{" << std::endl;
    archivo << "node [shape=box];" <<std::endl;
    NodoRep *aux = this->raiz->ant;
    while(aux!=this->raiz)
    {
        if(aux->ant!=this->raiz)
        {
            archivo << "\"Song: " << aux->nombre << "\"->\"Song: " << aux->ant->nombre << "\";" << std::endl;
        }
        else
        {
            archivo << "\"Song: " << aux->nombre << "\";" << std::endl;
        }
        aux = aux->ant;
    }
    archivo << "}" << std::endl;
}

void ListaDeReproduccion::graficaCola(std::ofstream &archivo)
{
    archivo << "digraph G{" << std::endl;
    archivo << "node [shape=box];" <<std::endl;
    NodoRep *aux = this->raiz->sig;
    while(aux!=this->raiz)
    {
        if(aux->sig!=this->raiz)
        {
            archivo << "\"Song: " << aux->nombre << "\"->\"Song: " << aux->sig->nombre << "\";" << std::endl;
        }
        else
        {
            archivo << "\"Song: " << aux->nombre << "\";" << std::endl;
        }
        aux = aux->sig;
    }
    archivo << "}" << std::endl;
}
