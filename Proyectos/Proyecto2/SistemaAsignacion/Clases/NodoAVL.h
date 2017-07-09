#ifndef NODOAVL_H
#define NODOAVL_H
#include "Catedratico.h"

class NodoAVL
{
    public:
        Catedratico *catedratico;
        int height;
        NodoAVL *left;
        NodoAVL *right;
        NodoAVL(Catedratico *catedratico);

    protected:

    private:
};

#endif // NODOAVL_H
