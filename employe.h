#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString >
#include<QSqlQuery>
#include<QVariant>
#include <QSqlQueryModel>
class employe
{
public:
    employe();
    employe (int , QString ,QString, QString ,int , QString , int);
   bool ajouter_e();
   bool supprimer_e(int);
   QSqlQueryModel * afficher_e();
   bool modifier_e(int) ;
bool rechercher_e (int) ;
   QSqlQueryModel * afficher_e_rech(int );
   QSqlQueryModel * stat();
private:
    int id ;
    QString nom ;
    QString  prenom ;
    QString  role ;
    int salaire ;
    QString profession ;
    int numero ;

};

#endif // EMPLOYE_H
