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
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLineEdit *JugElim;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QWidget *tab_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
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
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 60, 111, 17));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 120, 151, 17));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 120, 191, 20));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 240, 391, 191));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 141, 16));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 80, 181, 20));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 131, 16));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(180, 130, 181, 20));
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

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ajedrez 3D", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Modo de Juego", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Juego Normal", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Juego Con Tiempo (Min)", Q_NULLPTR));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tablero", Q_NULLPTR));
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