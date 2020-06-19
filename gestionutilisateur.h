#ifndef GESTIONUTILISATEUR_H
#define GESTIONUTILISATEUR_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include "user.h"

namespace Ui {
class gestionutilisateur;
}

class gestionutilisateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionutilisateur(QWidget *parent = 0);
    ~gestionutilisateur();

private slots:
    void on_validerAjouterUser_clicked();

    void on_supprimerButton_clicked();

    void on_numUser_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::gestionutilisateur *ui;
    user tmpUser;
    bool response=false;
};

#endif // GESTIONUTILISATEUR_H
