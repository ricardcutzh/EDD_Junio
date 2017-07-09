#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "funciones.h"
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <configuracion.h>
//VARIABLES GLOBALES
QLabel *d;
QLabel *b;
Jugador *player1;
Jugador *player2;
bool turnoPl1;
bool turnoPl2;
QVBoxLayout* layMatrix = new QVBoxLayout();
QVBoxLayout* layTree = new QVBoxLayout();
//LAYOUTSTABLEROS//
QGridLayout *lev0 = new QGridLayout();
QGridLayout *lev1 = new QGridLayout();
QGridLayout *lev2 = new QGridLayout();
//MATRICES DE LABELS
QLabel *l0[8][8] = {};
QLabel *l1[8][8] = {};
QLabel *l2[8][8] = {};
//FIN
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
    ui->Move->setEnabled(false);
    ui->Console->setEnabled(false);
    ui->BotonMover->setEnabled(false);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(updateGameTime()));
    PintaTableros();
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
        player1 = new Jugador(ui->pl1Name->text().toStdString(),0,0);
        turnoPl1 = true;
        ui->CurrentPlayer->setText(QString::fromStdString(player1->nombre));
        ui->Console->append("Turno: "+QString::fromStdString(player1->nombre));
        player2 = new Jugador(ui->pl2Name->text().toStdString(),0,0);
        turnoPl2 = false;
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
        ui->Move->setEnabled(true);
        ui->Console->setEnabled(true);
        ui->BotonMover->setEnabled(true);
        ui->Console->setText("");
    }
    else
    {
        QMessageBox::warning(this,"Error: Configuración", "No Se ha guardado una configuración");
    }
    actualizarTablero(l0,l1,l2);
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
           ui->pl1Name->setText("");
           ui->pl2Name->setText("");
           ui->GameType->setText("Time Is Over");
           ui->Move->setEnabled(false);
           ui->Console->setEnabled(false);
           ui->BotonMover->setEnabled(false);
           calculaFuncionGanador();
           int n = cantidadNegros();
           int b = cantidadBlancos();
           if(b > n)
           {
               QMessageBox::warning(this,"Game Over","Fin de Partida Gana Jugador 2: "+QString::fromStdString(player2->nombre));
           }
           else if(b < n)
           {
                QMessageBox::warning(this,"Game Over","Fin de Partida Gana Jugador 1: "+QString::fromStdString(player1->nombre));
           }
           else
           {
               QMessageBox::warning(this,"Game Over","Fin de Partida en Empate!");
           }
       }
       else
       {
           sec = 59;
           std::string m = std::to_string(minu);
           ui->Min->setText(QString::fromStdString(m));
       }
   }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(!matrizVacia())
    {
        std::string n = ui->ComboLevel->currentText().toStdString();
        int nivel = std::stoi(n);
        if(generaGrafoMatriz(nivel))
        {
            layMatrix->removeWidget(b);
            delete b;
            b = 0;
            //----------------//
            QPixmap img("Matriz.png");
            QLabel *nue = new QLabel();
            b = nue;
            nue->setPixmap(img);
            nue->setFixedSize(img.size());
            nue->repaint();
            layMatrix->addWidget(nue);
            ui->scrollAreaWidgetContents_2->setLayout(layMatrix);
        }
        else
        {
            layMatrix->removeWidget(b);
            delete b;
            b = 0;
        }
    }
    else
    {
        layMatrix->removeWidget(b);
        delete b;
        b = 0;
        QMessageBox::warning(this,"Error: Tablero", "No Se ha iniciado la partida");
    }
}

//SE ENCARGA DE LLEVAR A CABO LA LINEALIZACIÓN Y MOSTRARLA
void MainWindow::on_pushButton_9_clicked()
{
    if(!matrizVacia())
    {
        std::string n = ui->ComboLevel->currentText().toStdString();
        std::string tipo = ui->ComboLinea->currentText().toStdString();
        int nivel = std::stoi(n);
        realizaLinealizacion(nivel,tipo);
        if(realizaGrafoLinealizacion())
        {
            layMatrix->removeWidget(b);
            delete b;
            b = 0;
            QPixmap img("Linealizacion.png");
            QLabel *nue = new QLabel();
            b = nue;
            nue->setPixmap(img);
            nue->setFixedSize(img.size());
            nue->repaint();
            layMatrix->addWidget(nue);
            ui->scrollAreaWidgetContents_2->setLayout(layMatrix);
            limpiaLinealizacion();
        }
        else
        {
            layMatrix->removeWidget(b);
            delete b;
            b = 0;
        }
    }
    else
    {
        layMatrix->removeWidget(b);
        delete b;
        b = 0;
        QMessageBox::warning(this,"Error: Tablero", "No Se ha iniciado la partida");
    }
}

