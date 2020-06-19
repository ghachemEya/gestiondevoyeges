#include "interfaceuser.h"
#include "ui_interfaceuser.h"
#include "login.h"
#include "consultervoluser.h"
#include "gestionutilisateur.h"
#include "consulterinfosuser.h"
#include "gestionreservation.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
QString logine;
interfaceUser::interfaceUser(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::interfaceUser)
{
    ui->setupUi(this);
}

interfaceUser::~interfaceUser()
{
    delete ui;
}

void interfaceUser::on_back_clicked()
{
    login *w = new login();
    w->show();
    this->setHidden(true);

}



void interfaceUser::on_checkvols_clicked()
{
    consultervoluser *w = new consultervoluser();
    w->show();
    this->setHidden(true);
}



void interfaceUser::on_informations_clicked()
{
    consulterinfosuser *w = new consulterinfosuser();
    w->show();
    this->setHidden(true);
}

void interfaceUser::on_gestionreservation_clicked()
{

        gestionreservation *w = new gestionreservation();
        w->show();
        this->setHidden(true);



}
