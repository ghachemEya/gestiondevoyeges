#include "user.h"
#include "connexion.h"
#include <vector>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>


using namespace std;
user::user()
{

}


//Getter des attributs

int user::getIdUser(){
    return idUser;
}



QString user::getNom(){
    return nom;
}

QString user::getPrenom(){
    return prenom;
}

QString user::getEmail(){
    return email;
}

QString user::getNumTel(){
    return numTel;
}

QString user::getLogin(){
    return login;
}

QString user::getPassword(){
    return password;
}

QString user::getDateNaissance(){
    return dateNaissance;
}


QSqlQueryModel * user::consulterUSers(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("airline");
        if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM utilisateur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idUser"));
    return model;
}


bool user::ajouterUser(){

}

bool user::supprimerUser(int idUser){

}

QSqlQueryModel * user::consulterInfo(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("airline");
        if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    QString query = "SELECT * FROM utilisateur WHERE  isconnected = 1";
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idUser"));
    return model;
}
