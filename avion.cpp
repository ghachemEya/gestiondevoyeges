#include "avion.h"
#include <vector>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include "connexion.h"

avion::avion()
{
    id=0;
    reference=0;
    nom="";
    dateEntree="";
    etat="";
    nbplaces=0;
}

QSqlQueryModel* avion::consulterAvions(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("airline");
        if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM avion");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    return model;
}


bool avion::ajouterAvion(){
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO avion(id,reference,nom,etat,dateEntree,nbplaces "
                  "VALUES(:id,:reference,:nom,:etat,:dateEntree,:nbplaces)");
    query.bindValue(":id",res);
    query.bindValue(":reference",reference);
    query.bindValue(":nom",nom);
    query.bindValue(":etat",etat);
    query.bindValue(":dateEntree",dateEntree);
    query.bindValue(":nbplaces",nbplaces);
    return query.exec();
}
