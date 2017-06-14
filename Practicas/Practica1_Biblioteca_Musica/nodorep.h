#ifndef NODOREP_H
#define NODOREP_H
#include<string>

class NodoRep
{
public:
    NodoRep *sig;
    NodoRep *ant;
    std::string nombre;
    std::string path;
    NodoRep(std::string nombre, std::string path);
};

#endif // NODOREP_H
