#include <iostream>
#include<fstream>
extern "C"{
    #include<listasimple.h>
}
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
    Lista *l1 = crearLista();
    ifstream arc("C:\\Users\\ricar\\Documents\\C_C++_Projects\\Lectura\\arch.txt");
    if(!arc.is_open()){
        std::cout << "Error al abrir el archivo"<<std::endl;
    }
    else{
        string nombre;
        int contador = 0;
        Persona *p = (Persona*)malloc(sizeof(Persona));
        while(arc.good()){
            getline(arc,nombre,',');
            strcpy(p->nombre, nombre.c_str());//ATRAPO LO QUE ESTA EN UN ARCHIVO Y LO ASIGNO AL ARREGLO
            p->id = contador;//CREO UN ID PARA CADA UNO DE LOS QUE ENCUENTRA EN EL ARCHIVO .TXT
            contador++;//AUMENTA EL CONTADOR
            insertar(l1, p);//INSERTO EN L1
        }
    }
    printList(l1);//IMPRIMO L1
    arc.close();//CIERRO EL ARCHIVO
    return 0;
}
