#include "listaalbumes.h"
//ESTE ES UN LISTADO DE ALBUMES QUE SE GENEREN AL LEER EL ARCHIVO DE ENTRADA
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
    NodoAlbum *temp = this->primero->siguiente;
    while(temp!=NULL)
    {
        elim = temp->album->nombre;
        if(elim.compare(nombre)==0)
        {
            if(temp->siguiente!=NULL)//EN CASO DE QUE ME ENCUENTRE EN MEDIO DE LA LISTA
            {
                temp->anterior->siguiente = temp->siguiente;
                temp->siguiente->anterior = temp->anterior;
                free(temp);
                temp = NULL;
                this->elementos--;
                return true;
            }
            else//EN CASO QUE EL QUE VAYA A ELIMINAR SEA EL ULTIMO
            {
                temp->anterior->siguiente = NULL;
                free(temp);
                temp = NULL;
                this->elementos--;
                return true;
            }
        }
        temp = temp->siguiente;
    }
    return false;
}

//METODO PARA VER SI UN ALBUM YA EXISTE EN LA LISTA
bool ListaAlbumes::yaExisteAlbum(std::string nombre)
{
    if(!estaVacia())
    {
        NodoAlbum *temp = this->primero->siguiente;
        std::string compara;
        while(temp!=NULL)
        {
            compara = temp->album->nombre;
            if(compara.compare(temp)==0)
            {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }
    else
    {
        return false;
    }
}

//METODO QUE BUSCA Y DEVUELVE UNA REFERENCIA AL NODO QUE ENCUENTRE
NodoAlbum* ListaAlbumes::buscaAlbum(std::string nombre)
{
    std::string comp;
    NodoAlbum *retorno = this->primero->siguiente;
    while(retorno!=NULL)
    {
        if(comp.compare(nombre)==0)
        {
            return retorno;
        }
        retorno = retorno->siguiente;
    }
    return NULL;
}

//METODO QUE RETORNA EL NUMERO DE ELEMENTOS EN LA LISTA
int ListaAlbumes::count()
{
    return this->elementos;
}

//METODO QUE HACE EL PROMEDIO DE LOS ALBUMES PARA LA VALORACION DEL ARTISTA
float ListaAlbumes::valoracionArtista()
{
    if(!estaVacia())
    {
        float promedio = 0;
        float acumulado = 0;
        NodoAlbum *aux = this->primero->siguiente;
        while(aux!=NULL)
        {
            acumulado = acumulado + aux->album->valoracion;
            aux = aux->siguiente;
        }
        promedio = acumulado / this->elementos;
        return promedio;
    }
    else
    {
        return 0;
    }
}
