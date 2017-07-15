#include "BTree.h"
#include <exception>
BTree::BTree()
{
    this->p = new Pagina();
    this->xder = new Pagina();
    this->xizq = new Pagina();
}

//VE SI EL ARBOL ESTA VACIO
bool BTree::vacio(Pagina *p)
{
    return (p == NULL || p->cuentas == 0) ? true : false;
}
//METODO PUBLICO ENCARGADO DE HACER LA INSERCIÓN
void BTree::insertarNuevoHorario(Horario *clave)
{
    insertaPrivado(clave, this->p);
}

//METODO PRIVADO QUE HACE EL LLAMADO A LOS DEMAS METODOS
void BTree::insertaPrivado(Horario *clave, Pagina *raiz)
{
    empujar(clave, raiz);
    if(this->empA)
    {
        this->p = new Pagina();
        this->p->cuentas = 1;
        this->p->claves[0] = this->x;
        this->p->ramas[0] = raiz;
        this->p->ramas[1] = this->xr;
    }
    std::cout << "Arbol B inserción completa.." << std::endl;
}

//METODO ENCARGADO DE EMPUJAR
void BTree::empujar(Horario *clave, Pagina *raiz)
{
    int k = 0;
    this->esta = false;
    if(vacio(raiz))
    {
        this->empA = true;
        this->x = clave;
        this->xr = NULL;
    }
    else
    {
        k = buscarNodo(clave, raiz);
        if(this->esta)
        {
            std::cout << "no debe haber claves repetidas.." << std::endl;
            this->empA = false;
        }
        else
        {
            empujar(clave, raiz->ramas[k]);
            if(this->empA)
            {
                if(raiz->cuentas < 4)
                {
                    this->empA = false;
                    meterHoja(this->x, raiz, k);
                }
                else
                {
                    this->empA = true;
                    dividirNodo(this->x, raiz, k);
                }
            }
        }
    }
}

//DIVIDIR NODO
void BTree::dividirNodo(Horario *clave, Pagina *raiz, int k)
{
    int pos = 0;
    int posmda = 0;
    if(k<=2)
    {
        posmda = 2;
    }
    else
    {
        posmda = 3;
    }
    Pagina *mder = new Pagina();
    pos = posmda + 1;
    while(pos!=5)
    {
        mder->claves[(pos-posmda)-1] = raiz->claves[pos - 1];
        mder->ramas[pos - posmda] = raiz->ramas[pos];
        ++pos;
    }
    mder->cuentas = 4 - posmda;
    raiz->cuentas = posmda;
    if(k <= 2)
    {
        meterHoja(clave, raiz, k);
    }
    else
    {
        meterHoja(clave, mder, (k-posmda));
    }
    this->x = raiz->claves[raiz->cuentas - 1];
    mder->ramas[0] = raiz->ramas[raiz->cuentas];
    raiz->cuentas = --raiz->cuentas;
    this->xr = mder;
}

//METODO ENCARGADO DE METER HOJA
void BTree::meterHoja(Horario *clave, Pagina *raiz, int k)
{
    int i = raiz->cuentas;
    while(i != k)
    {
        raiz->claves[i] = raiz->claves[i-1];
        raiz->ramas[i+1] = raiz->ramas[i];
        i--;
    }
    raiz->claves[k] = clave;
    raiz->ramas[k+1] = this->xr;
    raiz->cuentas = ++raiz->cuentas;
}

void BTree::sucesor(Pagina *raiz, int k)
{
    Pagina *q = raiz->ramas[k];
    while(!vacio(q->ramas[0]))
    {
        q = q->ramas[0];
    }
    raiz->claves[k-1] = q->claves[0];
}

void BTree::combina(Pagina *raiz, int pos)
{
    int j;
    this->xder = raiz->ramas[pos];
    this->xizq = raiz->ramas[pos-1];
    this->xizq->cuentas++;
    this->xizq->claves[this->xizq->cuentas - 1] = raiz->claves[pos - 1];
    this->xizq->ramas[this->xizq->cuentas] = this->xder->ramas[0];
    j = 1;
    while(j != this->xder->cuentas + 1)
    {
        this->xizq->cuentas++;
        this->xizq->claves[this->xizq->cuentas - 1] = this->xder->claves[j - 1];
        this->xizq->ramas[this->xizq->cuentas] = this->xder->ramas[j];
        j++;
    }
    quitar(raiz, pos);
}

