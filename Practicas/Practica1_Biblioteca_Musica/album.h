#ifndef ALBUM_H
#define ALBUM_H
#include "listacanciones.h"
#include <string>

class Album
{
public:
    std::string nombre;
    float valoracion;
    Album(std:: string nombre);
    Album();
};

#endif // ALBUM_H
