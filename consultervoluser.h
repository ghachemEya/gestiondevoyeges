#ifndef CONSULTERVOLUSER_H
#define CONSULTERVOLUSER_H

#include <QMainWindow>
#include "vol.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
namespace Ui {
class consultervoluser;
}

class consultervoluser : public QMainWindow
{
    Q_OBJECT

public:
    explicit consultervoluser(QWidget *parent = 0);
    ~consultervoluser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::consultervoluser *ui;
    Vol tmpvol;
};

#endif // CONSULTERVOLUSER_H
