#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
class equipement
{
public:
    equipement();
    equipement(int,QString,QString,int,int);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier(int);
    bool rechercher(int);
    QSqlQueryModel* trie_id();
    QSqlQueryModel* trie_nom();
    QSqlQueryModel* trie_numero();
private:
    int id;
    QString nom;
    QString composant;
    int nombre;
    int numero;


};


#endif // EQUIPEMENT_H
