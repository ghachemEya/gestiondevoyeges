#ifndef INTERFACEUSER_H
#define INTERFACEUSER_H

#include <QMainWindow>
namespace Ui {
class interfaceUser;
}

class interfaceUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit interfaceUser(QWidget *parent = 0);
    ~interfaceUser();

private slots:
    void on_back_clicked();

    void on_checkvols_clicked();

    void on_informations_clicked();

    void on_gestionreservation_clicked();

private:
    Ui::interfaceUser *ui;

};

#endif // INTERFACEUSER_H
