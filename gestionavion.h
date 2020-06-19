#ifndef GESTIONAVION_H
#define GESTIONAVION_H

#include <QMainWindow>
#include "avion.h"

namespace Ui {
class gestionAvion;
}

class gestionAvion : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionAvion(QWidget *parent = 0);
    ~gestionAvion();

private slots:
    void on_pushButton_clicked();

    void on_ajouteravion_clicked();

    void on_supprimerAvion_clicked();

    void on_idavion_2_textChanged(const QString &arg1);

private:
    Ui::gestionAvion *ui;
    avion tempAvion;
};

#endif // GESTIONAVION_H
