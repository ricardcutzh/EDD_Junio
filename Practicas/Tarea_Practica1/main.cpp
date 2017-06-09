#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include"varios.h"
#include"nodo.h"
#include"listadoblecircular.h"
#include<cstring>
#define PATH "C:\\TareaP1\\"

using namespace std;

ListaDobleCircular *lista;
int main()
{
    lista = new ListaDobleCircular();
    inicio();
    return 0;
}

//inicio del programa
void inicio()
{
    int opcion = 0;
    string filename;
    string elim;
    while((opcion = menu_opciones())!=4)
    {
        switch (opcion) {
        case 1:

            cout << "-----------------------------------" << endl;
            cout << "Ingresa el nombre del archivo: ";
            cin >> filename;
            cout << "-------------------------------" << endl;
            leerFile(filename);
            cout << "| Archivo Leido Correctamente" << endl;
            cout << "| Total de Palabras en Lista: " << lista->elementos << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "| Desplegando Lista:  |" << endl;
            lista->p_imprimir();
            cout << "| Fin Lista           |" << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "-----------------------------------" << endl;
            cout << "Ingresa la Palabra a Eliminar: ";
            cin >> elim;
            cout << "-------------------------------" << endl;
            lista->p_eliminar(elim);
            if(lista->eliminado)
            {
                cout << "-----------------------------------" << endl;
                cout << "Elemento Eliminado.."<< endl;
                cout << "-------------------------------" << endl;
            }
            else
            {
                cout << "-----------------------------------" << endl;
                cout << "No se elimino la palabra: "<< elim<<endl;
                cout << "-------------------------------" << endl;
            }
            system("pause");
            system("cls");
            break;
        default:
            cout << "Opcion Invalida..."<< endl;
            system("pause");
            system("cls");
            break;
        }
    }
    cout << "Fin de Ejecucion"<< endl;
}

//menu del programa
int menu_opciones()
{
    int opcion = 0;
    printf(" ------------------------------------\n");
    printf("|  Bienvenido: Tarea Practica 1      |\n");
    printf(" ------------------------------------\n");
    printf("| 1. Leer archivo                    |\n");
    printf("| 2. Desplegar Listado de Palabras   |\n");
    printf("| 3. Eliminar una palabra            |\n");
    printf("| 4. Salir                           |\n");
    printf("|------------------------------------|\n");
    printf("| Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

//Lectura del Archivo de Texto definido en el PATH | inserta en la lista doble
void leerFile(string nombre)
{
    ifstream arch(PATH+nombre);
    if(!arch.is_open())
    {
        cout << "Ocurrio un error al leer el archivo: " << nombre << endl;
    }
    else
    {
        string palabra;
        while(arch.good())
        {
            getline(arch, palabra, '_');
            Nodo *nuevo = new Nodo(palabra);
            lista->p_insertar(nuevo);
        }
    }
    arch.close();
}