void BTree::moverDer(Pagina *raiz, int pos)
{
    int i = raiz->ramas[pos]->cuentas;
    while (i != 0) {
        raiz->ramas[pos]->claves[i] = raiz->ramas[pos]->claves[i - 1];
        raiz->ramas[pos]->ramas[i + 1] = raiz->ramas[pos]->ramas[i];
        --i;
    }
    raiz->ramas[pos]->cuentas++;
    raiz->ramas[pos]->ramas[1] = raiz->ramas[pos]->ramas[0];
    raiz->ramas[pos]->claves[0] = raiz->claves[pos - 1];
    raiz->claves[pos - 1] = raiz->ramas[pos - 1]->claves[raiz->ramas[pos - 1]->cuentas - 1];
    raiz->ramas[pos]->ramas[0] = raiz->ramas[pos - 1]->ramas[raiz->ramas[pos - 1]->cuentas];
    raiz->ramas[pos - 1]->cuentas--;
}

void BTree::moverIzq(Pagina *raiz, int pos)
{
    int i;
    raiz->ramas[pos - 1]->cuentas++;
    raiz->ramas[pos - 1]->claves[raiz->ramas[pos - 1]->cuentas - 1] = raiz->claves[pos - 1];
    raiz->ramas[pos - 1]->ramas[raiz->ramas[pos - 1]->cuentas] = raiz->ramas[pos]->ramas[0];
    raiz->claves[pos - 1] = raiz->ramas[pos]->claves[0];
    raiz->ramas[pos]->ramas[0] = raiz->ramas[pos]->ramas[1];
    raiz->ramas[pos]->cuentas--;
    i = 1;
    while (i != raiz->ramas[pos]->cuentas + 1) {
        raiz->ramas[pos]->claves[i - 1] = raiz->ramas[pos]->claves[i];
        raiz->ramas[pos]->ramas[i] = raiz->ramas[pos]->ramas[i + 1];
        i++;
    }
}

void BTree::quitar(Pagina *raiz, int pos)
{
    int j = pos + 1;
    while (j != raiz->cuentas + 1) {
        raiz->claves[j - 2] = raiz->claves[j - 1];
        raiz->ramas[j - 1] = raiz->ramas[j];
        j++;
    }
    raiz->cuentas--;
}

int BTree::buscarNodo(Horario *clave, Pagina *raiz)
{
    int j = 0;
    if (clave->codigo < raiz->claves[0]->codigo) {
        this->esta = false;
        j = 0;
    } else {
        j = raiz->cuentas;
        while (clave->codigo < raiz->claves[j - 1]->codigo && j > 1) {
            --j;
        }
        this->esta = (clave->codigo == raiz->claves[j - 1]->codigo);
    }
    return j;
}

void BTree::restablecer(Pagina *raiz, int pos)
{
    if(pos > 0)
    {
        if(raiz->ramas[pos - 1]->cuentas > 2)
        {
            moverDer(raiz, pos);
        }
        else
        {
            combina(raiz, pos);
        }
    }
    else if(raiz->ramas[1]->cuentas > 2)
    {
        moverIzq(raiz, 1);
    }
    else
    {
        combina(raiz, 1);
    }
}

//INICIA LAS OPERACIONES DE ELIMINAR
void BTree::eliminarHorario(Horario *clave)
{
    if(vacio(this->p))
    {
        //NO ELIMINA
    }
    else
    {
        eliminarPrivad(this->p, clave);
    }
}

//ELIMINAR PRIVADO
void BTree::eliminarPrivad(Pagina *raiz, Horario *clave)
{
    try
    {
        elimarRegistro(raiz, clave);
    }
    catch(int d)
    {
        this->esta = false;
        std::cout << "eerror"<< std::endl;
    }
    if(!esta)
    {
        std::cout << "No se encontro el elemento" << std::endl;
    }
    else
    {
        if(raiz->cuentas == 0)
        {
            raiz = raiz->ramas[0];
        }
        this->p = raiz;
        std::cout << "Elemento eliminado" << std::endl;
    }
}

//ELIMINA EL REGISTRO
void BTree::elimarRegistro(Pagina *raiz, Horario *clave)
{
    int pos = 0;
    Horario *suce;
    if(vacio(raiz))
    {
        this->esta = false;
    }
    else
    {
        pos = buscarNodo(clave, raiz);
        if(esta)
        {
            if(vacio(raiz->ramas[pos - 1]))
            {
                quitar(raiz, pos);
            }
            else
            {
                sucesor(raiz, pos);
                elimarRegistro(raiz->ramas[pos], raiz->claves[pos - 1]);
            }
        }
        else
        {
            elimarRegistro(raiz->ramas[pos], clave);
            if((raiz->ramas[pos]!=NULL) && (raiz->ramas[pos]->cuentas < 2))
            {
                restablecer(raiz, pos);
            }
        }
    }
}

void BTree::graficarArbol()
{
	this->contador = this->contador + 1;
    std::ofstream archivo;
    archivo.open(generaNombreImagen()+".dot");
    if(archivo.fail())
    {
        std::cout << "falla al abrir el archivo de arbol b" << std::endl;
    }
    else
    {
        archivo << "digraph Btree{" << std::endl;
        archivo << "node [shape=box, color=grey87];" << std::endl;
        //LLAMADA AL IMPRIMIR
        enlazarRamas(this->p, archivo);
        archivo << "}";
        archivo.close();
    }
}

