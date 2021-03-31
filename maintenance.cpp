#include "maintenance.h"

maintenance::maintenance()
{

}
maintenance::maintenance(int id,QString personnel,QString type,QString outil_necc,int num,QString date,float prix,int etat)
{
    this->id=id;
    this->personnel=personnel;
    this->type=type;
    this->outil_necc=outil_necc;
    this->num=num;
    this->date=date;
    this->prix=prix;
    this->etat=etat;
}
bool maintenance::ajouter()
{
    QSqlQuery q;
    q.prepare("insert into MAINTENANCE values(:id,:personnel,:type,:outil_necc,:num,:date,:prix,:etat)");
    q.bindValue(":id",id);
     q.bindValue(":personnel",personnel);
      q.bindValue(":type",type);
       q.bindValue(":outil_necc",outil_necc);
        q.bindValue(":num",num);
         q.bindValue(":date",date);
          q.bindValue(":prix",prix);
           q.bindValue(":etat",etat);
           return q.exec();

}
bool maintenance::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from maintenance where id=:id");
    q.bindValue(":id",id);//injection sql (securité)
    return q.exec();
}
QSqlQueryModel* maintenance::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from maintenance");
    return model;
}
bool maintenance::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update maintenance set personnel=:personnel,type=:type,outil_necc=:outil_necc,num=:num,datem=:date,prix=:prix,etat=:etat where id=:id");
    q.bindValue(":id",id);
     q.bindValue(":personnel",personnel);
      q.bindValue(":type",type);
       q.bindValue(":outil_necc",outil_necc);
        q.bindValue(":num",num);
         q.bindValue(":date",date);
          q.bindValue(":prix",prix);
           q.bindValue(":etat",etat);
           return q.exec();
}
bool maintenance::rechercher(int id)
{
    QSqlQuery q;
    q.prepare("select id from maintenance where id=:id");
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}
