#ifndef AVION_H
#define AVION_H


#include <QSqlQueryModel>

class avion
{

public:
    int id;
    int reference;
    QString nom;
    QString etat;
    QString dateEntree;
    int nbplaces;

public:
    avion();
    QSqlQueryModel* consulterAvions();
    bool ajouterAvion();
    bool supprimerAvion(int);
};

#endif // AVION_H
