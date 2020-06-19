#include "signup.h"
#include "ui_signup.h"
#include "connexion.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    login *w = new login();
    w->show();
    this->setHidden(true);

}

void signup::on_pushButton_2_clicked()
{
    QString login = ui->loginUser->text();
    QSqlQuery queryverif;
    QString test = "SELECT COUNT(*) FROM utilisateur WHERE login = '"+login+"'";
    queryverif.prepare(test);
    queryverif.exec();

    while(queryverif.next()){
        if(queryverif.value(0) > 0){
            ui->testAjout->setText("Ce login est déjà existant, Veuillez entrer un nouveau login");
        }else{
            QSqlQuery query;
            query.prepare("INSERT INTO utilisateur(nom,email,prenom,numTel,login,password,dateNaissance) VALUES(?,?,?,?,?,?,?)");
            query.addBindValue(ui->nameUser->text());
            query.addBindValue(ui->emailUser->text());
            query.addBindValue(ui->prenomUser->text());
            query.addBindValue(ui->telUser->text());
            query.addBindValue(ui->loginUser->text());
            query.addBindValue(ui->passwodUser->text());
            query.addBindValue(ui->dateNaissanceUser->text());
            if(!query.exec()){
                qWarning() << "ERROR: " << query.lastError().text();
                ui->testAjout->setText("Il y a une erreur au niveau de l'inscription ");
            }else{
                ui->testAjout->setText("Inscription est faite avec succée! Merci d'avoir choisit notre agence");
            }
        }
    }
}
