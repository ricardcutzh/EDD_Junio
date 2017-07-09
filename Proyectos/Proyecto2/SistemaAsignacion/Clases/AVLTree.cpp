#include "AVLTree.h"

AVLTree::AVLTree()
{
    this->root = NULL;
}

//OBTENER LA ALTURA DE UN NODO EN ESPECÍFICO
int AVLTree::height(NodoAVL *n)
{
    if(n==NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}

//FUNCION MAXIMO
int AVLTree::maximo(int a, int b)
{
    return (a > b) ? a : b;
}

NodoAVL *AVLTree::rotacionDerecha(NodoAVL *y)
{
    NodoAVL *x = y->left;
    NodoAVL *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = maximo(height(y->left), height(y->right))+1;
    x->height = maximo(height(x->left), height(x->right))+1;
    return x;
}

NodoAVL *AVLTree::rotacionIzquierda(NodoAVL *x)
{
    NodoAVL *y = x->right;
    NodoAVL *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = maximo(height(x->left),height(x->right))+1;
    y->height = maximo(height(y->left),height(y->right))+1;
    return y;
}

int AVLTree::obtenerFE(NodoAVL *n)
{
    if(n==NULL)
    {
        return 0;
    }
    else
    {
        return height(n->left) - height(n->right);
    }
}

void AVLTree::addToTree(Catedratico *catedratico)
{
    this->root = insertarNodo(this->root, catedratico);
}

NodoAVL *AVLTree::insertarNodo(NodoAVL *raiz, Catedratico *catedratico)
{
    if(raiz == NULL)
    {
        return new NodoAVL(catedratico);
    }
    if(catedratico->id < raiz->catedratico->id)
    {
        raiz->left = insertarNodo(raiz->left, catedratico);
    }
    else if(catedratico->id > raiz->catedratico->id)
    {
        raiz->right = insertarNodo(raiz->right, catedratico);
    }
    raiz->height = 1 + maximo(height(raiz->left), height(raiz->right));
    int balance = obtenerFE(raiz);
    //CASO 1 DE BALANCE: IZQUIERDA IZQUIERDA
    if(balance > 1 && catedratico->id < raiz->left->catedratico->id)
    {
        return rotacionDerecha(raiz);
    }
    //CASO 2 DE BALANCE DERECHA DERECHA
    if( balance < -1 && catedratico->id  > raiz->right->catedratico->id )
    {
        return rotacionIzquierda(raiz);
    }
    //CASO 3 IZQUIERDA DERECHA
    if( balance > 1 && catedratico->id > raiz->left->catedratico->id)
    {
        raiz->left = rotacionIzquierda(raiz->left);
        return rotacionDerecha(raiz);
    }
    //CASO 4 DERECHA IZQUIERDA
    if( balance < -1 && catedratico->id < raiz->right->catedratico->id )
    {
        raiz->right = rotacionDerecha(raiz->right);
        return rotacionIzquierda(raiz);
    }
    //EN CUALQUIER OTRO CASO:
    return raiz;
}

void AVLTree::graphTree()
{
    std::ofstream archivo;
    archivo.open("AVL.dot");
    if(archivo.fail())
    {
        return;
    }
    else
    {
        archivo << "digraph g {" << std::endl;
        graficaRamas(archivo, this->root);
        archivo << "}";
        archivo.close();
    }
}

void AVLTree::graficaRamas(std::ofstream &archivo, NodoAVL *raiz)
{
    if(raiz!=NULL)
    {
        archivo << "\"id: " << raiz->catedratico->id << " | Nom: " << raiz->catedratico->nombre << "\";" << std::endl;
        if(raiz->left!=NULL)
        {
            archivo << "\"id: " << raiz->catedratico->id << " | Nom: " << raiz->catedratico->nombre << "\"->\"id: " << raiz->left->catedratico->id << " | Nom: " << raiz->left->catedratico->nombre << "\";" << std::endl;
        }
        if(raiz->right!=NULL)
        {
            archivo << "\"id: " << raiz->catedratico->id << " | Nom: " << raiz->catedratico->nombre << "\"->\"id: " << raiz->right->catedratico->id << " | Nom: " << raiz->right->catedratico->nombre << "\";" << std::endl;
        }
        graficaRamas(archivo, raiz->left);
        graficaRamas(archivo, raiz->right);
    }
}

void AVLTree::deleteFromTree(int id)
{
    this->root = deleteNode(id, this->root);
}

NodoAVL *AVLTree::deleteNode(int id, NodoAVL *raiz)
{
    if(raiz == NULL)
    {
        return raiz;
    }
    if(id < raiz->catedratico->id)
    {
        raiz->left = deleteNode(id, raiz->left);
    }
    else if(id > raiz->catedratico->id)
    {
        raiz->right = deleteNode(id, raiz->right);
    }
    else
    {
        if( (raiz->left==NULL) || (raiz->right == NULL) )
        {
            NodoAVL *temp = NULL;
            if(temp == raiz->left)
            {
                temp = raiz->right;
            }
            else
            {
                temp = raiz->left;
            }
            if(temp == NULL)
            {
                temp = raiz;
                raiz = NULL;
            }
            else
            {
                raiz = temp;
            }
        }
        else
        {
            NodoAVL *temp = sucesor(raiz->right);
            raiz->catedratico = new Catedratico(temp->catedratico->id, temp->catedratico->nombre, temp->catedratico->direccion);
            raiz->right = deleteNode(temp->catedratico->id, raiz->right);
        }
    }
    if(raiz == NULL)
    {
        return raiz;
    }
    raiz->height = maximo(height(raiz->left), height(raiz->right));
    int balance = obtenerFE(raiz);
    //izq izq
    if(balance > 1 && obtenerFE(raiz->left) >= 0)
    {
        return rotacionDerecha(raiz);
    }
    //izq der
    if(balance > 1 && obtenerFE(raiz->left) < 0)
    {
        raiz->left = rotacionIzquierda(raiz->left);
        return rotacionDerecha(raiz);
    }
    //der der
    if(balance < -1 && obtenerFE(raiz->right) <= 0)
    {
        return rotacionIzquierda(raiz);
    }
    //der izq
    if(balance < -1 && obtenerFE(raiz->right) > 0 )
    {
        raiz->right = rotacionDerecha(raiz->right);
        return rotacionIzquierda(raiz);
    }
    return raiz;
}

NodoAVL *AVLTree::sucesor(NodoAVL *nodo)
{
    NodoAVL *aux = nodo;
    while(aux->left!=NULL)
    {
        aux = aux->left;
    }
    return aux;
}

void AVLTree::updateCatedratico(int id, std::string nombre, std::string direccion)
{
    Catedratico *nuevo = new Catedratico(id,nombre,direccion);
    actualizaCatedratico(id, nuevo, this->root);
}

void AVLTree::actualizaCatedratico(int id, Catedratico *nuevo, NodoAVL *raiz)
{
    if(raiz!=NULL)
    {
        if(raiz->catedratico->id == id)
        {
            raiz->catedratico = NULL;
            raiz->catedratico = nuevo;
            return;
        }
        actualizaCatedratico(id, nuevo, raiz->left);
        actualizaCatedratico(id, nuevo, raiz->right);
    }
}

Catedratico *AVLTree::buscarCatedratico(int id)
{
    return searchCatedratico(id, this->root);
}

Catedratico *AVLTree::searchCatedratico(int id, NodoAVL *raiz)
{
    if(raiz!=NULL)
    {
        if(raiz->catedratico->id == id)
        {
            return raiz->catedratico;
        }
        if(id < raiz->catedratico->id)
        {
            return searchCatedratico(id, raiz->left);
        }
        else if(id > raiz->catedratico->id)
        {
            return searchCatedratico(id, raiz->right);
        }
    }
    return NULL;
}
