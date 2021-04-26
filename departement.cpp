#include "departement.h"

departement::departement()
{

}
departement::departement (int id , QString nom ,QString type,int nomb_pers, QString nom_chef , int nbre_empl ){

    this->id=id ;
    this->nom=nom ;
    this->type=type ;
    this->nomb_pers=nomb_pers ;
    this->nom_chef=nom_chef ;
    this->nbre_empl=nbre_empl  ;

}
bool departement::ajouter_d()
{
    QSqlQuery q ;
    q.prepare("insert into departement values (:id , :nom ,:type , :nomb_pers , :nom_chef,:nbre_empl  )");
    q.bindValue(":id",id);
        q.bindValue(":nom",nom);
                q.bindValue(":type",type);
                 q.bindValue(":nomb_pers",nomb_pers);
                  q.bindValue(":nom_chef",nom_chef);
                   q.bindValue(":nbre_empl",nbre_empl);
                          return  q.exec();
}
bool departement::supprimer_d(int id)
{
    QSqlQuery q ;
    q.prepare("delete from departement where id=:id ");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel * departement::afficher_d()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from departement");
    return model ;
}
bool departement::modifier_d(int id)
{
    QSqlQuery q ;
    q.prepare("update departement set nom=:nom ,type=:type ,nomb_pers=:nomb_pers , nom_chef=:nom_chef ,nbre_empl=:nbre_empl where id=:id");
    q.bindValue(":id",id);
        q.bindValue(":nom",nom);
                q.bindValue(":type",type);
                 q.bindValue(":nomb_pers",nomb_pers);
                  q.bindValue(":nom_chef",nom_chef);
                   q.bindValue(":nbre_empl",nbre_empl);
                                  return  q.exec();
}

bool departement::rechercher_d (int id )
{
    QSqlQuery q;
    q.prepare ("select id from departement where id=:id") ;
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}

QSqlQueryModel * departement::afficher_d_tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from departement order by nom ASC");
    return model ;
}


