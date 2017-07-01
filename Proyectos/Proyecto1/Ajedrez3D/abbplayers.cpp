#include "abbplayers.h"

/*ARBOL DE BUSQUEDADA BINARIA DE JUGADORES ORDENADOS POR NOMBRE*/

//CONSTRUCTOR DEL ARBOL;
ABBPlayers::ABBPlayers()
{
    this->root = NULL;
    this->nodosHoja = 0;
    this->nodosRama = 0;
}

//DESTRUCTOR DEL ARBOL
ABBPlayers::~ABBPlayers()
{
    delete this->root;
    //delete this->nodosHoja;
    //delete this->nodosRama;
    //delete this->eliminado;
    //delete this->insertado;
}

//METODO PARA INSERTAR EN EL ARBOL (PUBLICO)
bool ABBPlayers::insertarABB(Jugador *nuevo)
{
    this->insertado = false;
    this->root = insertarABBP(this->root, nuevo);
    return this->insertado;
}

//METODO PARA INSERTAR ELEMENTOS EN EL ARBOL (PRIVADO)
NodoJugador *ABBPlayers::insertarABBP(NodoJugador *raiz, Jugador *nuevo)
{
    if(raiz == NULL)
    {
        raiz = new NodoJugador(nuevo);
        this->insertado = true;
    }
    else if(nuevo->nombre.compare(raiz->player->nombre)<0)
    {
        NodoJugador* izq;
        izq = insertarABBP(raiz->left, nuevo);
        raiz->left = izq;
    }
    else if(nuevo->nombre.compare(raiz->player->nombre)>0)
    {
        NodoJugador* der;
        der = insertarABBP(raiz->right, nuevo);
        raiz->right = der;
    }
    else
    {
        this->insertado = false;
    }
    return raiz;
}

//METODO PARA ELIMINAR DEL ARBOL (PUBLICO)
bool ABBPlayers::eliminarABB(std::string nombre)
{
    this->eliminado = false;
    this->root = eliminarABBP(this->root, nombre);
    return this->eliminado;
}

//METODO PARA ELIMINAR (PRIVADO)
NodoJugador* ABBPlayers::eliminarABBP(NodoJugador *subarbol, std::string nombre)
{
    if(subarbol == NULL)
    {
        //EL NODO ES NULO OSEA NO LO ENCONTRO Y NO LO ELIMINA
        this->eliminado = false;
    }
    else if(nombre.compare(subarbol->player->nombre)>0)
    {
        //SI EL NODO FUESE MAYOR ELIMINA POR LA DERECHA
        NodoJugador *der;
        der = eliminarABBP(subarbol->right, nombre);
        subarbol->right = der;
    }
    else if(nombre.compare(subarbol->player->nombre)<0)
    {
        //SI EL NODO FUESE MENOR ELIMINA POR LA IZQUIERDA
        NodoJugador *izq;
        izq = eliminarABBP(subarbol->left, nombre);
        subarbol->left = izq;
    }
    else
    {
        //CUANDO LO ENCUENTRA.. ELIMINA
        NodoJugador *aux;
        aux = subarbol;
        if( aux->left == NULL)
        {
            subarbol = aux->right;
        }
        else if(aux->right == NULL)
        {
            subarbol = aux->left;
        }
        else
        {
            aux = replace(aux);
        }
        //delete aux;
        aux = NULL;
        this->eliminado = true;
    }
    return subarbol;
}

//METODO SE ENCARGA DE EL REEMPLAZO PARA LA ELIMINACIÓN DEL NODO
NodoJugador *ABBPlayers::replace(NodoJugador *actual)
{
    NodoJugador *a, *p;
    p = actual;
    a = actual->left;
    while(a->right!=NULL)
    {
        p = a;
        a = a->right;
    }
    //Jugador *reemplazo = new Jugador(a->player->nombre, a->player->p_ganadas, a->player->p_perdidas);
    //actual->player = reemplazo;
    actual->player = a->player;
    if(p == actual)
    {
        p->left = a->left;
    }
    else
    {
        p->right = a->left;
    }
    return a;
}

