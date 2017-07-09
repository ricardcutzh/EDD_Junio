#pragma once
#include "NodoSalon.h"
#include <fstream>
class ListaSalones
{
public:
	NodoSalon *root;
	int elementos;
	ListaSalones();
	~ListaSalones();
	//METODOS
	void addToList(Salon *n);
	bool updateClassroom(int numSalon, int capacidad);
	bool deleteClassroom(int numSalon);
	Salon *searchClassroom(int numSalon);
	void graficaSalon(std::ofstream &archivo, std::string edificio);
private:
	bool estaVacia();
};

