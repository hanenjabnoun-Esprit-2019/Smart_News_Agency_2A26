#include "avis.h"

avis::avis()
{

}

avis::avis(int id,QString destinataire,QString type ,QString description, QString etat)
{
this->id=id;
    this->destinataire=destinataire;
    this->type=type;
    this->description=description;
    this->etat=etat;

}

bool avis::ajout_a(){
    QSqlQuery q;
    q.prepare("insert into avis values (:id,:destinataire,:type,:description,:etat)");
    q.bindValue(":id",id);
    q.bindValue(":destinataire",destinataire);
    q.bindValue(":type",type);
    q.bindValue(":description",description);
    q.bindValue(":etat",etat);

    return q.exec();

}

bool avis::supprimer_a(int id){

    QSqlQuery q;
    q.prepare("delete from avis where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel *avis::afficher_a(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select* from avis");
    return model;
}

bool avis::modifier_a(int id){
    QSqlQuery q;
    q.prepare("update avis set destinataire=:destinataire,type=:type,description=:description,etat=:etat where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":destinataire",destinataire);
    q.bindValue(":type",type);
    q.bindValue(":description",description);
    q.bindValue(":etat",etat);
    return q.exec();
}

bool avis::rechercher_a(int id){
    QSqlQuery q;
    q.prepare("select id from avis where id=:id");
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}
