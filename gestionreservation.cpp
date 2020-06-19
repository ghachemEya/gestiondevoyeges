#include "gestionreservation.h"
#include "ui_gestionreservation.h"
#include "interfaceadmin.h"
#include "interfaceuser.h"
#include "connexion.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
gestionreservation::gestionreservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionreservation)
{
    ui->setupUi(this);
    ui->tableView_consulterRev->setModel(tmpRev.consulterReservation());
    tmpRev.ajouterDansUnFicher();
}

gestionreservation::~gestionreservation()
{
    delete ui;
}

void gestionreservation::on_ajouterReservation_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
    QSqlQuery query;
    int idUser;
    int numVol;
    QString test="SELECT COUNT(*) FROM vol WHERE numVol LIKE '"+ui->idvol->text()+"%' AND nbPlaceRestant > 0";
    query.prepare(test);
    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        ui->textSetting->setText("L'ajout de la reservation est érroné");
    }
    else{
            while(query.next()){
                if (query.value(0).toInt() == 1){
                    //ajouter reservation supprimer une place
                    QSqlQuery queryuser;
                    queryuser.prepare("SELECT idUSer from utilisateur WHERE isconnected = 1");
                    if(!queryuser.exec()){
                        qWarning() << "ERROR: " << queryuser.lastError().text();
                    }
                    while(queryuser.next()){
                        idUser = queryuser.value(0).toInt();
                    }
                    QSqlQuery queryVol;
                    QString test="SELECT numVol FROM vol WHERE numVol LIKE '"+ui->idvol->text()+"%' AND nbPlaceRestant > 0";
                    queryVol.prepare(test);
                    if(!queryVol.exec()){
                        qWarning() << "ERROR: " << queryVol.lastError().text();
                    }
                    while(queryVol.next()){
                         numVol = queryVol.value(0).toInt();
                    }
                    QSqlQuery queryInsert;
                    queryInsert.prepare("INSERT INTO reservation (numVol,idUser) VALUES (?,?)");
                    queryInsert.addBindValue(numVol);
                    queryInsert.addBindValue(idUser);
                    if(queryInsert.exec()){
                        QSqlQuery queryy;
                        queryy.prepare("UPDATE vol set nbPlaceRestant = nbPlaceRestant-1  WHERE numVol = ?");
                        queryy.addBindValue(numVol);
                        if(!queryy.exec())
                         {
                              qCritical() << queryy.lastQuery();
                              qCritical() << queryy.lastError().databaseText();
                              qCritical() << queryy.lastError().driverText();
                              return;
                          }
                        ui->textSetting->setText("L'ajout de la reservation est fait avec succes");
                        ui->tableView_consulterRev->setModel(tmpRev.consulterReservation());

                    }else{
                        qWarning() << "ERROR: " << queryVol.lastError().text();
                        ui->textSetting->setText("L'ajout de la reservation est érroné");
                    }

                }
                else{
                    if (query.value(0).toInt() == 0){
                        ui->textSetting->setText("Aucun vol avec cet ID n'est disponible");
                    }
                    else{
                        ui->textSetting->setText("Veuillez affiner votre recherche, vous ne pouvez pas reserver plus qu'un vol à la fois");
                    }
                }
            }

    }
}

void gestionreservation::on_idvol_textChanged(const QString &arg1)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    QString query = "SELECT * FROM vol WHERE numVol LIKE '"+arg1+"%'";
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    ui->tableView_vol->setModel(model);
}

void gestionreservation::on_idvol_2_textChanged(const QString &arg1)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    QString query = "SELECT * FROM reservation WHERE id LIKE '"+arg1+"%'";
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    ui->tableView_supprev->setModel(model);
}


void gestionreservation::on_supprimerRev_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM reservation WHERE id = ?");
    query.addBindValue(ui->idvol_2->text().toInt());
    if(!query.exec()){

        ui->testSupp->setText("Suppression de la reservation est erronee");
    }else{
        ui->testSupp->setText("Suppression de la reservation est faite, merci!");
        ui->tableView_consulterRev->setModel(tmpRev.consulterReservation());
    }
}

void gestionreservation::on_pushButton_2_clicked()
{

    interfaceadmin  *l = new interfaceadmin();
    interfaceUser  *u = new interfaceUser();
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM utilisateur WHERE isconnected = 1 ");
    if(query.exec()){
         u->show();
         this->setHidden(true);
    }

    QSqlQuery query2;
    query2.prepare("SELECT COUNT(*) FROM utilisateur WHERE isadmin = 1");
    if(query2.exec()){
         l->show();
         this->setHidden(true);
    }

}
