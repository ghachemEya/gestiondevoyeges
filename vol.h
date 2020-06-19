#ifndef VOL
#define VOL


#include <QSqlQueryModel>


class Vol {

    int numVol;
    int dureeVol;
    int nbPlaceReserve;
    double prixVol;
    QString dateDepart;
    QString dateArrive;
    QString heureDepart;
    QString heureArrive;

public :
    Vol();
    Vol(int,int,int,double,QString,QString,QString,QString);
    int getNumVol();
    int getDureeVol();
    int getNbPlace();
    double getPrixVol();
    QString getDateDepart();
    QString getDateArrivee();
    QString getHeureDepart();
    QString getHeureArrivee();
    QSqlQueryModel* consulterVol();
    QSqlQueryModel* infoVol(int);
    bool ajouterVol();
    bool supprimerVol(int);
};


#endif // VOL

