#ifndef AIRPORT_H
#define AIRPORT_H
#include <QString>
#include <QSqlQueryModel>
class airport
{
public :
    int idairport;
    QString nom;
    QString ville;
public:
    airport();
    QSqlQueryModel* consulterAirport();
};

#endif // AIRPORT_H
