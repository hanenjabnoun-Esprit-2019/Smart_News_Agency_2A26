#ifndef SPONSORS_H
#define SPONSORS_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
class sponsors
{
public:
    sponsors();
    sponsors(int,QString,QString,QString,QString,QString,QString,QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier(int);
    bool rechercher(int);
private:
    int id;
    QString nom;
    QString type;
    QString duree;
    QString offre;
    QString adresse;
    QString num_tel;
    QString profession;





};

#endif // SPONSORS_H
