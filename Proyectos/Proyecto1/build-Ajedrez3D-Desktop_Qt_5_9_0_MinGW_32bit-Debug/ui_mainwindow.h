/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QRadioButton *Norm;
    QRadioButton *Tim;
    QLineEdit *minData;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *p1;
    QLabel *label_2;
    QLineEdit *p2;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *JugElim;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QGroupBox *groupBox_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *pl1Name;
    QLabel *pl2Name;
    QLabel *label_8;
    QLabel *GameType;
    QLabel *label_9;
    QLabel *Min;
    QLabel *label_10;
    QLabel *Seg;
    QPushButton *pushButton_6;
    QTabWidget *tabWidget_3;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *tab_8;
    QGroupBox *groupBox_6;
    QLabel *label_11;
    QLabel *CurrentPlayer;
    QLabel *label_12;
    QLineEdit *Move;
    QPushButton *BotonMover;
    QTextEdit *Console;
    QLabel *label_13;
    QWidget *tab_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QGroupBox *groupBox_7;
    QLabel *label_14;
    QComboBox *ComboLevel;
    QGroupBox *groupBox_8;
    QPushButton *pushButton_8;
    QLabel *label_15;
    QComboBox *ComboLinea;
    QPushButton *pushButton_9;
    QScrollArea *MatrizView;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *tab_5;
    QScrollArea *TreeViewArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QLabel *HeithLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(893, 547);
        QIcon icon;
        icon.addFile(QStringLiteral(":/rec/Img/1497870361_black_knight.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 871, 471));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 391, 191));
        Norm = new QRadioButton(groupBox);
        Norm->setObjectName(QStringLiteral("Norm"));
        Norm->setGeometry(QRect(20, 60, 111, 17));
        Tim = new QRadioButton(groupBox);
        Tim->setObjectName(QStringLiteral("Tim"));
        Tim->setGeometry(QRect(20, 120, 151, 17));
        minData = new QLineEdit(groupBox);
        minData->setObjectName(QStringLiteral("minData"));
        minData->setGeometry(QRect(170, 120, 191, 20));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 240, 391, 191));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 141, 16));
        p1 = new QLineEdit(groupBox_2);
        p1->setObjectName(QStringLiteral("p1"));
        p1->setGeometry(QRect(180, 80, 181, 20));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 131, 16));
        p2 = new QLineEdit(groupBox_2);
        p2->setObjectName(QStringLiteral("p2"));
        p2->setGeometry(QRect(180, 130, 181, 20));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(430, 30, 401, 191));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 50, 101, 16));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 50, 241, 23));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 120, 81, 16));
        JugElim = new QLineEdit(groupBox_3);
        JugElim->setObjectName(QStringLiteral("JugElim"));
        JugElim->setGeometry(QRect(130, 120, 241, 20));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 150, 241, 23));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(430, 240, 401, 191));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 80, 301, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/rec/Img/1497870084_settings-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 10, 841, 81));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 61, 16));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 50, 51, 16));
        pl1Name = new QLabel(groupBox_5);
        pl1Name->setObjectName(QStringLiteral("pl1Name"));
        pl1Name->setGeometry(QRect(80, 20, 171, 16));
        pl2Name = new QLabel(groupBox_5);
        pl2Name->setObjectName(QStringLiteral("pl2Name"));
        pl2Name->setGeometry(QRect(80, 50, 171, 16));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(330, 20, 81, 16));
        GameType = new QLabel(groupBox_5);
        GameType->setObjectName(QStringLiteral("GameType"));
        GameType->setGeometry(QRect(430, 20, 141, 16));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(330, 50, 71, 16));
        Min = new QLabel(groupBox_5);
        Min->setObjectName(QStringLiteral("Min"));
        Min->setGeometry(QRect(430, 50, 16, 16));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(450, 50, 16, 16));
        Seg = new QLabel(groupBox_5);
        Seg->setObjectName(QStringLiteral("Seg"));
        Seg->setGeometry(QRect(460, 50, 21, 16));
        pushButton_6 = new QPushButton(groupBox_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(600, 40, 181, 23));
        tabWidget_3 = new QTabWidget(tab_2);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(10, 100, 421, 331));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget_3->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabWidget_3->addTab(tab_8, QString());
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(450, 110, 401, 321));
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 40, 47, 13));
        CurrentPlayer = new QLabel(groupBox_6);
        CurrentPlayer->setObjectName(QStringLiteral("CurrentPlayer"));
        CurrentPlayer->setGeometry(QRect(70, 36, 131, 20));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 80, 61, 20));
        Move = new QLineEdit(groupBox_6);
        Move->setObjectName(QStringLiteral("Move"));
        Move->setGeometry(QRect(90, 80, 141, 20));
        BotonMover = new QPushButton(groupBox_6);
        BotonMover->setObjectName(QStringLiteral("BotonMover"));
        BotonMover->setGeometry(QRect(250, 80, 111, 23));
        Console = new QTextEdit(groupBox_6);
        Console->setObjectName(QStringLiteral("Console"));
        Console->setGeometry(QRect(20, 130, 361, 181));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 105, 71, 21));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/rec/Img/1497870390_Chess-Game-grey.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_2 = new QTabWidget(tab_3);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 10, 841, 421));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 10, 181, 80));
        label_14 = new QLabel(groupBox_7);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 30, 47, 20));
        ComboLevel = new QComboBox(groupBox_7);
        ComboLevel->setObjectName(QStringLiteral("ComboLevel"));
        ComboLevel->setGeometry(QRect(80, 30, 81, 22));
        groupBox_8 = new QGroupBox(tab_4);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(210, 10, 611, 80));
        pushButton_8 = new QPushButton(groupBox_8);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(40, 30, 121, 23));
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(210, 30, 81, 21));
        ComboLinea = new QComboBox(groupBox_8);
        ComboLinea->setObjectName(QStringLiteral("ComboLinea"));
        ComboLinea->setGeometry(QRect(290, 30, 111, 22));
        pushButton_9 = new QPushButton(groupBox_8);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(420, 30, 151, 23));
        MatrizView = new QScrollArea(tab_4);
        MatrizView->setObjectName(QStringLiteral("MatrizView"));
        MatrizView->setGeometry(QRect(10, 100, 811, 281));
        MatrizView->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 809, 279));
        MatrizView->setWidget(scrollAreaWidgetContents_2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/rec/Img/1497937279__m.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_2->addTab(tab_4, icon3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        TreeViewArea = new QScrollArea(tab_5);
        TreeViewArea->setObjectName(QStringLiteral("TreeViewArea"));
        TreeViewArea->setGeometry(QRect(20, 80, 791, 301));
        TreeViewArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 789, 299));
        TreeViewArea->setWidget(scrollAreaWidgetContents);
        pushButton_4 = new QPushButton(tab_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 30, 211, 23));
        pushButton_5 = new QPushButton(tab_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 30, 191, 23));
        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(480, 30, 81, 21));
        HeithLabel = new QLabel(tab_5);
        HeithLabel->setObjectName(QStringLiteral("HeithLabel"));
        HeithLabel->setGeometry(QRect(580, 30, 81, 21));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/rec/Img/1497937232_tree.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_2->addTab(tab_5, icon4, QString());
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/rec/Img/1497870210_screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 893, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ajedrez 3D", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Modo de Juego", Q_NULLPTR));
        Norm->setText(QApplication::translate("MainWindow", "Juego Normal", Q_NULLPTR));
        Tim->setText(QApplication::translate("MainWindow", "Juego Con Tiempo (Min)", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Elecci\303\263n de Jugadores", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Jugador 1 (Piezas Negras)", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Jugador 2 (Piezas Blancas)", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Administrar Jugadores", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Cargar Jugadores", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Selecionar Archivo", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Eliminar Jugador", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Eliminar", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Guardar Cambios", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Guardar Configuraciones", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Configuraci\303\263n de Juego", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Datos de Partida:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Jugador 1:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Jugador 2:", Q_NULLPTR));
        pl1Name->setText(QApplication::translate("MainWindow", "Nombre...", Q_NULLPTR));
        pl2Name->setText(QApplication::translate("MainWindow", "Nombre...", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Tipo de Juego:", Q_NULLPTR));
        GameType->setText(QApplication::translate("MainWindow", "Game Type...", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Tiempo:", Q_NULLPTR));
        Min->setText(QApplication::translate("MainWindow", "00", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", ":", Q_NULLPTR));
        Seg->setText(QApplication::translate("MainWindow", "00", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Empezar Partida!", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "Nivel 0", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("MainWindow", "Nivel 1", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "Nivel 2", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Movimientos Y Consola", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Turno:", Q_NULLPTR));
        CurrentPlayer->setText(QApplication::translate("MainWindow", "Current Player", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Movimiento:", Q_NULLPTR));
        BotonMover->setText(QApplication::translate("MainWindow", "Mover", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Consola:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tablero", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Elegir Nivel:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Nivel:", Q_NULLPTR));
        ComboLevel->clear();
        ComboLevel->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
        );
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Generar Reporte:", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Ver Tablero", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Linealizaci\303\263n:", Q_NULLPTR));
        ComboLinea->clear();
        ComboLinea->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Filas", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Columnas", Q_NULLPTR)
        );
        pushButton_9->setText(QApplication::translate("MainWindow", "Ver Linealizaci\303\263n", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Matriz Ortogonal", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Ver \303\201rbol de Jugadores", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Ver Top 10 Jugadores", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Altura de \303\201rbol:", Q_NULLPTR));
        HeithLabel->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "\303\201rbol Binario de B\303\272squedad", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Reportes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
