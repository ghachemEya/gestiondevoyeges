#ifndef GESTIONVOL_H
#define GESTIONVOL_H

#include <QMainWindow>
#include "vol.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class gestionvol;
}

class gestionvol : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionvol(QWidget *parent = 0);
    ~gestionvol();

private slots:
    void on_modifierButton_clicked();

    void on_supprimerButton_clicked();

    void on_numVolSupp_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::gestionvol *ui;
    Vol tmpVol;
};

#endif // GESTIONVOL_H
