#include "listaalbumes.h"

ListaAlbumes::ListaAlbumes()
{
    this->primero = new NodoAlbum();
    this->elementos = 0;
}

//METODOS PRIVADOS:
bool ListaAlbumes::estaVacia()
{
    if(this->elementos==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//METODOS PUBLICOS:

//METODO PARA INSERTAR ALBUMES A LA LISTA SI ESTOS NO EXISTEN..
void ListaAlbumes::insertar(Album *newAlbum, ListaCanciones *listado)
{
    NodoAlbum *nuevo = new NodoAlbum(newAlbum, listado);
    if(estaVacia())
    {
        this->primero->siguiente = nuevo;
        nuevo->anterior = this->primero;
        this->elementos++;
    }
    else
    {
        NodoAlbum *temp = this->primero->siguiente;
        while(temp->siguiente!=NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
        this->elementos++;
    }
}

//METODO PARA ELIMINAR UN ALBUM POR MEDIO DEL NOMBRE
bool ListaAlbumes::eliminar(std::string nombre)
{
    std::string elim;
}
