#include "Pagina.h"

Pagina::Pagina()
{
    for(int i = 0; i < 4; i++)
    {
        this->claves[i] = NULL;
    }
    for(int i = 0; i < 5; i++)
    {
        this->ramas[i] = NULL;
    }
    this->cuentas = 0;
}

std::string Pagina::printPage()
{
    std::string cadena = "";
    for(int i = 0; i<this->cuentas ; i++)
    {
        if(claves[i]!=NULL)
        {
            cadena = cadena + "[ codigo: " + convierteNumero(claves[i]->codigo) + " rango: " + claves[i]->rango + " dia: " + claves[i]->dia + " ] ";
        }
    }
    return cadena;
}

Horario *Pagina::encuentraHorario(int codigo)
{
    for(int i = 0; i<this->cuentas; i++)
    {
        if(claves[i]!=NULL)
        {
            if(claves[i]->codigo == codigo)
            {
                return claves[i];
            }
        }
    }
    return NULL;
}

bool Pagina::editarHorario(int codigo, Horario *nuevo)
{
    for(int i = 0; i<this->cuentas; i++)
    {
        if(claves[i]!=NULL)
        {
            if(claves[i]->codigo == codigo)
            {
                claves[i]->dia = nuevo->dia;
                claves[i]->rango = nuevo->rango;
                claves[i]->refCatedra = nuevo->refCatedra;
                claves[i]->refCurso = nuevo->refCurso;
                claves[i]->refSalon = nuevo->refSalon;
                return true;
            }
        }
    }
    return false;
}

std::string Pagina::convierteNumero(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str();
}
