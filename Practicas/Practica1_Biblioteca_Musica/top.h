#ifndef TOP_H
#define TOP_H
#include <nodotop.h>
#include <string>
#include <fstream>

class Top
{
public:
    NodoTop *primero;
    std::string tipo;
    int elementos;
    Top(std::string tipo);
    void add(NodoTop *nuevo);
    void escribirDotTop(std::ofstream &archivo);
private:
    bool yaExiste(std::string nombre);
    void eliminaUltimo();

};

#endif // TOP_H
