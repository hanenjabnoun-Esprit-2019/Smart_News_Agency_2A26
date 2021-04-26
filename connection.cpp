#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
<<<<<<< HEAD
db.setUserName("mariem");//inserer nom de l'utilisateur
db.setPassword("191JFT1245");//inserer mot de passe de cet utilisateur
=======
db.setUserName("ahmed");//inserer nom de l'utilisateur
db.setPassword("ahmed2000");//inserer mot de passe de cet utilisateur
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e

if (db.open())
test=true;





    return  test;
}