//METODO PUBLICO PARA ACCEDER A OBTENER LA ALTURA DEL ARBOL
int ABBPlayers::TreeHeight()
{
    return obtenerAltura(this->root);
}

//METODO PRIVADO PARA CALCULAR ALTURA RECURSIVO
int ABBPlayers::obtenerAltura(NodoJugador *subarb)
{
    if(subarb == NULL)
    {
        return 0;
    }
    else
    {
        int alturader = obtenerAltura(subarb->right);
        int alturaizq = obtenerAltura(subarb->left);
        if(alturaizq > alturader)
        {
            return alturaizq + 1;
        }
        else
        {
            return alturader + 1;
        }
    }
}

//METODO PRIVADO SI EVALUA SI ES HOJA EL NODO
bool ABBPlayers::EsHoja(NodoJugador *raiz)
{
    if(raiz->left == NULL && raiz->right == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//METODO QUE SE ENCARGA DE OBTENER EL NUMERO DE HOJAS Y RAMAS EN EL ARBOL
void ABBPlayers::evaluaArbol(NodoJugador *raiz)
{
    if(raiz!=NULL)
    {
        if(EsHoja(raiz))
        {
            this->nodosHoja = this->nodosHoja+1;
        }
        else
        {
            this->nodosRama = this->nodosRama+1;
        }
        evaluaArbol(raiz->left);
        evaluaArbol(raiz->right);
    }
}

//METODO QUE INICIALIZA LA EVALUACIÓN DEL ARBOL PARA ACTUALIZARLO
void ABBPlayers::actualizarArbol()
{
    this->nodosHoja = 0;
    this->nodosRama = 0;
    evaluaArbol(this->root);
}

//METODO PUBLICO PARA GRAFICAR EL ARBOL
bool ABBPlayers::graphTree()
{
    std::ofstream archivo;
    archivo.open("ABB.dot");
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        actualizarArbol();
        this->nodosRama = this->nodosRama-1;
        archivo << "digraph ABB{" << std::endl;
        archivo << "label=\"Nodos Hoja: " <<this->nodosHoja << " Nodos Rama: " << this->nodosRama << "\";" << std::endl;
        graphTreeP(archivo,this->root);
        archivo << "}" << std::endl;
        archivo.close();
        system("dot -Tpng ABB.dot -o ABB.png");
        //actualizarArbol();
        return true;
    }
}

//METODO PRIVADO QUE SE HACE CARGO DE LA RECURSIVIDAD AL RECORRER EL ARBOL Y ESCRIBIR EL ARCHIVO
void ABBPlayers::graphTreeP(std::ofstream &archivo, NodoJugador *raiz)
{
    if(raiz!=NULL)//SI HAY ALGO EN EL NODO LO ESCRIBO
    {
        archivo << "\"" << raiz->player->nombre << "\";" << std::endl;
        if(raiz->left != NULL)
        {
            //SI HAY HIJO DERECHO LO ESCRIBO
            archivo << "\"" << raiz->player->nombre << "\"->\"" << raiz->left->player->nombre << "\";" << std::endl;
        }
        if(raiz->right != NULL)
        {
            //SI HAY HIJO IZQUIERDO LO ESCRIBO
            archivo << "\"" << raiz->player->nombre << "\"->\"" << raiz->right->player->nombre << "\";" << std::endl;
        }
        graphTreeP(archivo, raiz->left);//MUEVO RECURSIVAMENTE HACIA LA IZQUIERDA
        graphTreeP(archivo, raiz->right);//MUEVO RECURSIVAMENTE HACIA LA DERECHA
    }
}

//VE SI EL ARBOL ESTA VACIO
bool ABBPlayers::vacio()
{
    if(this->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