void BTree::enlazarRamas(Pagina *p, std::ofstream &archivo)
{
    if(p->cuentas > 0 && p->ramas[0]!=NULL)
    {
        for(int i = 0; i<= p->cuentas; i++)
        {
            if(p->ramas[i]!=NULL)
            {
                if(p->ramas[i]->printPage().compare("")!=0)
                {
                    archivo << "\"" << p->printPage() << "\"->\"" << p->ramas[i]->printPage() << "\";" << std::endl;
                }
                if(p->ramas[i]->printPage().compare("")==0)
                {
                    archivo << "\"" << p->printPage() << "\";" << std::endl;
                }
                enlazarRamas(p->ramas[i], archivo);
            }
        }
    }
}


bool BTree::editarHorario(int codigo, Horario *nuevo)
{
    this->editado = false;
	if (this->p->editarHorario(codigo, nuevo))
	{
		return true;
	}
    editarHorarioPrivado(codigo,nuevo, this->p);
    return this->editado;
}

void BTree::editarHorarioPrivado(int codigo, Horario *nuevo, Pagina *raiz)
{
    if(raiz->cuentas > 0 && raiz->ramas[0]!=NULL)
    {
        for(int i = 0; i<= raiz->cuentas; i++)
        {
            if(raiz->ramas[i]!=NULL)
            {
                if(raiz->ramas[i]->editarHorario(codigo, nuevo))
                {
                    this->editado = true;
                    return;
                }
                else
                {
                    editarHorarioPrivado(codigo, nuevo, raiz->ramas[i]);
                }
            }
        }
    }
}

Horario *BTree::buscarHorario(int codigo)
{
    this->buscado = NULL;
	for (int i = 0; i <= this->p->cuentas; i++)
	{
		if (this->p->claves[i] != NULL)
		{
			if (this->p->claves[i]->codigo == codigo)
			{
				this->buscado = this->p->claves[i];
				return this->buscado;
			}
		}
	}
    buscarPrivado(codigo, this->p);
    return this->buscado;
}

std::string BTree::generaNombreImagen()
{
	return "Horarios\\Horarios_" + std::to_string(this->contador);
}

std::string BTree::reporteDeCursosPorEstudiante(int carnet)
{
	this->cadena = "";
	this->cadena = this->cadena + "<center> <h1> Reporte de Cursos de Estudiante: "+std::to_string(carnet)+" </h1> </center>\n";
	this->cadena = this->cadena + "<table class='table table-striped table-bordered'>";
	this->cadena = this->cadena + "<tr> <th>Curso</th> <th>Zona</th> <th>Final</th> <th>Nota Final</th> </tr>";
	if (this->p != NULL)
	{
		for (int i = 0; i <= this->p->cuentas; i++)
		{
			if (this->p->claves[i] != NULL)
			{
				this->cadena = this->cadena + this->p->claves[i]->asigandos->cursosAsignadosPorEstudiante(carnet, this->p->claves[i]->refCurso->nombre);
			}
		}
	}
	recorreReporteCursosEstudiante(carnet, this->p);
	this->cadena = this->cadena + "</table>\n";
	return this->cadena;
}

std::string BTree::reporteDeAlAsignadosCurso(int codCurso, int year, int semes)
{
	this->cadena = "";
	this->cadena = this->cadena + "<center> <h1>Asignados:</h1> </center>\n";
	this->cadena = this->cadena + "<table class='table table-striped table-bordered'>";
	this->cadena = this->cadena + "<tr> <th>Carnet</th> <th>Nombre</th> <th>Nota Final</th> </tr>";
	if (this->p != NULL)
	{
		for (int i = 0; i <= this->p->cuentas; i++)
		{
			if (this->p->claves[i] != NULL)
			{
				if (this->p->claves[i]->refCurso->codigo == codCurso  && this->p->claves[i]->semestre == semes && this->p->claves[i]->year == year)
				{
					this->cadena = this->cadena + this->p->claves[i]->asigandos->AsignadosACurso(0);
				}
			}
		}
	}
	recorreReporteDeAsignados(codCurso, year, semes, this->p);
	this->cadena = this->cadena + "</table>\n";
	return this->cadena;
}

