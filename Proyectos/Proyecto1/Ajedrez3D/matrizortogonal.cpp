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
    if((this->raiz->siguiente == NULL) && (this->raiz->abajo == NULL))
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
    Pieza *n = new Pieza(std::to_string(y),std::to_string(y));
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
    while(aux!=NULL)
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
        if(nuevo->y < aux->y)
        {
            bandera = 1;//SI VA DESPUES
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
    system("dot -Tpng Matriz.dot -o Matriz.png");
    archivo.close();
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
    if(aux->EsPiso)
    {
        retorno = "";
    }
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
    if(aux->EsPiso)
    {
        retorno = "";
    }
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
    while(aux!=NULL)
    {
        std::string n = DatoEnNiveN(aux, nivel);
        if(n.compare("")!=0)
        {
            if(n.compare("PISO"))
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
                        Destino = DatoEnNiveN(aux, nivel);
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
                    NodoMatriz *up = encuentraElArribaQueNoEsPiso(aux);
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
                    Destino = DatoEnNiveN(aux, nivel);
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
