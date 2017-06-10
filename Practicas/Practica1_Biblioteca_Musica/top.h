#ifndef TOP_H
#define TOP_H
#include <nodotop.h>
#include <string>

class Top
{
public:
    NodoTop *primero;
    std::string tipo;
    int elementos;
    Top(std::string tipo);
    void add(NodoTop *nuevo);
private:
    bool yaExiste(std::string nombre);
    void eliminaUltimo();

};

#endif // TOP_H
