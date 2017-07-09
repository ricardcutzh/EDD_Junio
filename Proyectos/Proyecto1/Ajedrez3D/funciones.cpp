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
    insertarNivel1Negros();
    insertarNivel1Blancos();
    insertarNivel2Negros();
    insertarNivel2Blancos();
}

//INSERTA LAS PIEZAS EN EL NIVEL 0 (NEGROS)
void insertaNivel0Negros()
{
    //INSERTANDO CABALLOS NEGROS
    Pieza *caballo1 = new Pieza("Caballo-N-1", "PIEZAS\\FINAL-CABALLO-NEGRA.png");
    caballo1->color = "Negro";
    caballo1->typePieza = "caballo";
    Pieza *caballo2 = new Pieza("Caballo-N-2", "PIEZAS\\FINAL-CABALLO-NEGRA.png");
    caballo2->color = "Negro";
    caballo2->typePieza = "caballo";
    matriz->insertarEnMatriz(1,1,0,caballo1);
    matriz->insertarEnMatriz(8,1,0,caballo2);
    //INSERTANDO ALFILES NEGROS
    Pieza *alfil1 = new Pieza("Alfil-N-1", "PIEZAS\\FINAL-AlFIL-NEGRO.png");
    alfil1->color = "Negro";
    alfil1->typePieza = "alfil";
    Pieza *alfil2 = new Pieza("Alfil-N-2", "PIEZAS\\FINAL-AlFIL-NEGRO.png");
    alfil2->color = "Negro";
    alfil2->typePieza = "alfil";
    matriz->insertarEnMatriz(2,1,0,alfil1);
    matriz->insertarEnMatriz(7,1,0,alfil2);
    //INSERTANDO TORRES
    Pieza *torre1 = new Pieza("Torre-N-1", "PIEZAS\\FINAL-TORRE-NEGRA.png");
    torre1->color = "Negro";
    torre1->typePieza = "torre";
    Pieza *torre2 = new Pieza("Torre-N-2", "PIEZAS\\FINAL-TORRE-NEGRA.png");
    torre2->color = "Negro";
    torre2->typePieza = "torre";
    matriz->insertarEnMatriz(3,1,0,torre1);
    matriz->insertarEnMatriz(6,1,0,torre2);
    //INSERTANDO REY Y REYNA
    Pieza *dama = new Pieza("Dama-N", "PIEZAS\\FINAL-REYNA-NEGRO.png");
    dama->color = "Negro";
    dama->typePieza = "dama";
    Pieza *rey = new Pieza("Rey-N","PIEZAS\\FINAL-REY-NEGRO.png");
    rey->color = "Negro";
    rey->typePieza = "rey";
    matriz->insertarEnMatriz(5,1,0,dama);
    matriz->insertarEnMatriz(4,1,0,rey);
    //INSERTANDO PEONES
    for(int i = 1; i <= 8; i++)
    {
        std::string n = std::to_string(i);
        Pieza *peon = new Pieza("Peon-N-"+n,"PIEZAS\\FINAL-PEON-NEGRO.png");
        peon->color = "Negro";
        peon->typePieza = "peon";
        matriz->insertarEnMatriz(i,2,0,peon);
    }
}

