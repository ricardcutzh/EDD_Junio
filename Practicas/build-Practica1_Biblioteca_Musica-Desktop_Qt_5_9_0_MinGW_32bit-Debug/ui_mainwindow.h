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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuReproducci_n;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(727, 471);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 727, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuReproducci_n = new QMenu(menuBar);
        menuReproducci_n->setObjectName(QStringLiteral("menuReproducci_n"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuReproducci_n->menuAction());
        menuArchivo->addAction(actionAbrir_Biblioteca);
        menuReproducci_n->addAction(actionPlay);
        menuReproducci_n->addAction(actionPause);
        menuReproducci_n->addAction(actionNext);
        menuReproducci_n->addAction(actionPrevious);
        mainToolBar->addAction(actionAbrir_Biblioteca);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPrevious);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionNext);
        mainToolBar->addAction(actionPlay);

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
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", Q_NULLPTR));
        menuReproducci_n->setTitle(QApplication::translate("MainWindow", "Reproducci\303\263n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
