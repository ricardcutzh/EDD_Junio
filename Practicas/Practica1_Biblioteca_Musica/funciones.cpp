#include<funciones.h>
#include<sstream>
ListaArtistas *listaArtistas;//LISTA DE ARTISTAS

//DECLARACIÓN DE LOS TOPS
Top *topSongs;
Top *topAlbums;
Top *topArtists;

//LISTA DE REPRODUCCIÓN
ListaDeReproduccion *playlist;
NodoRep *apuntador;

//LEER ARCHIVOS PARA CARGAR LA BIBLIOTECA
bool leerArchivoEntrada(string ruta)
{
    ifstream archivo(ruta);
    if(!archivo.is_open())
    {
        return false;
    }
    else
    {
        std::string artista;
        std::string album;
        std::string cancion;
        std::string valoracion;
        std::string path;
        while(archivo.good())
        {
            std::string aux;
            getline(archivo,artista,'_');
            getline(archivo,album, '_');
            getline(archivo,cancion,'_');
            getline(archivo,path,'_');
            getline(archivo,valoracion,';');
            //AQUI TOCA EL INGRESO A LA LISTA DE DATOS
            inserta_datos(artista, album, cancion, valoracion, path);
            getline(archivo,aux,'\n');
        }
    }
    archivo.close();
    return true;
}

//INSERTAR LOS DATOS A LA BIBLIOTECA
void inserta_datos(std::string arti, std::string album, std::string cancion,std::string valoracion, std::string path)
{
    float valo = std::stof(valoracion);
    if(listaArtistas->yaExisteArtista(arti))
    {
        //BUSCAR LA REFERENCIA AL NODO DE ARTISTA...
        NodoArtista *auxArt = listaArtistas->buscaArtista(arti);
        if(auxArt->albumes->yaExisteAlbum(album))//SI EXISTE EL ALBUM...
        {
            std::cout << "Artista existe: " << arti << " Album Existe: " << album << " Canción: " << cancion << std::endl;
            //BUSCO LA REFERENCIA AL NODO DEL ALBUM
            NodoAlbum *auxAlbum = auxArt->albumes->buscaAlbum(album);

            //CREO LA CANCIÓN
            Cancion *nuevaCancion = new Cancion(cancion, valo, path);

            //INSERTO LA CANCIÓN EN EL ALBUM
            auxAlbum->songs->insertar_cancion(nuevaCancion);
            /*std::cout << auxAlbum->album->nombre << std::endl;*/

        }
        else //SINO EXISTE...
        {

            //CREO EL NUEVO ALBUM Y LO INSERTO AL ARTISTA
            Album *nuevoAlbum = new Album(album);
            ListaCanciones *songs = new ListaCanciones();

            //CREO LA CANCIÓN
            Cancion *nuevaCancion = new Cancion(cancion, valo, path);

            //INSERTO LA NUEVA CANCIÓN A LA LISTA DE CANCIONES DEL ALBUM
            songs->insertar_cancion(nuevaCancion);

            //INSERTO EL ALBUM A LA LISTA DE ALBUMES DEL ARTISTA
            auxArt->albumes->insertar(nuevoAlbum, songs);
            std::cout << "Artista existe: " << arti << " Album No Existe: " << album << " Canción: " << cancion << std::endl;
        }
    }
    else
    {
        //OBJETOS...
        Cancion *nuevoCancion = new Cancion(cancion,valo,path);//CREO LA CANCION
        Album *nuevoAlbum = new Album(album);//CREO EL ALBUM
        Artista *nuevoArti = new Artista(arti);//CREO EL ARTISTA
        //FIN OBJETOS

        //LISTA CANCIONES
        ListaCanciones *songs = new ListaCanciones();
        songs->insertar_cancion(nuevoCancion);
        //FIN LISTA CANCIONES NUEVAS

        //LISTA DE ALBUMES
        ListaAlbumes *albums = new ListaAlbumes();
        albums->insertar(nuevoAlbum, songs);
        //FIN LISTA ALBUMES NUEVOS

        //INSERCIÓN A LA LISTA DE ARTISTAS
        listaArtistas->insertar_artista(nuevoArti, albums);

        std::cout << "Artista No existe: " << arti << " Album: " << album << " Canción: " << cancion << std::endl;
    }
}

//SE ENCARGA DE GENERAR EL GRAFO DE LA BIBLIOTECA
bool escribeBiblioteca()
{
    std::ofstream archivo;
    archivo.open("biblioteca.dot",ios::out);
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        listaArtistas->escribeArtistas(archivo);
        archivo.close();
        return true;
    }
}

