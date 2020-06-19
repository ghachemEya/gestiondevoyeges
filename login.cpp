#include "login.h"
#include "ui_login.h"
#include "connexion.h"
#include "gestionvol.h"
#include "interfaceadmin.h"
#include "gestionutilisateur.h"
#include "interfaceuser.h"
#include "signup.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
using namespace std;

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QString root;
}

login::~login()
{
    delete ui;
}

void login::on_btnConnect_clicked()
{
    if(ui->radioButton->isChecked()){
        ui->textConnect->setText("Connecter en tant que admin");
        QString login =ui->textEditLogin->text();
        QString password = ui->textEditPassword->text();
        QSqlQuery query;
        query.prepare("SELECT * FROM utilisateur WHERE login = ? AND password = ? AND isadmin = 1");
        query.addBindValue(login);
        query.addBindValue(password);
        if(!query.exec())
         {
              qCritical() << query.lastQuery();
              qCritical() << query.lastError().databaseText();
              qCritical() << query.lastError().driverText();
              return;
          }

           while(query.next())
          {
               QSqlQuery queryy;
               QString test = "UPDATE utilisateur SET isconnected = 1 WHERE login = '"+login+"'";
               queryy.prepare(test);
               if(!queryy.exec())
                {
                     qCritical() << queryy.lastQuery();
                     qCritical() << queryy.lastError().databaseText();
                     qCritical() << queryy.lastError().driverText();
                     return;
                 }
               interfaceadmin *w = new interfaceadmin();
               w->show();
               this->setHidden(true);
           }

    }else if(ui->radioButton_2->isChecked()){

        //Connecter en tant que utilisateur
        QString login =ui->textEditLogin->text();
        QString password = ui->textEditPassword->text();
        QSqlQuery query;
        query.prepare("SELECT * FROM utilisateur WHERE login = ? AND password = ? ");
        query.addBindValue(login);
        query.addBindValue(password);
        if(!query.exec())
         {
              qCritical() << query.lastQuery();
              qCritical() << query.lastError().databaseText();
              qCritical() << query.lastError().driverText();
              return;
          }

           while(query.next())
          {
               QSqlQuery queryy;
               QString test = "UPDATE utilisateur SET isconnected = 1 WHERE login = '"+login+"'";
               queryy.prepare(test);
               if(!queryy.exec())
                {
                     qCritical() << queryy.lastQuery();
                     qCritical() << queryy.lastError().databaseText();
                     qCritical() << queryy.lastError().driverText();
                     return;
                 }
               else{

                   interfaceUser *w = new interfaceUser();
                   w->show();
                   this->setHidden(true);
               }
           }

    }else{
        //Rien à faire Message d'erreur s'affiche à l'utilisateur / Admin on cas de ne pas choisir entre un user ou un admin
        ui->textConnect->setText("Veuillez choisir entre un utilisateur ou un admin! Merci");
    }
}


void login::on_pushButton_clicked()
{

    signup *w = new signup();
    w->show();
    this->setHidden(true);
}
