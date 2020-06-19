#-------------------------------------------------
#
# Project created by QtCreator 2020-05-06T15:43:00
#
#-------------------------------------------------
QT       += sql # On rajoute SQLnt
QT       += core gui
CONFIG += console
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vol.cpp \
    connexion.cpp \
    gestionvol.cpp \
    gestionutilisateur.cpp \
    user.cpp \
    login.cpp \
    signup.cpp \
    interfaceadmin.cpp \
    interfaceuser.cpp \
    gestionavion.cpp \
    avion.cpp \
    consulterinfosuser.cpp \
    consultervoluser.cpp \
    gestionairport.cpp \
    airport.cpp \
    gestionreservation.cpp \
    reservation.cpp

HEADERS  += mainwindow.h \
    connexion.h \
    vol.h \
    gestionvol.h \
    gestionutilisateur.h \
    user.h \
    login.h \
    signup.h \
    interfaceadmin.h \
    interfaceuser.h \
    gestionavion.h \
    avion.h \
    consulterinfosuser.h \
    consultervoluser.h \
    gestionairport.h \
    airport.h \
    gestionreservation.h \
    reservation.h

FORMS    += \
    gestionvol.ui \
    gestionutilisateur.ui \
    login.ui \
    signup.ui \
    interfaceadmin.ui \
    interfaceuser.ui \
    gestionavion.ui \
    aze.ui \
    consulterinfosuser.ui \
    consultervoluser.ui \
    gestionairport.ui \
    gestionreservation.ui

