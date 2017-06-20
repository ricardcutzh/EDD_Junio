#include "funciones.h"
ABBPlayers *PlayersTree;
ListaTopPlayers *topPlayers;

//INICIALIZA ARBOL
void inicializaArbol()
{
    PlayersTree = new ABBPlayers();
    topPlayers = new ListaTopPlayers();
}

//AQUI ESTARAN LAS FUNCIONES DEL JUEGO
bool leerArchivoDeJugadores(std::string ruta)
{
    std::ifstream archivo(ruta);
    if(!archivo.is_open())
    {
        return false;
    }
    else
    {
        std::string nombre;
        std::string parGan;
        std::string parPer;
        while(archivo.good())
        {
            std::string aux;
            std::getline(archivo, nombre, '_');
            std::getline(archivo, parGan, '_');
            std::getline(archivo, parPer, ';');
            //INSERTANDO DATOS AL ARBOL
            insertaDatos(nombre, parGan, parPer);
            std::getline(archivo, aux, '\n');
        }
    }
    archivo.close();
    return true;
}

//METODO PARA INSERTAR DIRECTO AL ARBOL
void insertaDatos(std::string nombre, std::string pg, std::string pp)
{
    //CONVERSIÓN DE STRING A INT
    short int pa_g = std::stoi(pg);
    short int pa_p = std::stoi(pp);
    //CREANDO NUEVO JUGADOR
    Jugador *pl = new Jugador(nombre, pa_g, pa_p);
    if(PlayersTree->insertarABB(pl))
    {
        //SI LO LOGRA INSERTAR:
        std::cout << "insertando a: " << nombre << std::endl;
    }
    else
    {
        //SI NO SE PUEDE...
        std::cout << "no se inserto a: " << nombre << std::endl;
    }
}

//METODO PARA GRAFICAR EL ARBOL
bool graficameArbol()
{
    return PlayersTree->graphTree();
}

//METODO PARA ELIMINAR UN JUGADOR
bool eliminaJugador(std::string nombre)
{
    return PlayersTree->eliminarABB(nombre);
}

//SOLO VERIFICA SI EL ARBOL ESTA VACÍO
bool verSiArbolEstaVacio()
{
    return PlayersTree->vacio();
}

//OBTIENE LA ALTURA DEL ARBOL
int getTreeHeight()
{
    return PlayersTree->TreeHeight();
}

//GENERA LOS TOP QUE SE ENCUENTRA EN EL ARBOL ACTUAL
void generaTops()
{
    delete topPlayers;
    topPlayers = new ListaTopPlayers();
    generaTopsR(PlayersTree->root);
}

//METODO RECURSIVO QUE SE ENCARGA DE RECORRER EL ARBOL
void generaTopsR(NodoJugador *raiz)
{
    if(raiz!=NULL)
    {
        NodoTop *nuevo = new NodoTop(raiz->player->nombre, raiz->player->p_ganadas);
        topPlayers->add(nuevo);
        generaTopsR(raiz->left);
        generaTopsR(raiz->right);
    }
}

bool graficameListaTops()
{
    std::ofstream archivo;
    archivo.open("TopPlayers.dot");
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        topPlayers->escribirDotTop(archivo);
        archivo.close();
        system("dot -Tpng TopPlayers.dot -o TopPlayers.png");
        //actualizarArbol();
        return true;
    }
}
