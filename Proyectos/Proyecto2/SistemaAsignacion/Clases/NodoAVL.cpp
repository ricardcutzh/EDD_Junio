#include "NodoAVL.h"

NodoAVL::NodoAVL(Catedratico *catedratico)
{
    this->catedratico = catedratico;
    this->left = NULL;
    this->right = NULL;
    this->height = 1;
}