//SE ENCARGA DE GENERAR EL GRAFO DE LOS TOPS ALBUMS
bool escribeTopArtistas()
{
    std::ofstream archivo;
    archivo.open("topArtist.dot", ios::out);
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        topArtists->escribirDotTop(archivo);
        archivo.close();
        return true;
    }
}

bool escribeTopAlbums()
{
    std::ofstream archivo;
    archivo.open("topAlbums.dot", ios::out);
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        topAlbums->escribirDotTop(archivo);
        archivo.close();
        return true;
    }
}

bool escribeTopSongs()
{
    std::ofstream archivo;
    archivo.open("topSongs.dot", ios::out);
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        topSongs->escribirDotTop(archivo);
        archivo.close();
        return true;
    }
}

//ESCRIBE EL GRAFO PARA LA PLAYLIST
bool escribePlayList()
{
    return playlist->grafica();
}

//LIBERA LA LISTA DE MOMORIA
void liberarLista()
{
    topSongs=0;
    free(topSongs);
    topAlbums = 0;
    free(topAlbums);
    topArtists = 0;
    free(topArtists);
    listaArtistas = 0;
    free(listaArtistas);
}

//CREA UNA NUEVA LISTA:
void crearNuevaLista()
{
    listaArtistas = new ListaArtistas();
    topSongs = new Top("Songs");
    topAlbums = new Top("Albums");
    topArtists = new Top("Artists");
}

//VA AGREGAR A LOS TOPS DE ARTISTAS:
void agregaTops()
{
    if(listaArtistas->count()>0)
    {
        NodoArtista *aux = listaArtistas->primero->siguiente;
        while(aux!=listaArtistas->primero)
        {
            recorreAlbumes(aux);
            aux->artista->valoracion = aux->albumes->valoracionArtista();
            NodoTop *nuevo = new NodoTop(aux->artista->nombre, aux->artista->valoracion);
            topArtists->add(nuevo);
            aux = aux->siguiente;
        }
    }
}

//VACIA PLAYLIST
void vaciaPlaylist()
{
    free(playlist);
    playlist = 0;
}

//INICIALIZA LA PLAYLIST
void iniciaPlaylist(string tipo)
{
    playlist = new ListaDeReproduccion(tipo);
}

//AGREGA A LOS TOPS DE ALBUMES
void recorreAlbumes(NodoArtista *art)
{
    if(art->albumes->count()>0)
    {
        NodoAlbum *aux = art->albumes->primero->siguiente;
        while(aux!=NULL)
        {
            recorreCanciones(aux);
            aux->album->valoracion = aux->songs->valoracionAlbum();
            NodoTop *nuevo = new NodoTop(aux->album->nombre, aux->album->valoracion);
            topAlbums->add(nuevo);
            aux = aux->siguiente;
        }
    }
}

//AGREGA A LOS TOPS DE CANCIONES
void recorreCanciones(NodoAlbum *alb)
{
    if(alb->songs->count()>0)
    {
        NodoCancion *aux = alb->songs->first;
        while(aux!=NULL)
        {
            NodoTop *nuevo = new NodoTop(aux->song->nombre, aux->song->valoracion);
            topSongs->add(nuevo);
            aux = aux->next;
        }
    }
}

//ELIMINACIÓN DE CANCIONES EXISTENTES EN LA BIBLIOTECA
bool eliminaCancion(string entrada)
{
    std::string artista;//DONDE ALMACENO EL ARTISTA
    std::string album;//DONDE ALMACENO EL ALBUM
    std::string cancion;//DONDE ALMACENO LA CANCION
    std::stringstream spl(entrada);//LO CONVIERTO A UN STREAM PARA PODER LEER EL STRING
    std::getline(spl, artista, '_');//OBTENGO EL ARTISTA
    std::getline(spl, album, '_');//OBTENGO EL ALBUM
    std::getline(spl, cancion, '_');//OBTENGO LA CANCION
    //AHORA ME PREGUNTO: ¿EXISTE EL ARTISTA EN LA LISTA?:
    if(listaArtistas->yaExisteArtista(artista))
    {
        //TRAIGO LA REFERENCIA AL NODO DONDE ESTA EL ARTISTA
        NodoArtista *auxArt = listaArtistas->buscaArtista(artista);

        //¿EXISTE EL ALBUM?
        if(auxArt->albumes->yaExisteAlbum(album))
        {
            //TRAIGO LA REFERENCIA AL NODO DEL ALBUM
            NodoAlbum *auxAlbum = auxArt->albumes->buscaAlbum(album);
            if(auxAlbum->songs->eliminar_cancion(cancion))
            {
                if(auxAlbum->songs->count()==0)
                {
                    auxArt->albumes->eliminar(album);
                    if(auxArt->albumes->count()==0)
                    {
                        listaArtistas->eliminar_artista(artista);
                    }
                }
                return true;
            }
            else//SI ALGO SALE MAL EN LA ELIMINACIÓN RETORNO FALSO...
            {
                return false;
            }
        }
        else//SI NO EXISTE EL ALBUM NO ELIMINO...
        {
            return false;
        }
    }//SI NO EXISTE ARTISTA NO ELIMINO...
    else
    {
        return false;
    }
}

