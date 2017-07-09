#include "ListaCursos.h"
#include <fstream>
ListaCursos::ListaCursos()
{
    this->elementos = 0;
    Curso *p = new Curso(0,"root",0,0);
    this->root = new NodoCurso(p);
}

void ListaCursos::addCourseToList(Curso *n)
{
    NodoCurso *nuevo = new NodoCurso(n);
    if(estaVacia())
    {
        this->root->siguiente = nuevo;
        this->elementos++;
    }
    else
    {
        NodoCurso *aux = this->root->siguiente;
        while(aux->siguiente!=NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        this->elementos++;
    }
}

bool ListaCursos::deleteCourse(int codigo)
{
    if(!estaVacia())
    {
        NodoCurso *aux = this->root->siguiente;
        NodoCurso *elim = NULL;
        while(aux->siguiente!=NULL)
        {
            if(aux->siguiente->curso->codigo == codigo)
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
            this->elementos--;
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

bool ListaCursos::updateCourse(int codigo, std::string nombre, int semestre, int creditos)
{
    if(!estaVacia())
    {
        NodoCurso *aux = this->root->siguiente;
        while(aux!=NULL)
        {
            if(aux->curso->codigo == codigo)
            {
                aux->curso->nombre = nombre;
                aux->curso->semestre = semestre;
                aux->curso->creditos = creditos;
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }
    else
    {
        return false;
    }
}

bool ListaCursos::graphCourseList()
{
    std::ofstream archivo;
    archivo.open("Cursos.dot");
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        archivo << "digraph g {" << std::endl;
        archivo << "label=\"Cursos\"" << std::endl;
        NodoCurso *aux = this->root->siguiente;
        while(aux!=NULL)
        {
            archivo << "\"Cod: " << aux->curso->codigo << " | Curso: " << aux->curso->nombre << "\";" << std::endl;
            if(aux->siguiente!=NULL)
            {
                archivo << "\"Cod: " << aux->curso->codigo << " | Curso: " << aux->curso->nombre << "\"->\"Cod: " << aux->siguiente->curso->codigo << " | Curso: " << aux->siguiente->curso->nombre << "\";" << std::endl;
            }
            aux = aux->siguiente;
        }
        archivo << "}";
        archivo.close();
        return true;
    }
}

bool ListaCursos::estaVacia()
{
    return this->elementos==0 ? true : false;
}
