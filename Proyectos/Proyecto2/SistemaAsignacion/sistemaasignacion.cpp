#include "sistemaasignacion.h"

SistemaAsignacion::SistemaAsignacion(const Wt::WEnvironment& env) : Wt::WApplication(env), ui(new Ui_SistemaAsignacion)
{
	ui->setupUi(root());
	ui->userPassword->setEchoMode(Wt::WLineEdit::Password);//INICIALIZA EL CAMPO DE CONTRASEÑA PARA ESCONDER LOS CARACTERES
	ui->cargaTab->show();
	/*ui->cargaTab->setHidden(true);
	ui->usuariosTab->setHidden(true);
	ui->ediSalTab->setHidden(true);
	ui->cursosTab->setHidden(true);
	ui->estuTab->setHidden(true);
	ui->cateTab->setHidden(true);
	ui->horarioTab->setHidden(true);
	ui->asignaTab->setHidden(true);
	ui->verCursosTab->setHidden(true);
	ui->logOutTab->setHidden(true);*/
}

SistemaAsignacion::~SistemaAsignacion()
{
	delete ui;
}
