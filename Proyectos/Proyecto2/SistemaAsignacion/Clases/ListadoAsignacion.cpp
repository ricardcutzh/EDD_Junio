#include "ListadoAsignacion.h"

ListadoAsignacion::ListadoAsignacion(int limite)
{
    this->elementos = 0;
    this->limite = limite;
    Estudiante *aux = new Estudiante(0, "root","root");
    this->root = new NodoAsignacion(aux, 0, 0);
}

bool ListadoAsignacion::estaVacia()
{
    return (this->elementos==0) ? true : false;
}

//VERIFICA SI EL CUPO SE LLENO
bool ListadoAsignacion::cupoLleno()
{
    return (this->elementos==this->limite) ? true : false;
}
//AGREGA DATOS AL LISTAD DE ASIGNACIÓN SIEMPRE Y CUANDO EL LIMITE NO SE SOBREPASA
void ListadoAsignacion::asignarEstudiante(Estudiante *estudiante, float zona, float exfinal)
{
    if(!cupoLleno())
    {
        NodoAsignacion *nuevo = new NodoAsignacion(estudiante, zona, exfinal);
        if(estaVacia())
        {
            this->root->siguiente = nuevo;
            this->elementos++;
        }
        else
        {
            NodoAsignacion *aux = this->root->siguiente;
            while(aux->siguiente!=NULL)
            {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            this->elementos++;
        }
    }
}

//ELIMINA UN NODO DE LA LISTA DE ASIGNACIÓN
bool ListadoAsignacion::desasignarEstudianteDecurso(int carnet)
{
    if(!estaVacia())
    {
        NodoAsignacion *aux = this->root;
        NodoAsignacion *elim = NULL;
        while(aux->siguiente!=NULL)
        {
            if(aux->siguiente->estudiante->carnet == carnet)
            {
                elim = aux->siguiente;
                break;
            }
            aux = aux->siguiente;
        }
        if(elim!=NULL)
        {
            aux->siguiente = elim->siguiente;
            delete elim;
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

//GRAFICA LA LISTA DE ESTUDIANTES EN LA ASIGNACIÓN DE UN CURSO ESPECÍFICO
void ListadoAsignacion::graficarAsignacion(std::ofstream &archivo, std::string nombre)
{
    if(!estaVacia())
    {
        NodoAsignacion *aux = this->root->siguiente;
        while(aux!=NULL)
        {
            archivo << "\"Est: " << aux->estudiante->carnet << " Nota: " << aux->exFinal + aux->zona << " Curso: " << nombre << "\";" << std::endl;
            if(aux->siguiente!=NULL)
            {
                archivo << "\"Est: " << aux->estudiante->carnet << " Nota: " << aux->exFinal + aux->zona << " Curso: " << nombre << "\"->\"Est: " << aux->siguiente->estudiante->carnet << " Nota: ";
                archivo << aux->siguiente->exFinal + aux->siguiente->zona << " Curso: " << nombre << "\";" << std::endl;
            }
            aux = aux->siguiente;
        }
    }
}
