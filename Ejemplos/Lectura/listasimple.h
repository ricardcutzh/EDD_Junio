#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
typedef struct Nodo Nodo;
typedef struct Lista Lista;
typedef struct Persona Persona;

struct Persona{
    char nombre[16];
    int id;
};

struct Nodo{
    Persona persona;
    Nodo *siguiente;
};

struct Lista{
    Nodo *primero;
    Nodo *ultimo;
};

Lista* crearLista();
Nodo* crearNodo(Persona *persona);
void destruirNodo(Nodo *nodo);
void insertar(Lista *lista, Persona *persona);
void printList(Lista *lista);


#endif // LISTASIMPLE_H
