#include "listaartistas.h"

ListaArtistas::ListaArtistas()
{
    this->primero = new NodoArtista();//CABEZA QUE VA A SOSTENER MI LISTA (ROOT)
    this->elementos = 0;
}

//METODOS PRIVADOS:
bool ListaArtistas::estaVacia()
{
    if(this->elementos == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//METODOS PUBLICOS:

//METODO QUE SE ENCARGA DE INSERTAR EN LA LISTA UN NUEVO ARTISTA Y UN LISTADO DE ALBUMS
void ListaArtistas::insertar_artista(Artista *newArtist, ListaAlbumes *albums)
{
    NodoArtista *nuevo = new NodoArtista(newArtist, albums);
    if(estaVacia())//SI LA LISTA ESTA VACÍA
    {
        this->primero->siguiente = nuevo;//LO INSERTO JUSTO DESPUES DE MI "RAÍZ"
        nuevo->anterior = this->primero;
        nuevo->siguiente = this->primero;
        this->primero->anterior = nuevo;
        this->elementos++;//AUMENTO EL CONTADOR
    }
    else
    {//EN CASO DE QUE NO ESTE VACÍA
        NodoArtista *temp = this->primero->siguiente;
        while(temp->siguiente!=this->primero)//RECORRO LA LISTA
        {
            temp = temp->siguiente;
        }
        //AL LLEGAR AL FINAL... LO INSERTO
        temp->siguiente->anterior = nuevo;
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
        this->elementos++;//AUMENTO EL CONTADOR
    }
}

//METODO QUE VERIFICA SI YA EXISTE UN ARTISTA EN LA LISTA
bool ListaArtistas::yaExisteArtista(std::string nombre)
{
    if(!estaVacia())
    {
        NodoArtista *temp = this->primero->siguiente;
        std::string compara;
        while(temp!=this->primero)
        {
            compara = temp->artista->nombre;
            if(nombre.compare(compara)==0)
            {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }
    else
    {
        return false;
    }
}

//METODO QUE SE ENCARGA DE BUSCAR UNA REFERENCIA A UN ARTISTA
NodoArtista* ListaArtistas::buscaArtista(std::string nombre)
{
    if(yaExisteArtista(nombre))//SI EL ARTISTA EXISTE ENTONCES PODRE BUSCAR SU REFERENCIA
    {
        NodoArtista *temp = this->primero->siguiente;//VARIABLE TEMPORAL PARA PODER MOVERME
        std::string compara;//VARIABLE AUXILIAR PARA COMPARAR LOS NOMBRES EN ARTISTAS
        while(temp!=this->primero)//MIENTRAS NO LLEGUE A LA CABEZA DE LA LISTA
        {
            compara = temp->artista->nombre;
            if(nombre.compare(compara)==0)//¿SON IGUALES?
            {
                return temp;//SI LO ES ENTONCES DEVUELVEME LA REFERENCIA A ESTE NODO
            }
            temp = temp->siguiente;//SI NO ENTONCES CONTINUA AL SIGUIENTE
        }
    }
    else//EN CASO DE QUE SE QUIERA BUSCAR UN ARTISTA QUE NO ESTE
    {
        //DEVUELVO LA REFERENCIA NULA
        return NULL;
    }
}

//METODO QUE ME RETORNA EL NUMERO DE ELEMENTOS EN LA LISTA
int ListaArtistas::count()
{
    return this->elementos;
}

//METODO PARA ELIMINAR DE UNA LISTA
bool ListaArtistas::eliminar_artista(std::string nombre)
{
    if(yaExisteArtista(nombre))//SI EXISTE EL ARTISTA QUE QUIERO ELIMINAR...
    {
        NodoArtista *elim = buscaArtista(nombre);//BUSCO LA REFERENCIA A ESE ARTISTA
        elim->anterior->siguiente = elim->siguiente;//RECONECTO EL PUNTERO SIGUIENTE DEL ANTERIOR
        elim->siguiente->anterior = elim->anterior;//RECONECTO EL PUNTERO ANTERIOR DEL SIGUIENTE
        free(elim);//LIBERO LA MEMORIA
        elim = NULL;//POR SEGURIDAD..
        this->elementos--;//DECREMENTO EL NUMERO DE ELEMENTOS EN LA LISTA
    }
    else
    {
        //SI NO EXISTE ENTONCES NO ELIMINO NADA...
        return false;
    }
}

//ESCRIBE LA LISTA DE ARTISTAS EN EL ARCHIVO
void ListaArtistas::escribeArtistas(std::ofstream &archivo)
{
    if(!estaVacia())
    {
        int contador = 0;
        archivo << "digraph G {" << std::endl;
        archivo << "node [shape=box];" << std::endl;

        //PARA CONECTARLO CIRCULARMENTE
        archivo << "\"Art: "<< this->primero->anterior->artista->nombre << "\"->\"Art: " << this->primero->siguiente->artista->nombre << "\";" << std::endl;
        archivo << "\"Art: "<< this->primero->siguiente->artista->nombre << "\"->\"Art: " << this->primero->anterior->artista->nombre << "\";" << std::endl;
        NodoArtista *aux = this->primero->siguiente;
        while(aux!=this->primero)
        {
            //ENLAZO CADA ARTISTA CON SU PRIMER ALBUM EN LISTA
            archivo << "\"Art: "<< aux->artista->nombre << "\"->\"Alb: " << aux->albumes->primero->siguiente->album->nombre << "\";"<<std::endl;
            if(aux->anterior!=this->primero)
            {
                archivo << "\"Art: " << aux->artista->nombre << "\"->\"Art: " << aux->anterior->artista->nombre << "\";" << std::endl;
            }
            if(aux->siguiente!=this->primero)
            {
                archivo << "\"Art: " << aux->artista->nombre << "\"->\"Art: " << aux->siguiente->artista->nombre << "\";" << std::endl;
            }
            //ESCRIBO LA LISTA DE ALBUMS DEL ARTISTA
            archivo << "subgraph cluster_" << contador << "{" << std::endl;
            archivo << "rank=same;" << std::endl;
            archivo << "label=\"Albums\";" << std::endl;
            aux->albumes->escribirAlbumes(archivo);
            archivo << "};"<<std::endl;

            //ME MUEVO AL SIGUIENTE
            contador++;
            aux = aux->siguiente;
        }
        sameRank(archivo);
        archivo << "}" << std::endl;
    }
}

void ListaArtistas::sameRank(std::ofstream &archivo)
{
    archivo << "{rank=same;";
    NodoArtista *aux = this->primero->siguiente;
    while(aux!=this->primero)
    {
        archivo << "\"Art: " << aux->artista->nombre << "\";";
        aux = aux->siguiente;
    }
    archivo << "};" << std::endl;
}
