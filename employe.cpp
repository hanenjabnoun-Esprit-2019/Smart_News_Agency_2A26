#include "employe.h"

employe::employe()
{

}
employe:: employe (int id , QString nom ,QString prenom ,QString role , int salaire ,QString profession , int numero , int id_dep ){

    this->id=id ;
    this->nom=nom ;
    this->prenom=prenom ;
    this->role=role ;
    this->salaire=salaire ;
    this->profession=profession  ;
    this->numero =numero ;
    this->id_dep=id_dep;
}
bool employe::ajouter_e()
{
    QSqlQuery q ;
    q.prepare("insert into employe values (:id , :nom ,:prenom , :role , :salaire ,:profession , :numero ,:id_dep )");
    q.bindValue(":id",id);
        q.bindValue(":nom",nom);
            q.bindValue(":prenom",prenom);
                q.bindValue(":role",role);
                    q.bindValue(":salaire",salaire);
                        q.bindValue(":profession",profession);
                           q.bindValue(":numero",numero);
                              q.bindValue(":id_dep", id_dep);
                          return  q.exec();
}
bool employe::supprimer_e(int id)
{
    QSqlQuery q ;
    q.prepare("delete from employe where id=:id ");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel * employe::afficher_e()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");
    return model ;
}
bool employe::modifier_e(int id)
{
    QSqlQuery q ;
    q.prepare("update employe set nom=:nom ,prenom=:prenom , role=:role , salaire=:salaire ,profession=:profession , numero=:numero where id=:id");
            q.bindValue(":id",id);
                q.bindValue(":nom",nom);
                    q.bindValue(":prenom",prenom);
                        q.bindValue(":role",role);
                            q.bindValue(":salaire",salaire);
                                q.bindValue(":profession",profession);
                                   q.bindValue(":numero",numero);
                                  return  q.exec();
}

bool employe::rechercher_e (int id )
{
    QSqlQuery q;
    q.prepare ("select id from employe where id=:id") ;
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}

QSqlQueryModel * employe::afficher_e_rech(int id )
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString ::number(id) ;
    model->setQuery("select * from employe where id like '"+res+"%'");
    return model ;
}

QSqlQueryModel * employe::stat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select role,count(*) as nombre from employe group by role");
    return model ;
}
