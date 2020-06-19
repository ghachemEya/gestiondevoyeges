#include "consulterinfosuser.h"
#include "ui_consulterinfosuser.h"
#include "interfaceuser.h"
QString userinfo;
consulterinfosuser::consulterinfosuser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::consulterinfosuser)
{
    ui->setupUi(this);
    ui->tableView_infopersonnel->setModel((tmpuser.consulterInfo()));
}

consulterinfosuser::~consulterinfosuser()
{
    delete ui;
}

void consulterinfosuser::on_pushButton_clicked()
{
    interfaceUser *w =new interfaceUser();
    w->show();
    this->setHidden(true);
}
