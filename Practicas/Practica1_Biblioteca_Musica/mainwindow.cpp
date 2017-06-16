#include "mainwindow.h"
#include "iostream"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "funciones.h"
#include <QPixmap>
#include <QLabel>
#include <QBoxLayout>
#include <nodorep.h>
#include <QMediaPlayer>

using namespace std;
QVBoxLayout *lay = new QVBoxLayout();
QLabel *d;//APUNTADOR AL LABEL QUE ESTARÉ CAMBIANDO CADA VEZ
bool yaAbri=false;
bool yaImg = false;
bool creeNuevaPlayList = false;
bool enReproduccion = false;
QMediaPlayer *player;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());
    player = new QMediaPlayer(this);
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
    if((cancionElim.compare("")!=0)&&yaAbri==true)//SI LA ENTRADA NO ESTA VACÍA
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
    else//SI LA ENTRADA ESTA VACÍA O LA BIBLIOTECA NO SE CARGO
    {
        QMessageBox::warning(this, "Error","Favor ingrese una canción o Cargue la biblioteca");
    }
}

//CREA UNA LISTA DE REPRODUCCIÓN
void MainWindow::on_pushButton_2_clicked()
{
    if(yaAbri)
    {
        if(ui->lista->isChecked())
        {
            vaciaPlaylist();
            iniciaPlaylist("LDE");
            creeNuevaPlayList = true;
        }
        if(ui->Pil->isChecked())
        {
            vaciaPlaylist();
            iniciaPlaylist("STACK");
            creeNuevaPlayList = true;
        }
        if(ui->col->isChecked())
        {
            vaciaPlaylist();
            iniciaPlaylist("QUEUE");
            creeNuevaPlayList = true;
        }
        QMessageBox::information(this, "Nueva Playlist", "Ya puede cargar canciones a la misma!");
        if(enReproduccion)
        {
            lay->removeWidget(d);
            delete d;
            d=0;
            enReproduccion = false;
            player->stop();
            //player = 0;
        }
    }
    else
    {
        QMessageBox::information(this, "Aviso", "Cargue una biblioteca primero");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(creeNuevaPlayList)
    {
        std::string entrada = ui->addSong->text().toStdString();
        Cancion *nuevaPl = encuentraCancion(entrada);
        if(nuevaPl!=NULL)
        {
            agregaAPlayList(nuevaPl);
            QMessageBox::information(this,"Agregada","Canción agregada a la Playlist");
            ui->addSong->setText("");
            //NodoRep *aux = inicializaApuntador();
            //ui->playingNow->setText(QString::fromStdString(aux->nombre));
        }
        else
        {
            QMessageBox::warning(this, "Ups!", "Canción No existe...");
        }
    }
    else
    {
        QMessageBox::warning(this, "Ups!", "Debes crear una playlist primero!");
    }
}

void MainWindow::on_pushButton_4_clicked()//PLAY
{
    if(creeNuevaPlayList)
    {
        //ENCUENTRO LA REFERENCIA
        NodoRep *aux = inicializaApuntador();
        //ASIGNO EL NOMBRE EN LABEL PARA VER QUE SE ESTA REPRODUCIENDO
        ui->playingNow->setText(QString::fromStdString(aux->nombre));
        //LE ASIGNO EL PATH DE LA CANCIÓN
        player->setMedia(QUrl::fromLocalFile(QString::fromStdString(aux->path)));
        qDebug() << player->errorString();
        //EMPIEZA LA REPRODUCCIÓN
        player->play();
        enReproduccion = true;
        std::cout<<"No hay error"<<std::endl;
        lay->removeWidget(d);
        delete d;
        d=0;
        if(escribePlayList())
        {
            yaImg=true;
            system("dot -Tpng Playlist.dot -o Playlist.png");
            QPixmap img("Playlist.png");
            QLabel *lab = new QLabel();
            d = lab;
            lab->setPixmap(img);
            lab->setFixedSize(img.size());
            lab->repaint();
            //AGREGO AL LAYOUT
            lay->addWidget(lab);
            ui->scrollAreaWidgetContents_2->setLayout(lay);
        }
    }
}

void MainWindow::on_actionNext_triggered()
{
    //AVANZA
    if(creeNuevaPlayList)
    {
        NodoRep *aux = siguiente();
        if((aux->nombre.compare("root")!=0))
        {
            //EL LABEL LO ACTUALIZO
            ui->playingNow->setText(QString::fromStdString(aux->nombre));
            player->stop();
            player->setMedia(QUrl::fromLocalFile(QString::fromStdString(aux->path)));
            //qDebug() << player->errorString();
            player->play();
            //LIMPIO EL AREA DE REPORTES
            lay->removeWidget(d);
            delete d;
            d=0;
            if(escribePlayList())
            {
                yaImg=true;
                system("dot -Tpng Playlist.dot -o Playlist.png");
                QPixmap img("Playlist.png");
                QLabel *lab = new QLabel();
                d = lab;
                lab->setPixmap(img);
                lab->setFixedSize(img.size());
                lab->repaint();
                //AGREGO AL LAYOUT
                lay->addWidget(lab);
                ui->scrollAreaWidgetContents_2->setLayout(lay);
            }
        }
        else
        {
            lay->removeWidget(d);
            delete d;
            d=0;
            creeNuevaPlayList = false;
            enReproduccion = false;
            player->stop();
            QMessageBox::information(this,"Fin","Fin de Playlist!");
        }
    }
}

void MainWindow::on_actionPrevious_triggered()
{
    //REGRESA
    if(creeNuevaPlayList)
    {
        NodoRep *ant = anterior();
        if(ant!=NULL)
        {
            ui->playingNow->setText(QString::fromStdString(ant->nombre));
            player->setMedia(QUrl::fromLocalFile(QString::fromStdString(ant->path)));
            //qDebug() << player->errorString();
            player->play();
            lay->removeWidget(d);
            delete d;
            d=0;
            if(escribePlayList())
            {
                yaImg=true;
                system("dot -Tpng Playlist.dot -o Playlist.png");
                QPixmap img("Playlist.png");
                QLabel *lab = new QLabel();
                d = lab;
                lab->setPixmap(img);
                lab->setFixedSize(img.size());
                lab->repaint();
                //AGREGO AL LAYOUT
                lay->addWidget(lab);
                ui->scrollAreaWidgetContents_2->setLayout(lay);
            }
        }
        else
        {
            QMessageBox::information(this,"Fin","No se puede regresar...");
        }
    }
}

void MainWindow::on_actionPlay_triggered()
{
    if(enReproduccion)
    {
        player->play();
    }
}

void MainWindow::on_actionPause_triggered()
{
    if(enReproduccion)
    {
        //player->stop();
        player->pause();
    }
}
