#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include"nodo.h"


class ListaDobleCircular
{
public:
    ListaDobleCircular();
    Nodo *primero;
    int elementos;
    bool eliminado;
    void p_insertar(Nodo *nuevo);
    void p_imprimir();
    void p_eliminar(std::string pal);
private:
    int tipo = 0;
    void imprimirLista(Nodo *siguiente);
    void eliminar(Nodo *aux, std::string pal);
    Nodo *recorre_encuentra(Nodo *recorre, std::string pal);
    bool estaVacia();
};

#endif // LISTADOBLECIRCULAR_H
