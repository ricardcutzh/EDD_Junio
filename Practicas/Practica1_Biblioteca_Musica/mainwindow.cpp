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
bool yaAbri=false;
bool yaImg = false;
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
        yaAbri = true;
        QMessageBox::information(this, "Mensje", "Archivo Cargado Correctamente");
        agregaTops();
    }

}

//GENERAR IMAGEN
void MainWindow::on_actionVer_Biblioteca_triggered()
{
    if(yaAbri==true)
    {
        if(escribeBiblioteca()){
            if(yaImg){
                lay->removeWidget(d);
                delete d;
                d=0;
            }
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
            yaImg = true;
        }
        else
        {
            QMessageBox::warning(this, "Error...","No se creo correctamente");
        }
    }
    else
    {
        QMessageBox::warning(this, "Error...","No Se ha Cargado una Biblioteca...");
    }
}

//PARA PODER INGRESAR UN NUEVO ARCHIVO
void MainWindow::on_actionNueva_Biblioteca_triggered()
{
    yaAbri = false;
    yaImg = false;
    liberarLista();//LIBERO MEMORIA DE LA LISTA
    lay->removeWidget(d);//REMUEVO EL WIDGET
    delete d;//LIBERO DE MEMORIA
    d=0;//SOLO POR SEGURIDAD
    this->repaint();//REPINTO
    //MENSAJE DE CONFIRMACIÓN
    QMessageBox::information(this, "Creación de Nueva Biblioteca","Biblioteca Creada: Puede Cargar un nuevo archivo");
}

//MUESTRA EL REPORTE DE TOP 5 ARTISTAS
void MainWindow::on_actionTop_5_Artists_triggered()
{
    lay->removeWidget(d);
    delete d;
    d=0;
    if(yaAbri)
    {
        if(escribeTopArtistas())
        {
            yaImg=true;
            system("dot -Tpng topArtist.dot -o topArtist.png");
            QPixmap img("topArtist.png");
            QLabel *lab = new QLabel();
            d = lab;
            lab->setPixmap(img);
            lab->setFixedSize(img.size());
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
    this->repaint();
}

//MUESTRA EL REPORTE DE TOP 5 ALBUNES
void MainWindow::on_actionTop_5_Albums_triggered()
{
    lay->removeWidget(d);
    delete d;
    d=0;
    if(yaAbri)
    {
        if(escribeTopAlbums())
        {
            yaImg=true;
            system("dot -Tpng topAlbums.dot -o topAlbums.png");
            QPixmap img("topAlbums.png");
            QLabel *lab = new QLabel();
            d = lab;
            lab->setPixmap(img);
            lab->setFixedSize(img.size());
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
}

//MUESTRA EL REPORTE DE TOP 5 CANCIONES
void MainWindow::on_actionTop_5_Songs_triggered()
{
    lay->removeWidget(d);
    delete d;
    d=0;
    if(yaAbri)
    {
        if(escribeTopSongs())
        {
            yaImg=true;
            system("dot -Tpng topSongs.dot -o topSongs.png");
            QPixmap img("topSongs.png");
            QLabel *lab = new QLabel();
            d = lab;
            lab->setPixmap(img);
            lab->setFixedSize(img.size());
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
}

//BOTON PARA ELIMINAR
void MainWindow::on_pushButton_clicked()
{
    //OBTENGO EL TEXTO DE LA ENTRADA A ELIMINAR
    std::string cancionElim = ui->SongToDelete->text().toStdString();
    if(cancionElim.compare("")!=0)//SI LA ENTRADA NO ESTA VACÍA
    {
        if(eliminaCancion(cancionElim))
        {
            QMessageBox::information(this,"Información","Se eliminó la canción");
            ui->SongToDelete->setText("");

            //LIBERO LA LISTA DE TOPS Y LLENO CON LA NUEVA INFORMACIÓN QUE OBTENGO
            vaciaTops();
            iniciaTops();
            agregaTops();
        }
        else{
            QMessageBox::warning(this, "Error","No se logró eliminar la canción");
        }

    }
    else//SI LA ENTRADA ESTA VACÍA
    {
        QMessageBox::warning(this, "Error","Favor ingrese una canción");
    }
}
