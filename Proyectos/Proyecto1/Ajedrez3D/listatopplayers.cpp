#include "listatopplayers.h"

ListaTopPlayers::ListaTopPlayers()
{
    this->elementos = 0;
    this->raiz = new NodoTop("root", 0);
}
ListaTopPlayers::~ListaTopPlayers()
{
    delete this->raiz;
}

bool ListaTopPlayers::yaExiste(std::string nombre)
{
    if(this->elementos == 0)
    {
        return false;
    }
    else
    {
        NodoTop *temp = this->raiz->siguiente;
        std::string compa;
        while(temp!=NULL)
        {
            compa = temp->nombre;
            if(nombre.compare(compa)==0)
            {
                return true;
            }
            temp = temp->siguiente;
        }
    }
    return false;
}

void ListaTopPlayers::add(NodoTop *nuevo)
{
    if(!yaExiste(nuevo->nombre))
    {
        if(this->elementos == 0)
        {
            this->raiz->siguiente = nuevo;
            nuevo->anterior = this->raiz;
            this->elementos++;
        }
        else
        {
            int tipo = 0;
            NodoTop *aux = this->raiz->siguiente;
            while(aux!=NULL)
            {
                if(nuevo->victorias > aux->victorias)
                {
                    tipo = 1;
                    break;
                }
                if(aux->siguiente == NULL)
                {
                    break;
                }
                aux = aux->siguiente;
            }
            if(tipo==1)
            {
                aux->anterior->siguiente = nuevo;
                nuevo->anterior = aux->anterior;
                nuevo->siguiente = aux;
                aux->anterior = nuevo;
                this->elementos = this->elementos+1;
            }
            else
            {
                aux->siguiente = nuevo;
                nuevo->anterior = aux;
                this->elementos = this->elementos+1;
            }
        }
        if(this->elementos>10)
        {
            //ELIMINA EL ULTIMO
            eliminaUltimo();
        }
    }
}

void ListaTopPlayers::eliminaUltimo()
{
    NodoTop *temp = this->raiz->siguiente;
    while(temp->siguiente!=NULL)
    {
        temp = temp->siguiente;
    }
    temp->anterior->siguiente = NULL;
    free(temp);
    temp = NULL;
    this->elementos--;
}

void ListaTopPlayers::escribirDotTop(std::ofstream &archivo)
{
    archivo << "digraph top{" << std::endl;
    archivo << "node [shape=box];" << std::endl;
    archivo << "label=\"Top 10" << " Players " << "\";" << std::endl;
    NodoTop *aux = this->raiz->siguiente;
    while(aux!=NULL)
        {
            if(aux->siguiente!=NULL)
            {
                archivo << "\"Nombre: " << aux->nombre << " | Vic: " << aux->victorias << "\"->\"Nombre: " << aux->siguiente->nombre << " | Vic: " << aux->siguiente->victorias << "\";" << std::endl;
            }
            else
            {
                archivo << "\"Nombre: " << aux->nombre << " | Vic: " << aux->victorias << "\";" << std::endl;
            }
            aux = aux->siguiente;
        }
    sameRank(archivo);
    archivo << "}" << std::endl;
}

void ListaTopPlayers::sameRank(std::ofstream &archivo)
{
    archivo << "{rank=same;";
    NodoTop *aux = this->raiz->siguiente;
    while(aux!=NULL)
    {
        archivo << "\"Nombre: " << aux->nombre << " | Vic: " << aux->victorias <<"\";";
        aux = aux->siguiente;
    }
    archivo << "}" << std::endl;
}
