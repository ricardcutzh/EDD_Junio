#ifndef PAGINA_H
#define PAGINA_H
#include "Horario.h"
#include <string>
#include <sstream>

class Pagina
{
    public:
        Horario *claves[4];
        Pagina *ramas[5];
        int cuentas;
        Pagina();
        std::string printPage();
        std::string convierteNumero(int n);
        Horario *encuentraHorario(int codigo);
        bool editarHorario(int codigo, Horario *nuevo);
    protected:

    private:
};

#endif // PAGINA_H
