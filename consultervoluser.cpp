#include "consultervoluser.h"
#include "ui_consultervoluser.h"
#include "interfaceuser.h"
consultervoluser::consultervoluser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::consultervoluser)
{
    ui->setupUi(this);
    ui->tableView_consultervoluser->setModel(tmpvol.consulterVol());
}

consultervoluser::~consultervoluser()
{
    delete ui;
}

void consultervoluser::on_pushButton_clicked()
{
    interfaceUser *w =new interfaceUser();
    w->show();
    this->setHidden(true);
}
