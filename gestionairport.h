#ifndef GESTIONAIRPORT_H
#define GESTIONAIRPORT_H

#include <QMainWindow>
#include "airport.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
namespace Ui {
class gestionairport;
}

class gestionairport : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionairport(QWidget *parent = 0);
    ~gestionairport();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_idairport_2_textChanged(const QString &arg1);

private:
    Ui::gestionairport *ui;
    airport tmpairpot;
};

#endif // GESTIONAIRPORT_H
