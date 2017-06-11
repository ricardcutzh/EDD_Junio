#-------------------------------------------------
#
# Project created by QtCreator 2017-06-09T19:39:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Practica1_Biblioteca_Musica
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    nodocancion.cpp \
    listacanciones.cpp \
    cancion.cpp \
    nodotop.cpp \
    top.cpp \
    album.cpp \
    nodoalbum.cpp \
    listaalbumes.cpp \
    artista.cpp \
    nodoartista.cpp \
    listaartistas.cpp

HEADERS += \
        mainwindow.h \
    nodocancion.h \
    listacanciones.h \
    cancion.h \
    nodotop.h \
    top.h \
    album.h \
    nodoalbum.h \
    listaalbumes.h \
    artista.h \
    nodoartista.h \
    listaartistas.h \
    funciones.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    recursos.qrc
