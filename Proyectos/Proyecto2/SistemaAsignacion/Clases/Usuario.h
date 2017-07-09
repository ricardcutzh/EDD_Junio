#pragma once
#include <string>
class Usuario
{
public:
	int id;
	std::string nombre;
	std::string password;
	std::string tipo;
	Usuario(int id, std::string nombre, std::string password, std::string tipo);
	~Usuario();
};

