#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "funciones.h"
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <configuracion.h>
//VARIABLES GLOBALES
QLabel *d;
QVBoxLayout* layTree = new QVBoxLayout();
Configuracion *config;
int minu;
int sec;
//FIN VARIABLES GLOBALES

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());
    inicializaArbol();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(updateGameTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//BOTON PARA SELECIONAR EL ARCHIVO DE JUGADORES
void MainWindow::on_pushButton_clicked()
{
    std::string path = QFileDialog::getOpenFileName(this, "Importar Jugadores", "C:\\").toStdString();
    if(leerArchivoDeJugadores(path))
    {
        QMessageBox::information(this, "Aviso","Archivo Cargado Correctamente");
    }
}

//BOTON PARA ELIMINAR JUGADORES
void MainWindow::on_pushButton_2_clicked()
{
    if(!verSiArbolEstaVacio())
    {
        std::string textoElim = ui->JugElim->text().toStdString();
        if(textoElim.compare("")!=0)
        {
            if(eliminaJugador(textoElim))
            {
                QMessageBox::information(this, "Eliminación","El Jugador se ha eliminado correctamente!");
                ui->JugElim->setText("");
            }
            else
            {
                QMessageBox::warning(this, "Error","No se encontró el Jugador a Eliminar");
            }
        }
        else
        {
            QMessageBox::warning(this, "Error","Ingrese un nombre para eliminar");
        }
    }
    else
    {
        QMessageBox::warning(this, "Error","No hay Jugadores ingresados!");
    }
}


//MUESTRA LA IMAGEN DEL ARBOL
void MainWindow::on_pushButton_4_clicked()
{
    if(!verSiArbolEstaVacio())
    {
        layTree->removeWidget(d);
        delete d;
        d = 0;
        if(graficameArbol())
        {
            int h = getTreeHeight();
            std::string aux = std::to_string(h);
            ui->HeithLabel->setText(QString::fromStdString(aux));
            //CARGO LA IMAGEN
            QPixmap img("ABB.png");
            QLabel* l = new QLabel();
            d = l;
            l->setPixmap(img);
            l->setFixedSize(img.size());
            l->repaint();
            layTree->addWidget(l);
            ui->scrollAreaWidgetContents->setLayout(layTree);
        }
    }
    else
    {
        layTree->removeWidget(d);
        delete d;
        d = 0;
        QMessageBox::warning(this, "Error","No se han cargado a los Jugadores");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(!verSiArbolEstaVacio())
    {
        layTree->removeWidget(d);
        delete d;
        d = 0;
        generaTops();
        if(graficameListaTops())
        {
            QPixmap img("TopPlayers.png");
            QLabel* l = new QLabel();
            d = l;
            l->setPixmap(img);
            l->setFixedSize(img.size());
            l->repaint();
            layTree->addWidget(l);
            ui->scrollAreaWidgetContents->setLayout(layTree);
        }
    }
    else
    {
        layTree->removeWidget(d);
        delete d;
        d = 0;
        QMessageBox::warning(this, "Error","No se han cargado a los Jugadores");
    }
}

//BOTON DE CONFIGURACIONES
void MainWindow::on_pushButton_3_clicked()
{
    delete config;
    std::string pl1 = ui->p1->text().toStdString();
    std::string pl2 = ui->p2->text().toStdString();
    bool esConTiempo;
    if(pl1.compare("")!=0 && pl2.compare("")!=0)
    {
        int tiempo;
        if(ui->Tim->isChecked())
        {
            esConTiempo = true;
            tiempo = std::stoi(ui->minData->text().toStdString());
        }
        else
        {
            esConTiempo = false;
            tiempo = 0;
        }
        config = new Configuracion(esConTiempo, pl1, pl2);
        config->time = tiempo;
        QMessageBox::information(this,"Mensaje", "Configuraciones guardadas!");
    }
    else
    {
        QMessageBox::warning(this,"Error: Falta Información", "Faltan Casillas por Llenar");
    }
}

//INICIALIZA PARTIDA
void MainWindow::on_pushButton_6_clicked()
{
    if(config != NULL)
    {
        ui->pl1Name->setText(QString::fromStdString(config->pl1));
        ui->pl2Name->setText(QString::fromStdString(config->pl2));
        if(config->Tiempo)
        {
            ui->GameType->setText("Tiempo");
            minu = config->time-1;
            sec = 59;
            ui->Min->setText(QString::fromStdString(std::to_string(minu)));
            ui->Seg->setText(QString::fromStdString(std::to_string(sec)));
            timer->start(1000);
        }
        else
        {
            ui->GameType->setText("Normal");
        }
        inicializarMatriz();
        generaGrafoMatriz(0);
    }
    else
    {
        QMessageBox::warning(this,"Error: Configuración", "No Se ha guardado una configuración");
    }
}

//METODO QUE SE ENCARGA DE ACTUALIZAR EL TIMER
void MainWindow::updateGameTime()
{
   sec = sec-1;
   std::string s = std::to_string(sec);
   ui->Seg->setText(QString::fromStdString(s));
   if(sec==0)
   {
       minu = minu-1;
       if(minu<0)
       {
           ui->Seg->setText("00");
           ui->Min->setText("00");
           timer->stop();
       }
       else
       {
           sec = 59;
           std::string m = std::to_string(minu);
           ui->Min->setText(QString::fromStdString(m));
       }
   }
}