//VACIA LOS TOPS PARA VOLVER A LLENARLOS CON LA NUEVA INFORMACIÓN
void vaciaTops()
{
    topSongs=0;
    free(topSongs);
    topAlbums = 0;
    free(topAlbums);
    topArtists = 0;
    free(topArtists);
}

//INICIALIZA LOS TOPS PARA VOLVER A RECORRER Y SABER CUALES SON LOS TOP CANCIONES
void iniciaTops()
{
    topSongs = new Top("Songs");
    topAlbums = new Top("Albums");
    topArtists = new Top("Artists");
}

//BUSCAR LA REFERENCIA AL NODO DE CANCIÓN PARA AÑADIR A LA PLAYLIST
Cancion *encuentraCancion(string entrada)
{
    std::string artista;//DONDE ALMACENO EL ARTISTA
    std::string album;//DONDE ALMACENO EL ALBUM
    std::string cancion;//DONDE ALMACENO LA CANCION
    std::stringstream spl(entrada);//LO CONVIERTO A UN STREAM PARA PODER LEER EL STRING
    std::getline(spl, artista, '_');//OBTENGO EL ARTISTA
    std::getline(spl, album, '_');//OBTENGO EL ALBUM
    std::getline(spl, cancion, '_');//OBTENGO LA CANCION
    //AHORA PREGUNTO ¿EXISTE EL ARTISTA?
    if(listaArtistas->yaExisteArtista(artista))
    {
        NodoArtista *auxArt = listaArtistas->buscaArtista(artista);
        //¿EXISTE EL ALBUM?
        if(auxArt->albumes->yaExisteAlbum(album))
        {
            NodoAlbum *auxAlb = auxArt->albumes->buscaAlbum(album);
            //¿EXISTE LA CANCIÓN EN ESTE ALBUM?
            if(auxAlb->songs->existeCancion(cancion))
            {
                //RETORNO LA REFERENCIA A LA CANCIÓN
                return auxAlb->songs->buscaLaCancion(cancion);
            }
            else
            {
                //RETORNO NULL
                return NULL;
            }
        }
        else
        {
            //RETORNA NULL NO EXISTE
            return NULL;
        }
    }
    else
    {
        //RETORNA NULL NO EXISTE
        return NULL;
    }
}

//INICIALIZA EL APUNTADOR
NodoRep *inicializaApuntador()
{
    if(playlist->tipolista.compare("LDE")==0)
    {
        return apuntador = playlist->raiz->sig;
    }
    if(playlist->tipolista.compare("QUEUE")==0)
    {
        return apuntador = playlist->raiz->sig;
    }
    if(playlist->tipolista.compare("STACK")==0)
    {
        return apuntador = playlist->raiz->ant;
    }
}

//RETORNA EL SIGUIENTE DE LA LISTA
NodoRep *siguiente()
{
    if(playlist->tipolista.compare("LDE")==0)
    {
        if(apuntador->sig == playlist->raiz)
        {
            apuntador = playlist->raiz->sig;
        }
        else
        {
            apuntador = apuntador->sig;
        }
        return apuntador;
    }
    if(playlist->tipolista.compare("QUEUE")==0)
    {
        if(apuntador!=playlist->raiz)
        {
            apuntador = apuntador->sig;
            playlist->Desencolar();
            return apuntador;
        }
        else{
            playlist->Desencolar();
        }
    }
    if(playlist->tipolista.compare("STACK")==0)
    {
        if(apuntador!=playlist->raiz)
        {
            apuntador = apuntador->ant;
            //std::cout<< apuntador->nombre<<std::endl;
            playlist->Pop();
            return apuntador;
        }
        else
        {
            playlist->Pop();
        }
    }
    return NULL;
}

//ANTERIOR
NodoRep *anterior()
{
    if(playlist->tipolista.compare("LDE")==0)
    {
        if(apuntador->ant == playlist->raiz)
        {
            apuntador = playlist->raiz->ant;
        }
        else
        {
            apuntador = apuntador->ant;
        }
        return apuntador;
    }
    return NULL;
}

//AGREGA LA CANCIÓN AL PLAYLIST
void agregaAPlayList(Cancion *song)
{
    playlist->addToPlaylist(song->nombre,song->PATH);
}
