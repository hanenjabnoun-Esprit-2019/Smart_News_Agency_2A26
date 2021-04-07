#include "news.h"

news::news()
{


}
news::news(int id_n,QString nom_n, QString type_n,QString horaire_n, QString duree_n,QString nom_pres_n)
{
    this->id_n=id_n;
    this->nom_n=nom_n;
    this->type_n=type_n;
    this->horaire_n=horaire_n;
    this->duree_n=duree_n;
    this->nom_pres_n= nom_pres_n;

}
bool news::ajouter_n()
{
  QSqlQuery query;

  QString res = QString::number(id_n);
  //prepare() prend la requete pour la preparer a l'execution

  query.prepare("insert into news values (:id_n, :nom_n, :type_n, :horaire_n, :duree_n, :nom_pres_n)");
  //creation des variables liees
  query.bindValue(":id_n",res);
  query.bindValue(":nom_n",nom_n);
  query.bindValue(":type_n",type_n);
  query.bindValue(":horaire_n",horaire_n);
  query.bindValue(":duree_n",duree_n);
  query.bindValue(":nom_pres_n",nom_pres_n);

  return query.exec();//exec() envoie la requete poour lexecuter

}

QSqlQueryModel * news::afficher_n()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *  from news");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_n"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_n"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_n"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("horaire_n"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("duree_n"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nom_pres_n"));
    return model;
}

bool news::supprimer_n(int id_n)
{
   QSqlQuery query;
   QString res=QString::number(id_n);

   query.prepare("delete from news where id_n=:id_n");
   query.bindValue(":id_n",id_n);

   return query.exec();


}
bool news::modifier_n(int id_n)
{
   QSqlQuery query;
   QString res=QString::number(id_n);
   query.prepare("update news set nom_n=:nom_n,numero_n=:numero_n,type_n=:type_n,disponibilite_n=:disponibilite_n,nbre_equip=:nbre_equip");
   query.bindValue(":id_n", res);
   query.bindValue(":nom_n",nom_n);
   query.bindValue(":type_n",type_n);
   query.bindValue(":horaire_n",horaire_n);
   query.bindValue(":duree_n",duree_n);
   query.bindValue(":nom_pres_n",nom_pres_n);
   return query.exec();
}
bool news::rechercher_n(int id_n)
{
    QSqlQuery q;
    QString res=QString::number(id_n);
    q.prepare("select id_n from news where id_n=:id_n");
    q.bindValue(":id_n", id_n);
    q.exec();
    return q.next();
}

QSqlQueryModel * news::afficher_rech_n(QString selon,QString rech)
{
    QSqlQueryModel * model=new QSqlQueryModel();

       model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_n"));
       model->setQuery("select * from news where "+selon+" like '"+rech+"%'");
    return model;

}
QSqlQueryModel * news::afficher_tri_n(int id_n)
{
      QSqlQueryModel * model=new QSqlQueryModel();
      QString res=QString::number(id_n);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_n"));
      model->setQuery("select * from news order by id_n asc");
      return model;
}


