#ifndef CONNEXION
#define CONNEXION

#include <QtSql>
#include <QDebug>
//#include "qtdir/src/sql/drivers/psql/qsql_mysql.cpp"
class connexion {
private:
    QSqlDatabase db;
public :
    connexion();
    void close();
    void open();
};

#endif // CONNEXION

