#include "mainwindow.h"
#include "iostream"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "funciones.h"
#include <QPixmap>
#include <QLabel>
#include <QBoxLayout>
using namespace std;
QVBoxLayout *lay = new QVBoxLayout();
QLabel *d;//APUNTADOR AL LABEL QUE ESTARÉ CAMBIANDO CADA VEZ
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ABRIR UN ARCHIVO DE ENTRADA
void MainWindow::on_actionAbrir_Biblioteca_triggered()
{
    crearNuevaLista();
    std::string PATH = QFileDialog::getOpenFileName(this,"Abrir Biblioteca","C:\\").toStdString();
    if(leerArchivoEntrada(PATH))
    {
        QMessageBox::information(this, "Mensje", "Archivo Cargado Correctamente");
    }

}

//GENERAR IMAGEN
void MainWindow::on_actionVer_Biblioteca_triggered()
{
    if(escribeBiblioteca()){
        //COMANDO AL CMD PARA GENERAR LA IMAGEN DEL ARCHIVO ESCRITO
        system("dot -Tpng biblioteca.dot -o bliblioteca.png");

        //MENSAJE DE CONFIRMACIÓN
        QMessageBox::information(this, "Creación de Imagen","Biblioteca Generada Correctamente");

        //CREACIÓN DE LA IMAGEN
        QPixmap img("bliblioteca.png");
        QLabel *lab = new QLabel();

        //ESTE APUNTADOR SIEMPRE HARA REFERENCIA A ESTE LABEL CREADO
        d = lab;
        lab->setPixmap(img);
        lab->setFixedSize(img.size());
        //REPINTO
        lab->repaint();
        //AGREGO AL LAYOUT
        lay->addWidget(lab);
        ui->scrollAreaWidgetContents_2->setLayout(lay);

    }
    else
    {
        QMessageBox::warning(this, "Error...","No se creo correctamente");
    }
}

//PARA PODER INGRESAR UN NUEVO ARCHIVO
void MainWindow::on_actionNueva_Biblioteca_triggered()
{
    liberarLista();//LIBERO MEMORIA DE LA LISTA
    lay->removeWidget(d);//REMUEVO EL WIDGET
    delete d;//LIBERO DE MEMORIA
    d=0;//SOLO POR SEGURIDAD
    this->repaint();//REPINTO
    //MENSAJE DE CONFIRMACIÓN
    QMessageBox::information(this, "Creación de Nueva Biblioteca","Biblioteca Creada: Puede Cargar un nuevo archivo");
}
