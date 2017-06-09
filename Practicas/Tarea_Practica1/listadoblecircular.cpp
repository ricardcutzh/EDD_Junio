#include "listadoblecircular.h"
#include <string>
#include<iostream>
#include<stdlib.h>
using namespace std;

ListaDobleCircular::ListaDobleCircular()
{
    this->primero = new Nodo("root");//UN PUNTERO RAIZ QUE HACE REFERENCIA A LA CABEZA DE LA LISTA
    this->elementos = 0;
}

bool ListaDobleCircular:: estaVacia()//VERIFICA SI ESTA VACÍA
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
    if(estaVacia())//SI LA LISTA ESTA VACÍA LO INCERTO DIRECTAMENTE Y HAGO LAS CONEXIONES CON LA RAÍZ DE LA LISTA
    {
        this->primero->siguiente = nuevo;
        nuevo->anterior = this->primero;
        nuevo->siguiente = this->primero;
        this->primero->anterior = nuevo;
        this->elementos++;
    }
    else
    {
        //METODO RECURSIVO QUE DEVUELVE PUNTERO EN DONDE DEBO DE REACOMODAR LOS PUNTEROS
        //DEPENDIENDO DEL TIPO
        Nodo *aux = recorre_encuentra(this->primero->siguiente,nuevo->palabra);
        if(tipo == 2)//EN EL CASO DE QUE LA PALABRA SEA MAYOR..
        {
            nuevo->siguiente = aux->siguiente;
            aux->siguiente->anterior = nuevo;
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
            this->elementos++;//AUMENTO EL NUMERO DE ELEMENTOS INCERTADOS..
        }
        if(tipo == 1)//EN EL CASO DE QUE ESTE ANTES...
        {
            aux->anterior->siguiente = nuevo;
            nuevo->anterior = aux->anterior;
            nuevo->siguiente = aux;
            aux->anterior = nuevo;
            this->elementos++;//AUMENTO EL NUMERO DE ELEMENTOS INCERTADOS..
        }
    }
}


Nodo* ListaDobleCircular::recorre_encuentra(Nodo *recorre, std::string pal)//METODO RECURSIVO
{
    std::string cad1 = recorre->palabra;
    std::string cad2 = pal;
    int comp = cad2.compare(cad1);
    if(comp < 0)//SI ES MENOR
    {
        this->tipo = 1;
        return recorre;
    }
    if(recorre->siguiente != this->primero)//SI SIGUIENTE ES DIFERENTE DE PRIMERO
    {
        //HAGO LLAMADO AL MISMO METODO DE FORMA RECURSIVA
        return recorre_encuentra(recorre->siguiente, pal);
    }
    else//EN CASO DE QUE LLEGUE AL FINAL DE LA LISTA... RETORNO EL PUNTERO Y ASI CORTO LA RECURSIVIDAD
    {
        this->tipo = 2;
        return recorre;
    }
}

void ListaDobleCircular::p_imprimir()
{
    if(estaVacia())//EN CASO DE QUE NO HAYA ELEMENTOS EN LISTA
    {
        cout<< "| Lista vacia...     |" << endl;
    }
    else if(this->elementos == 1)// SI SOLO EXISTE UN ELEMENTO IMPRIMO ESE UNO...
    {
        cout << "| Palabra: " << this->primero->siguiente->palabra << " |" << endl;
    }
    else
    {
        //SI HAY MAS DE 1 HAGO LLAMADOL IMPRIMIR RECURSIVO...
        imprimirLista(this->primero->siguiente);
    }
}

void ListaDobleCircular::imprimirLista(Nodo *siguiente)
{
    if(siguiente != this->primero)//SIEMPRE Y CUANDO EL SIGUIENTE NO SEA IGUAL AL PRIMERO..
    {
        //IMPRIMO EL CONTENIDO DEL NODO Y..
        cout<< "| Palabra: " << siguiente->palabra << " |" <<endl;
        //HAGO LA LLAMADA AL METODO DE NUEVO SOLO QUE ESTA VEZ ENVIO EL SIGUIENTE PUNTERO PARA MOVERME...
        imprimirLista(siguiente->siguiente);
    }
    //CUALQUIER OTRO CASO SE ROMPE LA RECURSIVIDAD...
}

void ListaDobleCircular::p_eliminar(std:: string palabra)
{
    this->eliminado = false;
    if(estaVacia())
    {
        cout << "| No hay elementos para eliminar |"<< endl;
    }
    else
    {
        eliminar(this->primero->siguiente, palabra);//PRIMERA LLAMADA AL METODO RECURSIVO
    }
}

void ListaDobleCircular::eliminar(Nodo *aux, string pal)
{
    string cad1 = aux->palabra;
    int comp = cad1.compare(pal);
    if(comp == 0)//SI COINCIDEN ELIMINO...
    {
        Nodo *temp = aux;
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        this->elementos--;
        free(temp);
        temp = NULL;
        this->eliminado = true;//VERIFICO QUE LA PALABRA FUE ELIMINADA CORRECTAMENTE
        eliminar(aux->siguiente, pal);
    }
    else if(aux->siguiente != this->primero)
    {
        eliminar(aux->siguiente, pal);//EN CASO DE QUE NO ENCUENTRE ME MUEVO AL SIGUIENTE SI NO ES IGUAL A PRIMERO
    }
}
