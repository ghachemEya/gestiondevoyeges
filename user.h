#ifndef USER_H
#define USER_H


#include <QSqlQueryModel>

class user
{

    int idUser;
    QString nom;
    QString prenom;
    QString email;
    QString numTel;
    QString login;
    QString password;
    QString dateNaissance;



public:
    user();
    int getIdUser();
    QString getNom();
    QString getPrenom();
    QString getEmail();
    QString getNumTel();
    QString getLogin();
    QString getPassword();
    QString getDateNaissance();
    QSqlQueryModel* consulterUSers();
    QSqlQueryModel* consulterInfo();
    bool ajouterUser();
    bool supprimerUser(int);

};

#endif // USER_H
