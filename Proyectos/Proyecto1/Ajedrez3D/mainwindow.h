#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void ponLabels();

    void PintaTableros();

    void ManejaTurnos();

    void on_BotonMover_clicked();

public slots:
    void updateGameTime();
private:
    QTimer *timer;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
