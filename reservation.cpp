#include "reservation.h"
#include <iostream>
#include <vector>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <fstream>
using namespace std;

Reservation::Reservation()
{

}

Reservation::Reservation(int id, int numVol, int idUser){
    this->id=id;
    this->numVol=numVol;
    this->idUser=idUser;
}

QSqlQueryModel* Reservation::consulterReservation(){
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("SELECT * FROM reservation");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
return model;
}


void Reservation::ajouterDansUnFicher(){
    vector<Reservation> rev;
    QSqlQuery queryverif;
    QString test = "SELECT * FROM reservation";
    queryverif.prepare(test);
    queryverif.exec();
    while(queryverif.next()){
        Reservation a(queryverif.value(0).toInt(),queryverif.value(1).toInt(),queryverif.value(2).toInt());
        rev.push_back(a);
        string const nomFichier("/home/eyaghachem/build-projetC-Desktop-Debug/reservation.txt");
        ofstream monFlux(nomFichier.c_str());

        if(monFlux)  //On teste si tout est OK
        {
            //Tout est OK, on peut utiliser le fichier
            for(unsigned int i = 0; i < rev.size(); i++) // D’ailleurs, i++ ou ++i ?
            {
                    monFlux <<"Idtenficateur de la reservation "<<rev[i].id <<" Idtenficateur du Vol "<< rev[i].numVol<< " Idtenficateur de l'utilisateur " << rev[i].idUser <<endl;
            }
        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }
    }
}
