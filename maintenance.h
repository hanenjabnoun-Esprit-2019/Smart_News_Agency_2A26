#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
class maintenance
{
public:
    maintenance();
    maintenance(int,QString,QString,QString,int,QString,int,int);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier(int);
    bool rechercher(int);
    QSqlQueryModel* afficherRech(QString selon,QString rech);
private:
    int id;
    QString personnel;
    QString type;
    QString outil_necc;
    int num;
    QString date;
    int prix;
    int etat;
};

#endif // MAINTENANCE_H
