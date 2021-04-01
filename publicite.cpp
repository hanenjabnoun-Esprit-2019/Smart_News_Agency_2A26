#include "publicite.h"

publicite::publicite()
{

}
publicite::publicite(int id,QString nom,QString type,QString domaine,QString duree)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->domaine=domaine;
    this->duree=duree;
}
bool publicite::ajouter()
{
    QSqlQuery q;
    q.prepare("insert into PUBLICITE values(:id,:nom,:type,:domaine,:duree)");
    q.bindValue(":id",id);
     q.bindValue(":nom",nom);
      q.bindValue(":type",type);
       q.bindValue(":domaine",domaine);
        q.bindValue(":duree",duree);
           return q.exec();

}
bool publicite::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from publicite where id=:id");
    q.bindValue(":id",id);//injection sql (securité)
    return q.exec();
}
QSqlQueryModel* publicite::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from publicite");
    return model;
}
bool publicite::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update publicite set nom=:nom,type=:type,domaine=:domaine,duree=:duree where id=:id");
    q.bindValue(":id",id);
     q.bindValue(":nom",nom);
      q.bindValue(":type",type);
       q.bindValue(":domaine",domaine);
        q.bindValue(":duree",duree);
           return q.exec();
}
bool publicite::rechercher(int id)
{
    QSqlQuery q;
    q.prepare("select id from publicite where id=:id");
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}

QSqlQueryModel* publicite::afficher_tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from publicite order by nom ASC");
    return model;
}
QSqlQueryModel* publicite::afficher_rech(int id)
{
    QString res=QString::number(id);
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from publicite where id like '"+res+"%'");
    return model;
}
