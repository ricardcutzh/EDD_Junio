#include "listacanciones.h"
#include "nodocancion.h"
#include "cancion.h"
#include <stdlib.h>
//ESTE SERA UN LISTADO DE CANCIONES EN LISTA SIMPLE

ListaCanciones::ListaCanciones()//CONSTRUCTOR DE MI LISTA DE CANCIONES
{
    this->first = NULL;
    this->last = NULL;
    this->elementos = 0;//VARIABLE PARA LLEVAR EL CONTROL DEL NUMERO DE ELEMENTOS EN MI LISTA
}

//METODOS PRIVADOS:
bool ListaCanciones::estaVacia()
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

//METODOS PUBLICOS:

//INSERTAR EN LISTA SIMPLE
void ListaCanciones::insertar_cancion(Cancion *newSong)
{
    NodoCancion *nuevo = new NodoCancion(newSong);
    if(estaVacia())
    {
        this->first = nuevo;
        this->last = nuevo;
        this->elementos++;
    }
    else
    {
        this->last->next = nuevo;//INSERTO AL FINAL DEL ULTIMO ELEMENTO
        this->last = nuevo;
        this->elementos++;
    }

}

//ELIMINACION DE LA LISTA DE CANCIONES
bool ListaCanciones::eliminar_cancion(std::string nombre)
{
    bool eliminado = false;
    std::string pr = this->first->song->nombre;
    if(nombre.compare(pr)==0)//VOY A ELIMINAR EL PRIMERO ASI NO PIERDO EL PUNTERO
    {
        if(this->elementos == 1)//SI SOLO HAY UN SOLO ELEMENTO EN LISTA
        {
            free(this->first);//LIBERO DE MEMORIA EL PRIMERO
            this->first = NULL;
            free(this->last);//LIBREO DE MEMORIA EL ULTIMO
            this->last = NULL;
            this->elementos--;//DECREMENTO EL CONTADOR
            eliminado = true;
            return eliminado;
        }
        else
        {
            NodoCancion *temp = this->first; //PARA NO PERDER LA REFERENCIA EL PRIMERO
            this->first =this->first->next;
            free(temp);//LIBERO A LO QUE APUNTA TEMPORAL
            temp = NULL;
            this->elementos--;//DECREMENTO EL CONTADOR
            eliminado = true;
            return eliminado;
        }
    }
    else
    {
        NodoCancion *antTemp = NULL;//AUXILIAR PARA LLEVAR UNA REFERENCIA AL ANTERIOR PARA MOVERME Y PODER ELIMINAR
        NodoCancion *temp = this->first;//EL TEMPORAL QUE VA A IR COMPARANDO PARA VER CUAL LIBERAR
        std::string elim;
        while(temp!=NULL)
        {
            elim = temp->song->nombre;
            if(elim.compare(nombre)==0)
            {
                if(temp == this->last)//SI EN CASO DEBO ELIMINAR EL ULTIMO ELEMENTO EN LISTA
                {
                    this->last = antTemp;//EL ANTERIOR QUEDA COMO EL ULTIMO
                    this->last->next = NULL;//LO APUNTO AL ULTIMO
                    free(temp);//LIBERO A TEMPORAL
                    temp = NULL;//POR SEGURIDAD LO IGUALO A NULL
                    eliminado = true;
                    this->elementos--;
                    return eliminado;
                }
                else//EN CUALQUIER OTRO CASO ME ENCUENTRO EN MEDIO DE LA LISTA
                {
                    antTemp->next = temp->next;
                    free(temp);
                    temp == NULL;
                    this->elementos--;
                    eliminado = true;
                    return eliminado;
                }
            }
            antTemp = temp;//MUEVO EL ANTERIOR
            temp = temp->next;//MUEVO EL TEMPORAL
        }
    }
    return eliminado;
}

//RETORNA EL NUMERO DE ELEMENTOS EN LISTA
int ListaCanciones::count()
{
    return this->elementos;
}

//GENERA LA VALORACIÓN DEL ALBUM DE CANCIONES
float ListaCanciones::valoracionAlbum()
{
    if(!estaVacia())
    {
        float promedio = 0;
        float acumulado = 0;
        NodoCancion *aux = this->first;
        while (aux!=NULL) {
           acumulado = acumulado + aux->song->valoracion;
           aux = aux->next;
        }
        promedio = acumulado / this->elementos;
        return promedio;
    }
    else
    {
        return 0;
    }
}
