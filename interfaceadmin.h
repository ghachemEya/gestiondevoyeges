#ifndef INTERFACEADMIN_H
#define INTERFACEADMIN_H

#include <QMainWindow>

namespace Ui {
class interfaceadmin;
}

class interfaceadmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit interfaceadmin(QWidget *parent = 0);
    ~interfaceadmin();

private slots:
    void on_back_clicked();

    void on_gestionvol_clicked();

    void on_gestiondeuser_clicked();

    void on_gestionavions_clicked();

    void on_gestiondeairport_clicked();

    void on_gestionReservation_clicked();

private:
    Ui::interfaceadmin *ui;

};

#endif // INTERFACEADMIN_H
