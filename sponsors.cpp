#include "sponsors.h"

sponsors::sponsors()
{

}
sponsors::sponsors(int id,QString nom,QString type,QString duree,QString offre, QString adresse, QString num_tel, QString profession)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->duree=duree;
    this->offre=offre;
    this->adresse=adresse;
    this->num_tel=num_tel;
    this->profession=profession;


}
bool sponsors::ajouter()
{
    QSqlQuery q;
    q.prepare("insert into sponsors values(:id,:nom,:type,:duree,:offre,:adresse,:num_tel,:profession)");
    q.bindValue(":id",id);
     q.bindValue(":nom",nom);
      q.bindValue(":type",type);
       q.bindValue(":duree",duree);
        q.bindValue(":offre",offre);
        q.bindValue(":adresse",adresse);
        q.bindValue(":num_tel",num_tel);
        q.bindValue(":profession",profession);

           return q.exec();

}
bool sponsors::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from sponsors where id=:id");
    q.bindValue(":id",id);//injection sql (securité)
    return q.exec();
}
QSqlQueryModel* sponsors::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from sponsors");
    return model;
}
bool sponsors::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update sponsors set nom=:nom,type=:type,duree=:duree,offre=:offre,adresse=:adresse,num_tel=:num_tel,profession=:profession where id=:id");
    q.bindValue(":id",id);
     q.bindValue(":nom",nom);
      q.bindValue(":type",type);
        q.bindValue(":duree",duree);
        q.bindValue(":offre",offre);
        q.bindValue(":adresse",adresse);
        q.bindValue(":num_tel",num_tel);
        q.bindValue(":profession",profession);


           return q.exec();
}
bool sponsors::rechercher(int id)
{
    QSqlQuery q;
    q.prepare("select id from sponsors where id=:id");
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}
