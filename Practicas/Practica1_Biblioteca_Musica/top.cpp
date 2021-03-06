#include "top.h"

//LISTA DOBLE PARA GENERAR MIS REPORTES DE TOPS
//YA SEA ALBUMES, CANCIONES O ARTISTAS
Top::Top(std::string tipo)//YA SEA CANCIONES O ALBUMES 0 ARTISTAS
{
    this->tipo = tipo;
    this->primero = new NodoTop("Root",0);//MI NODO QUE SOSTIENE MI LISTA DE TOPS
    this->elementos = 0;
}

//METODOS
//PRIVADOS
bool Top::yaExiste(std::string nombre)
{
    if(this->elementos == 0)
    {
        return false;//SI NO HAY ELEMENTOS ENTONCES NO EXISTE
    }
    else
    {
        NodoTop *temp = this->primero->sig;//TOMO EL PRIMERO
        std::string compa;//MI STRING AUX PARA COMPARAR
        while(temp!=NULL)
        {
            compa = temp->nombre;
            if(nombre.compare(compa)==0)//COMPARO SI SON IGUALES
            {
                return true;//SI LO SON YA EXISTE Y RETORNO
            }
            temp = temp->sig;//ME MUEVO AL SIGUIENTE EN LISTA
        }
    }
    return false;//EN CASO DE QUE NO LO ENCUENTRE DEVUELVO FALSO
}

//PUBLICOS
void Top::add(NodoTop *nuevo)
{
    if(!yaExiste(nuevo->nombre))
    {
        if(this->elementos == 0)
        {
            this->primero->sig = nuevo;
            nuevo->ant = this->primero;
            this->elementos++;
        }
        else
        {
            int tipo = 0;
            NodoTop *aux = this->primero->sig;
            while (aux!=NULL) {
                if(nuevo->valoracion > aux->valoracion)
                {
                    tipo = 1;
                    break;
                }
                if(aux->sig==NULL)
                {
                    break;
                }
                aux = aux->sig;
            }
            if(tipo == 1)//DE QUE LA VALORACIÓN SEA MAS BAJA
            {
                aux->ant->sig = nuevo;
                nuevo->ant = aux->ant;
                nuevo->sig = aux;
                aux->ant = nuevo;
                this->elementos = this->elementos+1;
            }
            else//EN CASO DE QUE EL NUEVO SEA MAS ALTA BUSCARA SU LUGAR ANTES QUE EL AUXILIAR
            {

                aux->sig = nuevo;
                nuevo->ant = aux;
                this->elementos = this->elementos+1;
            }
        }
        if(this->elementos>5){
            eliminaUltimo();
        }
    }
}

void Top::eliminaUltimo()
{
    NodoTop *temp = this->primero->sig;
    while (temp->sig!=NULL) {
        temp = temp->sig;
    }
    temp->ant->sig = NULL;
    free(temp);
    temp = NULL;
    this->elementos--;
}

void Top::escribirDotTop(std::ofstream &archivo)
{
    archivo << "digraph top{" << std::endl;
    archivo << "node [shape=box];" << std::endl;
    archivo << "label=\"Top 5" << this->tipo << "\";" << std::endl;
    NodoTop *aux = this->primero->sig;
    while(aux!=NULL)
    {
        if(aux->sig!=NULL)
        {
            archivo << "\"Nombre: " << aux->nombre << " | Val: " << aux->valoracion << "\"->\"Nombre: " << aux->sig->nombre << " | Val: " << aux->sig->valoracion << "\";" << std::endl;
        }
        else
        {
            archivo << "\"Nombre: " << aux->nombre << " | Val: " << aux->valoracion << "\";" << std::endl;
        }
        aux = aux->sig;
    }
    archivo << "}" << std::endl;
}
