#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "funciones.h"
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

//VARIABLES GLOBALES
QLabel *d;
QVBoxLayout* layTree = new QVBoxLayout();
//FIN VARIABLES GLOBALES

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());
    inicializaArbol();
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
