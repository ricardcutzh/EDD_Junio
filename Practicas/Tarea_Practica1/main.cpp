#include <iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include"varios.h"

using namespace std;


int main()
{
    inicio();
    return 0;
}

//inicio del programa
void inicio()
{
    int opcion = 0;
    int valor = 0;
    while((opcion = menu_opciones())!=4)
    {
        switch (opcion) {
        case 1:
            cout << "Has escogido leer un archivo..." << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Has escogido Desplegar la Lista..." << endl;
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Has escogido Eliminar de la Lista..."<< endl;
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
    printf("|------------------------------------|\n");
    printf("| Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

