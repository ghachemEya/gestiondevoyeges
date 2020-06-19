#include "gestionvol.h"
#include "ui_gestionvol.h"
#include "vol.h"
#include "login.h"
#include "interfaceadmin.h"
#include "interfaceuser.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

gestionvol::gestionvol(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionvol)
{
    ui->setupUi(this);
    ui->tableView_ConsulterVol->setModel(tmpVol.consulterVol());
}

gestionvol::~gestionvol()
{
    delete ui;
}

void gestionvol::on_modifierButton_clicked()

{

    QSqlQuery query;
    query.prepare("INSERT INTO vol(numVol,dureeVol,nbPlaceRes,nbPlaceRestant,prixVol,dateDepart,dateArrivee,heureDepart,heureArrivee,nomairportArrivee,nomairportDepart) VALUES(?,?,?,?,?,?,?,?,?,?,?)");
    query.addBindValue(ui->numeroVol->text().toInt());
    query.addBindValue(ui->dureeVol->text().toInt());
    query.addBindValue(ui->nbPlaceReserve->text().toInt());
    query.addBindValue(ui->nbPlaceReserve->text().toInt());
    query.addBindValue(ui->prixVol->text().toFloat());
    query.addBindValue(ui->dateDepartVol->date().toString());
    query.addBindValue(ui->dateArriveeVol->date().toString());
    query.addBindValue(ui->heureDepartVol->dateTime().toString());
    query.addBindValue(ui->heureArriveeVol->dateTime().toString());
    query.addBindValue(ui->airportArrivee->text());
    query.addBindValue(ui->airportDepart->text());
    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        ui->testAjout->setText("L'ajout du vol est érroné");
    }else{
        ui->testAjout->setText("Vol ajouté avec succee");
        // Création d'un objet QFile
        QFile file("vol.txt");
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
        flux <<tout<< "Numero de vol " <<ui->numeroVol->text()<<" duree du vol "<< ui->dureeVol->text()<<" nb de palce reservees "<<  ui->nbPlaceReserve->text()<< " prix du vol "<<  ui->prixVol->text()<< " date de depart "<< ui->dateDepartVol->date().toString()<<
              " date d'arrivee' "<< ui->dateArriveeVol->date().toString()<< " heure de depart  "<<  ui->heureDepartVol->dateTime().toString()<<" heure d'arrivee' "<< ui->heureArriveeVol->dateTime().toString()<<" Nom du airport arrivee"<<ui->airportArrivee->text()<<" Nom du airport depart"<<ui->airportDepart->text()<< endl;
        ui->tableView_ConsulterVol->setModel(tmpVol.consulterVol());
    }
}

void gestionvol::on_supprimerButton_clicked()
{

       QSqlQuery query;
       query.prepare("DELETE FROM vol WHERE numVol = ?");
       query.addBindValue(ui->numVolSupp->text().toInt());
       if(!query.exec()){
           qWarning() << "ERROR: " << query.lastError().text();
           ui->testSupp->setText("Suppression de vol est erronee");
       }else{
           ui->testSupp->setText("Suppression de vol est faite, merci!");
           ui->tableView_ConsulterVol->setModel(tmpVol.consulterVol());
       }
}


void gestionvol::on_numVolSupp_textChanged(const QString &arg1)
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("airline");
        if (!db.open()) { }
        QSqlQueryModel * model = new QSqlQueryModel();
        QString query = "SELECT * FROM vol WHERE numVol ="+arg1;
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("numVol"));
        ui->tableView_supp->setModel(model);
}

void gestionvol::on_pushButton_clicked()
{
    interfaceadmin *w = new interfaceadmin();
    w->show();
    this->setHidden(true);
}