//INSERTA LAS PIEZAS EN EL NIVEL 0 (BLANCOS)
void insertaNivel0Blancos()
{
    //INSERTANDO CABALLOS NEGROS
    Pieza *caballo1 = new Pieza("Caballo-B-1", "PIEZAS\\FINAL-CABALLO-BLANCA.png");
    caballo1->color = "Blanco";
    caballo1->typePieza = "caballo";
    Pieza *caballo2 = new Pieza("Caballo-B-2", "PIEZAS\\FINAL-CABALLO-BLANCA.png");
    caballo2->color = "Blanco";
    caballo2->typePieza = "caballo";
    matriz->insertarEnMatriz(1,8,0,caballo1);
    matriz->insertarEnMatriz(8,8,0,caballo2);
    //INSERTANDO ALFILES NEGROS
    Pieza *alfil1 = new Pieza("Alfil-B-1", "PIEZAS\\FINAL-ALFIL-BLANCO.png");
    alfil1->color = "Blanco";
    alfil1->typePieza = "alfil";
    Pieza *alfil2 = new Pieza("Alfil-B-2", "PIEZAS\\FINAL-ALFIL-BLANCO.png");
    alfil2->color = "Blanco";
    alfil2->typePieza = "alfil";
    matriz->insertarEnMatriz(2,8,0,alfil1);
    matriz->insertarEnMatriz(7,8,0,alfil2);
    //INSERTANDO TORRES
    Pieza *torre1 = new Pieza("Torre-B-1", "PIEZAS\\FINAL-TORRE-BLANCA.png");
    torre1->color = "Blanco";
    torre1->typePieza = "torre";
    Pieza *torre2 = new Pieza("Torre-B-2", "PIEZAS\\FINAL-TORRE-BLANCA.png");
    torre2->color = "Blanco";
    torre2->typePieza = "torre";
    matriz->insertarEnMatriz(3,8,0,torre1);
    matriz->insertarEnMatriz(6,8,0,torre2);
    //INSERTANDO REY Y REYNA
    Pieza *dama = new Pieza("Dama-B", "PIEZAS\\FINAL-REYNA-BLANCO.png");
    dama->color = "Blanco";
    dama->typePieza = "dama";
    Pieza *rey = new Pieza("Rey-B","PIEZAS\\FINAL-REY-BLANCO.png");
    rey->color = "Blanco";
    rey->typePieza = "rey";
    matriz->insertarEnMatriz(5,8,0,dama);
    matriz->insertarEnMatriz(4,8,0,rey);
    //INSERTANDO PEONES
    for(int i = 1; i <= 8; i++)
    {
        std::string n = std::to_string(i);
        Pieza *peon = new Pieza("Peon-B-"+n,"PIEZAS\\FINAL-PEON-BLANCO.png");
        peon->color = "Blanco";
        peon->typePieza = "peon";
        matriz->insertarEnMatriz(i,7,0,peon);
    }
}

//INSERTA LAS PIEZAS EN EL NIVEL 1 (NEGROS)
void insertarNivel1Negros()
{
    //INSERTANDO TORRE EN NIVEL1
    Pieza *torre = new Pieza("Torre-N-3","PIEZAS\\FINAL-TORRE-NEGRA.png");
    torre->color = "Negro";
    torre->typePieza = "torre";
    matriz->insertarEnMatriz(6,1,1,torre);
    //INSERTANDO ALFIL
    Pieza *alfil3 = new Pieza("Alfil-N-3","PIEZAS\\FINAL-AlFIL-NEGRO.png");
    alfil3->color ="Negro";
    alfil3->typePieza = "alfil";
    matriz->insertarEnMatriz(7,1,1,alfil3);
    //INSERTANDO CABALLO
    Pieza *caballo = new Pieza("Caballo-N-3","PIEZAS\\FINAL-CABALLO-NEGRA.png");
    caballo->color = "Negro";
    caballo->typePieza = "caballo";
    matriz->insertarEnMatriz(8,1,1,caballo);
    //INSERTANDO PEONES
    for(int i=6; i<=8; i++)
    {
        std::string n = std::to_string(i+3);
        Pieza *peon = new Pieza("Peon-N-"+n,"PIEZAS\\FINAL-PEON-NEGRO.png");
        peon->color = "Negro";
        peon->typePieza = "peon";
        matriz->insertarEnMatriz(i,2,1,peon);
    }
}

//INSERTA LAS PIEZAS EN EL NIVEL 1 (BLANCOS)
void insertarNivel1Blancos()
{
    //INSERTANDO TORRE EN NIVEL1
    Pieza *torre = new Pieza("Torre-B-3","PIEZAS\\FINAL-TORRE-BLANCA.png");
    torre->color = "Blanco";
    torre->typePieza = "torre";
    matriz->insertarEnMatriz(3,8,1,torre);
    //INSERTANDO ALFIL
    Pieza *alfil3 = new Pieza("Alfil-B-3","PIEZAS\\FINAL-ALFIL-BLANCO.png");
    alfil3->color ="Blanco";
    alfil3->typePieza = "alfil";
    matriz->insertarEnMatriz(2,8,1,alfil3);
    //INSERTANDO CABALLO
    Pieza *caballo = new Pieza("Caballo-B-3","PIEZAS\\FINAL-CABALLO-BLANCA.png");
    caballo->color = "Blanco";
    caballo->typePieza = "caballo";
    matriz->insertarEnMatriz(1,8,1,caballo);
    //INSERTANDO PEONES
    for(int i=1; i<=3; i++)
    {
        std::string n = std::to_string(i+8);
        Pieza *peon = new Pieza("Peon-B-"+n,"PIEZAS\\FINAL-PEON-BLANCO.png");
        peon->color = "Blanco";
        peon->typePieza = "peon";
        matriz->insertarEnMatriz(i,7,1,peon);
    }
}

