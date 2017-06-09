#include "listadoblecircular.h"
#include <string>
#include<iostream>
using namespace std;

ListaDobleCircular::ListaDobleCircular()
{
    this->primero = new Nodo("root");
    this->elementos = 0;
}

bool ListaDobleCircular:: estaVacia()
{
    if(this->elementos == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ListaDobleCircular::p_insertar(Nodo *nuevo)
{
    this->tipo = 0;
    if(estaVacia())
    {
        this->primero->siguiente = nuevo;
        nuevo->anterior = this->primero;
        nuevo->siguiente = this->primero;
        this->primero->anterior = nuevo;
        this->elementos++;
    }
    else
    {
        Nodo *aux = recorre_encuentra(this->primero->siguiente,nuevo->palabra);
        if(tipo == 2)
        {
            nuevo->siguiente = aux->siguiente;
            aux->siguiente->anterior = nuevo;
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
            this->elementos++;
        }
        if(tipo == 1)
        {
            aux->anterior->siguiente = nuevo;
            nuevo->anterior = aux->anterior;
            nuevo->siguiente = aux;
            aux->anterior = nuevo;
            this->elementos++;
        }
    }
}


Nodo* ListaDobleCircular::recorre_encuentra(Nodo *recorre, std::string pal)
{
    std::string cad1 = recorre->palabra;
    std::string cad2 = pal;
    int comp = cad2.compare(cad1);
    if(comp < 0)
    {
        this->tipo = 1;
        return recorre;
    }
    if(recorre->siguiente != this->primero)
    {
        return recorre_encuentra(recorre->siguiente, pal);
    }
    else
    {
        this->tipo = 2;
        return recorre;
    }
}

void ListaDobleCircular::p_imprimir()
{
    if(estaVacia())
    {
        cout<< "| Lista vacia...     |" << endl;
    }
    else if(this->elementos == 1)
    {
        cout << "| Palabra: " << this->primero->siguiente->palabra << " |" << endl;
    }
    else
    {
        imprimirLista(this->primero->siguiente);
    }
}

void ListaDobleCircular::imprimirLista(Nodo *siguiente)
{
    if(siguiente != this->primero)
    {
        cout<< "| Palabra: " << siguiente->palabra << " |" <<endl;
        imprimirLista(siguiente->siguiente);
    }
}
