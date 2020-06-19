#ifndef RESERVATION_H
#define RESERVATION_H


#include <QSqlQueryModel>
class Reservation
{
public:
     Reservation();
     Reservation(int,int,int);
     QSqlQueryModel* consulterReservation();
     void ajouterDansUnFicher();
public:
     int id;
     int numVol;
     int idUser;
};

#endif // RESERVATION_H
