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

std::string Pagina::reporteUno(int carnet)
{
	std::string cadena = "";
	for (int i = 0; i<this->cuentas; i++)
	{
		if (claves[i] != NULL)
		{
			if (claves[i]->asigandos->elementos > 0)
			{
				cadena = cadena + claves[i]->asigandos->cursosAsignadosPorEstudiante(carnet, claves[i]->refCurso->nombre);
			}
		}
	}
	return cadena;
}

std::string Pagina::reporteDos(int codCurso, int year, int semes)
{
	std::string cadena = "";
	for (int i = 0; i<this->cuentas; i++)
	{
		if (claves[i] != NULL)
		{
			if (claves[i]->asigandos->elementos > 0)
			{
				if (claves[i]->refCurso->codigo == codCurso  && claves[i]->semestre == semes && claves[i]->year == year)
				{
					cadena = cadena + claves[i]->asigandos->AsignadosACurso(0);
				}
			}
		}
	}
	return cadena;
}

std::string Pagina::reporteTres(int cod, int semestre, int year)
{
	std::string cadena = "";
	for (int i = 0; i<this->cuentas; i++)
	{
		if (claves[i] != NULL)
		{
			if (claves[i]->asigandos->elementos > 0)
			{
				if (claves[i]->refSalon->numSalon == cod && claves[i]->semestre == semestre && claves[i]->year == year)
				{
					cadena = cadena + "<tr>\n";
					cadena = cadena + "<td>" + std::to_string(claves[i]->refCurso->codigo) + "</td><td>" + claves[i]->refCurso->nombre + "</td><td>" + claves[i]->rango + "</td><td>" + claves[i]->dia + "</td>";
					cadena = cadena + "</tr>\n";
				}
			}
		}
	}
	return cadena;
}

std::string Pagina::reporteCuatro()
{
	std::string cadena = "";
	for (int i = 0; i<this->cuentas; i++)
	{
		if (claves[i] != NULL)
		{
			if (claves[i]->asigandos->elementos > 0)
			{
				cadena = cadena + claves[i]->asigandos->aproRepro(claves[i]->refCurso->nombre);
			}
		}
	}
	return cadena;
}

std::string Pagina::convierteNumero(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str();
}
