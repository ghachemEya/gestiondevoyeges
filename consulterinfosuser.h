#ifndef CONSULTERINFOSUSER_H
#define CONSULTERINFOSUSER_H
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include "user.h"

namespace Ui {
class consulterinfosuser;
}

class consulterinfosuser : public QMainWindow
{
    Q_OBJECT

public:
    explicit consulterinfosuser(QWidget *parent = 0);
    ~consulterinfosuser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::consulterinfosuser *ui;
    user tmpuser;
};

#endif // CONSULTERINFOSUSER_H
