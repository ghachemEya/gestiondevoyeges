#ifndef GESTIONRESERVATION_H
#define GESTIONRESERVATION_H

#include <QMainWindow>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include "reservation.h"
namespace Ui {
class gestionreservation;
}

class gestionreservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionreservation(QWidget *parent = 0);
    ~gestionreservation();

private slots:
    void on_ajouterReservation_clicked();

    void on_idvol_textChanged(const QString &arg1);

    void on_idvol_2_textChanged(const QString &arg1);

    void on_supprimerRev_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gestionreservation *ui;
    Reservation tmpRev;
};

#endif // GESTIONRESERVATION_H
