#include "TablaHash.h"

TablaHash::TablaHash()
{
    this->m = 37;
    this->nodos = new NodoHash*[37];
    for(int i=0; i<this->m; i++)
    {
        NodoHash *a = new NodoHash();
        this->nodos[i] = a;
    }
    this->totalDatos = 0;
    this->ocupacion = 0;
}

float TablaHash::calculaOcupacion()
{

    float porcentaje = (totalDatos * 100) / this->m;
    //std::cout << porcentaje << " " << this->m << std::endl;
    return porcentaje;
}

int TablaHash::funcionDeDispersion(int carnet)
{
    int clave = carnet % this->m;
    return clave;
}

void TablaHash::insertarEnTablaHash(Estudiante *estudiante)
{
    int index = funcionDeDispersion(estudiante->carnet);
    if(!this->nodos[index]->Ocupado)
    {
        this->nodos[index]->estudiante = estudiante;
        this->nodos[index]->Ocupado = true;
        //this->aux[index]->estudiante = estudiante;
        //this->aux[index]->Ocupado = true;
        this->totalDatos++;
    }
    else
    {
        insertaDispersion(index, estudiante);
    }
    if(calculaOcupacion()>55)
    {
        rehashTabla();
        std::cout << "Rehash: " << this->m << std::endl;
    }
}


int TablaHash::dispersionDoble(int carnet, int i, int iteracion)
{
    int clave = ((carnet % 7) + 1)*iteracion;
    int index = calculaIndexCorrecto(i, clave);
    return index;
}

int TablaHash::calculaIndexCorrecto(int index, int salto)
{
    int nuevo = index + salto;
    if(nuevo < this->m)
    {
        return nuevo;
    }
    else
    {
        nuevo = salto - (this->m - index);
        while(nuevo > this->m)
        {
            nuevo = nuevo - this->m;
        }
        return nuevo;
    }
}

void TablaHash::rehashTabla()
{
    int mAnterior = this->m;
    calculaNuevaM();
    int sizeNewArray = (this->m*55)/100;
    NodoHash *ayuda[sizeNewArray];
    for(int k = 0; k < sizeNewArray; k++)
    {
        ayuda[k] = new NodoHash();
    }
    int contador = 0;
    for(int i=0;i<mAnterior;i++)
    {
        if(this->nodos[i]->Ocupado)
        {
            Estudiante *auxiliar = new Estudiante(this->nodos[i]->estudiante->carnet, this->nodos[i]->estudiante->nombre, this->nodos[i]->estudiante->direccion);
            ayuda[contador] = new NodoHash();
            ayuda[contador]->estudiante = auxiliar;
            ayuda[contador]->Ocupado = true;
            contador++;
        }
    }
    delete this->nodos;
    this->nodos = new NodoHash*[this->m];
    this->totalDatos = 0;
    for(int y = 0; y<this->m; y++)
    {
        this->nodos[y] = new NodoHash();
    }
    for(int x = 0; x<sizeNewArray;x++)
    {
        if(ayuda[x]->estudiante!=NULL)
        {
            insertarEnTablaHash(ayuda[x]->estudiante);
        }
    }
}

void TablaHash::calculaNuevaM()
{
    int mn = this->m+1;
    bool noesprimo = true;
    bool encontre = false;
    while(!encontre)
    {
        for(int i = 2; i<mn; i++)
        {
            if(mn%i==0)
            {
                noesprimo= true;
                break;
            }
        }
        if(!noesprimo)
        {
            encontre = true;
            break;
        }
        mn = mn+1;
        noesprimo = false;
    }
    this->m = mn;
}

//FUNCIÓN DE DISPERSION
void TablaHash::insertaDispersion(int index, Estudiante *estudiante)
{
    int contador = 1;
    //std::cout << "dispersion doble" << std::endl;
    int nuevoIndex = dispersionDoble(estudiante->carnet, index, contador);
    contador++;
    while(nodos[nuevoIndex]->Ocupado)
    {
        //std::cout << "loop " << estudiante->carnet  << std::endl;
        nuevoIndex = dispersionDoble(estudiante->carnet, nuevoIndex, contador);
        contador++;
    }
    this->nodos[nuevoIndex]->estudiante = estudiante;
    this->nodos[nuevoIndex]->Ocupado = true;
    //this->aux[index]->estudiante = estudiante;
    //this->aux[index]->Ocupado = true;
    this->totalDatos++;
}

void TablaHash::verTabla()
{
    std::cout << calculaOcupacion() << std::endl;
    for(int i = 0; i<this->m; i++)
    {
        if(this->nodos[i]->Ocupado)
        {
            std::cout << i << " | " << this->nodos[i]->estudiante->nombre << " | " << this->nodos[i]->estudiante->carnet << std::endl;
        }
    }
}


NodoHash *TablaHash::buscarEstudiante(int carnet)
{
    if(this->totalDatos>0)
    {
        int index = funcionDeDispersion(carnet);
        if(this->nodos[index]->estudiante->carnet == carnet)
        {
            return this->nodos[index];
        }
        else
        {
            int contador = 1;
            index = dispersionDoble(carnet, index, contador);
            while(this->nodos[index]->Ocupado || this->nodos[index]->FueBorrado)
            {
                if(this->nodos[index]->FueBorrado)
                {
                    dispersionDoble(carnet, index, contador);
                }
                else
                {
                    if(this->nodos[index]->estudiante->carnet == carnet)
                    {
                        return this->nodos[index];
                    }
                    dispersionDoble(carnet, index, contador);
                }
                contador++;
            }
        }
        return NULL;
    }
    return NULL;
}

void TablaHash::editarEstudiante(int carnet, std::string nombre, std::string direccion)
{
    if(totalDatos>0)
    {
        NodoHash *edicion = buscarEstudiante(carnet);
        if(edicion->estudiante!=NULL)
        {
            edicion->estudiante->direccion = direccion;
            edicion->estudiante->nombre = nombre;
        }
    }
}

bool TablaHash::eliminar(int carnet)
{
    if(totalDatos>0)
    {
        int index = funcionDeDispersion(carnet);
        if(this->nodos[index]->estudiante->carnet == carnet)
        {
            delete this->nodos[index]->estudiante;
            this->nodos[index]->FueBorrado = true;
            this->nodos[index]->Ocupado = false;
            this->nodos[index]->estudiante = NULL;
            return true;
        }
        else
        {
            int contador = 1;
            index = dispersionDoble(carnet, index, contador);
            contador  = contador +1;
            while(this->nodos[index]->Ocupado || this->nodos[index]->FueBorrado)
            {
                if(this->nodos[index]->FueBorrado)
                {
                    index = dispersionDoble(carnet, index, contador);
                }
                else
                {
                    if(this->nodos[index]->estudiante->carnet == carnet)
                    {
                        delete this->nodos[index]->estudiante;
                        this->nodos[index]->FueBorrado = true;
                        this->nodos[index]->Ocupado = false;
                        this->nodos[index]->estudiante = NULL;
                        return true;
                    }
                    else
                    {
                        index = dispersionDoble(carnet, index, contador);
                    }
                }
                contador++;
            }
            return false;
        }
    }
    else
    {
        return false;
    }
}









