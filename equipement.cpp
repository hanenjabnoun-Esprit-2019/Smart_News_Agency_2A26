#include "equipement.h"

equipement::equipement()
{

}
equipement::equipement(int id,QString nom,QString composant,int nombre,int numero)
{
    this->id=id;
    this->nom=nom;
    this->composant=composant;
    this->nombre=nombre;
    this->numero=numero;

}
bool equipement::ajouter()
{
    QSqlQuery q;
    q.prepare("insert into equipement values(:id,:nom,:composant,:nombre,:numero)");
    q.bindValue(":id",id);
     q.bindValue(":nom",nom);
      q.bindValue(":composant",composant);
       q.bindValue(":nombre",nombre);
         q.bindValue(":numero",numero);

           return q.exec();

}
bool equipement::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from equipement where id=:id");
    q.bindValue(":id",id);//injection sql (securité)
    return q.exec();
}
QSqlQueryModel* equipement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from equipement");
    return model;
}
bool equipement::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update equipement set nom=:nom,composant=:composant,nombre=:nombre,numero=:numero where id=:id");
    q.bindValue(":id",id);
     q.bindValue(":nom",nom);
      q.bindValue(":composant",composant);
       q.bindValue(":nombre",nombre);
        q.bindValue(":numero",numero);

           return q.exec();
}
bool equipement::rechercher(int id)
{
    QSqlQuery q;
    q.prepare("select id from equipement where id=:id");
    q.bindValue(":id",id);
    q.exec();
    return q.next();
}
QSqlQueryModel * equipement::trie_id()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select *from equipement order by id ASC");
return model;
}
QSqlQueryModel * equipement::trie_nom()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select *from equipement order by nom ASC");
return model;
}
QSqlQueryModel * equipement::trie_numero()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select *from equipement order by numero ASC");
return model;
}

