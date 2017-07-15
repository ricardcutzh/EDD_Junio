#include "sistemaasignacion.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>
int numError = 0;
//ESTRUTURAS:
//--USUARIOS:
ListaUsuarios *usuarios = new ListaUsuarios();
Usuario *usLog;
//--FIN USUARIOS
//--EDIFICIOS
ListaEdificios *edificios = new ListaEdificios();
//--FIN EDIFICIOS
//--CURSOS
ListaCursos *cursos = new ListaCursos();
//--FIN CURSOS
//--CATEDRATICOS
AVLTree *arbol = new AVLTree();
//--FIN CATEDRATICOS
//--HORARIOS
BTree *btree = new BTree();
//--FIN HORARIOS
//--ESTUDIANTES
TablaHash *tabla = new TablaHash();
//--FIN ESTUDIANTES
SistemaAsignacion::SistemaAsignacion(const Wt::WEnvironment& env) : Wt::WApplication(env), ui(new Ui_SistemaAsignacion)
{
	std::cout << "NUEVA APLICACION GENERADA" << std::endl;
	ui->setupUi(root());
	//SLOTS CONECCTIONS
#pragma region ConeccionesSlots

	ui->botonLogIn->clicked().connect(this, &SistemaAsignacion::autenticaUsuario);
	ui->botInsertaUs->clicked().connect(this, &SistemaAsignacion::registraUsuario);
	ui->btnSearchModUs->clicked().connect(this, &SistemaAsignacion::BuscarUsuario);
	ui->btnModUs->clicked().connect(this, &SistemaAsignacion::editarUsuario);
	ui->btnElimUs->clicked().connect(this, &SistemaAsignacion::EliminarUsuario);
	ui->RepUsuarios->clicked().connect(this, &SistemaAsignacion::GraficarUsuario);

	ui->btnNuevoEdif->clicked().connect(this, &SistemaAsignacion::registreEdificios);
	ui->btnModBuscar->clicked().connect(this, &SistemaAsignacion::buscaEdificio);
	ui->btnMod->clicked().connect(this, &SistemaAsignacion::editaEdificio);
	ui->btnElim->clicked().connect(this, &SistemaAsignacion::eliminaEdificio);

	ui->btnSalonNuevo->clicked().connect(this, &SistemaAsignacion::registrarNuevoSalon);
	ui->btnBuscarEdiSal->clicked().connect(this, &SistemaAsignacion::buscarSalon);
	ui->btnModSalon->clicked().connect(this, &SistemaAsignacion::modificarSalon);
	ui->btnElimSalon->clicked().connect(this, &SistemaAsignacion::eliminarSalon);
	ui->RepEdiSa->clicked().connect(this, &SistemaAsignacion::GraficaEdificios);

	ui->btnNuevoCurso->clicked().connect(this, &SistemaAsignacion::registrarCurso);
	ui->btnSrcCursoMod->clicked().connect(this, &SistemaAsignacion::buscarCurso);
	ui->btnModCurso->clicked().connect(this, &SistemaAsignacion::modificarCurso);
	ui->btnElimCurso->clicked().connect(this, &SistemaAsignacion::eliminarCurso);
	ui->btnRepCurso->clicked().connect(this, &SistemaAsignacion::graficarCurso);

	ui->btnNuevoCat->clicked().connect(this, &SistemaAsignacion::registrarCatedraticos);
	ui->btnSrcCat->clicked().connect(this, &SistemaAsignacion::buscarCatedratico);
	ui->btnModCat->clicked().connect(this, &SistemaAsignacion::modificarCaterdratico);
	ui->btnElimCat->clicked().connect(this, &SistemaAsignacion::eliminarCatedratico);
	ui->verCat->clicked().connect(this, &SistemaAsignacion::graficarCatedraticos);

	ui->btnNuHor->clicked().connect(this, &SistemaAsignacion::registrarHorario);
	ui->btnSrcHor->clicked().connect(this, &SistemaAsignacion::buscarHorario);
	ui->btnNuMod->clicked().connect(this, &SistemaAsignacion::modificarHorario);
	ui->btnSrcHor_cp->clicked().connect(this, &SistemaAsignacion::eliminarHorario);
	ui->RepHorario->clicked().connect(this, &SistemaAsignacion::graficarHorario);

	ui->btnNuevoEstudiante->clicked().connect(this, &SistemaAsignacion::registrarEstudiante);
	ui->srcBtnModEstu->clicked().connect(this, &SistemaAsignacion::buscarEstudiante);
	ui->btnModEstud->clicked().connect(this, &SistemaAsignacion::modificarEstudiante);
	ui->btnElimEstud->clicked().connect(this, &SistemaAsignacion::eliminarEstudiante);

	ui->button->clicked().connect(this, &SistemaAsignacion::registrarAsignacion);
	ui->button_cp->clicked().connect(this, &SistemaAsignacion::buscarAsignacion);
	ui->button_cp_cp->clicked().connect(this, &SistemaAsignacion::modificarAsignacion);
	ui->button_cp_cp_cp->clicked().connect(this, &SistemaAsignacion::eliminarAsignacion);
	ui->RepAsigna->clicked().connect(this, &SistemaAsignacion::graficarAsignacion);

	ui->botonPath->clicked().connect(this, &SistemaAsignacion::CargaArchivo);
	ui->button_cp_cp_cp_cp->clicked().connect(this, &SistemaAsignacion::reporteUno);
	ui->btnRep2->clicked().connect(this, &SistemaAsignacion::reporteDos);
	ui->btnRep3->clicked().connect(this, &SistemaAsignacion::reporteTres);
	ui->btnRep4->clicked().connect(this, &SistemaAsignacion::reporteCuatro);
	ui->logOutBtn->clicked().connect(this, &SistemaAsignacion::quitarPermisos);
#pragma endregion
	//END SLOTS

	ui->btnVerHasEst->clicked().connect(this, &SistemaAsignacion::prueba);

	ui->userPassword->setEchoMode(Wt::WLineEdit::Password);//INICIALIZA EL CAMPO DE CONTRASEÑA PARA ESCONDER LOS CARACTERES
    ui->cargaTab->setHidden(true);
	ui->usuariosTab->setHidden(true);
	ui->ediSalTab->setHidden(true);
	ui->cursosTab->setHidden(true);
	ui->estuTab->setHidden(true);
	ui->cateTab->setHidden(true);
	ui->horarioTab->setHidden(true);
	ui->asignaTab->setHidden(true);
	ui->verCursosTab->setHidden(true);
	ui->logOutTab->setHidden(true);
}

