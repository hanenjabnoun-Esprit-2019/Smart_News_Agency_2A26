#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString >
#include<QSqlQuery>
#include<QVariant>
#include <QSqlQueryModel>
class departement
{
public:
    departement();
    departement(int , QString ,QString, int  , QString , int);
   bool ajouter_d();
   bool supprimer_d(int);
   QSqlQueryModel * afficher_d();
   bool modifier_d(int) ;
bool rechercher_d (int) ;
   QSqlQueryModel * afficher_d_tri();
private:
    int id ;
    QString nom ;
    QString type ;
   int nomb_pers ;
    QString nom_chef ;
    int nbre_empl ;

};

#endif // DEPARTEMENT_H