//INSERTA LAS PIEZAS EN EL NIVEL 2 (NEGROS)
void insertarNivel2Negros()
{
    //INSERTANDO CABALLO
    Pieza *caballo4 = new Pieza("Caballo-N-4","PIEZAS\\FINAL-CABALLO-NEGRA.png");
    caballo4->color = "Negro";
    caballo4->typePieza = "caballo";
    matriz->insertarEnMatriz(1,1,2,caballo4);
    //INSERTANDO EL ALFIL
    Pieza *alfil = new Pieza("Alfil-N-4","PIEZAS\\FINAL-AlFIL-NEGRO.png");
    alfil->color = "Negro";
    alfil->typePieza = "alfil";
    matriz->insertarEnMatriz(2,1,2,alfil);
    //INSERTANDO LA TORRE
    Pieza *torre = new Pieza("Torre-N-4","PIEZAS\\FINAL-TORRE-NEGRA.png");
    torre->color = "Negro";
    torre->typePieza = "torre";
    matriz->insertarEnMatriz(3,1,2,torre);
    //INSERTANDO PEONES
    for(int i = 1; i <=3; i++)
    {
        std::string n = std::to_string(i+11);
        Pieza *peon = new Pieza("Peon-N-"+n, "PIEZAS\\FINAL-PEON-NEGRO.png");
        peon->color = "Negro";
        peon->typePieza = "peon";
        matriz->insertarEnMatriz(i,2,2,peon);
    }
}

//INSERTA LAS PIEZAS EN EL NIVEL 2 (BLANCOS)
void insertarNivel2Blancos()
{
    //INSERTANDO CABALLO
    Pieza *caballo = new Pieza("Caballo-B-4","PIEZAS\\FINAL-CABALLO-BLANCA.png");
    caballo->color = "Blanco";
    caballo->typePieza = "caballo";
    matriz->insertarEnMatriz(8,8,2,caballo);
    //INSERTANDO EL ALFIL
    Pieza *alfil = new Pieza("Alfil-B-4", "PIEZAS\\FINAL-ALFIL-BLANCO.png");
    alfil->color = "Blanco";
    alfil->typePieza = "alfil";
    matriz->insertarEnMatriz(7,8,2,alfil);
    //INSERTANDO TORRE
    Pieza *torre = new Pieza("Torre-B-4","PIEZAS\\FINAL-TORRE-BLANCA.png");
    torre->color = "Blanco";
    torre->typePieza = "torre";
    matriz->insertarEnMatriz(6,8,2,torre);
    //INSERTANDO PEONES
    for(int i = 6; i<=8; i++)
    {
        std::string n = std::to_string(i+6);
        Pieza *peon = new Pieza("Peon-B-"+n, "PIEZAS\\FINAL-PEON-BLANCO.png");
        peon->color = "Blanco";
        peon->typePieza = "peon";
        matriz->insertarEnMatriz(i,7,2,peon);
    }

}

//MANDA A LLAMAR LOS METODOS DE LA MATRIZ GRAFICAR
bool generaGrafoMatriz(int nivel)
{
    return matriz->generaDotMatriz(nivel);
}

//SOLO ME RETORNA PARA VER SI LA MATRIZ ESTA VACÍA
bool matrizVacia()
{
    if(matriz==NULL)
    {
        return true;
    }
    else
    {
        return matriz->matrizVacia();
    }
}

