#include "gestionavion.h"
#include "ui_gestionavion.h"
#include "interfaceadmin.h"
#include "interfaceadmin.h"
#include "connexion.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
gestionAvion::gestionAvion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionAvion)
{
    ui->setupUi(this);
    ui->tableView_gestionAvion->setModel(tempAvion.consulterAvions());
}

gestionAvion::~gestionAvion()
{
    delete ui;
}

void gestionAvion::on_pushButton_clicked()
{
    interfaceadmin *w = new interfaceadmin();
    w->show();
    this->setHidden(true);
}



void gestionAvion::on_ajouteravion_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO avion(id,reference,nom,etat,dateEntree,nbplaces) VALUES(?,?,?,?,?,?)");
    query.addBindValue(ui->idavion->text().toInt());
    query.addBindValue(ui->refavion->text().toInt());
    query.addBindValue(ui->nomavion->text());
    query.addBindValue(ui->etatavion->text());
    query.addBindValue(ui->dateentreeavion->text());
    query.addBindValue(ui->nbplaceavion->text().toInt());
    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        ui->textSetting->setText("L'ajout de l'avion' est érroné");
    }else{
        ui->textSetting->setText("Avion ajouté avec succee");
        // Création d'un objet QFile
        QFile file("avion.txt");
        // On ouvre notre fichier en lecture ecrire et on vérifie l'ouverture
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
            return;
        // Création d'un objet QTextStream à partir de notre objet QFile
        QTextStream flux(&file);
        //Read from the file all the data and put it in string
        QString tout = flux.readAll();
        // On choisit le codec correspondant au jeu de caractères que l'on souhaite ; ici, UTF-8
        flux.setCodec("UTF-8");
        // Écriture des différentes lignes dans le fichier
        flux <<tout<< "identifiant de l'avion' " <<ui->idavion->text()<<" reference du l'avion' "<< ui->refavion->text()<<" nb de palce  "<<  ui->nbplaceavion->text()<< " etat du l'avion' "<<  ui->etatavion->text()<< " Nom de l'avion"<< ui->nomavion->text()<<
              " date d'entree' "<< ui->dateentreeavion->date().toString()<<endl;
        ui->tableView_gestionAvion->setModel(tempAvion.consulterAvions());

    }
}

void gestionAvion::on_supprimerAvion_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM avion WHERE id = ?");
    query.addBindValue(ui->idavion_2->text().toInt());
    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        ui->testSupp->setText("Suppression de l'utilisateur' est erronee");
    }else{
        ui->testSupp->setText("Suppression de l'utilisateur' est faite, merci!");
        ui->tableView_gestionAvion->setModel(tempAvion.consulterAvions());
    }
}



void gestionAvion::on_idavion_2_textChanged(const QString &arg1)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    QString query = "SELECT * FROM avion WHERE id ="+arg1;
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    ui->tableView_gestionAvion_2->setModel(model);
}
