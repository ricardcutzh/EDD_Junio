#include "funciones.h"
ABBPlayers *PlayersTree;
ListaTopPlayers *topPlayers;
MatrizOrtogonal *matriz;

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

//GRAFICA LA LISTA DE LOS TOP 10 JUGADORES
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

void inicializarMatriz()
{
    matriz = new MatrizOrtogonal();
    insertaNivel0Negros();
    insertaNivel0Blancos();
}

void insertaNivel0Negros()
{
    //INSERTANDO CABALLOS NEGROS
    Pieza *caballo1 = new Pieza("Caballo-N-1", "Caballo 1");
    caballo1->color = "Negro";
    Pieza *caballo2 = new Pieza("Caballo-N-2", "Caballo 2");
    caballo2->color = "Negro";
    matriz->insertarEnMatriz(1,1,0,caballo1);
    matriz->insertarEnMatriz(8,1,0,caballo2);
    //INSERTANDO ALFILES NEGROS
    Pieza *alfil1 = new Pieza("Alfil-N-1", "Alfil 1");
    alfil1->color = "Negro";
    Pieza *alfil2 = new Pieza("Alfil-N-2", "Alfil 2");
    alfil2->color = "Negro";
    matriz->insertarEnMatriz(2,1,0,alfil1);
    matriz->insertarEnMatriz(7,1,0,alfil2);
    //INSERTANDO TORRES
    Pieza *torre1 = new Pieza("Torre-N-1", "Torre 1");
    torre1->color = "Negro";
    Pieza *torre2 = new Pieza("Torre-N-2", "Torre 2");
    torre2->color = "Negro";
    matriz->insertarEnMatriz(3,1,0,torre1);
    matriz->insertarEnMatriz(6,1,0,torre2);
    //INSERTANDO REY Y REYNA
    Pieza *dama = new Pieza("Dama-N", "Dama");
    dama->color = "Negro";
    Pieza *rey = new Pieza("Rey-N","Rey");
    rey->color = "Negro";
    matriz->insertarEnMatriz(5,1,0,dama);
    matriz->insertarEnMatriz(4,1,0,rey);
    //INSERTANDO PEONES
    for(int i = 1; i <= 8; i++)
    {
        std::string n = std::to_string(i);
        Pieza *peon = new Pieza("Peon-N-"+n,"Peon "+n);
        peon->color = "Negro";
        matriz->insertarEnMatriz(i,2,0,peon);
    }
}

void insertaNivel0Blancos()
{
    //INSERTANDO CABALLOS NEGROS
    Pieza *caballo1 = new Pieza("Caballo-B-1", "Caballo 1");
    caballo1->color = "Blanco";
    Pieza *caballo2 = new Pieza("Caballo-B-2", "Caballo 2");
    caballo2->color = "Blanco";
    matriz->insertarEnMatriz(1,8,0,caballo1);
    matriz->insertarEnMatriz(8,8,0,caballo2);
    //INSERTANDO ALFILES NEGROS
    Pieza *alfil1 = new Pieza("Alfil-B-1", "Alfil 1");
    alfil1->color = "Blanco";
    Pieza *alfil2 = new Pieza("Alfil-B-2", "Alfil 2");
    alfil2->color = "Blanco";
    matriz->insertarEnMatriz(2,8,0,alfil1);
    matriz->insertarEnMatriz(7,8,0,alfil2);
    //INSERTANDO TORRES
    Pieza *torre1 = new Pieza("Torre-B-1", "Torre 1");
    torre1->color = "Blanco";
    Pieza *torre2 = new Pieza("Torre-B-2", "Torre 2");
    torre2->color = "Blanco";
    matriz->insertarEnMatriz(3,8,0,torre1);
    matriz->insertarEnMatriz(6,8,0,torre2);
    //INSERTANDO REY Y REYNA
    Pieza *dama = new Pieza("Dama-B", "Dama");
    dama->color = "Blanco";
    Pieza *rey = new Pieza("Rey-B","Rey");
    rey->color = "Blanco";
    matriz->insertarEnMatriz(5,8,0,dama);
    matriz->insertarEnMatriz(4,8,0,rey);
    //INSERTANDO PEONES
    for(int i = 1; i <= 8; i++)
    {
        std::string n = std::to_string(i);
        Pieza *peon = new Pieza("Peon-B-"+n,"Peon "+n);
        peon->color = "Blanco";
        matriz->insertarEnMatriz(i,7,0,peon);
    }
}

//MANDA A LLAMAR LOS METODOS DE LA MATRIZ GRAFICAR
bool generaGrafoMatriz(int nivel)
{
    return matriz->generaDotMatriz(nivel);
}
