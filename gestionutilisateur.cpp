#include "gestionutilisateur.h"
#include "ui_gestionutilisateur.h"
#include "interfaceadmin.h"
#include "connexion.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

gestionutilisateur::gestionutilisateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionutilisateur)
{
    ui->setupUi(this);
    ui->ConsulterUsers_tableView->setModel(tmpUser.consulterUSers());
}

gestionutilisateur::~gestionutilisateur()
{
    delete ui;

}



void gestionutilisateur::on_validerAjouterUser_clicked()
{
    QString login = ui->loginUser->text();
    QSqlQuery queryverif;
    QString test = "SELECT COUNT(*) FROM utilisateur WHERE login = '"+login+"'";
    queryverif.prepare(test);
    queryverif.exec();
    while(queryverif.next()){
        if(queryverif.value(0) > 0){
            ui->textSetting->setText("Ce login est déjà existant, Veuillez entrer un nouveau login");
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
                ui->textSetting->setText("Il y a une erreur au niveau de l'inscription ");
            }else{
                ui->textSetting->setText("Inscription est faite avec succée! Merci d'avoir choisit notre agence");
                ui->ConsulterUsers_tableView->setModel(tmpUser.consulterUSers());
            }
        }
    }
}

void gestionutilisateur::on_supprimerButton_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM utilisateur WHERE idUser = ?");
    query.addBindValue(ui->numUser->text().toInt());
    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        ui->testSupp->setText("Suppression de l'utilisateur' est erronee");
    }else{
        ui->testSupp->setText("Suppression de l'utilisateur' est faite, merci!");
        ui->ConsulterUsers_tableView->setModel(tmpUser.consulterUSers());
    }


}

void gestionutilisateur::on_numUser_textChanged(const QString &arg1)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    QString query = "SELECT * FROM utilisateur WHERE idUser ="+arg1;
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("idUser"));
    ui->tableView_suppUser->setModel(model);

}

void gestionutilisateur::on_pushButton_clicked()
{
    interfaceadmin *w = new interfaceadmin();
    w->show();
    this->setHidden(true);


}
