#include "studio.h"

studio::studio()
{


}
studio::studio(int id,QString nom, QString type,QString numero, QString disponibilite,QString nbre_equip)
{
 this->id=id;
    this->nom=nom;
    this->numero=numero;
    this->type=type;
    this->disponibilite=disponibilite;
    this->nbre_equip=nbre_equip;

}
bool studio::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(id);
    //prepare() prendd la requete pour la preparer a l'execution

    query.prepare("insert into studio  values (:id, :nom, :numero, :type, :disponibilite, :nbre_equip)");
    //creation des variables liees
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":numero",numero);
    query.bindValue(":type",type);
    query.bindValue(":disponibilite",disponibilite);
    query.bindValue(":nbre_equip",nbre_equip);

  return query.exec();//exec() envoie la requete poour lexecuter

}

QSqlQueryModel * studio::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *  from studio");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("disponibilite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nbre_equip"));
    return model;
}

bool studio::supprimer(int id)
{
   QSqlQuery query;
   QString res=QString::number(id);

   query.prepare("delete from studio where id=:id");
   query.bindValue(":id",res);

   return query.exec();


}
bool studio::modifier(int id)
{
   QSqlQuery q;

   q.prepare("update studio set nom=:nom,numero=:numero,type=:type,disponibilite=:disponibilite,nbre_equip=:nbre_equip where id=:id");
   q.bindValue(":id", id);
   q.bindValue(":nom",nom);
   q.bindValue(":numero",numero);
   q.bindValue(":type",type);
   q.bindValue(":disponibilite",disponibilite);
   q.bindValue(":nbre_equip",nbre_equip);
  return q.exec();
}
bool studio::rechercher(int id)
{
    QSqlQuery q;
    QString res=QString::number(id);
    q.prepare("select id from studio where id=:id");
    q.bindValue(":id", id);
    q.exec();
    return q.next();
}

QSqlQueryModel * studio::afficher_rech(QString selon,QString rech)
{
    QSqlQueryModel * model=new QSqlQueryModel();

       model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
       model->setQuery("select * from studio where "+selon+" like '"+rech+"%'");
    return model;

}
QSqlQueryModel * studio::afficher_tri(int id)
{
      QSqlQueryModel * model=new QSqlQueryModel();
      QString res=QString::number(id);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setQuery("select * from studio order by nom DESC");
   return model;
}


