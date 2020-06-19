#include "connexion.h"
#include "vol.h"
#include <vector>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
using namespace std;


//Constructeur par defaut
Vol::Vol(){
    numVol =0;
    dureeVol=0;
    nbPlaceReserve=0;
    prixVol=0.0;
    dateDepart="";
    dateArrive="";
    heureArrive="";
    heureDepart="";
}

//Constructeur par parametres
Vol::Vol(int numVol, int dureeVol, int nbPlaceReserve, double prixVol, QString dateDepart, QString dateArrive, QString heureArrive, QString heureDepart ){
    this->numVol =numVol;
    this->dureeVol=dureeVol;
    this->nbPlaceReserve=nbPlaceReserve;
    this->prixVol=prixVol;
    this->dateDepart=dateDepart;
    this->dateArrive=dateArrive;
    this->heureArrive=heureArrive;
    this->heureDepart=heureDepart;
}

//Getter des attributs

int Vol::getNumVol(){
    return numVol;
}

int Vol::getDureeVol(){
    return dureeVol;
}

int Vol::getNbPlace(){
    return nbPlaceReserve;
}

double Vol::getPrixVol(){
    return prixVol;
}

QString Vol::getDateDepart(){
    return dateDepart;
}

QString Vol::getDateArrivee(){
    return dateArrive;
}

QString Vol::getHeureArrivee(){
    return heureArrive;
}

QString Vol::getHeureDepart(){
    return heureDepart;
}


//Consulter les vols
QSqlQueryModel* Vol::consulterVol(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("airline");
        if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM vol");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("numVol"));
    return model;
}

QSqlQueryModel* Vol::infoVol(int numVolSupp){

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("airline");
        if (!db.open()) { }
        QSqlQuery query;
        /*query.prepare("SELECT * FROM vol WHERE numVol = ?");
        query.addBindValue(1475);
        qDebug()<<query.lastQuery();*/


    QSqlQueryModel * model = new QSqlQueryModel();


    return model;
}



//Ajouter un Vol
bool Vol::ajouterVol(){
    QSqlQuery query;
    QString res= QString::number(numVol);
    query.prepare("INSERT INTO vol(numVol,dureeVol,nbPlaceRes,prixVol,dateDepart,dateArrivee,heureDepart,heureArrivee "
                  "VALUES(:numVol,:dureeVol,:nbPlaceReserve,:prixVol,:dateDepart,:dateArrive,:heureDepart,:heureArrive)");
    query.bindValue(":numVol",res);
    query.bindValue(":dureeVol",dureeVol);
    query.bindValue(":nbPlaceReserve",nbPlaceReserve);
    query.bindValue(":prixVol",prixVol);
    query.bindValue(":dateDepart",dateDepart);
    query.bindValue(":dateArrivee",dateArrive);
    query.bindValue(":heureDepart",heureDepart);
    query.bindValue(":heureArrivee",heureArrive);
    return query.exec();
}

//Supprimer un vol
bool Vol::supprimerVol(int numeroVol){
    QSqlQuery query;
    QString res= QString::number(numeroVol);
    query.prepare("DELETE FROM vol where numVol = :numVol");
    query.bindValue(":numVol",res);
    return query.exec();
}
