#include "mainwindow.h"
#include "gestionvol.h"
#include "gestionutilisateur.h"
#include <QApplication>
#include "login.h"
#include "connexion.h"
#include "vol.h"
#include <QDebug>


#define q2c(string) string.toStdString()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    login w;
    c.open();
    w.show();


    return a.exec();
}
