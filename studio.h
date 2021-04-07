#ifndef STUDIO_H
#define STUDIO_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QMessageBox>
class studio
{
public:
    studio();
    studio(int,QString,QString,QString,QString,QString);
    //fonctionalite de base relatives a l'entite studio
    bool ajouter();
    QSqlQueryModel  *  afficher();
    bool supprimer(int);
    bool modifier(int);
    bool rechercher(int);
    QSqlQueryModel * afficher_tri(int id);
    QSqlQueryModel * afficher_rech(QString,QString);
private:
    int id;
    QString nom;
    QString numero;
    QString type;
    QString disponibilite;
    QString nbre_equip;
};

#endif // STUDIO_H
