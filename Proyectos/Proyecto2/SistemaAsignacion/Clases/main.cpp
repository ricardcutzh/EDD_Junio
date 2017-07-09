#include <iostream>
#include "AVLTree.h"
#include "Catedratico.h"
#include "BTree.h"
#include "Horario.h"
#include "Salon.h"
#include "Curso.h"
#include "Catedratico.h"
#include "TablaHash.h"

using namespace std;

int main()
{
    /*Catedratico *n = new Catedratico(1,"juea","dir");
    Salon *s = new Salon(10, 100);
    Curso *c = new Curso(777, "mate",1,10);
    BTree *arbolb = new BTree();
    Horario *n1 = new Horario(6, "rango1", "dia1",s,n,c);
    Horario *n2 = new Horario(11, "rango2", "dia2",s,n,c);
    Horario *n3 = new Horario(5, "rango3", "dia3",s,n,c);
    Horario *n4 = new Horario(4, "rango4", "dia4",s,n,c);
    Horario *n5 = new Horario(8, "rango5", "dia5",s,n,c);
    Horario *n6 = new Horario(9, "rango6", "dia6",s,n,c);
    Horario *n7 = new Horario(12, "rango7", "dia7",s,n,c);
    Horario *n8 = new Horario(21, "rango8", "dia8",s,n,c);
    arbolb->insertarNuevoHorario(n1);
    arbolb->insertarNuevoHorario(n2);
    arbolb->insertarNuevoHorario(n3);
    arbolb->insertarNuevoHorario(n4);
    arbolb->insertarNuevoHorario(n5);
    arbolb->insertarNuevoHorario(n6);
    arbolb->insertarNuevoHorario(n7);
    arbolb->insertarNuevoHorario(n8);
    Horario *np = new Horario(9, "EL 11", "FUE EDITADO",s,n,c);
    arbolb->editarHorario(9,np);
    Horario *bus = arbolb->buscarHorario(5);
    arbolb->graficarArbol();
    if(bus!=NULL)
    {
        std::cout << "NP: " << bus->dia << " | " << bus->rango << "  codigo: " << bus->codigo << std::endl;
    }
    //*/

    TablaHash *tabla = new TablaHash();
    Estudiante *es = new Estudiante(201513696,"Joseph","dir");
    Estudiante *es1 = new Estudiante(201504100,"Chris","dir");
    Estudiante *es2 = new Estudiante(201504444,"Christian","dir");
    Estudiante *es3 = new Estudiante(201503476,"Ricardo","dir");
    Estudiante *es4 = new Estudiante(201504272,"Augusto","dir");
    Estudiante *es5 = new Estudiante(200718932,"Anonimo1","dir");
    Estudiante *es6 = new Estudiante(201503440,"Anonimo2","dir");
    Estudiante *es7 = new Estudiante(201503464,"Anonimo3","dir");
    Estudiante *es8 = new Estudiante(201504284,"Anonimo4","dir");
    Estudiante *es9 = new Estudiante(201000284,"Anonimo5","dir");
    Estudiante *es10 = new Estudiante(201513858,"Anonimo6","dir");
    Estudiante *es11 = new Estudiante(201513747,"Anonimo7","dir");
    Estudiante *es12 = new Estudiante(201513758,"Anonimo8","dir");
    Estudiante *es13 = new Estudiante(201513634,"Anonimo9","dir");
    Estudiante *es14 = new Estudiante(201513629,"Anonimo10","dir");
    Estudiante *es15 = new Estudiante(201504420,"Anonimo11","dir");
    Estudiante *es16 = new Estudiante(201504399,"Anonimo12","dir");
    Estudiante *es17 = new Estudiante(201504397,"Anonimo13","dir");
    Estudiante *es18 = new Estudiante(201504385,"Anonimo14","dir");
    Estudiante *es19 = new Estudiante(201504381,"Anonimo15","dir");
    Estudiante *es20 = new Estudiante(201504334,"Anonimo16","dir");
    Estudiante *es21 = new Estudiante(201213223,"Anonimo17","dir");
    Estudiante *es22 = new Estudiante(201313734,"Anonimo18","dir");
    Estudiante *es23 = new Estudiante(201220160,"Anonimo19","dir");
    Estudiante *es24 = new Estudiante(201313780,"Anonimo16","dir");
    tabla->insertarEnTablaHash(es);
    tabla->insertarEnTablaHash(es1);
    tabla->insertarEnTablaHash(es2);
    tabla->insertarEnTablaHash(es3);
    tabla->insertarEnTablaHash(es4);
    tabla->insertarEnTablaHash(es5);
    tabla->insertarEnTablaHash(es6);
    tabla->insertarEnTablaHash(es7);
    tabla->insertarEnTablaHash(es8);
    tabla->insertarEnTablaHash(es9);
    tabla->insertarEnTablaHash(es10);
    tabla->insertarEnTablaHash(es11);
    tabla->insertarEnTablaHash(es12);
    tabla->insertarEnTablaHash(es13);
    tabla->insertarEnTablaHash(es14);
    tabla->insertarEnTablaHash(es15);
    tabla->insertarEnTablaHash(es16);
    tabla->insertarEnTablaHash(es17);
    tabla->insertarEnTablaHash(es18);
    tabla->insertarEnTablaHash(es19);
    tabla->insertarEnTablaHash(es20);
    tabla->insertarEnTablaHash(es21);
    tabla->insertarEnTablaHash(es22);
    tabla->insertarEnTablaHash(es23);
    tabla->insertarEnTablaHash(es24);
    tabla->editarEstudiante(201503476, "EDITADO","NUEVA DIR");
    tabla->editarEstudiante(201504100, "CHRISTPPHER LOPEZ","NUEVA DIR");
    tabla->verTabla();
    NodoHash *r = tabla->buscarEstudiante(201504381);
    if(r->estudiante!=NULL)
    {
        std::cout << r->estudiante->nombre << std::endl;
    }
    std::cout << "Eliminado: " << tabla->eliminar(201504100) << std::endl;
    tabla->verTabla();
    tabla->insertarEnTablaHash(es1);
    tabla->verTabla();
    return 0;
}
