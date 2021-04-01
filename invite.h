#ifndef INVITE_H
#define INVITE_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>

class invite
{
public:
    invite();
    invite(int,QString,QString,QString,int,QString);
    bool ajout_i();
    bool supprimer_i(int);
    QSqlQueryModel *afficher_i();
    QSqlQueryModel *afficher_i_tri();
QSqlQueryModel *afficher_i_rech(int);
    bool modifier_i(int);
    bool rechercher_i(int);
    QSqlQueryModel *stat();

private:
    int id;
   QString nom;
   QString prenom;
   QString profession;
   int num_tel;
   QString programme;
};

#endif // INVITE_H
