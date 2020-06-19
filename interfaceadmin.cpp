#include "interfaceadmin.h"
#include "ui_interfaceadmin.h"
#include "gestionvol.h"
#include "gestionutilisateur.h"
#include "gestionavion.h"
#include "login.h"
#include "gestionairport.h"
#include "gestionreservation.h"

interfaceadmin::interfaceadmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interfaceadmin)
{
    ui->setupUi(this);
}

interfaceadmin::~interfaceadmin()
{
    delete ui;
}

void interfaceadmin::on_back_clicked()
{
    login *w = new login();
    w->show();
    this->setHidden(true);
}




void interfaceadmin::on_gestionvol_clicked()
{
    gestionvol *w = new gestionvol();
    w->show();
    this->setHidden(true);
}

void interfaceadmin::on_gestiondeuser_clicked()
{
    gestionutilisateur *w = new gestionutilisateur();
    w->show();
    this->setHidden(true);
}



void interfaceadmin::on_gestionavions_clicked()
{
    gestionAvion *w = new gestionAvion();
    w->show();
    this->setHidden(true);
}

void interfaceadmin::on_gestiondeairport_clicked()
{
    gestionairport *w = new gestionairport();
    w->show();
    this->setHidden(true);
}

void interfaceadmin::on_gestionReservation_clicked()
{
    gestionreservation *w = new gestionreservation();
    w->show();
    this->setHidden(true);
}
