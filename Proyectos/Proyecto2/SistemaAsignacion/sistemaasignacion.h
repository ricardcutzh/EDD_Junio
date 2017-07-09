#ifndef SISTEMAASIGNACION_H
#define SISTEMAASIGNACION_H
#include <Wt/WApplication>

#include "ui_sistemaasignacion.h"
//INCLUYENDO LOS USUARIOS
#include "Clases\Usuario.h"
#include "Clases\NodoUsuario.h"
#include "Clases\ListaUsuarios.h"
//FIN DE INCLUSIÓN DE USUARIOS

class SistemaAsignacion : public Wt::WApplication
{

public:
	SistemaAsignacion(const Wt::WEnvironment& env);
	~SistemaAsignacion();

	// declare slots here

private:
	Ui_SistemaAsignacion *ui;
	
};

#endif // SISTEMAASIGNACION_H
