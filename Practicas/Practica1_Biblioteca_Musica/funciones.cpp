#include<funciones.h>
ListaArtistas *listaArtistas;//LISTA DE ARTISTAS
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
        return true;
        archivo.close();
    }
}

//LIBERA LA LISTA DE MOMORIA
void liberarLista()
{
    listaArtistas = 0;
    free(listaArtistas);
}

//CREA UNA NUEVA LISTA:
void crearNuevaLista()
{
    listaArtistas = new ListaArtistas();
}