SistemaAsignacion::~SistemaAsignacion()
{
	delete ui;
}

//METODOS PARA CONTROLAR LOS USUARIOS
#pragma region UsuariosController
//METODOS DE USUARIOS:
void SistemaAsignacion::autenticaUsuario()
{
	std::string nombre = ui->UserName->text().toUTF8();
	std::string password = ui->userPassword->text().toUTF8();
	if (nombre.compare("") != 0 && password.compare("") != 0)
	{
		if (usuarios->autentica(nombre, password))
		{
			if (nombre.compare("Admin") == 0 && password.compare("Admin") == 0)
			{
				usLog = new Usuario(0, "Admin", "Admin", "sudo");
				otorgaPermisos(usLog->tipo);
			}
			else
			{
				Usuario *aux = usuarios->buscarUsuarioNom(nombre, password);
				usLog = aux;
				otorgaPermisos(usLog->tipo);
			}
			ui->UserName->setText("");
			ui->userPassword->setText("");
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Inicio de Sesion", "Usuario Ingresado al Sistema Correctamente", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			ui->panel->setTitle("Sistema de Asignacion: Bienvenido " + usLog->nombre);
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Usuario No existe en el sistema", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error","Llene los campos necesarios",Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//METODO QUE OTORGA PERMISOS DEPENDIENDO DE SU TIPO
void SistemaAsignacion::otorgaPermisos(std::string tipo)
{
	ui->LogInTab->setHidden(true);
	if (tipo.compare("sudo") == 0)
	{
		ui->usuariosTab->setHidden(false);
		ui->cargaTab->setHidden(false);
		ui->ediSalTab->setHidden(false);
		ui->cursosTab->setHidden(false);
		ui->estuTab->setHidden(false);
		ui->cateTab->setHidden(false);
		ui->horarioTab->setHidden(false);
		ui->asignaTab->setHidden(false);
		ui->verCursosTab->setHidden(false);
		ui->logOutTab->setHidden(false);
		return;
	}
	if (tipo.compare("Colaborador") == 0)
	{
		ui->ediSalTab->setHidden(false);
		ui->cursosTab->setHidden(false);
		ui->estuTab->setHidden(false);
		ui->cateTab->setHidden(false);
		ui->horarioTab->setHidden(false);
		ui->asignaTab->setHidden(false);
		ui->verCursosTab->setHidden(false);
		ui->logOutTab->setHidden(false);
		return;
	}
	if (tipo.compare("Estudiante") == 0)
	{
		return;
	}
	ui->logOutTab->setHidden(false);
}

//REGISTRO DE USUARIOS
void SistemaAsignacion::registraUsuario()
{
	std::string ids = ui->usIdInserta->text().toUTF8();
	std::string nombre = ui->usNombreInserta->text().toUTF8();
	std::string password = ui->usPassInserta->text().toUTF8();
	std::string tipo = ui->comboUsTipoInserta->valueText().toUTF8();
	if (ids.compare("") != 0 && nombre.compare("") != 0 && password.compare("") != 0 && tipo.compare("") != 0)
	{
		int id = std::stoi(ids);
		Usuario *nuevo = new Usuario(id, nombre, password, tipo);
		usuarios->addToList(nuevo);
		ui->usIdInserta->setText("");
		ui->usNombreInserta->setText("");
		ui->usPassInserta->setText("");
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//MODIFICACIÓN DE USUARIOS
void SistemaAsignacion::editarUsuario()
{
	std::string ids = ui->usModId->text().toUTF8();
	std::string nombre = ui->usNomMod->text().toUTF8();
	std::string password = ui->usPassMod->text().toUTF8();
	if (ids.compare("") != 0 && nombre.compare("") != 0 && password.compare("") != 0)
	{
		int id = std::stoi(ids);
		NodoUsuario *aux = usuarios->buscarUsuario(id);
		if (aux != NULL)
		{
			if (usuarios->updateUser(id, nombre, password, aux->user->tipo))
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Información", "Usuario Actualizado Exitosamente!", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
				ui->usModId->setText("");
				ui->usNomMod->setText("");
				ui->usPassMod->setText("");
			}
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios Para buscar Usuario", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//ELIMINACIÓN DE USUARIOS
void SistemaAsignacion::EliminarUsuario()
{
	std::string ids = ui->usElimID->text().toUTF8();
	if (ids.compare("") != 0)
	{
		int id = std::stoi(ids);
		if (usuarios->deleteUser(id))
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Información", "Usuario Eliminado del sistema", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			ui->usElimID->setText("");
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios Para Eliminar Usuario", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//BUSCAR UN USUARIO PARA EDICION
void SistemaAsignacion::BuscarUsuario()
{
	std::string ids = ui->usModId->text().toUTF8();
	if (ids.compare("") != 0)
	{
		int id = std::stoi(ids);
		NodoUsuario *aux = usuarios->buscarUsuario(id);
		if (aux != NULL)
		{
			ui->usNomMod->setText(Wt::WString::fromUTF8(aux->user->nombre));
			ui->usPassMod->setText(Wt::WString::fromUTF8(aux->user->password));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Usuario No Existe en el Sistema", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios Para buscar Usuario", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//GENERA IMAGEN Y LA COLOCA EN SU LUGAR
void SistemaAsignacion::GraficarUsuario()
{
	usuarios->writeGraph();
	std::string comando = "dot -Tpng " + usuarios->generaNombreImagen() + ".dot -o " + usuarios->generaNombreImagen() + ".png";
	char *c = strdup(comando.c_str());
	system(c);
	ui->conteUsuarios->clear();
	Wt::WImage *image = new Wt::WImage(Wt::WLink(usuarios->generaNombreImagen() + ".png"), ui->conteUsuarios);
	ui->conteUsuarios->refresh();
}


#pragma endregion

//METODOS PARA CONTROLLAR LOS EDIFICIOS
#pragma region EdificiosController
//METODO PARA REGISTRAR EDIFICIOS
void SistemaAsignacion::registreEdificios()
{
	std::string nombre = ui->ediInsertar->text().toUTF8();
	if (nombre.compare("") != 0)
	{
		NodoEdificio *nuevo = new NodoEdificio(nombre);
		edificios->addToList(nuevo);
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Edificio Registrado", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
		ui->ediInsertar->setText("");
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//METODO PARA BUSCAR UN EDIFICIO
void SistemaAsignacion::buscaEdificio()
{
	std::string nom = ui->ModEdificioNombre->text().toUTF8();
	if (nom.compare("") != 0)
	{
		NodoEdificio *aux = edificios->buscarEdificio(nom);
		if (aux != NULL)
		{
			ui->NombreNuevoMod->setText(Wt::WString::fromUTF8(aux->nombre));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Edificio no Existe en Sistema", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios para modificar ediicios", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//METODO PARA EDITAR EL EDIFICIO
void SistemaAsignacion::editaEdificio()
{
	std::string nuevoNombre = ui->NombreNuevoMod->text().toUTF8();
	if (nuevoNombre.compare("") != 0)
	{
		if (edificios->modificarEdificio(ui->ModEdificioNombre->text().toUTF8(), nuevoNombre))
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Edificio Modificado", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			ui->ModEdificioNombre->setText("");
			ui->NombreNuevoMod->setText("");
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se Modifico el Edificio", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios Para editar Edificio", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//METODO PARA ELIMINAR EDIFICIO
void SistemaAsignacion::eliminaEdificio()
{
	std::string nomElim = ui->ElimEdificio->text().toUTF8();
	if (nomElim.compare("") != 0)
	{
		if (edificios->deleteEdificio(nomElim))
		{
			ui->ElimEdificio->setText("");
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Edificio Eliminado", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se elimino del sistema", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llene los campos necesarios Para eliminar Edificio", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//METODO PARA GRAFICAR EDIFICIO
void SistemaAsignacion::GraficaEdificios()
{
	edificios->GraficarEdificios();
	std::string comando = "dot -Tpng " + edificios->generaNombreDeImagen() + ".dot -o " + edificios->generaNombreDeImagen() + ".png";
	char *c = strdup(comando.c_str());
	system(c);
	ui->conteEdiSa->clear();
	Wt::WImage *image = new Wt::WImage(Wt::WLink(edificios->generaNombreDeImagen()+ ".png"), ui->conteEdiSa);
	ui->conteEdiSa->refresh();
}

#pragma endregion

//METODOS PARA CONTROLAR LOS SALONES
#pragma region SalonesController

//METODO ENCARGADO DEL REGISTRO DE LOS SALONES
void SistemaAsignacion::registrarNuevoSalon()
{
	std::string numSalon = ui->SalonNuevo->text().toUTF8();
	std::string capacidad = ui->SalonCapacidad->text().toUTF8();
	std::string edif = ui->EdificioSalAsociar->text().toUTF8();
	if (numSalon.compare("") != 0 && capacidad.compare("") != 0 && edif.compare("") != 0)
	{
		NodoEdificio *aux = edificios->buscarEdificio(edif);
		if (aux != NULL)
		{
			int numS = std::stoi(numSalon);
			int capa = std::stoi(capacidad);
			Salon *nuevo = new Salon(numS, capa);
			aux->salones->addToList(nuevo);
			ui->SalonNuevo->setText("");
			ui->SalonCapacidad->setText("");
			ui->EdificioSalAsociar->setText("");
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Salon Asociado Exitosamente", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "El edificio no existe", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "LLene Los campos necesarios", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//METODO ENCARGADO DE BUSCAR UN SALON CORRESPONDIENTE 
void SistemaAsignacion::buscarSalon()
{
	std::string idSalon = ui->ModNumSalon->text().toUTF8();
	std::string idEdificio = ui->ModEdiAsociado->text().toUTF8();
	if (idSalon.compare("") != 0 && idEdificio.compare("") != 0)
	{
		NodoEdificio *aux = edificios->buscarEdificio(idEdificio);
		if (aux != NULL)
		{
			int ids = std::stoi(idSalon);
			Salon *auxS = aux->salones->searchClassroom(ids);
			if (auxS != NULL)
			{
				ui->nuevoNumeroMod->setText(Wt::WString::fromUTF8(std::to_string(auxS->numSalon)));
				ui->capacidadNuevaMod->setText(Wt::WString::fromUTF8(std::to_string(auxS->capacidad)));
			}
			else
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Salon No Existe en este edificio", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Edificio No Existe", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error Busquedad de Salon", "Llene los campos necesarios para hacer la búsquedad", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//MODIFICA EL SALON BUSCADO
void SistemaAsignacion::modificarSalon()
{
	std::string idSalonAn = ui->ModNumSalon->text().toUTF8();
	std::string idEdif = ui->ModEdiAsociado->text().toUTF8();
	std::string nuevoNume = ui->nuevoNumeroMod->text().toUTF8();
	std::string capaNueva = ui->capacidadNuevaMod->text().toUTF8();
	if (nuevoNume.compare("") != 0 && capaNueva.compare("") != 0 && idSalonAn.compare("")!=0 && idEdif.compare("")!=0)
	{
		NodoEdificio *auxEd = edificios->buscarEdificio(idEdif);
		if (auxEd!=NULL)
		{
			int nums = std::stoi(idSalonAn);
			Salon *auxSa = auxEd->salones->searchClassroom(nums);
			if (auxSa != NULL)
			{
				int nuNum = std::stoi(nuevoNume);
				int nuCap = std::stoi(capaNueva);
				if (auxEd->salones->updateClassroom(nums, nuCap, nuNum))
				{
					Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Salon Actualizado Existosamente", Wt::Information, Wt::Ok);
					messageBox->show();
					messageBox->buttonClicked().connect(std::bind([=]() {
						delete messageBox;
					}));
					ui->ModNumSalon->setText("");
					ui->ModEdiAsociado->setText("");
					ui->nuevoNumeroMod->setText("");
					ui->capacidadNuevaMod->setText("");
				}
				else
				{
					Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Se pudo Actualizar el Salon", Wt::Information, Wt::Ok);
					messageBox->show();
					messageBox->buttonClicked().connect(std::bind([=]() {
						delete messageBox;
					}));
					ui->ModNumSalon->setText("");
					ui->ModEdiAsociado->setText("");
					ui->nuevoNumeroMod->setText("");
					ui->capacidadNuevaMod->setText("");
				}
			}
			else
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Salon No Existe", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Edificio no existe", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan Campos necesarios para modificar salon", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

//ELIMINA EL SALON ESPECIFICADO
void SistemaAsignacion::eliminarSalon()
{
	std::string ids = ui->elimSalonID->text().toUTF8();
	std::string idEd = ui->ElimEdifAsociado->text().toUTF8();
	if (ids.compare("") != 0 && idEd.compare("") != 0)
	{
		NodoEdificio *aux = edificios->buscarEdificio(idEd);
		if(aux != NULL)
		{
			int id = std::stoi(ids);
			if (aux->salones->deleteClassroom(id))
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Salon Eliminado Exitosamente", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
				ui->elimSalonID->setText("");
				ui->ElimEdifAsociado->setText("");
			}
			else
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se pudo eliminar el salon", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "El Edificio no existe", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Campos aun sin llenar", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

#pragma endregion

//METODOS PARA CONTROLAR LOS CURSOS
#pragma region CursosController
void SistemaAsignacion::registrarCurso()
{
	std::string idCurso = ui->NuevoCursoID->text().toUTF8();
	std::string nombre = ui->NomCursoNuevo->text().toUTF8();
	std::string sem = ui->SemesCursoNuevo->text().toUTF8();
	std::string cre = ui->CreCursNu->text().toUTF8();
	if (idCurso.compare("") != 0 && nombre.compare("") != 0 && sem.compare("") != 0 && cre.compare("") != 0)
	{
		int id = std::stoi(idCurso);
		int cr = std::stoi(cre);
		int semestre = std::stoi(sem);
		Curso *curso = new Curso(id, nombre, semestre, cr);
		cursos->addCourseToList(curso);
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Curso Registrado Exitosamente", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Falta llenar campos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::buscarCurso()
{
	std::string idcurso = ui->IDModCurso->text().toUTF8();
	if (idcurso.compare("") != 0)
	{
		int cod = std::stoi(idcurso);
		Curso *aux = cursos->buscarCurso(cod);
		if (aux != NULL)
		{
			ui->NomModCurso->setText(Wt::WString::fromUTF8(aux->nombre));
			ui->SemModCurso->setText(Wt::WString::fromUTF8(std::to_string(aux->semestre)));
			ui->CredModCurso->setText(Wt::WString::fromUTF8(std::to_string(aux->creditos)));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Curso no existe en el sistema", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No hay un ID de Curso", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::modificarCurso()
{
	std::string idcurso = ui->IDModCurso->text().toUTF8();
	std::string nombre = ui->NomModCurso->text().toUTF8();
	std::string semestre = ui->SemModCurso->text().toUTF8();
	std::string creditos = ui->CredModCurso->text().toUTF8();
	if (idcurso.compare("") != 0 && nombre.compare("") != 0 && semestre.compare("") != 0 && creditos.compare("") != 0)
	{
		int id = std::stoi(idcurso);
		int sem = std::stoi(semestre);
		int credi = std::stoi(creditos);
		if (cursos->updateCourse(id, nombre, sem, credi))
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Información", "Curso Actualizado", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			ui->IDModCurso->setText("");
			ui->NomModCurso->setText("");
			ui->SemModCurso->setText("");
			ui->CredModCurso->setText("");
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se logro Actualizar el curso", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Falta llenar campos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::eliminarCurso()
{
	std::string idCurso = ui->elimCursoID->text().toUTF8();
	if (idCurso.compare("") != 0)
	{
		int id = std::stoi(idCurso);
		if (cursos->deleteCourse(id))
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Curso eliminado", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			ui->elimCursoID->setText("");
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se elimino el curso", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Falta llenar campos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::graficarCurso()
{
	cursos->graphCourseList();
	std::string comando = "dot -Tpng " + cursos->generaNombreImagen() + ".dot -o " + cursos->generaNombreImagen()+ ".png";
	char *c = strdup(comando.c_str());
	system(c);
	ui->cursoContenedorImg->clear();
	Wt::WImage *image = new Wt::WImage(Wt::WLink(cursos->generaNombreImagen() + ".png"), ui->cursoContenedorImg);
	ui->cursoContenedorImg->refresh();
}

#pragma endregion

//METODOS PARA CONTROLAR LOS CATEDRATICOS
#pragma region CatedraticosController
void SistemaAsignacion::registrarCatedraticos()
{
	std::string ids = ui->nuevoCatID->text().toUTF8();
	std::string nomb = ui->nuevoCatNom->text().toUTF8();
	std::string dir = ui->nuevoDirCat->text().toUTF8();
	if (ids.compare("") != 0 && nomb.compare("") != 0 && dir.compare("") != 0)
	{
		int id = std::stoi(ids);
		Catedratico *nuevo = new Catedratico(id, nomb, dir);
		arbol->addToTree(nuevo);
		ui->nuevoCatID->setText("");
		ui->nuevoCatNom->setText("");
		ui->nuevoDirCat->setText("");
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Catedratico creado", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::buscarCatedratico()
{
	std::string idb = ui->ModCatID->text().toUTF8();
	if (idb.compare("") != 0)
	{
		int id = std::stoi(idb);
		Catedratico *aux = arbol->buscarCatedratico(id);
		if (aux != NULL)
		{
			ui->ModNomCat->setText(Wt::WString::fromUTF8(aux->nombre));
			ui->ModDirCat->setText(Wt::WString::fromUTF8(aux->direccion));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Catedratico no existe", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::modificarCaterdratico()
{
	std::string idb = ui->ModCatID->text().toUTF8();
	std::string nom = ui->ModNomCat->text().toUTF8();
	std::string dir = ui->ModDirCat->text().toUTF8();
	if (idb.compare("") != 0 && nom.compare("") != 0 && dir.compare("") != 0)
	{
		int id = std::stoi(idb);
		arbol->updateCatedratico(id, nom, dir);
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Catedratico actualizado", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
		ui->ModCatID->setText("");
		ui->ModNomCat->setText("");
		ui->ModDirCat->setText("");
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}

}

void SistemaAsignacion::eliminarCatedratico()
{
	std::string id = ui->ElimIDCat->text().toUTF8();
	if (id.compare("") != 0)
	{
		int ids = std::stoi(id);
		arbol->deleteFromTree(ids);
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Información", "Catedrático Eliminado", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::graficarCatedraticos()
{
	arbol->graphTree();
	std::string comando = "dot -Tpng " + arbol->generaNombreImagen() + ".dot -o " + arbol->generaNombreImagen() + ".png";
	char *c = strdup(comando.c_str());
	system(c);
	ui->catRepoConte->clear();
	Wt::WImage *image = new Wt::WImage(Wt::WLink(arbol->generaNombreImagen() + ".png"), ui->catRepoConte);
	ui->catRepoConte->refresh();
}

#pragma endregion

//METODOS PARA CONTROLAR LOS HORARIOS
#pragma region HorarioController

void SistemaAsignacion::registrarHorario()
{
	std::string idPeriodo = ui->HorarioNuevoID->text().toUTF8();
	std::string periodo = ui->NuPerHor->text().toUTF8();
	std::string dia = ui->NuDiaHor->text().toUTF8();
	int codCurso = std::stoi(ui->NuCodCursoHor->text().toUTF8());
	int codSalon = std::stoi(ui->CodSalHorarioNu->text().toUTF8());
	std::string codEdif = ui->CodEdiHorNu->text().toUTF8();
	int codCat = std::stoi(ui->CodCatHorNu->text().toUTF8());
	int sem = std::stoi(ui->SemHorNu->text().toUTF8());
	int year = std::stoi(ui->YearHorNu->text().toUTF8());
	if (idPeriodo.compare("") != 0 && periodo.compare("") != 0 && dia.compare("") != 0)
	{
		Curso *curso = cursos->buscarCurso(codCurso);
		NodoEdificio *ed = edificios->buscarEdificio(codEdif);
		Salon *sal = ed->salones->searchClassroom(codSalon);
		Catedratico *cat = arbol->buscarCatedratico(codCat);
		if (curso != NULL && ed != NULL && sal != NULL && cat != NULL)
		{
			int id = std::stoi(idPeriodo);
			Horario *nuevo = new Horario(id, periodo, dia, sal, cat, curso, sem, year, codEdif);
			btree->insertarNuevoHorario(nuevo);
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Información", "Horario Creado Satisfactoriamente", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Datos invalidos", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}

	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Campos faltantes", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::buscarHorario()
{
	int idHor = std::stoi(ui->HorarioModID_cp->text().toUTF8());
	Horario *aux = btree->buscarHorario(idHor);
	if (aux != NULL)
	{
		ui->ModPerHor->setText(Wt::WString::fromUTF8(aux->rango));
		ui->ModDiaHor->setText(Wt::WString::fromUTF8(aux->dia));
		ui->ModCodCursoHor->setText(Wt::WString::fromUTF8(std::to_string(aux->refCurso->codigo)));
		ui->CodSalHorarioMod->setText(Wt::WString::fromUTF8(std::to_string(aux->refSalon->numSalon)));
		ui->CodCatHorMod->setText(Wt::WString::fromUTF8(std::to_string(aux->refCatedra->id)));
		ui->CodEdiHorMod->setText(Wt::WString::fromUTF8(aux->edif));
		ui->SemHorMod->setText(Wt::WString::fromUTF8(std::to_string(aux->semestre)));
		ui->YearHorMod->setText(Wt::WString::fromUTF8(std::to_string(aux->year)));
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Horario no existe", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::modificarHorario()
{
	int idHor = std::stoi(ui->HorarioModID_cp->text().toUTF8());
	try
	{
		std::string periodo = ui->ModPerHor->text().toUTF8();
		std::string dia = ui->ModDiaHor->text().toUTF8();
		int codCurso = std::stoi(ui->ModCodCursoHor->text().toUTF8());
		int codSal = std::stoi(ui->CodSalHorarioMod->text().toUTF8());
		int codCat = std::stoi(ui->CodCatHorMod->text().toUTF8());
		std::string edif = ui->CodEdiHorMod->text().toUTF8();
		int sem = std::stoi(ui->SemHorMod->text().toUTF8());
		int year = std::stoi(ui->YearHorMod->text().toUTF8());
		Curso *curso = cursos->buscarCurso(codCat);
		NodoEdificio *edi = edificios->buscarEdificio(edif);
		Salon *salon = edi->salones->searchClassroom(codSal);
		Catedratico *cate = arbol->buscarCatedratico(codCat);
		int semestre = std::stoi(ui->SemHorMod->text().toUTF8());
		//int year = std::stoi(ui->YearHorMod->text().toUTF8());
		Horario *hor = new Horario(idHor, periodo, dia, salon, cate, curso, semestre, year, edif);
		btree->editarHorario(idHor, hor);
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Horario actualizado", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
		ui->HorarioModID_cp->setText("");
		ui->ModPerHor->setText("");
		ui->ModDiaHor->setText("");
		ui->ModCodCursoHor->setText("");
		ui->CodSalHorarioMod->setText("");
		ui->CodCatHorMod->setText("");
		ui->CodEdiHorMod->setText("");
		ui->SemHorMod->setText("");
		ui->YearHorMod->setText("");
	}
	catch (int s)
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se pude modificar el horario", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::eliminarHorario()
{
	std::string s = ui->HorarioIDElim->text().toUTF8();
	if (s.compare("") != 0)
	{
		int idelim = std::stoi(ui->HorarioIDElim->text().toUTF8());
		Horario *claveElim = btree->buscarHorario(idelim);
		if (claveElim != NULL)
		{
			btree->eliminarHorario(claveElim);
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Horario Eliminado", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Horario No Eliminado", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Campos Incompletos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::graficarHorario()
{
	btree->graficarArbol();
	std::string comando = "dot -Tpng " + btree->generaNombreImagen() + ".dot -o " + btree->generaNombreImagen() + ".png";
	char *c = strdup(comando.c_str());
	system(c);
	ui->conteHorario->clear();
	Wt::WImage *image = new Wt::WImage(Wt::WLink(btree->generaNombreImagen() + ".png"), ui->conteHorario);
	ui->conteHorario->refresh();
}

#pragma endregion

//METODOS PARA CONTROLAR LA ASIGNACIÓN
#pragma region AsignacionController
void SistemaAsignacion::registrarAsignacion()
{
	std::string idAl = ui->NuAsigIDAl->text().toUTF8();
	std::string idHor = ui->NuAsigHorID->text().toUTF8();
	std::string zona = ui->NuAsigZona->text().toUTF8();
	std::string fin = ui->NuAsigExFinal->text().toUTF8();
	if (idAl.compare("") != 0 && idHor.compare("") != 0 && zona.compare("") != 0 && fin.compare("") != 0)
	{
		int idA = std::stoi(idAl);
		int idHo = std::stoi(idHor);
		Horario *ho = btree->buscarHorario(idHo);
		NodoHash *es = tabla->buscarEstudiante(idA);
		if(ho != NULL && es!=NULL)
		{
			float z = std::stof(zona);
			float ex = std::stof(fin);
			if (!ho->asigandos->cupoLleno())
			{
				ho->asigandos->asignarEstudiante(es->estudiante, z, ex);
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Estudiante Asignado", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
			else
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Cupo lleno!", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
			ui->NuAsigExFinal->setText("");
			ui->NuAsigHorID->setText("");
			ui->NuAsigZona->setText("");
			ui->NuAsigExFinal->setText("");
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Existe el Horario", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos por ser llenados", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::buscarAsignacion()
{
	std::string idAl = ui->ModAsigIDAl->text().toUTF8();
	std::string idHor = ui->ModAsigHorID->text().toUTF8();
	if (idAl.compare("") != 0 && idHor.compare("") != 0)
	{
		int idH = std::stoi(idAl);
		int idA = std::stoi(idHor);
		Horario *aux = btree->buscarHorario(idH);
		if (aux != NULL)
		{
			NodoAsignacion *auxi = aux->asigandos->buscarAsignacion(idA);
			if (auxi != NULL)
			{
				ui->ModAsigZona->setText(Wt::WString::fromUTF8(std::to_string(auxi->zona)));
				ui->ModAsignExFinal->setText(Wt::WString::fromUTF8(std::to_string(auxi->exFinal)));
			}
			else
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Hay Alumno Asignado", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Existe este horario", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos por ser llenados", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::modificarAsignacion()
{
	std::string idAl = ui->ModAsigIDAl->text().toUTF8();
	std::string idHor = ui->ModAsigHorID->text().toUTF8();
	std::string zona = ui->ModAsigZona->text().toUTF8();
	std::string fin = ui->ModAsignExFinal->text().toUTF8();
	if (zona.compare("") != 0 && fin.compare("") != 0)
	{
		Horario *aux = btree->buscarHorario(std::stoi(idHor));
		if (aux != NULL)
		{
			NodoAsignacion *auxi = aux->asigandos->buscarAsignacion(std::stoi(idAl));
			if (auxi != NULL)
			{
				auxi->exFinal = std::stof(fin);
				auxi->zona = std::stof(zona);
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Inforamcion", "Asignacion actualizada", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
				ui->ModAsigIDAl->setText("");
				ui->ModAsigHorID->setText("");
				ui->ModAsigHorID->setText("");
				ui->ModAsigZona->setText("");
			}
			else
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Existe esta Asignacion", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Existe este horario", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Datos imcompletos", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::eliminarAsignacion()
{
	std::string idAl = ui->ElimAsigIDAl->text().toUTF8();
	std::string idHor = ui->ElimAsigHorID->text().toUTF8();
	if (idAl.compare("") != 0 && idHor.compare("") != 0)
	{
		int idA = std::stoi(idAl);
		int idH = std::stoi(idHor);
		Horario *aux = btree->buscarHorario(idH);
		if (aux != NULL)
		{
			if (aux->asigandos->desasignarEstudianteDecurso(idA))
			{
				ui->ElimAsigHorID->setText("");
				ui->ElimAsigIDAl->setText("");
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("informacion", "Alumno Desasignado", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
			else
			{
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se completo la desasignacion", Wt::Information, Wt::Ok);
				messageBox->show();
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
			}
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Existe este horario", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Campos vacios", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::graficarAsignacion()
{
	int id = std::stoi(ui->idHorarioRepAsignacion->text().toUTF8());
	Horario *aux = btree->buscarHorario(id);
	if (aux != NULL)
	{
		ui->tablaHorario->clear();
		Wt::WText *text1 = new Wt::WText(aux->asigandos->htmlAsignacion(), ui->tablaHorario);
	}
	else
	{
		ui->tablaHorario->clear();
		Wt::WText *text1 = new Wt::WText("<h1>Horario No Existe</h1>", ui->tablaHorario);
	}
}

#pragma endregion

//METODOS PARA CONTROLAR LOS ESTUDIANTES
#pragma region EstudiantesController
void SistemaAsignacion::registrarEstudiante()
{
	std::string carnet = ui->IDEstudianteNuevo->text().toUTF8();
	std::string nombre = ui->NomEstudNuevo->text().toUTF8();
	std::string dir = ui->DirEstNuevo->text().toUTF8();
	if (dir.compare("") != 0 && nombre.compare("") != 0 && carnet.compare("") != 0)
	{
		int id = std::stoi(carnet);
		Estudiante *nuevo = new Estudiante(id, nombre, dir);
		tabla->insertarEnTablaHash(nuevo);
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Estudiante Registrado", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
		ui->IDEstudianteNuevo->setText("");
		ui->NomEstudNuevo->setText("");
		ui->DirEstNuevo->setText("");
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Campos no llenados", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::buscarEstudiante()
{
	std::string ides = ui->IDModEstudiante->text().toUTF8();
	if (ides.compare("") != 0)
	{
		int id = std::stoi(ides);
		NodoHash *aux = tabla->buscarEstudiante(id);
		if (aux != NULL)
		{
			ui->ModNombreEstud->setText(aux->estudiante->nombre);
			ui->ModDirEstud->setText(aux->estudiante->direccion);
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No Existen registros de este estudiante", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos por ser llenados", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::modificarEstudiante()
{
	std::string ides = ui->IDModEstudiante->text().toUTF8();
	std::string nom = ui->ModNombreEstud->text().toUTF8();
	std::string dir = ui->ModDirEstud->text().toUTF8();
	if (ides.compare("") != 0 && nom.compare("") != 0 && dir.compare("") != 0)
	{
		int id = std::stoi(ides);
		tabla->editarEstudiante(id, nom, dir);
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Estudiante editado", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
		ui->IDModCurso->setText("");
		ui->ModNombreEstud->setText("");
		ui->ModDirEstud->setText("");
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos por ser llenados", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::eliminarEstudiante()
{
	std::string idelim = ui->elimEstudID->text().toUTF8();
	if (idelim.compare("") != 0)
	{
		int id = std::stoi(idelim);
		if (tabla->eliminar(id))
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("informacion", "Estudiante Eliminado", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			ui->elimEstudID->setText("");
		}
		else
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se Elimino el Estudiante", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Faltan campos por ser llenados", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

#pragma endregion

#pragma region Funciones
void SistemaAsignacion::CargaArchivo()
{
	std::string pth = ui->PathText->text().toUTF8();
	if (pth.compare("") != 0)
	{
		std::ifstream archivo(pth);
		if (!archivo.is_open())
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "No se abrio el archivo", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
		else
		{
			std::string linea = "";
			std::string aux = "";
			while (archivo.good())
			{
				std::getline(archivo, linea, ';');
				std::getline(archivo, aux, '\n');
				if (linea[0] == 'U')
				{
					cargaUsuarios(linea);
				}
				if (linea[0] == 'E' && linea[1] == 's')
				{
					cargaEstudiantes(linea);
				}
				if (linea[0] == 'E' && linea[1] == 'd')
				{
					cargaEdificios(linea);
				}
				if (linea[0] == 'S')
				{
					cargarSalones(linea);
				}
				if (linea[0] == 'C'  && linea[1]=='a')
				{
					cargarCatedraticos(linea);
				}
				if (linea[0] == 'C' && linea[1] == 'u')
				{
					cargaCursos(linea);
				}
				if (linea[0] == 'H')
				{
					cargarHorarios(linea);
				}
				if (linea[0] == 'A')
				{
					cargarAsignacion(linea);
				}
			}
			ui->PathText->setText("");
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Archivo Cargado Correctamente!", Wt::Information, Wt::Ok);
			messageBox->show();
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
		}
	}
	else
	{
		Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", "Llena el campo de archivo", Wt::Information, Wt::Ok);
		messageBox->show();
		messageBox->buttonClicked().connect(std::bind([=]() {
			delete messageBox;
		}));
	}
}

void SistemaAsignacion::cargaUsuarios(std::string entrada)
{
	std::string sub = entrada.substr(8);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//AQUI EMPIEZO A RECOLECTAR LOS DATOS DEL USUARIO PARA INSERTARLO
	std::string ids;
	std::string nombre;
	std::string password;
	std::string tipo;
	std::stringstream nueva(sub2);
	std::getline(nueva, ids, ',');
	std::getline(nueva, nombre, ',');
	std::getline(nueva, password, ',');
	password = quitaComillas(password);
	std::getline(nueva, tipo, '_');
	int idn = std::stoi(ids);
	if (tipo.compare("colaborador") == 0)
	{
		tipo = "Colaborador";
	}
	if (tipo.compare("estudiante") == 0)
	{
		tipo = "Estudiante";
	}
	//INSERTO EN LA LISTA
	Usuario *nuevo = new Usuario(idn, nombre, password, tipo);
	usuarios->addToList(nuevo);
}

void SistemaAsignacion::cargaEstudiantes(std::string entrada)
{
	std::string sub = entrada.substr(11);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//EMPIEZO A RECOLECTAR INFORMACION
	std::string carnet;
	std::string nombre;
	std::string direccion;
	std::stringstream n(sub2);
	std::getline(n, carnet, ',');
	std::getline(n, nombre, ',');
	std::getline(n, direccion, '_');
	nombre = quitaComillas(nombre);
	direccion = quitaComillas(direccion);
	int id = std::stoi(carnet);
	Estudiante *es = new Estudiante(id, nombre, direccion);
	tabla->insertarEnTablaHash(es);
}

void SistemaAsignacion::cargaEdificios(std::string entrada)
{
	std::string sub = entrada.substr(9);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//EMPIEZO A RECOLECTAR INFORMACION
	std::string edif;
	std::stringstream n(sub2);
	std::getline(n, edif, '_');
	edif = quitaComillas(edif);
	NodoEdificio *nuevo = new NodoEdificio(edif);
	edificios->addToList(nuevo);
}

void SistemaAsignacion::cargarSalones(std::string entrada)
{
	std::string sub = entrada.substr(6);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//EMPIEZO A RECOLECTAR INFORMACIÓN
	std::string edif;
	std::string numSalon;
	std::string capacidad;
	std::stringstream n(sub2);
	std::getline(n, edif, ',');
	edif = quitaComillas(edif);
	std::getline(n, numSalon, ',');
	std::getline(n, capacidad, '_');
	int nums = std::stoi(numSalon);
	int capac = std::stoi(capacidad);
	NodoEdificio *aux = edificios->buscarEdificio(edif);
	
	if (aux != NULL)
	{
		std::cout << aux->nombre << " "  << numSalon << " " << capac << std::endl;
		Salon *s = new Salon(nums, capac);
		aux->salones->addToList(s);
	}
	else
	{
		numError = numError + 1;
	}
}

void SistemaAsignacion::cargarCatedraticos(std::string entrada)
{
	std::string sub = entrada.substr(12);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//EMPIEZO A RECOLECTAR
	std::string id;
	std::string nombre;
	std::string direccion;
	std::stringstream n(sub2);
	std::getline(n, id, ',');
	std::getline(n, nombre, ',');
	std::getline(n, direccion, '_');
	nombre = quitaComillas(nombre);
	direccion = quitaComillas(direccion);
	//std::cout << id << " " << nombre << " " << direccion << std::endl;
	int idi = std::stoi(id);
	Catedratico *nuevo = new Catedratico(idi, nombre, direccion);
	arbol->addToTree(nuevo);
}

void SistemaAsignacion::cargaCursos(std::string entrada)
{
	std::string sub = entrada.substr(6);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//EMPIEZO A RECOLECTAR LA INFORMACION
	std::string cod;
	std::string nombre;
	std::string semestre;
	std::string creditos;
	std::stringstream n(sub2);
	std::getline(n, cod, ',');
	std::getline(n, nombre, ',');
	nombre = quitaComillas(nombre);
	std::getline(n, semestre, ',');
	std::getline(n, creditos, '_');
	//std::cout << cod << " " << nombre << " " << semestre << " " << creditos << std::endl;
	int codi = std::stoi(cod);
	int sem = std::stoi(semestre);
	int cre = std::stoi(creditos);
	Curso *nuevo = new Curso(codi, nombre, sem, cre);
	cursos->addCourseToList(nuevo);
}

void SistemaAsignacion::cargarHorarios(std::string entrada)
{
	std::string sub = entrada.substr(8);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//EMPIEZO A RECOLECTAR LA INFORMACION
	std::string id;
	std::string periodo;
	std::string dia;
	std::string codcurso;
	std::string numsal;
	std::string edif;
	std::string codCat;
	std::string sem;
	std::string year;
	std::stringstream n(sub2);
	std::getline(n, id, ',');
	int ids = std::stoi(id);
	std::getline(n, periodo, ',');
	periodo = quitaComillas(periodo);
	std::getline(n, dia, ',');
	dia = quitaComillas(dia);
	std::getline(n, codcurso, ',');
	int idcor = std::stoi(codcurso);
	std::getline(n, numsal, ',');
	int nums = std::stoi(numsal);
	std::getline(n, edif, ',');
	//edif = quitaComillas(edif);
	std::getline(n, codCat, ',');
	int codcat = std::stoi(codCat);
	std::getline(n, sem, ',');
	int semes = std::stoi(sem);
	std::getline(n, year, '_');
	int yeari = std::stoi(year);
	Curso *c = cursos->buscarCurso(idcor);
	NodoEdificio *edi = edificios->buscarEdificio(edif);
	Salon *s = NULL;
	if (edi != NULL)
	{
		s = edi->salones->searchClassroom(nums);
	}
	else
	{
		std::cout << "No Encontre edificio" << std::endl;
	}
	Catedratico *cat = arbol->buscarCatedratico(codcat);
	if (c != NULL && s != NULL && cat != NULL)
	{
		Horario *nuevo = new Horario(ids, periodo, dia, s, cat, c, semes, yeari, edif);
		btree->insertarNuevoHorario(nuevo);
	}
	else
	{
		std::cout << "Cat es nulo o salon o curso" << std::endl;
		numError++;
	}
}

void SistemaAsignacion::cargarAsignacion(std::string entrada)
{
	std::string sub = entrada.substr(8);
	std::string sub2 = sub.substr(0, sub.length() - 1);
	//EMPIEZO A RECOLECTAR LA INFORMACION
	std::string carnet;
	std::string idhor;
	std::string zona;
	std::string exfinal;
	std::stringstream n(sub2);
	std::getline(n, carnet, ',');
	int car = std::stoi(carnet);
	std::getline(n, idhor, ',');
	int idHora = std::stoi(idhor);
	std::getline(n, zona, ',');
	float z = std::stof(zona);
	std::getline(n, exfinal, '_');
	float exf = std::stof(exfinal);
	//NodoHash *es = tabla->buscarEstudiante(car);
	Estudiante * es = tabla->buscarEnTablaHash(car);
	Horario *hor = btree->buscarHorario(idHora);
	if (es != NULL && hor != NULL)
	{
		if (!hor->asigandos->cupoLleno())
		{
			hor->asigandos->asignarEstudiante(es, z, exf);
		}
	}
	else
	{
		numError++;
	}
}

void SistemaAsignacion::reporteUno()
{
	std::string idcar = ui->Rep1IDEstudiante->text().toUTF8();
	std::string rep;
	if (idcar.compare("") != 0)
	{
		int ca = std::stoi(idcar);
		rep = btree->reporteDeCursosPorEstudiante(ca);
		ui->ContenedorRep1->clear();
		Wt::WText *text1 = new Wt::WText(rep, ui->ContenedorRep1);
	}
}

void SistemaAsignacion::reporteDos()
{
	std::string sem = ui->rep2Sem->text().toUTF8();
	std::string ye = ui->rep2Year->text().toUTF8();
	std::string cod = ui->codCursoRep2->text().toUTF8();
	if (sem.compare("") != 0 && ye.compare("") != 0 && cod.compare("") != 0)
	{
		int seme = std::stoi(sem);
		int year = std::stoi(ye);
		int codi = std::stoi(cod);
		std::string rep = btree->reporteDeAlAsignadosCurso(codi, year, seme);
		ui->contenedorRep2->clear();
		Wt::WText *text1 = new Wt::WText(rep, ui->contenedorRep2);
	}
}

void SistemaAsignacion::reporteTres()
{
	std::string sal = ui->Rep3Sal->text().toUTF8();
	std::string ye = ui->Rep3Anio->text().toUTF8();
	std::string sem = ui->Rep3Sem->text().toUTF8();
	if (sal.compare("") != 0 && ye.compare("") != 0 && sem.compare("") != 0)
	{
		int salon = std::stoi(sal);
		int year = std::stoi(ye);
		int semestre = std::stoi(sem);
		std::string rep = btree->reporteDeCursosEnSalon(salon, semestre, year);
		ui->Rep3Contenedor->clear();
		Wt::WText *text1 = new Wt::WText(rep, ui->Rep3Contenedor);
	}
}

void SistemaAsignacion::reporteCuatro()
{
	std::string sem = ui->SemRep4->text().toUTF8();
	std::string anio = ui->yearRep4->text().toUTF8();
	if (sem.compare("") != 0 && anio.compare("") != 0)
	{
		int semestre = std::stoi(sem);
		int year = std::stoi(anio);
		std::string rep = btree->reporteDeAprobReprob(semestre, year);
		ui->ConenedorRep4->clear();
		Wt::WText *text1 = new Wt::WText(rep, ui->ConenedorRep4);
	}
}

void SistemaAsignacion::quitarPermisos()
{
	ui->LogInTab->setHidden(false);
	ui->cargaTab->setHidden(true);
	ui->usuariosTab->setHidden(true);
	ui->ediSalTab->setHidden(true);
	ui->cursosTab->setHidden(true);
	ui->estuTab->setHidden(true);
	ui->cateTab->setHidden(true);
	ui->horarioTab->setHidden(true);
	ui->asignaTab->setHidden(true);
	ui->verCursosTab->setHidden(true);
	ui->logOutTab->setHidden(true);
	ui->panel->setTitle("Sistema de Asignacion");
	Wt::WMessageBox *messageBox = new Wt::WMessageBox("Informacion", "Sesion finalizada", Wt::Information, Wt::Ok);
	messageBox->show();
	messageBox->buttonClicked().connect(std::bind([=]() {
		delete messageBox;
	}));
	ui->ediInsertar->setText("");
}



std::string SistemaAsignacion::quitaComillas(std::string entrada)
{
	std::string sub1 = entrada.substr(1, entrada.length() - 2);
	return sub1;
}



#pragma endregion


void SistemaAsignacion::prueba()
{
	ui->EstContenedor->clear();
	Wt::WText *text1 = new Wt::WText(tabla->cadenaHTML(), ui->EstContenedor);

}