#ifndef AVLTREE_H
#define AVLTREE_H
#include "NodoAVL.h"
#include <fstream>
#include <iostream>

class AVLTree
{
    public:
        NodoAVL *root;
        AVLTree();
        void addToTree(Catedratico *catedratico);
        void graphTree();
        void deleteFromTree(int id);
        void updateCatedratico(int id, std::string nombre, std::string direccion);
        Catedratico *buscarCatedratico(int id);
    private:
        Catedratico *searchCatedratico(int id, NodoAVL *raiz);
        void graficaRamas(std::ofstream &archivo, NodoAVL *raiz);
        void actualizaCatedratico(int id, Catedratico *nuevo, NodoAVL *raiz);
        int height(NodoAVL *n);
        int maximo(int a, int b);
        NodoAVL *rotacionDerecha(NodoAVL *y);
        NodoAVL *rotacionIzquierda(NodoAVL *x);
        int obtenerFE(NodoAVL *n);
        NodoAVL *insertarNodo(NodoAVL *raiz, Catedratico *catedratico);
        NodoAVL *deleteNode(int id, NodoAVL *raiz);
        NodoAVL *sucesor(NodoAVL *nodo);
};

#endif // AVLTREE_H