void MainWindow::ponLabels()
{
    QGridLayout *grid = new QGridLayout();
    std::string coordenada;
    for(int x = 0; x <8 ; x++)
    {
        for(int y = 0; y < 8 ; y++)
        {
            QLabel *l = new QLabel("");
            coordenada = "x: "+std::to_string(x)+" y: "+std::to_string(y);
            l->setText(QString::fromStdString(coordenada));
            if(x%2 == 0 )
            {
                if(y%2 == 0)
                {
                    l->setStyleSheet("QLabel { background-color: white;}");
                }
                else
                {
                    l->setStyleSheet("QLabel { background-color: gray;}");
                }
            }
            else
            {
                if(y%2 == 0)
                {
                    l->setStyleSheet("QLabel { background-color: gray;}");
                }
                else
                {
                    l->setStyleSheet("QLabel { background-color: white;}");
                }
            }
            grid->addWidget(l,y,x);
            l1[y][x] = l;
        }
    }
    ui->tab_6->setLayout(grid);
}

//PINTA EL TABLERO DE JUEGO
void MainWindow::PintaTableros()
{
    for(int x = 0; x < 8 ; x++)
    {
        for(int y = 0; y < 8 ; y++)
        {
            QLabel *la0 = new QLabel();
            QLabel *la1 = new QLabel();
            QLabel *la2 = new QLabel();
            if(x%2 == 0 )
            {
                if(y%2 == 0)
                {
                    la0->setStyleSheet("QLabel { background-color: white;}");
                    la1->setStyleSheet("QLabel { background-color: white;}");
                    la2->setStyleSheet("QLabel { background-color: white;}");
                }
                else
                {
                    la0->setStyleSheet("QLabel { background-color: gray;}");
                    la1->setStyleSheet("QLabel { background-color: gray;}");
                    la2->setStyleSheet("QLabel { background-color: gray;}");
                }
            }
            else
            {
                if(y%2 == 0)
                {
                    la0->setStyleSheet("QLabel { background-color: gray;}");
                    la1->setStyleSheet("QLabel { background-color: gray;}");
                    la2->setStyleSheet("QLabel { background-color: gray;}");
                }
                else
                {
                    la0->setStyleSheet("QLabel { background-color: white;}");
                    la1->setStyleSheet("QLabel { background-color: white;}");
                    la2->setStyleSheet("QLabel { background-color: white;}");
                }
            }
            lev0->addWidget(la0,y,x);
            l0[y][x] = la0;
            lev1->addWidget(la1,y,x);
            l1[y][x] = la1;
            lev2->addWidget(la2,y,x);
            l2[y][x] = la2;
        }
    }
    ui->tab_6->setLayout(lev0);
    ui->tab_7->setLayout(lev1);
    ui->tab_8->setLayout(lev2);

}

//BOTON PARA RECIBIR LA ENTRADA DE MOVIMIENTOS
void MainWindow::on_BotonMover_clicked()
{
    std::string entrada = ui->Move->text().toStdString();
    if(entrada.compare("")!=0)
    {
        if(turnoPl1)
        {
            if(muevePieza(entrada,"Negro"))
            {
                actualizarTablero(l0,l1,l2);
                ui->Console->append("--------------------");
                ui->Console->append(ui->Move->text());
                ui->Console->append("--------------------");
                ManejaTurnos();
                int n = cantidadDeDamas();
                if(n<2)
                {
                    ui->Console->setEnabled(false);
                    ui->Move->setEnabled(false);
                    ui->BotonMover->setEnabled(false);
                    QMessageBox::warning(this,"Juego Finalizado!","Ganador: P1");
                }
            }
            else
            {
                QMessageBox::warning(this,"Error","Movimiento No Valido");
            }
        }
        else
        {
            if(muevePieza(entrada,"Blanco"))
            {
                actualizarTablero(l0,l1,l2);
                ui->Console->append("--------------------");
                ui->Console->append(ui->Move->text());
                ui->Console->append("--------------------");
                ManejaTurnos();
                int n = cantidadDeDamas();
                if(n<2)
                {
                    ui->Console->setEnabled(false);
                    ui->Move->setEnabled(false);
                    ui->BotonMover->setEnabled(false);
                    QMessageBox::warning(this,"Juego Finalizado!","Ganador: P2");
                }
            }
            else
            {
                QMessageBox::warning(this,"Error","Movimiento No Valido");
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Error:","No ha ingresado un movimiento");
    }
}

//SOLO SE ENCARGA DE CAMBIAR QUIEN ES EL JUGADOR EN TURNO
void MainWindow::ManejaTurnos()
{
    if(turnoPl1)
    {
        turnoPl1 = false;
        ui->CurrentPlayer->setText(QString::fromStdString(player2->nombre));
        ui->Console->append("Turno: "+QString::fromStdString(player2->nombre));
        turnoPl2 = true;
    }
    else
    {
        turnoPl2 = false;
        ui->CurrentPlayer->setText(QString::fromStdString(player1->nombre));
        ui->Console->append("Turno: "+QString::fromStdString(player1->nombre));
        turnoPl1 = true;
    }
}
