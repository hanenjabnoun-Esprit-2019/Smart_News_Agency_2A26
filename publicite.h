#ifndef PUBLICITE_H
#define PUBLICITE_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
class publicite
{
public:
    publicite();
    publicite(int,QString,QString,QString,QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_tri();
    bool modifier(int);
    bool rechercher(int);
    QSqlQueryModel* afficher_rech(int);
private:
    int id;
    QString nom;
    QString type;
    QString domaine;
    QString duree;


};

#endif // PUBLICITE_H
