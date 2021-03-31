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
    maintenance(int,QString,QString,QString,int,QString,float,int);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier(int);
    bool rechercher(int);
private:
    int id;
    QString personnel;
    QString type;
    QString outil_necc;
    int num;
    QString date;
    float prix;
    int etat;
};

#endif // MAINTENANCE_H
