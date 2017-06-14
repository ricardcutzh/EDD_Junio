#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbrir_Biblioteca_triggered();

    void on_actionVer_Biblioteca_triggered();

    void on_actionNueva_Biblioteca_triggered();

    void on_actionTop_5_Artists_triggered();

    void on_actionTop_5_Albums_triggered();

    void on_actionTop_5_Songs_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