std::string BTree::reporteDeCursosEnSalon(int salon, int semestre, int year)
{
	this->cadena = "";
	this->cadena = this->cadena + "<center> <h1>Cursos Impartidos en Salon: "+std::to_string(salon)+" </h1> </center>\n";
	this->cadena = this->cadena + "<table class='table table-striped table-bordered'>";
	this->cadena = this->cadena + "<tr> <th>Codigo de Curso</th> <th>Nombre de Curso</th> <th>Periodo</th> <th>Dia</th> </tr>";
	if (this->p != NULL)
	{
		for (int i = 0; i <= this->p->cuentas; i++)
		{
			if (this->p->claves[i] != NULL)
			{
				if (this->p->claves[i]->refSalon->numSalon == salon  && this->p->claves[i]->semestre == semestre && this->p->claves[i]->year == year)
				{
					this->cadena = this->cadena + "<tr>\n";
					this->cadena = this->cadena + "<td>" + std::to_string(this->p->claves[i]->refCurso->codigo) + "</td><td>" + this->p->claves[i]->refCurso->nombre + "</td><td>"+ this->p->claves[i]->rango + "</td><td>"+ this->p->claves[i]->dia + "</td>";
					this->cadena = this->cadena + "</tr>\n";
				}
			}
		}
	}
	recorreReporteDeCursosEnSalon(salon, semestre, year, this->p);
	this->cadena = this->cadena + "</table>\n";
	return this->cadena;
}

std::string BTree::reporteDeAprobReprob(int semestre, int year)
{
	this->cadena = "";
	this->cadena = this->cadena + "<center> <h1>Reporte de Cursos Aprobados y Reprobados  </h1> </center>\n";
	this->cadena = this->cadena + "<table class='table table-striped table-bordered'>";
	this->cadena = this->cadena + "<tr> <th>Carnet</th> <th>Estudiante</th> <th>Nombre de Curso</th> <th>Estatus</th> <th>Nota Final</th> </tr>";
	if (this->p != NULL)
	{
		for (int i = 0; i <= this->p->cuentas; i++)
		{
			if (this->p->claves[i] != NULL)
			{
				this->cadena = this->cadena + this->p->claves[i]->asigandos->aproRepro(this->p->claves[i]->refCurso->nombre);
			}
		}
	}
	recorreReporteDeAprobadoReprob(semestre, year, this->p);
	this->cadena = this->cadena + "</table>\n";
	return this->cadena;
}

void BTree::recorreReporteDeAprobadoReprob(int semestre, int year, Pagina * raiz)
{
	if (raiz->cuentas > 0 && raiz->ramas[0] != NULL)
	{
		for (int i = 0; i <= raiz->cuentas; i++)
		{
			if (raiz->ramas[i] != NULL)
			{
				this->cadena = this->cadena + raiz->ramas[i]->reporteCuatro();
				recorreReporteDeAprobadoReprob(semestre, year, raiz->ramas[i]);
			}

		}
	}
}

void BTree::recorreReporteDeCursosEnSalon(int salon, int semestr, int year, Pagina * raiz)
{
	if (raiz->cuentas > 0 && raiz->ramas[0] != NULL)
	{
		for (int i = 0; i <= raiz->cuentas; i++)
		{
			if (raiz->ramas[i] != NULL)
			{
				this->cadena = this->cadena + raiz->ramas[i]->reporteTres(salon, semestr, year);
				recorreReporteDeCursosEnSalon(salon, semestr, year, raiz->ramas[i]);
			}

		}
	}
}

void BTree::recorreReporteDeAsignados(int codCurso, int year, int semes, Pagina * raiz)
{
	if (raiz->cuentas > 0 && raiz->ramas[0] != NULL)
	{
		for (int i = 0; i <= raiz->cuentas; i++)
		{
			if (raiz->ramas[i] != NULL)
			{
				this->cadena = this->cadena + raiz->ramas[i]->reporteDos(codCurso, year, semes);
				recorreReporteDeAsignados(codCurso, year, semes, raiz->ramas[i]);
			}

		}
	}
}

void BTree::recorreReporteCursosEstudiante(int carnet, Pagina * raiz)
{
	if (raiz->cuentas > 0 && raiz->ramas[0] != NULL)
	{
		for (int i = 0; i <= raiz->cuentas; i++)
		{
			if (raiz->ramas[i] != NULL)
			{
				this->cadena = this->cadena + raiz->ramas[i]->reporteUno(carnet);
				recorreReporteCursosEstudiante(carnet, raiz->ramas[i]);
			}

		}
	}
}

void BTree::buscarPrivado(int codigo, Pagina *raiz)
{
    if(raiz->cuentas > 0 && raiz->ramas[0]!=NULL)
    {
        for(int i = 0; i<= raiz->cuentas; i++)
        {
            if(raiz->ramas[i]!=NULL)
            {
                Horario *aux = raiz->ramas[i]->encuentraHorario(codigo);
                if(aux!=NULL)
                {
                    this->buscado = aux;
                }
                else
                {
                    buscarPrivado(codigo, raiz->ramas[i]);
                }
            }
        }
    }
}


