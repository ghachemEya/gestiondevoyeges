#include "gestionairport.h"
#include "ui_gestionairport.h"
#include "interfaceadmin.h"
#include "connexion.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
gestionairport::gestionairport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestionairport)
{
    ui->setupUi(this);
    ui->tableView_gestionairport->setModel(tmpairpot.consulterAirport());
}

gestionairport::~gestionairport()
{
    delete ui;
}

void gestionairport::on_pushButton_2_clicked()
{
    interfaceadmin *w= new interfaceadmin();
    w->show();
    this->setHidden(true);
}

void gestionairport::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO airport(id,nom,ville) VALUES(?,?,?)");
    query.addBindValue(ui->idairport->text().toInt());
    query.addBindValue(ui->nomairport->text());
    query.addBindValue(ui->villeairport->text());
    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        ui->textSetting->setText("L'ajout de l'airport est érroné");
    }else{
        ui->textSetting->setText("airport ajouté avec succee");
        // Création d'un objet QFile
        QFile file("airport.txt");
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
        flux <<tout<< "identifiant de l'airport' " <<ui->idairport->text()<<" nom du l'airport' "<< ui->nomairport->text()<<" ville de l'airport'  "<<  ui->villeairport->text()<<endl;
        ui->tableView_gestionairport->setModel(tmpairpot.consulterAirport());

    }
}

void gestionairport::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM airport WHERE id = ?");
    query.addBindValue(ui->idairport_2->text().toInt());
    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        ui->testSupp->setText("Suppression de l'airport est erronee");
    }else{
        ui->testSupp->setText("Suppression de l'airport est faite, merci!");
        ui->tableView_gestionairport->setModel(tmpairpot.consulterAirport());
    }
}

void gestionairport::on_idairport_2_textChanged(const QString &arg1)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
    QSqlQueryModel * model = new QSqlQueryModel();
    QString query = "SELECT * FROM airport WHERE id ="+arg1;
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    ui->tableView_suppairport->setModel(model);
}
