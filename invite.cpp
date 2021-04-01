#include "invite.h"

invite::invite()
{

}

invite::invite(int id,QString nom,QString prenom,QString profession,int num_tel,QString programme )
{
this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->profession=profession;
    this->num_tel=num_tel;
    this->programme=programme;
}

bool invite::ajout_i(){
    QSqlQuery q;
    q.prepare("insert into invites values (:id,:nom,:prenom,:profession,:num_tel,:programme)");
    q.bindValue(":id",id);
    q.bindValue(":nom",nom);
    q.bindValue(":prenom",prenom);
    q.bindValue(":profession",profession);
    q.bindValue(":num_tel",num_tel);
    q.bindValue(":programme",programme);
    return q.exec();

}

bool invite::supprimer_i(int id){

    QSqlQuery q;
    q.prepare("delete from invites where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel *invite::afficher_i(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select* from invites");
    return model;
}

bool invite::modifier_i(int id){
    QSqlQuery q;
    q.prepare("update invites set nom=:nom,prenom=:prenom,profession=:profession,num_tel=:num_tel,programme=:programme where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":nom",nom);
    q.bindValue(":prenom",prenom);
    q.bindValue(":profession",profession);
    q.bindValue(":num_tel",num_tel);
    q.bindValue(":programme",programme);
    return q.exec();
}

bool invite::rechercher_i(int id){
    QSqlQuery q;
    q.prepare("select id from invites where id=:id");
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}

QSqlQueryModel *invite::afficher_i_tri(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select* from invites order by nom ASC");

    return model;
}
QSqlQueryModel *invite::afficher_i_rech(int id){
    QSqlQueryModel* model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from invites where id like '"+res+"%'");
    return model;
}
QSqlQueryModel * invite::stat()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select profession,count(*) from invites group by profession");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));

    return model;
}
