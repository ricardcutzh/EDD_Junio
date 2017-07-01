#include "matrizortogonal.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

//CONSTRUCTOR DE LA MATRIZ
MatrizOrtogonal::MatrizOrtogonal()
{
    //CREO LA RAIZ DE LA MATRIZ EL QUE JUNTA CABECERAS DE COLUMNAS Y FILAS
    Pieza *n = new Pieza("root","root");
    this->raiz = new NodoMatriz(0,0,0,n,false);
}

//DESTRUCTOR
MatrizOrtogonal::~MatrizOrtogonal()
{
    //AUN PENDIENTE
}

//VERIFICA SI LA MATRIZ ESTA VACIA
bool MatrizOrtogonal::matrizVacia()
{
    if((this->raiz->siguiente == NULL) || (this->raiz->abajo == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//METODO QUE VERIFICA SI LA COLUMNA YA EXISTE:
bool MatrizOrtogonal::existeColumna(int x)
{
    //AUXILIAR PARA RECORRER LAS CABECERAS DE COLUMNAS
    NodoMatriz *aux = this->raiz->siguiente;
    bool siEsta = false;
    while(aux!=NULL)
    {
        if(aux->x == x)//SI SI ESTA...
        {
            siEsta = true;
            break;//ROMPO EL CICLO
        }
        aux = aux->siguiente;//SI NO LO ENCONTRO ME MUEVO AL SIGUIENTE..
    }
    return siEsta;//RETORNO RESPUESTA
}

//METODO QUE VERIFICA SI EXISTE LA FILA:
bool MatrizOrtogonal::existeFila(int y)
{
    NodoMatriz *aux = this->raiz->abajo;//ES LA MISMA IDEA QUE EL QUE BUSCA COL
    bool SiEsta = false;//SOLO QUE ME MUEVO HACIA ABAJO POR LAS CABECERAS DE FILAS
    while(aux!=NULL)
    {
        if(aux->y == y)
        {
            SiEsta = true;
            break;
        }
        aux = aux->abajo;
    }
    return SiEsta;
}

//METODO QUE CREA LA CABECERA CORRESPONIENDE DE COLUMNA Y ME DEVUELVE LA REFERENCIA
NodoMatriz *MatrizOrtogonal::crearCabeceraColumnas(int x)
{
    NodoMatriz *aux = this->raiz->siguiente;//NODO PARA RECORRER
    Pieza *n = new Pieza(std::to_string(x),std::to_string(x));
    n->typePieza = "CABECERA";
    NodoMatriz *nuevo = new NodoMatriz(x,x,0, n,false);//NODO DE CABECERA
    if(matrizVacia())
    {   //SI LA MATRIZ ESTA VACIA LO COLOCO ALA PAR DE LA RAIZ ES LA PRIMER CABECERA
        this->raiz->siguiente = nuevo;
        nuevo->anterior = this->raiz;
        return nuevo;
    }
    else//SI NO...
    {
        int bandera = 0;//SIRVE PARA VER QUE TIPO DE CONEXIÓN HACER...(ORDENAR)
        while(aux!=NULL)
        {
            if(x < aux->x)
            {//QUIERE DECIR QUE EL NODO VA ANTES DEL AUX
                bandera = 1;
                break;
            }
            if(aux->siguiente!=NULL)//ESTA VERIFICACION SIRVE PARA QUEDARME UNO ANTES
            {//EVITA EXCEPCIONES...
                aux = aux->siguiente;
            }
            else
            {
                break;
            }
        }
        if(bandera==1)//BANDERA = 1 ES PORQUE VA ANTES DEL AUX
        {
            aux->anterior->siguiente = nuevo;
            nuevo->anterior = aux->anterior;
            nuevo->siguiente = aux;
            aux->anterior = nuevo;
        }
        else//ES PORQUE VA DESPUES...
        {
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }
    return nuevo;
}

//METODO QUE CREA LA CABECERA CORRESPONIENDE DE FILA Y ME DEVUELVE LA REFERENCIA
NodoMatriz *MatrizOrtogonal::crearCabecerasFilas(int y)
{
    NodoMatriz *aux = this->raiz->abajo;//PARA RECORRER
    Pieza *n = new Pieza(letras[y],std::to_string(y));
    n->typePieza = "CABECERA";
    NodoMatriz *nuevo = new NodoMatriz(y,y,0,n,false);//PARA CABECERA..
    if(matrizVacia())
    {//SI ESTA VACIA LO PONGO ABAJO DE LA RAIZ
        this->raiz->abajo = nuevo;
        nuevo->arriba = this->raiz;
    }
    else
    {
        int bandera = 0;
        while(aux!=NULL)//ES LA MISMA IDEA QUE EL DE COLUMNAS...
        {
            if(y < aux->y)
            {
                bandera = 1;
                break;
            }
            if(aux->abajo!=NULL)
            {
                aux = aux->abajo;
            }
            else
            {
                 break;
            }
        }
        if(bandera == 1)//ES PORQUE VA ANTES
        {
            aux->arriba->abajo = nuevo;
            nuevo->arriba = aux->arriba;
            nuevo->abajo = aux;
            aux->arriba = nuevo;
        }
        if(bandera == 0)
        {
            aux->abajo = nuevo;
            nuevo->arriba = aux;//ES PORQUE VA DESPUES
        }
    }
    return nuevo;
}

//METODO QUE BUSCA LA FILA CORRESPONDIENTE Y ME DEVUELVE SU REFERENCIA
NodoMatriz *MatrizOrtogonal::encuentraFila(int y)
{
    NodoMatriz *aux = this->raiz;
    while(aux!=NULL)
    {
        if(aux->y == y)//SI ENCUENTRO LA FILA
        {
            break;//ROMPO EL CICLO
        }
        if(aux->abajo != NULL)//ESTE IF ELSE LO USO PARA NO LLEGAR AL ULTIMO = NULL
        {
            aux = aux->abajo;
        }
        else
        {
            break;
        }
    }
    return aux;//NOTA: ESTE NUNCA VA A RETORNAR NULL POR LAS VALIDACIONES EN INCERSION
}

//METODO QUE BUSCA LA COLUMNA CORRESPONDIENTE Y ME DEVUELVE SU REFERENCIA
NodoMatriz *MatrizOrtogonal::encuentraColumna(int x)
{
    NodoMatriz *aux = this->raiz;
    while(aux!=NULL)
    {
        if(aux->x == x)
        {
            break;
        }
        if(aux->siguiente!=NULL)
        {
            aux = aux->siguiente;
        }
        else
        {
            break;
        }
    }
    return aux;
}

//METODO QUE SE ENCARGA DE PONER UN NODO EN EL LUGAR QUE LE CORRESPONDE EN FILA
NodoMatriz *MatrizOrtogonal::recorreFila(NodoMatriz *nodoB, NodoMatriz *nuevo)
{
    NodoMatriz *aux = nodoB;
    int bandera = 0;
    while(aux->siguiente!=NULL)
    {
        if(nuevo->x < aux->siguiente->x)
        {
            bandera = 1;
            break;
        }
        if(aux->siguiente!=NULL)
        {
            aux = aux->siguiente;
        }
        else
        {
            break;
        }
    }
    if(bandera == 1)
    {
        aux->siguiente->anterior = nuevo;
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    if(bandera == 0)
    {
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    return nuevo;
}

//METODO QUE SE ENCARGA DE PONER UN NODO EN EL LUGAR QUE LE CORRESPONDE EN COLUMNA
NodoMatriz *MatrizOrtogonal::recorreColumna(NodoMatriz *nodoB, NodoMatriz *nuevo)
{
    NodoMatriz *aux = nodoB->abajo;
    int bandera = 0;
    while(aux->abajo!=NULL)
    {
        if(nuevo->y < aux->abajo->y)
        {
            bandera = 1;//SI VA ANTES
            break;
        }
        if(aux->abajo!=NULL)
        {
            aux = aux->abajo;
        }
    }
    if(bandera==1)//LAS CONEXIONES DE PUNTEROS SI VA ANTES..
    {
        aux->abajo->arriba = nuevo;
        nuevo->abajo = aux->abajo;
        aux->abajo = nuevo;
        nuevo->arriba = aux;
    }
    if(bandera == 0)//SI VA DESPUES...
    {
        aux->abajo = nuevo;
        nuevo->arriba = aux;
    }
    return nuevo;
}

//METODO QUE SE ENCARGA DE HACER LAS CONEXIONES Y DEVOLVERME LA REFERENCIA DEL NUEVO
NodoMatriz *MatrizOrtogonal::colocaEnColumnaConPosicionCorrecta(NodoMatriz *nodoB, NodoMatriz *nuevo)
{
    int bandera = 0;
    NodoMatriz *aux = nodoB;
    while(aux->abajo!=NULL)
    {
        if(nuevo->y < aux->abajo->y)
        {
            bandera = 1;
            break;
        }
        if(aux->abajo!=NULL)
        {
            aux = aux->abajo;
        }
        else
        {
            break;
        }
    }
    if(bandera == 1)
    {
        aux->abajo->arriba = nuevo;
        nuevo->abajo = aux->abajo;
        aux->abajo = nuevo;
        nuevo->arriba = aux;
    }
    if(bandera == 0)
    {
        aux->abajo = nuevo;
        nuevo->arriba = aux;
    }
    return nuevo;
}

//METODO QUE SE ENCARGA DE HACER LAS CONEXIONES EN FILA Y DEVOLVEREME LA REFERENCIA A ESE NODO
NodoMatriz *MatrizOrtogonal::colocaEnFilaConPosicionCorrecta(NodoMatriz *nodoB, NodoMatriz *nuevo)
{
    int bandera = 0;
    NodoMatriz *aux = nodoB;
    while(aux->siguiente!=NULL)
    {
        if(nuevo->x < aux->siguiente->x)
        {
            bandera = 1;
            break;
        }
        if(aux->siguiente!=NULL)
        {
            aux = aux->siguiente;
        }
        else
        {
            break;
        }
    }
    if(bandera == 1)
    {
        aux->siguiente->anterior = nuevo;
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    if(bandera == 0)
    {
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    return nuevo;
}

//METODO QUE EMPIEZA LA GRAFICACIÓN DE LA MATRIZ
bool MatrizOrtogonal::generaDotMatriz(int nivel)
{
    std::ofstream archivo;
    archivo.open("Matriz.dot",std::ios::out);
    if(archivo.fail())
    {
        return false;
    }
    else
    {
        archivo << "digraph g {" << std::endl;
        archivo << "node [shape=box, color=cornflowerblue ];" << std::endl;
        //ALINEAR NIVELES
        alinearTitulos(archivo, this->raiz);
        if(nivel > 0)
        {
            //APUNTAR A ENCABEZADOS DE COLUMNAS
            apuntaEncabezadosColumnas(archivo, nivel);
            apuntaEncabezadosFila(archivo, nivel);
            //APUNTAR A ENCABEZADOS DE FILAS
        }
        NodoMatriz *aux = this->raiz;
        while(aux!=NULL)
        {
            if(!aux->EsPiso)
            {
                archivo << "\"" << aux->pieza->tipo << "\";" << std::endl;
            }
            //ALINEAR POR NIVELES
            alinearPorNiveles(archivo, aux, nivel);
            //ESCRIBE MATRIZ SEGUN NIVELES
            escribeMatrizSegunNiveles(archivo, aux, nivel);
            aux = aux->abajo;
        }
        archivo << "}";
    }
    archivo.close();
    system("dot -Tpng Matriz.dot -o Matriz.png");
    return true;
}

//APUNTA LOS ENCABEZADOS DE FILA A LOS NODOS CORRESPONDIENTES
void MatrizOrtogonal::apuntaEncabezadosFila(std::ofstream &archivo, int nivel)
{
    NodoMatriz *aux = this->raiz;
    while(aux!=NULL)
    {
        archivo << "\"" << aux->pieza->tipo << "\";" << std::endl;
        if(aux->abajo!=NULL)
        {
            archivo << "\"" << aux->pieza->tipo << "\"->\"" << aux->abajo->pieza->tipo << "\";" << endl;
        }
        if(aux->arriba!=NULL)
        {
            archivo << "\"" << aux->pieza->tipo << "\"->\"" << aux->arriba->pieza->tipo << "\";" << endl;
        }
        if(aux->siguiente!=NULL)
        {
            std::string auxi = buscaFilaDatoEnNivelN(aux, nivel);
            if(auxi.compare("")!=0)
            {
                archivo << "\"" << aux->pieza->tipo << "\"->\"" << auxi << "\";" << endl;
            }
        }
        aux = aux->abajo;
    }
}

//APUNTA LOS ENCABEZADOS DE COLUMNAS A LOS NODOS CORRESPONDIENTES
void MatrizOrtogonal::apuntaEncabezadosColumnas(std::ofstream &archivo, int nivel)
{
    NodoMatriz *aux = this->raiz;
    while(aux!=NULL)
    {
        archivo << "\"" << aux->pieza->tipo << "\";" << endl;
        if(aux->siguiente!=NULL)
        {
            archivo << "\"" << aux->pieza->tipo << "\"->\"" << aux->siguiente->pieza->tipo << "\";" << endl;
        }
        if(aux->anterior!=NULL)
        {
            archivo << "\"" << aux->pieza->tipo << "\"->\"" << aux->anterior->pieza->tipo << "\";" << endl;
        }
        if(aux->abajo!=NULL)
        {
            std::string auxi = buscaColumnaDatoEnNivelN(aux, nivel);
            if(auxi.compare("")!=0)
            {
                archivo << "\"" << aux->pieza->tipo << "\"->\"" << auxi  << "\";" << endl;
            }
        }
        aux = aux->siguiente;
    }
}

//BUSCA EN LA FILA EL DATO QUE CORRESPONDE AL NIVEL
std::string MatrizOrtogonal::buscaFilaDatoEnNivelN(NodoMatriz *inicio, int nivel)
{
    NodoMatriz *aux = inicio;
    std::string  retorno = "";
    while(aux!=NULL)
    {
        retorno = DatoEnNiveN(aux, nivel);
        if(retorno.compare("")!=0)
        {
            break;
        }
        else
        {
            aux = aux->siguiente;
        }
    }
    /*if(aux->EsPiso)
    {
        retorno = "";
    }*/
    return retorno;
}

//BUSCA EN LA COLUMNA EL DATO QUE LE CORRESPONDE AL NIVEL
std::string MatrizOrtogonal::buscaColumnaDatoEnNivelN(NodoMatriz *inicio, int nivel)
{
    NodoMatriz *aux = inicio;
    std::string retorno = "";
    while(aux!=NULL)
    {
        retorno = DatoEnNiveN(aux, nivel);
        if(retorno.compare("")!=0)
        {
            break;
        }
        else
        {
            aux = aux->abajo;
        }
    }
    /*if(aux->EsPiso)
    {
        retorno = "";
    }*/
    return retorno;
}

//SE MUEVE PARA BUSCAR EL DATO EN EL NIVEL N
std::string MatrizOrtogonal::DatoEnNiveN(NodoMatriz *inicio, int n)
{
    NodoMatriz *aux = inicio;
    std::string reto = "";
    while(aux!=NULL)
    {
        if(aux->z == n)
        {
            reto = aux->pieza->tipo;
            break;
        }
        aux = aux->adelante;
    }
    return reto;
}

//SE ENCARGA DE ALINEAR LOS NIVELES EN EL DOT
void MatrizOrtogonal::alinearPorNiveles(ofstream &archivo, NodoMatriz *fil, int nivel)
{
    archivo << "{rank=same;";
    NodoMatriz *aux = fil;
    archivo << "\"" << aux->pieza->tipo << "\";";
    while(aux!=NULL)
    {
        std::string n = DatoEnNiveN(aux, nivel);
        if(n.compare("")!=0)
        {
            if(n.compare("PISO")!=0)
            {
                archivo << "\"" << n << "\";";
            }
        }
        aux = aux->siguiente;
    }
    archivo << "};" << std::endl;
}

//ALINEAR TITULOS PARA QUE TENGAN MISMA ALTURA
void MatrizOrtogonal::alinearTitulos(ofstream &archivo, NodoMatriz *r)
{
    archivo << "{rank=same;";
    NodoMatriz *aux = r;
    while(aux!=NULL)
    {
        std::string n = DatoEnNiveN(aux, 0);
        if(n.compare("")!=0)
        {
            if(n.compare("PISO")!=0)
            {
                 archivo << "\"" << n << "\";";
            }
        }
        aux = aux->siguiente;
    }
    archivo << "};" << std::endl;
}

//SE ENCARGA DE RECORRER LOS SIGUIENTES HASTA NO ENCONTRAR PISOS PARA NO GRAFICARLOS
NodoMatriz *MatrizOrtogonal::encuentraElSiguienteQueNoEsPiso(NodoMatriz *inicio)
{
    NodoMatriz *aux = inicio;
    while(aux!=NULL)
    {
        if(!aux->EsPiso)//SI ENCUENTRA UNO QUE NO ES PISO ENTONCES PARA
        {
            break;
        }
        if(aux->siguiente!=NULL)//DE LO CONTRARIO CONTINUA CON LA BUSQUEDAD...
        {
            aux = aux->siguiente;
        }
        else//ESTA ES UNA VALIDACIÓN PARA QUE NO LLEGUE A NULL
        {
            break;
        }
    }
    if(aux->EsPiso)
    {
        return NULL;
    }
    return aux;
}

//SE ENCARGA DE RECORRER LOS ANTERIORES HASTA ENCONTRAR UN NODO QUE NO SEA PISO
NodoMatriz *MatrizOrtogonal::encuentraElAnteriorQueNoEsPiso(NodoMatriz *inicio)
{
    NodoMatriz *aux = inicio;
    while(aux!=NULL)
    {
        if(!aux->EsPiso)//SI ENCUENTRA UNO QUE NO SEA PISO PARA
        {
            break;
        }
        if(aux->anterior!=NULL)
        {
            aux = aux->anterior;
        }
        else
        {
            break;
        }
    }
    if(aux->EsPiso)
    {
        return NULL;
    }
    return aux;
}

//SE ENCARGA DE RECORRER LOS DE ARRIBA HASTA NO ENCONTRAR UN NODO PISO
NodoMatriz *MatrizOrtogonal::encuentraElArribaQueNoEsPiso(NodoMatriz *inicio)
{
    NodoMatriz *aux = inicio;
    while(aux!=NULL)
    {
        if(!aux->EsPiso)
        {
            break;
        }
        if(aux->arriba!=NULL)
        {
            aux = aux->arriba;
        }
        else
        {
            break;
        }
    }
    if(aux->EsPiso)
    {
        return NULL;
    }
    return aux;
}

//SE ENCARGA DE RECORRER LOS DE ABAJO HASTA NO ENCONTRAR UN NODO PISO
NodoMatriz *MatrizOrtogonal::encuentraElAbajoQueNoEsPiso(NodoMatriz *inicio)
{
    NodoMatriz *aux = inicio;
    while(aux!=NULL)
    {
        if(!aux->EsPiso)
        {
            break;
        }
        if(aux->abajo!=NULL)
        {
            aux = aux->abajo;
        }
        else
        {
            break;
        }
    }
    if(aux->EsPiso)
    {
        return NULL;
    }
    return aux;
}

//EL ENCARGADO DE HACER EL GRAFICADO Y DE LLAMAR A LAS FUNCIONES NECESARIAS
void MatrizOrtogonal::escribeMatrizSegunNiveles(std::ofstream &archivo, NodoMatriz *fil, int nivel)
{
    NodoMatriz *aux = fil;
    std::string Original;//LOS STRINGS QUE CONTENDRAN LOS DATOS QUE DEBEN DE MOSTRAR
    std::string Destino;//EL DESTINO
    while(aux!=NULL)
    {
        if(!aux->EsPiso)//SI NO ES UN NODO PISO
        {
            if(aux->siguiente!=NULL)//SI EL SIGUIENTE NO ES NULO
            {
                Original = DatoEnNiveN(aux,nivel);//TOMO EL DATO DE ORIGEN SEGUN SU NIVEL
                if(aux->siguiente->EsPiso)//EL SIGUIENTE ES PISO?
                {//SI LO ES ENTONCES BUSCO EL SIGUIENTE QUE NO SEA PISO...
                    NodoMatriz *next = encuentraElSiguienteQueNoEsPiso(aux->siguiente);
                    if(next!=NULL)//SI SI EXISTE UN SIGUIENTE QUE NO ES NULO
                    {
                        Destino = DatoEnNiveN(next, nivel);//TOMO EL DATO PARA IMPRIMIR
                    }
                    else
                    {//SI NO EXISTE UN SIGUIENTE ENTONCES NO IMPRIMO NADA
                        Destino = "";
                    }
                }
                else//S EL SIGUIENTE NO ES PISO
                {
                    Destino = DatoEnNiveN(aux->siguiente, nivel);
                }
                //AHORA COMPARO SI AMBOS STRINGS TIENEN DATOS...
                if(Original.compare("")!=0 && Destino.compare("")!=0)
                {
                    archivo << "\"" << Original << "\"->\"" << Destino << "\";" << endl;
                }
                else if(Original.compare("")!=0 && Destino.compare("")==0)
                {//SI EL DESTINO NO TIENE INFORMACIÓN SOLO IMPRIME EL ORIGEN
                    archivo << "\"" << Original << "\";" << endl;
                }
                //VACIO LOS STRINGS...
                Destino = "";
                Original = "";
            }
            if(aux->anterior!=NULL)//SI EL ANTERIOR NO ES NULO
            {
                Original = DatoEnNiveN(aux, nivel);
                if(aux->anterior->EsPiso)
                {
                    NodoMatriz *before = encuentraElAnteriorQueNoEsPiso(aux);
                    if(before!=NULL)
                    {
                        Destino = DatoEnNiveN(before, nivel);
                    }
                    else
                    {
                        Destino = "";
                    }
                }
                else
                {
                    Destino = DatoEnNiveN(aux->anterior, nivel);
                }
                if(Original.compare("")!=0 && Destino.compare("")!=0)
                {
                    archivo << "\"" << Original << "\"->\"" << Destino << "\";" << endl;
                }
                else if(Original.compare("")!=0 && Destino.compare("")==0)
                {
                    archivo << "\"" << Original << "\";" << endl;
                }
                Original = "";
                Destino = "";
            }
            if(aux->abajo!=NULL)//SI EL DE ABAJO NO ES NULO
            {
                Original = DatoEnNiveN(aux, nivel);
                if(aux->abajo->EsPiso)
                {
                    NodoMatriz *down = encuentraElAbajoQueNoEsPiso(aux->abajo);
                    if(down!=NULL)
                    {
                        Destino = DatoEnNiveN(down, nivel);
                    }
                    else
                    {
                        Destino = "";
                    }
                }
                else
                {
                    Destino = DatoEnNiveN(aux->abajo, nivel);
                }
                if(Original.compare("")!=0 && Destino.compare("")!=0)
                {
                    archivo << "\"" << Original << "\"->\"" << Destino << "\";" << endl;
                }
                else if(Original.compare("")!=0 && Destino.compare("")==0)
                {
                    archivo << "\"" << Original << "\";" << endl;
                }
                Original = "";
                Destino = "";
            }
            if(aux->arriba!=NULL)//SI EL DE ARRIBA NO ES NULO
            {
                Original = DatoEnNiveN(aux, nivel);
                if(aux->arriba->EsPiso)
                {
                    NodoMatriz *up = encuentraElArribaQueNoEsPiso(aux->arriba);
                    if(up!=NULL)
                    {
                        Destino = DatoEnNiveN(up, nivel);
                    }
                    else
                    {
                        Destino = "";
                    }
                }
                else
                {
                    Destino = DatoEnNiveN(aux->arriba, nivel);
                }
                if(Original.compare("")!=0 && Destino.compare("")!=0)
                {
                    archivo << "\"" << Original << "\"->\"" << Destino << "\";" << endl;
                }
                else if(Original.compare("")!=0 && Destino.compare("")==0)
                {
                    archivo << "\"" << Original << "\";" << endl;
                }
                Original = "";
                Destino ="";
            }
        }
        aux = aux->siguiente;
    }
}

//ENCARGADO DE ENCONTRAR LA INTERSECCIÓN DE UNC COORDENADA EN ESPECÍFICO
NodoMatriz *MatrizOrtogonal::existeInterseccion(int x, int y)
{
    NodoMatriz *aux = encuentraFila(y);//ME DEVUELVE LA POSICIÓN EN Y DE LAS COORDENADAS
    aux = aux->siguiente;
    while(aux!=NULL)//SE ENCARGA DE MOVERSE EN X ENCONTRANDO EL DATO QUE ANDO BUSCANDO
    {
        if(aux->x == x)//AL SER IGUALES ENTONCES HE ENCONTRADO EL DATO QUE BUSCO
        {
            break;
        }
        aux = aux->siguiente;//SINO.. SIGO BUSCANDO
    }
    return aux;
}

//SE ENCARGA DE POSICIONAR EL NODO EN EL LUGAR CORRECTO SEGUN EL NIVEL QUE TENGA
NodoMatriz *MatrizOrtogonal::insertaEnCuboOrdenado(NodoMatriz *inicio, NodoMatriz *nuevo)
{
    NodoMatriz *aux = inicio;
    if(aux->adelante!=NULL)//SI ES EL PRIMERO EN ESE NODO EN IR A Z...
    {
        aux->adelante = nuevo;
        nuevo->atras = aux;
    }
    else//SI YA EXISTEN OTROS NIVELES BUSCA EL LUGAR QUE LE CORRESPONDE
    {
        int bandera = 0;
        while(aux!=NULL)
        {
            if(nuevo->z < aux->z)
            {
                bandera = 1;
                break;
            }
            if(aux->adelante!=NULL)
            {
                aux = aux->adelante;
            }
            else
            {
                break;
            }
        }
        if(bandera == 1)
        {
            aux->atras->adelante = nuevo;
            nuevo->atras = aux->atras;
            nuevo->adelante = aux;
            aux->atras = nuevo;
        }
        if(bandera == 0)
        {
            aux->adelante = nuevo;
            nuevo->atras = aux;
        }
    }
    return inicio;
}

//SE ENCARGA DE RETORNARME UN NODO PISO:
NodoMatriz *MatrizOrtogonal::creaNodoPiso(int x, int y)
{
    Pieza *p = new Pieza("PISO","PISO");
    NodoMatriz *piso = new NodoMatriz(x,y,0,p,true);
    return piso;
}

//EL METODO PARA INGRESAR A LA MATRIZ:
void MatrizOrtogonal::insertarEnMatriz(int x, int y, int z, Pieza *pieza)
{
    NodoMatriz *nuevo = new NodoMatriz(x,y,z,pieza, false);//CREO EL NUEVO NODO A INSERTAR..
    bool SiHayCol = existeColumna(x);//COMPRUEBA SI EXISTE LA COLUMNA A INSERTAR
    bool SiHayFil = existeFila(y);//COMPRUEBA SI EXISTE LA FILA
    if((SiHayCol==false) && (SiHayFil==false))//CASO 1: NO HAY FILA NI COLUMNA...
    {
        NodoMatriz *punteroCol = crearCabeceraColumnas(x);//ENVIO LA COLUMNA QUE DEBE CREAR Y GUARDO LA REFERENCIA
        NodoMatriz *punteroFil = crearCabecerasFilas(y);//ENVIO LA FILA QUE DEBE CREAR Y GUARDO LA REFERENCIA
        if(z > 0)//SI DEBE INSERTARSE EN 3D...
        {
            NodoMatriz *piso = creaNodoPiso(x,y);//CREO EL PISO DONDE SE VA A INSERTAR EL NODO ADELANTE
            punteroCol->abajo = piso;//JUNTO LA CABECERA DE X
            piso->arriba = punteroCol;
            punteroFil->siguiente = piso;//JUNTO LA CABECERA EN Y
            piso->anterior = punteroFil;
            piso = insertaEnCuboOrdenado(piso, nuevo);//LO INSERTA ADELANTE EN EL LUGAR QUE LE CORRESPONDE
        }
        else//SI NO.. ENTONCES ES EN 2D
        {
            punteroCol->abajo = nuevo;//JUNTO LA CABECERA X
            nuevo->arriba = punteroCol;
            punteroFil->siguiente = nuevo;//JUNTO LA CABECERA Y
            nuevo->anterior = punteroFil;
        }
        return;//TERMINA LA INSERCIÓN
    }
    if((SiHayCol==false) && (SiHayFil==true))//CASO 2: HAY FILA PERO NO COLUMNA
    {
        NodoMatriz *punteroCol = crearCabeceraColumnas(x);//CREA LA CABECERA
        NodoMatriz *punteroFil = encuentraFila(y);//BUSCA LA CABECERA EXISTENTE
        if(z > 0)//SI HAY QUE INSERTARLO EN 3D
        {
            NodoMatriz *piso = creaNodoPiso(x,y);//COMO NO EXISTE ESTA INTERSECCIÓN (X,Y) ENTONCES CREO EL PISO
            NodoMatriz *coloca = recorreFila(punteroFil, piso);//EN LA FILA QUE EXISTE PONE EL NODO PISO DONDE CORRESPONDE
            punteroCol->abajo = coloca;//CON LA CABECERA QUE CREE, UNO LOS PUNTEROS
            coloca->arriba = punteroCol;
            coloca = insertaEnCuboOrdenado(coloca, nuevo);//INSERTO EN 3D
        }
        else//SI SE DEBE INSERTAR EN 2D...
        {
            NodoMatriz *colocado = recorreFila(punteroFil, nuevo);
            punteroCol->abajo = colocado;//UNO LOS PUNTEROS CON SUS CABECERAS
            colocado->arriba = punteroCol;
        }
        return;//FINALIZA LA INSERCIÓN
    }
    if((SiHayCol==true) && (SiHayFil==false))//CASO 3: HAY COLUMNA PERO NO FILA
    {
        NodoMatriz *punteroCol = encuentraColumna(x);
        NodoMatriz *punteroFil = crearCabecerasFilas(y);
        if(z > 0)//SI SE DEBE INSERTAR EN 3D
        {
            NodoMatriz *piso = creaNodoPiso(x,y);
            NodoMatriz *colocado = recorreColumna(punteroCol, piso);
            punteroFil->siguiente = colocado;
            colocado->anterior = punteroFil;
            colocado = insertaEnCuboOrdenado(piso, nuevo);
        }
        else//SI ES EN 2D
        {
            NodoMatriz *colocado = recorreColumna(punteroCol, nuevo);
            punteroFil->siguiente = colocado;//HAGO LA UNION DE LOS PUNTEROS
            colocado->anterior = punteroFil;
        }
        return;//FINALIZA LA INSERCIÓN
    }
    if((SiHayCol==true) && (SiHayFil==true))//CASO 4: HAY COLUMNA Y FILA
    {
        if(z > 0)//SI HAY QUE INSERTARLO EN 3D
        {
            NodoMatriz *interseccion = existeInterseccion(x,y);//COMPRUEBO SI EXISTE ESTA COORDENADA (X,Y)
            if(interseccion!=NULL)
            {//SI EXISTE..
                insertaEnCuboOrdenado(interseccion, nuevo);
            }
            else//SI NO EXISTE
            {
                NodoMatriz *piso = creaNodoPiso(x,y);//CREO EL NODO PISO
                NodoMatriz *colum = encuentraColumna(x);
                NodoMatriz *fila = encuentraFila(y);
                NodoMatriz *auxfil = colocaEnFilaConPosicionCorrecta(fila, piso);
                NodoMatriz *auxcol = colocaEnColumnaConPosicionCorrecta(colum, auxfil);
                auxcol = insertaEnCuboOrdenado(auxcol, nuevo);
            }
        }
        else//SI HAY QUE INSERTARLO EN 2D
        {
            NodoMatriz *interseccion = existeInterseccion(x,y);//VE SI ENCUENTRA LA INTERSECCIÓN
            if(interseccion!=NULL)//SI SI EXISTE LA INTERSECCIÓN
            {
                interseccion->pieza = nuevo->pieza;//REEMPLAZO EL DATO DEL PISO CON EL DE LA PIEZA
                interseccion->EsPiso = false;
            }
            else
            {
                NodoMatriz *punteroCol = encuentraColumna(x);//ENCUENTRA LA COLUMNA EXISTENTE
                NodoMatriz *punteroFil = encuentraFila(y);//ENCUENTRA LA FILA EXISTENTE
                NodoMatriz *colfil = colocaEnFilaConPosicionCorrecta(punteroFil, nuevo);//COLOCA EL NODO EN POSICIÓN
                NodoMatriz *coloca = colocaEnColumnaConPosicionCorrecta(punteroCol, colfil);//COLOCA EL NODO EN POSICIÓN
            }
        }
        return;//FIN DE EJECUCIÓN
    }
}

//DEVUELVE EL NUMERO DE DATOS QUE HAY EN COLUMNAS
int MatrizOrtogonal::numeroDeDatosEnColumnas(NodoMatriz *col)
{
    NodoMatriz *aux = col;
    int contador = -1;
    while(aux!=NULL)
    {
        aux = aux->abajo;
        contador = contador+1;
    }
    return contador;
}

//DEVUELVE EL NUMERO DE DATOS QUE HAY EN UNA FILA
int MatrizOrtogonal::numeroDeDatosEnFilas(NodoMatriz *fil)
{
    NodoMatriz *aux = fil;
    int contador = 0;
    while(aux!=NULL)
    {
        if(aux->siguiente!=NULL)//SI EL SIGUIENTE NO ES NULO ENTONCES CONTINUO
        {
            aux = aux->siguiente;
        }
        else
        {//SI LO ES ROMPE EL CICLO Y RETORNA EL NUMERO DE NODOS RECORRIDOS
            break;
        }
        contador = contador+1;
    }
    return contador;
}

//BUSCA EL NODO QUE SE DEBE ELIMINAR DESDE UNA COLUMNA
NodoMatriz *MatrizOrtogonal::punteroEliminarDesdeColumna(NodoMatriz *col, int x, int y, int z)
{
    NodoMatriz *aux = col;
    while(aux!=NULL)
    {
        if(aux->x == x && aux->y == y)
        {
            break;
        }
        aux = aux->abajo;
    }
    return aux;
}

//BUSCA EL NODO QUE SE DEBE ELIMINAR DESDE UNA FILA
NodoMatriz *MatrizOrtogonal::punteroEliminarDesdeFila(NodoMatriz *fila, int x, int y, int z)
{
    NodoMatriz *aux = fila->siguiente;
    while(aux!=NULL)
    {
        if(aux->x == x && aux->y == y)
        {
            break;
        }
        aux = aux->siguiente;
    }
    return aux;
}

//ELIMINADO DE MATRIZ EN EL NIVEL 0
bool MatrizOrtogonal::EliminarDeMatriz(int x, int y, int z)
{
    bool siExisteCol = existeColumna(x);
    bool siExisteFil = existeFila(y);
    if(siExisteCol==true && siExisteFil==true)
    {
        NodoMatriz *punteroCol = encuentraColumna(x);
        NodoMatriz *punteroFil = encuentraFila(y);
        NodoMatriz *elim = punteroEliminarDesdeFila(punteroFil, x,y,z);
        int numFil = numeroDeDatosEnFilas(punteroFil);
        int numCol = numeroDeDatosEnColumnas(punteroCol);
        if(numCol == 1 && numFil == 1)//CASO 1: UN SOLO DATO EN AMBAS CABECERAS
        {
            if(elim->adelante!=NULL)//EXISTEN MAS NODOS ADELANTE (3D)
            {
                elim->pieza->PATH = "PISO";
                elim->pieza->tipo = "PISO";
                elim->pieza->typePieza = "PISO";
                elim->pieza->color = "PISO";
                elim->EsPiso = true;//VUELVO PISO LA PIEZA
            }
            else
            {//SI ES UN NODO QUE NO TIENE NADA ENCIMA...
                punteroCol->anterior->siguiente = punteroCol->siguiente;
                if(punteroCol->siguiente!=NULL)
                {
                    punteroCol->siguiente->anterior = punteroCol->anterior;
                }
                delete punteroCol;//LIBERO LA MEMORIA DEL OBJETO
                punteroFil->arriba->abajo = punteroFil->abajo;
                if(punteroFil->abajo!=NULL)
                {
                    punteroFil->abajo->arriba = punteroFil->arriba;
                }
                delete punteroFil;
                delete elim;//LIBERO DE LA MEMORIA LOS OBJETOS
            }
            return true;
        }
        if(numCol == 1 && numFil > 1)//CASO 2: UN SOLO DATO EN COLS PERO MAS DE UNO EN FILAS
        {
            if(elim->adelante!=NULL)
            {
                elim->pieza->PATH = "PISO";
                elim->pieza->tipo = "PISO";
                elim->pieza->typePieza = "PISO";
                elim->pieza->color = "PISO";
                elim->EsPiso = true;//VUELVO PISO LA PIEZA
            }
            else
            {
                punteroCol->anterior->siguiente = punteroCol->siguiente;
                if(punteroCol->siguiente!=NULL)
                {
                    punteroCol->siguiente->anterior = punteroCol->anterior;
                }
                delete punteroCol;
                elim->anterior->siguiente = elim->siguiente;
                if(elim->siguiente!=NULL)
                {
                    elim->siguiente->anterior = elim->anterior;
                }
                delete elim;
            }
            return true;
        }
        if(numCol > 1 && numFil == 1)//CASO 3: UN SOLO DATO EN FILAS PERO MAS DE UNO EN COLS
        {
            if(elim->adelante!=NULL)
            {
                elim->pieza->PATH = "PISO";
                elim->pieza->tipo = "PISO";
                elim->pieza->typePieza = "PISO";
                elim->pieza->color = "PISO";
                elim->EsPiso = true;//VUELVO PISO LA PIEZA
            }
            else
            {
                punteroFil->arriba->abajo = punteroFil->abajo;
                if(punteroFil->abajo!=NULL)
                {
                    punteroFil->abajo->arriba = punteroFil->arriba;
                }
                delete punteroFil;
                elim->arriba->abajo = elim->abajo;
                if(elim->abajo!=NULL)
                {
                    elim->abajo->arriba = elim->arriba;
                }
                delete elim;
            }
            return true;
        }
        if(numCol > 1 && numFil > 1)//CASO 4: DONDE HAY DE UN DATO EN COLS Y FILS
        {
            if(elim->adelante!=NULL)
            {
                elim->pieza->PATH = "PISO";
                elim->pieza->tipo = "PISO";
                elim->pieza->typePieza = "PISO";
                elim->pieza->color = "PISO";
                elim->EsPiso = true;//VUELVO PISO LA PIEZA
            }
            else
            {
                elim->anterior->siguiente = elim->siguiente;
                if(elim->siguiente!=NULL)
                {
                    elim->siguiente->anterior = elim->anterior;
                }
                elim->arriba->abajo = elim->abajo;
                if(elim->abajo!=NULL)
                {
                    elim->abajo->arriba = elim->arriba;
                }
                delete elim;
            }
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}

//ELIMINADO DE MATRIZ EN EL NIVEL N
bool MatrizOrtogonal::EliminarDeMatriz3D(int x, int y, int z)
{
    bool existeCol = existeColumna(x);
    bool existeFil = existeFila(y);
    if(existeCol == true && existeFil == true)
    {
        NodoMatriz *interseccion = existeInterseccion(x,y);
        NodoMatriz *aux = interseccion;
        while(aux!=NULL)
        {
            if(aux->z == z)
            {
                break;
            }
        }
        if(aux!=NULL)
        {
            aux->atras->adelante = aux->adelante;
            if(aux->adelante!=NULL)
            {
                aux->adelante->atras = aux->atras;
            }
            delete aux;
            if(interseccion->EsPiso == true && interseccion->adelante==NULL)
            {
                EliminarDeMatriz(x,y,z);
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//ELIMINAR GENERAL EL QUE INICIA LAS ELIMINACIONES EN EL JUEGO
bool MatrizOrtogonal::EliminarGeneral(int x, int y, int z)
{
    if(z > 0)
    {
        return EliminarDeMatriz3D(x,y,z);
    }
    else
    {
        return EliminarDeMatriz(x,y,z);
    }
}

//CREA UNA NUEVA LISTA DE LINEALIZACIÓN
void MatrizOrtogonal::creaNuevaLinealizacion(string tipo)
{
    linea = new ListaLinealizacion(tipo);
}

//HACE LA LINEALIZACIÓN POR COLUMNAS
void MatrizOrtogonal::linealizaPorColumnas(int nivel)
{
    if(!matrizVacia())
    {
        NodoMatriz *aux = this->raiz->siguiente;
        while(aux!=NULL)
        {
            NodoMatriz *auxFil = aux->abajo;
            while(auxFil!=NULL)
            {
                std::string ca = DatoEnNiveN(auxFil, nivel);
                if(ca.compare("")!=0 && ca.compare("PISO")!=0)
                {
                    NodoLinealizacion *n = new NodoLinealizacion(ca);
                    this->linea->agregar(n);
                }
                auxFil = auxFil->abajo;
            }
            aux = aux->siguiente;
        }
    }
}

//HACE LA LINEALIZACION POR FILAS
void MatrizOrtogonal::linealizaPorFilas(int nivel)
{
    if(!matrizVacia())
    {
        NodoMatriz *aux = this->raiz->abajo;
        while(aux!=NULL)
        {
            NodoMatriz *auxcol = aux->siguiente;
            while(auxcol!=NULL)
            {
                std::string ca = DatoEnNiveN(auxcol, nivel);
                if(ca.compare("")!=0 && ca.compare("PISO")!=0)
                {
                    NodoLinealizacion *n = new NodoLinealizacion(ca);
                    this->linea->agregar(n);
                }
                auxcol = auxcol->siguiente;
            }
            aux = aux->abajo;
        }
        //this->linea->verLista();
    }
}

//PINTA LOS LABELS DE LAS MATRICES
void MatrizOrtogonal::pintaMatrizLabels(QLabel *mat[8][8], int nivel)
{
    NodoMatriz *fil = this->raiz->abajo;
    while(fil!=NULL)
    {
        NodoMatriz *col = fil->siguiente;
        while(col!=NULL)
        {
            NodoMatriz *auxiliar = nodoEnNivelN(nivel, col);
            if(auxiliar!=NULL)
            {
                if(!auxiliar->EsPiso)
                {
                    QPixmap img(QString::fromStdString(auxiliar->pieza->PATH));
                    mat[col->y-1][col->x-1]->setPixmap(img);
                    mat[col->y-1][col->x-1]->repaint();
                }
                else
                {
                    QPixmap img("");
                    mat[col->y-1][col->x-1]->setPixmap(img);
                    mat[col->y-1][col->x-1]->repaint();
                }
            }
            col = col->siguiente;
        }
        fil = fil->abajo;
    }
}

//ME DEVUELVE EL NODO EN NIVEL N
NodoMatriz *MatrizOrtogonal::nodoEnNivelN(int nivel, NodoMatriz *inicio)
{
    NodoMatriz *aux = inicio;
    bool bandera = false;
    while(aux!=NULL)
    {
        if(aux->z == nivel)
        {
            bandera = true;
            break;
        }
        aux = aux->adelante;
    }
    if(!bandera)
    {
        return NULL;
    }
    return aux;
}

//BUSCA EL NODO QUE COINCIDA
NodoMatriz *MatrizOrtogonal::buscaNodo(string tipoPieza, string color)
{
    if(!matrizVacia())
    {
        //NODO QUE ME SIRVE PARA MOVERSE EN FILAS
        NodoMatriz *fil = this->raiz->abajo;
        while(fil!=NULL)
        {
            //NODO QUE ME SIRVE PARA MOVERSE POR COLUMNAS
            NodoMatriz *col = fil->siguiente;
            while(col!=NULL)
            {
                if(col->pieza->color.compare(color)==0 && col->pieza->typePieza.compare(tipoPieza)==0)
                {//SI ENCUENTRO UNA PIEZA DE IGUAL COLOR Y DE IGUAL TIPO...
                    //CREO UN NODO REORNTO QUE SERA UNA COPIA DE LA INFORMACIÓN QUE TIENE EL NODO QUE ENCONTRE
                    Pieza *copia = new Pieza(col->pieza->tipo, col->pieza->PATH);
                    copia->color = color;
                    copia->typePieza = tipoPieza;
                    NodoMatriz *retorno = new NodoMatriz(col->x,col->y,col->z ,copia, false);
                    std::cout << "encontre el nodo en x: " << retorno->x << " y: " << retorno->y << " z: " << retorno->z << std::endl;
                    return retorno;
                }
                col = col->siguiente;
            }
            fil = fil->abajo;
        }
        return NULL;
    }
    return NULL;
}

//ES EL NODO QUE SE PUEDE BUSCAR
bool MatrizOrtogonal::buscaPeonValido(string tipopieza, string color, int xdes, int ydes, int zdes)
{
    if(!matrizVacia())
    {
        NodoMatriz *fil = this->raiz->abajo;
        while(fil!=NULL)
        {
            NodoMatriz *col = fil->siguiente;
            while(col!=NULL)
            {
                if(col->pieza->typePieza.compare(tipopieza)==0 && col->pieza->color.compare(color)==0)
                {
                    int codigo = validaPeon(col, xdes, ydes, zdes, color);
                    if(codigo!=0)
                    {
                        return muevePeon(col, xdes, ydes, zdes, color, codigo);
                    }
                }
                col = col->siguiente;
            }
            fil = fil->abajo;
        }
    }
    return false;
}

//ES EL NODO ALFIL QUE PUEDE MOVERSE
bool MatrizOrtogonal::bucaAlfilValido(string tipopieza, string color, int xdest, int ydest, int zdest)
{
    if(!matrizVacia())
    {
        NodoMatriz *fil = this->raiz->abajo;
        while(fil!=NULL)
        {
            NodoMatriz *col = fil->siguiente;
            while(col!=NULL)
            {
                if(col->pieza->typePieza.compare(tipopieza)==0 && col->pieza->color.compare(color)==0)
                {
                    int si = validaAlfil(col, xdest, ydest, zdest, color);
                    if(si==1)
                    {
                        Pieza *p = new Pieza(col->pieza->tipo, col->pieza->PATH);
                        p->color = col->pieza->color;
                        p->typePieza = col->pieza->typePieza;
                        NodoMatriz *copia = new NodoMatriz(col->x, col->y, col->z, p, false);
                        return mueveCualquierPieza(copia, xdest, ydest, zdest);

                    }
                }
                col = col->siguiente;
            }
            fil = fil->abajo;
        }
    }
    return false;
}

//SE ENCARGA DE VALIDAR EL ALFILA
int MatrizOrtogonal::validaAlfil(NodoMatriz *ori, int xdest, int ydest, int zdest, string color)
{
    if(xdest == ori->x && ydest!= ori->y)
    {
        if(ydest < ori->y)
        {
            //BUSCAR ARRIBA
            if(ori->arriba==NULL)
            {
                return 1;
            }
            NodoMatriz *ar = encuentraElArribaQueNoEsPiso(ori->arriba);
            if(ar==NULL)
            {
                //MOVER
                return 1;
            }
            if(ar->pieza->typePieza.compare("CABECERA")==0)
            {
                return 1;
            }
            if(ar->y < ydest)
            {
                //MUEVE
                return 1;
            }
            else if(ar->y == ydest)
            {
                if(EsDelColorContrario(color, ar->x, ar->y, ar->z))
                {
                    //MOVER
                    return 1;
                }
            }
        }
        else
        {
            //BUSCAR ABAJO
            if(ori->abajo==NULL)
            {
                return 1;
            }
            NodoMatriz *ab = encuentraElAbajoQueNoEsPiso(ori->abajo);
            if(ab==NULL)
            {
                //MOVER
                return 1;
            }
            if(ydest < ab->y )
            {
                //MUEVE
                return 1;
            }
            else if(ab->y == ydest)
            {
                if(EsDelColorContrario(color, ab->x, ab->y, ab->z))
                {
                    //MOVER
                    return 1;
                }
            }
        }
    }
    else if(xdest!= ori->x && ydest== ori->y)
    {
        if(xdest < ori->x)
        {
            //BUSCAR ANTERIOR
            if(ori->anterior==NULL)
            {
                return 1;
            }
            NodoMatriz *ant = encuentraElAnteriorQueNoEsPiso(ori->anterior);
            if(ant==NULL)
            {
                //MUEVE
                return 1;
            }
            if(ant->pieza->typePieza.compare("CABECERA")==0)
            {
                return 1;
            }
            if(xdest > ant->x)
            {
                //MUEVE
                return 1;
            }
            else if(xdest == ant->x)
            {
                if(EsDelColorContrario(color, ant->x,ant->y, ant->z))
                {
                    //MUEVE
                    return 1;
                }
            }
        }
        else
        {
            //BUSCAR SIGUIENTE
            if(ori->siguiente==NULL)
            {
                return 1;
            }
            NodoMatriz *sig = encuentraElSiguienteQueNoEsPiso(ori->siguiente);
            if(sig==NULL)
            {
                //MOVER
                return 1;
            }
            if(xdest < sig->x)
            {
                //MUEVE
                return 1;
            }
            else if(xdest == sig->x )
            {
                if(EsDelColorContrario(color, sig->x, sig->y, sig->z))
                {
                    //MUEVE
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool MatrizOrtogonal::buscaCaballo(string tipopieza, string color, int xdest, int ydest, int zdest)
{
    if(!matrizVacia())
    {
        NodoMatriz *fil = this->raiz->abajo;
        while(fil!=NULL)
        {
            NodoMatriz *col = fil->siguiente;
            while(col!=NULL)
            {
                if(col->pieza->typePieza.compare(tipopieza)==0 && col->pieza->color.compare(color)==0)
                {
                    //VALIDAR
                    Pieza *p = new Pieza(col->pieza->tipo, col->pieza->PATH);
                    p->color = col->pieza->color;
                    p->typePieza = col->pieza->typePieza;
                    NodoMatriz *copia = new NodoMatriz(col->x, col->y, col->z, p, false);
                    return mueveCualquierPieza(copia, xdest, ydest, zdest);
                }
                col = col->siguiente;
            }
            fil = fil->abajo;
        }
    }
    return false;
}

bool MatrizOrtogonal::validaCaballo(NodoMatriz *ori, string color, int xdest, int ydest, int zdest)
{
    if(xdest != ori->x && ydest != ori->y)
    {
        if( xdest < ori->x && ydest < ori->y )// anterior | arriba
        {

        }
        if( xdest > ori->x && ydest < ori->y)//  arriba /
        {

        }

    }
}

//MUVEL CUALQUIER PIEZA
bool MatrizOrtogonal::mueveCualquierPieza(NodoMatriz *ori, int xdest, int ydest, int zdest)
{
    Pieza *nueva = new Pieza(ori->pieza->tipo, ori->pieza->PATH);
    nueva->color = ori->pieza->color;
    nueva->typePieza = ori->pieza->typePieza;
    insertarEnMatriz(xdest, ydest, zdest, nueva);
    EliminarGeneral(ori->x, ori->y, ori->z);
    return true;
}

//ENCARGADOS DE MOVER LOS PEONES
bool MatrizOrtogonal::muevePeon(NodoMatriz *origen, int xDest, int yDest, int zDest, string color, int codigo)
{
    std::cout << codigo << std::endl;
    if(codigo == 11)
    {
        Pieza *nueva = new Pieza(origen->pieza->tipo, origen->pieza->PATH);
        nueva->color = origen->pieza->color;
        nueva->typePieza = origen->pieza->typePieza;
        insertarEnMatriz(xDest, yDest, zDest, nueva);
        EliminarGeneral(origen->x, origen->y, origen->z);
        return true;
    }
    if(codigo == 21)
    {
        Pieza *nueva = new Pieza(origen->pieza->tipo, origen->pieza->PATH);
        nueva->color = origen->pieza->color;
        nueva->typePieza = origen->pieza->typePieza;
        insertarEnMatriz(xDest,yDest,zDest,nueva);
        EliminarGeneral(origen->x, origen->y,origen->z);
        return true;
    }
    if(codigo == 13)
    {
        Pieza *nueva = new Pieza(origen->pieza->tipo, origen->pieza->PATH);
        nueva->color = origen->pieza->color;
        nueva->typePieza = origen->pieza->typePieza;
        int xori = origen->x;
        int yori = origen->y;
        int zori = origen->z;
        EliminarGeneral(xori,yori,zori);
        insertarEnMatriz(xDest,yDest,zDest,nueva);
        return true;
    }
    return false;
}

int MatrizOrtogonal::validaPeon(NodoMatriz *ori, int xDest, int yDest, int zDest, string color)
{
    if(color.compare("Negro")==0)
    {
        //CASO DE MOVIEMIENTO 1: CASILLA ADELANTE SI ES NEGRO
        if(ori->x==xDest && ori->y+1==yDest)
        {
            if(!existeElNodoDestino(xDest, yDest, zDest))
            {
                //CODIGO QUE LA PIEZA DESTINO NO EXISTE: 11
                return 11;
            }
            else
            {
                //CODIGO DE QUE NO SE REALIZO EL MOVIMIENTO PORQUE NO EXISTE
                return 12;
            }
        }//CASO 2 :DESEA COMER
        if( (xDest==ori->x-1 && yDest == ori->y-1) || (xDest==ori->x+1 && yDest == ori->y-1 ) )
        {
            if(existeElNodoDestino(xDest,yDest,zDest)==true && EsDelColorContrario(color,xDest,yDest,zDest)==true)
            {//SI EL NODO QUE EXISTE ES DEL COLOR CONTRARIO
                return 13;
            }
            else
            {
                return 23;
            }
        }
        return 0;
    }
    else
    {//SI ES BLANCO: CASO 1 MOVER HACIA ADELANTE
        if(ori->x==xDest && ori->y-1==yDest)
        {
            if(!existeElNodoDestino(xDest,yDest,zDest))
            {
                return 21;
            }
            else
            {
                return 22;
            }
        }//CASO QUE DESEA COMER LA BLANCA
        if((xDest==ori->x-1 && yDest == ori->y+1 ) && (xDest==ori->x+1 && yDest == ori->y+1 ))
        {
            if(existeElNodoDestino(xDest,yDest,zDest)==true && EsDelColorContrario(color, xDest, yDest, zDest)==true)
            {
                return 13;
            }
            else
            {
                return 23;
            }
        }

    }
    return 0;
}

bool MatrizOrtogonal::existeElNodoDestino(int x, int y, int z)
{
    NodoMatriz *fil = this->raiz->abajo;
    while(fil!=NULL)
    {
        NodoMatriz *col = fil->siguiente;
        while(col!=NULL)
        {
            if(col->x == x && col->y == y)
            {
                NodoMatriz *aux = nodoEnNivelN(z,col);
                if(aux!=NULL && !aux->EsPiso)
                {
                    return true;
                }
            }
            col = col->siguiente;
        }
        fil = fil->abajo;
    }
    return false;
}

//VERIFICA SI ES DEL COLOR CONTRARIO
bool MatrizOrtogonal::EsDelColorContrario(string color, int x, int y, int z)
{
    NodoMatriz *fil = encuentraFila(y)->siguiente;
    while(fil!=NULL)
    {
        if(fil->x == x && fil->y == y && fil->z == z)
        {
            NodoMatriz *aux = nodoEnNivelN(z,fil);
            if(aux->pieza->color.compare(color)!=0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        fil = fil->siguiente;
    }
    return false;
}

//BUSCA ALA TORRE
bool MatrizOrtogonal::buscaTorre(string tipopieza, string color, int xdest, int ydest, int zdest)
{
    if(!matrizVacia())
    {
        NodoMatriz *fil = this->raiz->abajo;
        while(fil!=NULL)
        {
            NodoMatriz *col = fil->siguiente;
            while(col!=NULL)
            {
                if(col->pieza->typePieza.compare(tipopieza)==0 && col->pieza->color.compare(color)==0)
                {
                    Pieza *p = new Pieza(col->pieza->tipo, col->pieza->PATH);
                    p->color = col->pieza->color;
                    p->typePieza = col->pieza->typePieza;
                    NodoMatriz *copia = new NodoMatriz(col->x, col->y, col->z, p, false);
                    return mueveCualquierPieza(copia, xdest, ydest, zdest);
                }
                col = col->siguiente;
            }
            fil = fil->abajo;
        }
    }
}

//BUSCA AL REY
bool MatrizOrtogonal::buscaRey(string tipopieza, string color, int xdest, int ydest, int zdest)
{
    if(!matrizVacia())
    {
        NodoMatriz *fil = this->raiz->abajo;
        while(fil!=NULL)
        {
            NodoMatriz *col = fil->siguiente;
            while(col!=NULL)
            {
                if(col->pieza->typePieza.compare(tipopieza)==0 && col->pieza->color.compare(color)==0)
                {
                    Pieza *p = new Pieza(col->pieza->tipo, col->pieza->PATH);
                    p->color = col->pieza->color;
                    p->typePieza = col->pieza->typePieza;
                    NodoMatriz *copia = new NodoMatriz(col->x, col->y, col->z, p, false);
                    return mueveCualquierPieza(copia, xdest, ydest, zdest);
                }
                col = col->siguiente;
            }
            fil = fil->abajo;
        }
    }
}

//BUSCA ALA REYNA
bool MatrizOrtogonal::buscaReyna(string tipopieza, string color, int xdest, int ydest, int zdest)
{
    NodoMatriz *fil = this->raiz->abajo;
    while(fil!=NULL)
    {
        NodoMatriz *col = fil->siguiente;
        while(col!=NULL)
        {
            if(col->pieza->typePieza.compare(tipopieza)==0 && col->pieza->color.compare(color)==0)
            {
                Pieza *p = new Pieza(col->pieza->tipo, col->pieza->PATH);
                p->color = col->pieza->color;
                p->typePieza = col->pieza->typePieza;
                NodoMatriz *copia = new NodoMatriz(col->x, col->y, col->z, p, false);
                return mueveCualquierPieza(copia, xdest, ydest, zdest);
            }
            col = col->siguiente;
        }
        fil = fil->abajo;
    }
}

void MatrizOrtogonal::calculaGanador()
{
    this->negros = 0;
    this->blancos = 0;
    if(!matrizVacia())
    {
        NodoMatriz *fil = this->raiz->abajo;
        while(fil!=NULL)
        {
            NodoMatriz *col = fil->siguiente;
            while(col!=NULL)
            {
                if(col->pieza->color.compare("Negro")==0)
                {
                    this->negros = this->negros + 1;
                }
                if(col->pieza->color.compare("Blanco")==0)
                {
                    this->blancos = this->blancos + 1;
                }
                col = col->siguiente;
            }
            fil = fil->abajo;
        }
    }
}
