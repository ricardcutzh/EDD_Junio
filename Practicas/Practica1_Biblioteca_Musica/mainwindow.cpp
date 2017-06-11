#include "mainwindow.h"
#include "iostream"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//ABRIR UN ARCHIVO DE ENTRADA
void MainWindow::on_actionAbrir_Biblioteca_triggered()
{
    std::string PATH = QFileDialog::getOpenFileName(this,"Abrir Biblioteca","C:\\").toStdString();
}
