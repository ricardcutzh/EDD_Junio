#ifndef BTREE_H
#define BTREE_H
#include "Pagina.h"
#include "Horario.h"
#include "iostream"
#include <fstream>
class BTree
{
    public:
		std::string cadena;
		int contador = 0;
        Pagina *p;
        Pagina *xder;
        Pagina *xizq;
        Horario *x;
        Pagina *xr;
        bool editado;
        Horario *buscado;
        bool empA = false;
        bool esta = false;
        BTree();
        void insertarNuevoHorario(Horario *clave);
        void eliminarHorario(Horario *clave);
        void graficarArbol();
        bool editarHorario(int codigo, Horario *nuevo);
        Horario *buscarHorario(int codigo);
		std::string generaNombreImagen();
		std::string reporteDeCursosPorEstudiante(int carnet);
		std::string reporteDeAlAsignadosCurso(int codCurso, int year, int semes);
		std::string reporteDeCursosEnSalon(int salon, int semestre, int year);
		std::string reporteDeAprobReprob(int semestre, int year);
    protected:

    private:
		void recorreReporteDeAprobadoReprob(int semestre, int year, Pagina *raiz);
		void recorreReporteDeCursosEnSalon(int salon, int semestr, int year, Pagina *raiz);
		void recorreReporteDeAsignados(int codCurso, int year, int semes, Pagina *raiz);
		void recorreReporteCursosEstudiante(int carnet, Pagina *raiz);
        void buscarPrivado(int codigo, Pagina *raiz);
        void editarHorarioPrivado(int codigo, Horario *nuevo, Pagina *raiz);
        void insertaPrivado(Horario *clave, Pagina *raiz);
        void empujar(Horario *clave, Pagina *raiz);
        void meterHoja(Horario *clave, Pagina *raiz, int k);
        void dividirNodo(Horario *clave, Pagina *raiz, int k);
        void sucesor(Pagina *raiz, int k);
        void combina(Pagina *raiz, int pos);
        void moverDer(Pagina *raiz, int pos);
        void moverIzq(Pagina *raiz, int pos);
        void quitar(Pagina *raiz, int pos);
        void restablecer(Pagina *raiz, int pos);
        int buscarNodo(Horario *clave, Pagina *raiz);
        bool vacio(Pagina *p);
        void eliminarPrivad(Pagina *raiz, Horario *clave);
        void elimarRegistro(Pagina *raiz, Horario *clave);
        void enlazarRamas(Pagina *pagina, std::ofstream &archivo);
};

#endif // BTREE_H
