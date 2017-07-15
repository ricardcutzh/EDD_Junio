#ifndef SISTEMAASIGNACION_H
#define SISTEMAASIGNACION_H
#include <Wt/WApplication>
#include <string>
#include "ui_sistemaasignacion.h"
#include <Wt/WMessageBox>
#include <Wt/WImage>
#include <Wt/WText>
//INCLUYENDO LOS USUARIOS
#include "Clases\Usuario.h"
#include "Clases\NodoUsuario.h"
#include "Clases\ListaUsuarios.h"
//FIN DE INCLUSIÓN DE USUARIOS

//INCLUYENDO LOS SALONES
#include "Clases\Salon.h"
#include "Clases\NodoSalon.h"
#include "Clases\ListaSalones.h"
//FIN DE INCLUSIÓN DE SALONES

//INCLUYENDO LOS EDIFICIOS
#include "Clases\NodoEdificio.h"
#include "Clases\ListaEdificios.h"
//FIN DE INCLUSIÓN DE LOS EDIFICIOS

//INCLUYENDO LOS CURSOS
#include "Clases\NodoCurso.h"
#include "Clases\ListaCursos.h"
#include "Clases\Curso.h"
//FIN DE INCLUSION DE CURSOS

//INCLUYENDO LOS CATEDRATICOS
#include "Clases\Catedratico.h"
#include "Clases\AVLTree.h"
#include "Clases\NodoAVL.h"
//FIN DE INCLUSION DE CATEDRATICOS

//INCLUYENDO HORARIOS
#include "Clases\Pagina.h"
#include "Clases\BTree.h"
#include "Clases\Horario.h"
//FIN DE INCLUSION DE HORARIOS

//INCLUYENDO ASIGNACIONES
#include "Clases\ListadoAsignacion.h"
#include "Clases\NodoAsignacion.h"
//FIN DE INCLUSION DE ASIGNACIONES

//INCLUYENDO ESTUDIANTES
#include "Clases\NodoHash.h"
#include "Clases\TablaHash.h"
//FIN DE LA INCLUSION
class SistemaAsignacion : public Wt::WApplication
{

public:
	SistemaAsignacion(const Wt::WEnvironment& env);
	~SistemaAsignacion();

	// declare slots here
#pragma region UsuariosSlots
	//--USUARIOS----
	void autenticaUsuario();
	void otorgaPermisos(std::string tipo);
	void registraUsuario();
	void editarUsuario();
	void EliminarUsuario();
	void BuscarUsuario();
	void GraficarUsuario();
	//--FIN USUARIOS---
#pragma endregion

#pragma region EdificiosSlots
	//--EDIFICIOS------
	void registreEdificios();
	void buscaEdificio();
	void editaEdificio();
	void eliminaEdificio();
	void GraficaEdificios();
	//--FIN EDIFICIOS--
#pragma endregion

#pragma region SalonesSlots
	//---SALONES
	void registrarNuevoSalon();
	void buscarSalon();
	void modificarSalon();
	void eliminarSalon();
	//---FIN SALONES
#pragma endregion

#pragma region CursosSlots
	//--CURSOS
	void registrarCurso();
	void buscarCurso();
	void modificarCurso();
	void eliminarCurso();
	void graficarCurso();
	//--FIN CURSOS
#pragma endregion

#pragma region HorarioSlots
	//HORARIO
	void registrarHorario();
	void buscarHorario();
	void modificarHorario();
	void eliminarHorario();
	void graficarHorario();
	//FIN HORARIO
#pragma endregion

#pragma region CatedraticoSlots
	void registrarCatedraticos();
	void buscarCatedratico();
	void modificarCaterdratico();
	void eliminarCatedratico();
	void graficarCatedraticos();
#pragma endregion

	void prueba();

#pragma region AsignacionSlots
	void registrarAsignacion();
	void buscarAsignacion();
	void modificarAsignacion();
	void eliminarAsignacion();
	void graficarAsignacion();
#pragma endregion

#pragma region EstudiantesSlots
	void registrarEstudiante();
	void buscarEstudiante();
	void modificarEstudiante();
	void eliminarEstudiante();
#pragma endregion

#pragma region FuncionesDeSistema
	void CargaArchivo();

	void cargaUsuarios(std::string entrada);
	void cargaEstudiantes(std::string entrada);
	void cargaEdificios(std::string entrada);
	void cargarSalones(std::string entrada);
	void cargarCatedraticos(std::string entrada);
	void cargaCursos(std::string entrada);
	void cargarHorarios(std::string entrada);
	void cargarAsignacion(std::string entrada);

	void reporteUno();
	void reporteDos();
	void reporteTres();
	void reporteCuatro();
	void quitarPermisos();
	//QUITA LAS COMILLAS
	std::string quitaComillas(std::string entrada);
#pragma endregion


private:
	Ui_SistemaAsignacion *ui;
	
};

#endif // SISTEMAASIGNACION_H
