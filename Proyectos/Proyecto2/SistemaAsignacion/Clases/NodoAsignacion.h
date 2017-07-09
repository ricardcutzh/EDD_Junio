#ifndef NODOASIGNACION_H
#define NODOASIGNACION_H
#include "Estudiante.h"
//NODO DE LISTA ENLAZADA SIMPLE DE ASIGNACIÓN
class NodoAsignacion
{
    public:
        Estudiante *estudiante;
        float zona;
        float exFinal;
        NodoAsignacion *siguiente;
        NodoAsignacion(Estudiante *estudiante, float zona, float exfinal);

    protected:

    private:
};

#endif // NODOASIGNACION_H
