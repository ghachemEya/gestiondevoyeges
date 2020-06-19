#include "connexion.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

connexion::connexion(){

}

void connexion::open(){
    const QString DRIVER("QSQLITE");
    try {
        QSqlDatabase::isDriverAvailable(DRIVER);
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName("airline");
        if(!db.open())
            qWarning() << "ERROR: " << db.lastError();
        QSqlQuery queryVol("CREATE TABLE IF NOT EXISTS vol (numVol INTEGER PRIMARY KEY, dureeVol  INTEGER ,nbPlaceRes  INTEGER, nbPlaceRestant  INTEGER , prixVol  REAL ,dateDepart TEXT, dateArrivee TEXT, heureDepart TEXT ,heureArrivee TEXT,nomairportArrivee TEXT,nomairportDepart TEXT)");
        QSqlQuery queryUser("CREATE TABLE IF NOT EXISTS utilisateur (idUser INTEGER PRIMARY KEY AUTOINCREMENT, nom TEXT, email TEXT, prenom TEXT, numTel TEXT,login TEXT, password TEXT, dateNaissance TEXT, isadmin INTEGER DEFAULT 0, isconnected INTEGER DEFAULT 0)");
        QSqlQuery queryAvion ("CREATE TABLE IF NOT EXISTS avion (id INTEGER PRIMARY KEY, reference TEXT, nom TEXT, etat TEXT, dateEntree TEXT,nbplaces INTEGER)");
        QSqlQuery queryAirport ("CREATE TABLE IF NOT EXISTS airport (id INTEGER PRIMARY KEY, nom TEXT, ville TEXT)");
        QSqlQuery queryReservation("CREATE TABLE IF NOT EXISTS reservation (id 	INTEGER PRIMARY KEY AUTOINCREMENT, numVol INTEGER,idUser INTEGER)");
        if(!queryVol.isActive())
            qWarning() << "ERROR: " << queryVol.lastError().text();
        if(!queryUser.isActive())
            qWarning() << "ERROR: " << queryUser.lastError().text();
        if(!queryAvion.isActive())
            qWarning() << "ERROR: " << queryVol.lastError().text();

        if(!queryAirport.isActive())
            qWarning() << "ERROR: " << queryVol.lastError().text();

        if(!queryReservation.isActive())
            qWarning() << "ERROR: " << queryVol.lastError().text();
        QSqlQuery queryy;
        QString test = "UPDATE utilisateur SET isconnected = 0 WHERE 1";
        queryy.prepare(test);
        if(!queryy.exec())
         {
              qCritical() << queryy.lastQuery();
              qCritical() << queryy.lastError().databaseText();
              qCritical() << queryy.lastError().driverText();
              return;
          }
    }
    catch(int exception){
        qWarning() << "SQL problem: " << exception;
    }
}


void connexion::close(){

}
