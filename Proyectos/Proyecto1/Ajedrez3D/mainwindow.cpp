#include "mainwindow.h"
#include "ui_mainwindow.h"

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
