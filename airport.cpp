#include "airport.h"

airport::airport()
{

}
QSqlQueryModel* airport::consulterAirport(){
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("airline");
    if (!db.open()) { }
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("SELECT * FROM airport");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
return model;
}
