#include<stdlib.h>
#include<stdio.h>
#include<listasimple.h>
#include<string.h>

//FUNCION QUE SE ENCARGA DE DAR MEMORIA A LA LISTA
Lista* crearLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}

//FUNCION QUE SE ENCARGA DE CREARME LOS NODOS (DAR MEMORIA)
Nodo* crearNodo(Persona *persona){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevo->persona.nombre, persona->nombre);
    nuevo->persona.id = persona->id;
    nuevo->siguiente = NULL;
    return nuevo;
}

//LIBERA LA MEMORIA QUE ESTA UTILIZANDO DE UN NODO AL ELIMINAR
void destruirNodo(Nodo *nodo){
    free(nodo);
}


//INSERTA AL FINAL DE LA LISTA SIMPLE
void insertar(Lista *lista, Persona *persona){
    Nodo* nuevo = crearNodo(persona);
    if(lista->primero == NULL){
        lista->primero = nuevo;
        lista->ultimo = nuevo;
    }
    else{
        lista->ultimo->siguiente = nuevo;
        lista->ultimo = nuevo;
    }
}


//ENCARGADO DE IMPRIMIR LA LISTA EN PANTALLA
void printList(Lista *lista){
    if(lista->primero == NULL){
        printf("Lista vacia...\n");
    }
    else{
        Nodo *aux = lista->primero;
        printf("Inicio de Lista: \n");
        while(aux!=NULL){
            printf("Nombre: %s | id: %i \n", aux->persona.nombre, aux->persona.id);
            aux = aux->siguiente;
        }
        printf("Fin de Lista...\n");
    }
}


