#include "listalinealizacion.h"

ListaLinealizacion::ListaLinealizacion(std::string tipo)
{
    this->first = NULL;
    this->tipo = tipo;
    this->elementos = 0;
}

ListaLinealizacion::~ListaLinealizacion()
{
    while(this->elementos>0)
    {
        eliminarPrimero();
    }
}

void ListaLinealizacion::agregar(NodoLinealizacion *nuevo)
{
    if(this->first==NULL)
    {
        this->first = nuevo;
        this->elementos++;
        //std::cout << "inseratado " << elementos << std::endl;
    }
    else
    {
        NodoLinealizacion *aux = this->first;
        while(aux->siguiente!=NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        this->elementos++;
        //std::cout << "insertado " << elementos << std::endl;
    }
}

void ListaLinealizacion::eliminarPrimero()
{
    if(this->first!=NULL)
    {
        NodoLinealizacion *temp = this->first;
        this->first = this->first->siguiente;
        delete temp;
        this->elementos--;
    }
}

bool ListaLinealizacion::generaElGrafo()
{
    std::ofstream archivo("Linealizacion.dot");
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        if(this->elementos>0)
        {
            archivo << "digraph g{" << std::endl;
            archivo << "label=\"" << this->tipo << "\";" << std::endl;
            NodoLinealizacion *aux = this->first;
            while(aux!=NULL)
            {
                archivo << "\"" << aux->nombrePieza << "\";" << std::endl;
                if(aux->siguiente!=NULL)
                {
                    archivo << "\"" << aux->nombrePieza <<"\"->\"" << aux->siguiente->nombrePieza << "\";" << std::endl;
                }
                aux = aux->siguiente;
            }
            archivo << "}";
            archivo.close();
            system("dot -Tpng Linealizacion.dot -o Linealizacion.png");
            return true;
        }
        else
        {
            return false;
        }
    }
}

void ListaLinealizacion::verLista()
{
    NodoLinealizacion *aux = this->first;
    while(aux!=NULL)
    {
        std::cout << aux->nombrePieza << std::endl;
        aux = aux->siguiente;
    }
}