//INICIA LA LINEALIZACION DE TODO
void realizaLinealizacion(int nivel, std::string tipo)
{
    std::string ad = std::to_string(nivel);
    matriz->creaNuevaLinealizacion(tipo+" | Nivel: "+ad);
    if(tipo.compare("Filas")==0)
    {
        matriz->linealizaPorFilas(nivel);
    }
    else
    {
        matriz->linealizaPorColumnas(nivel);
    }
}

//RETORNA EL RESULTADO DE QUERER GENERAR EL GRAFO
bool realizaGrafoLinealizacion()
{
    return matriz->linea->generaElGrafo();
}

void limpiaLinealizacion()
{
    delete matriz->linea;
}

//ACTUALIZA EL TABLERO EN LA INTERFAZ GRAFICA
void actualizarTablero(QLabel *l0[8][8], QLabel *l1[8][8], QLabel *l2[8][8])
{
    despintaTableros(l0);
    despintaTableros(l1);
    despintaTableros(l2);
    matriz->pintaMatrizLabels(l0,0);
    matriz->pintaMatrizLabels(l1,1);
    matriz->pintaMatrizLabels(l2,2);
}

//RECIVE LA ENTRADA PARA PODER REALIZAR UN MOVIMIENTO
bool muevePieza(string entrada, string color)
{
    std::string inicial;
    std::string nivel;
    std::string casillas;
    std::stringstream ent(entrada);
    std::getline(ent,inicial,'-');
    std::getline(ent, nivel, '-');
    std::getline(ent, casillas, '\n');
    inicial = devuelvemeTipoDePieza(inicial);
    int lev = std::stoi(nivel);
    std::string sy = casillas.substr(0,1);
    int x = std::stoi(casillas.substr(1,1));
    int y = indice(sy);
    if(x<=8 && x>0 && y>0 && y<=8 && inicial.compare("")!=0 && lev <=2)
    {
        if(inicial.compare("peon")==0)
        {
            return matriz->buscaPeonValido(inicial, color, x, y, lev);
        }
        if(inicial.compare("alfil")==0)
        {
            return matriz->bucaAlfilValido(inicial, color, x, y, lev);
        }
        if(inicial.compare("caballo")==0)
        {
            return matriz->buscaCaballo(inicial, color, x, y, lev);
        }
        if(inicial.compare("torre")==0)
        {
            return matriz->buscaTorre(inicial, color, x, y, lev);
        }
        if(inicial.compare("rey")==0)
        {
            return matriz->buscaRey(inicial, color, x, y, lev);
        }
        if(inicial.compare("dama")==0)
        {
            return matriz->buscaReyna(inicial, color, x, y, lev);
        }
    }
    else
    {
        return false;
    }

}

int cantidadDeDamas()
{
    return matriz->cuentaReinas();
}

//CONVIERTE LA INICIAL AL TIPO DE PIEZA QUE DEBE DE PROCESAR
string devuelvemeTipoDePieza(string inicial)
{
    if(inicial.compare("P")==0)
    {
        return "peon";
    }
    if(inicial.compare("T")==0)
    {
        return "torre";
    }
    if(inicial.compare("A")==0)
    {
        return "alfil";
    }
    if(inicial.compare("C")==0)
    {
        return "caballo";
    }
    if(inicial.compare("R")==0)
    {
        return "rey";
    }
    if(inicial.compare("D")==0)
    {
        return "dama";
    }
    return "";
}

//DEVUELVE EL INDICE QUE TIENE PARA PODER UBICARLO EN EL LA MATRIZ
int indice(string l)
{
    std::string auxiliarArray[9] = {"root","H","G","F","E","D","C","B","A"};
    for(int i = 0; i < 9; i++)
    {
        if(auxiliarArray[i].compare(l)==0)
        {
            return i;
        }
    }
    return 0;
}

//DESPINTA TODO TABLEROS PARA EVITAR QUE QUEDEN LABELS PINTADOS
void despintaTableros(QLabel *mat[8][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j = 0; j<8 ;j++)
        {
            QPixmap img("");
            mat[i][j]->setPixmap(img);
            mat[i][j]->repaint();
        }
    }
}

void calculaFuncionGanador()
{
    matriz->calculaGanador();
}

int cantidadBlancos()
{
    return matriz->blancos;
}

int cantidadNegros()
{
    return matriz->negros;
}
