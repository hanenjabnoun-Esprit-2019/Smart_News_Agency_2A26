#ifndef AVIS_H
#define AVIS_H

#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>

class avis
{
public:
    avis();
    avis(int,QString,QString);
    bool ajout_a();
    bool supprimer_a(int);
    QSqlQueryModel *afficher_a();
    bool modifier_a(int);
    bool rechercher_a(int);

private:
    int id;
   QString destinataire;
   QString type;

};

#endif // AVIS_H
