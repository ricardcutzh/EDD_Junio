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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir_Biblioteca;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionNext;
    QAction *actionPrevious;
    QAction *actionVer_Biblioteca;
    QAction *actionNueva_Biblioteca;
    QAction *actionTop_5_Songs;
    QAction *actionTop_5_Albums;
    QAction *actionTop_5_Artists;
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *SongToDelete;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuReproducci_n;
    QMenu *menuTops;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(856, 503);
        actionAbrir_Biblioteca = new QAction(MainWindow);
        actionAbrir_Biblioteca->setObjectName(QStringLiteral("actionAbrir_Biblioteca"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/rec/imgs/1497179937_editor-folder-add-glyph.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir_Biblioteca->setIcon(icon);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/rec/imgs/1497179559_play-circle-fill.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon1);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/rec/imgs/1497179537_pause-circle-fill.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon2);
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName(QStringLiteral("actionNext"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/rec/imgs/1497179516_204_CircledNext.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext->setIcon(icon3);
        actionPrevious = new QAction(MainWindow);
        actionPrevious->setObjectName(QStringLiteral("actionPrevious"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/rec/imgs/1497179494_203_CircledBack.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrevious->setIcon(icon4);
        actionVer_Biblioteca = new QAction(MainWindow);
        actionVer_Biblioteca->setObjectName(QStringLiteral("actionVer_Biblioteca"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/rec/imgs/1497267961_icon-image.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVer_Biblioteca->setIcon(icon5);
        actionNueva_Biblioteca = new QAction(MainWindow);
        actionNueva_Biblioteca->setObjectName(QStringLiteral("actionNueva_Biblioteca"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/rec/imgs/1497344676_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNueva_Biblioteca->setIcon(icon6);
        actionTop_5_Songs = new QAction(MainWindow);
        actionTop_5_Songs->setObjectName(QStringLiteral("actionTop_5_Songs"));
        actionTop_5_Albums = new QAction(MainWindow);
        actionTop_5_Albums->setObjectName(QStringLiteral("actionTop_5_Albums"));
        actionTop_5_Artists = new QAction(MainWindow);
        actionTop_5_Artists->setObjectName(QStringLiteral("actionTop_5_Artists"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 50, 421, 371));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 419, 369));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(450, 50, 391, 80));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 47, 13));
        SongToDelete = new QLineEdit(groupBox);
        SongToDelete->setObjectName(QStringLiteral("SongToDelete"));
        SongToDelete->setGeometry(QRect(60, 20, 321, 20));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 50, 131, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(450, 150, 391, 271));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 47, 13));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 30, 111, 23));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 70, 311, 20));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 100, 75, 23));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 150, 111, 16));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 180, 82, 17));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 200, 82, 17));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 220, 161, 17));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(210, 210, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 251, 31));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        MainWindow->setCentralWidget(centralWidget);
        scrollArea->raise();
        groupBox->raise();
        groupBox_2->raise();
        label->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 856, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuReproducci_n = new QMenu(menuBar);
        menuReproducci_n->setObjectName(QStringLiteral("menuReproducci_n"));
        menuTops = new QMenu(menuBar);
        menuTops->setObjectName(QStringLiteral("menuTops"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuReproducci_n->menuAction());
        menuBar->addAction(menuTops->menuAction());
        menuArchivo->addAction(actionAbrir_Biblioteca);
        menuArchivo->addAction(actionVer_Biblioteca);
        menuArchivo->addAction(actionNueva_Biblioteca);
        menuReproducci_n->addAction(actionPlay);
        menuReproducci_n->addAction(actionPause);
        menuReproducci_n->addAction(actionNext);
        menuReproducci_n->addAction(actionPrevious);
        menuTops->addAction(actionTop_5_Songs);
        menuTops->addSeparator();
        menuTops->addAction(actionTop_5_Albums);
        menuTops->addSeparator();
        menuTops->addAction(actionTop_5_Artists);
        mainToolBar->addAction(actionAbrir_Biblioteca);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPrevious);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionNext);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionVer_Biblioteca);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Reproductor Audio", Q_NULLPTR));
        actionAbrir_Biblioteca->setText(QApplication::translate("MainWindow", "Abrir Biblioteca", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        actionNext->setText(QApplication::translate("MainWindow", "Next", Q_NULLPTR));
        actionPrevious->setText(QApplication::translate("MainWindow", "Previous", Q_NULLPTR));
        actionVer_Biblioteca->setText(QApplication::translate("MainWindow", "Ver Biblioteca", Q_NULLPTR));
        actionNueva_Biblioteca->setText(QApplication::translate("MainWindow", "Nueva Biblioteca", Q_NULLPTR));
        actionTop_5_Songs->setText(QApplication::translate("MainWindow", "Top 5 Songs", Q_NULLPTR));
        actionTop_5_Albums->setText(QApplication::translate("MainWindow", "Top 5 Albums", Q_NULLPTR));
        actionTop_5_Artists->setText(QApplication::translate("MainWindow", "Top 5 Artists", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Eliminar Canci\303\263n de Biblioteca", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Canci\303\263n: ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Eliminar", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Reproducci\303\263n De Playlists", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Canci\303\263n:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Crear Nueva", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Agregar", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Tipo de Reproducci\303\263n", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Pila", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Cola", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "Lista Doble Enlazada Circular", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Reportes:", Q_NULLPTR));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", Q_NULLPTR));
        menuReproducci_n->setTitle(QApplication::translate("MainWindow", "Reproducci\303\263n", Q_NULLPTR));
        menuTops->setTitle(QApplication::translate("MainWindow", "Tops", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
