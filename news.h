#ifndef news_H
#define news_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>

class news
{
public:
    news();
    news(int,QString,QString,QString,QString,QString);

    //fonctionalite de base relatives a l'entite studio
    bool ajouter_n();
    QSqlQueryModel  *  afficher_n();
    bool supprimer_n(int);
    bool modifier_n(int);
    bool rechercher_n(int);
    QSqlQueryModel * afficher_tri_n(int id_n);
    QSqlQueryModel * afficher_rech_n(QString,QString);
private:
    int id_n;
    QString nom_n;
    QString type_n;
    QString horaire_n;
    QString duree_n;
    QString nom_pres_n;
};

#endif // news_H
