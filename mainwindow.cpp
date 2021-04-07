#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studio.h"
#include "news.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->tableView->setModel(Stmp.afficher());
    ui->tableView_2->setModel(ntmp.afficher_n());
    connect(ui->lineEdit_40,SIGNAL(textChanged(QString)),this,SLOT(affrech()));
    connect(ui->lineEdit_39,SIGNAL(textChanged(QString)),this,SLOT(affrech_n()));


}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_pushButton_clicked()
{
//reecuperation des information saisies dans les 3 champs
    //convertit la chaine saisie en un entier car lattribut id est de type int
    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString numero=ui->lineEdit_num->text();
    QString  type=ui->lineEdit_type->text();
    QString disponibilite=ui->lineEdit_dispo->text();
    QString nbre_equip=ui->lineEdit_nbre->text();
    studio S(id,nom,numero,type,disponibilite,nbre_equip); //instancier un objet de la classe studio
                                                           //en utilisant les inforrmations saisies dans linterface

    bool test=S.ajouter(); //inserer lobjet studio inssdtancie dans la table studio
                           //et recuperer la valeur de retour de query.exec()
    if(test)
    {

        ui->tableView->setModel(Stmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                  "click cancel to exit."), QMessageBox::Cancel);
    }

else

        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("ajout non eeffectue.\n"
                                "click cancel to exit."),QMessageBox::Cancel);

}


void MainWindow::on_pushButton_supprimer_clicked()
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
    int id=ui->tableView->model()->index(row,0).data().toInt();
    bool test=Stmp.supprimer(id);
    if(test)
      {
        //refrech actualiser
        ui->tableView->setModel(Stmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression effectue\n"
                                  "click cancel to exit."), QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("suppression non eeffectue.\n"
                                "click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    //reecuperation des information saisies dans les 3 champs
        //convertit la chaine saisie en un entier car lattribut id est de type int
        int id_n=ui->lineEdit_19->text().toInt();
        QString nom_n=ui->lineEdit_20->text();
        QString type_n=ui->lineEdit_21->text();
        QString  horaire_n=ui->lineEdit_22->text();
        QString duree_n=ui->lineEdit_23->text();
        QString nom_pres_n=ui->lineEdit_24->text();
        news n(id_n,nom_n,type_n,horaire_n,duree_n,nom_pres_n); //instancier un objet de la classe news
                                                               //en utilisant les inforrmations saisies dans linterface

        bool test=n.ajouter_n(); //inserer lobjet studio inssdtancie dans la table news
                               //et recuperer la valeur de retour de query.exec()
        if(test)
        {
            //actualiser
            ui->tableView_2->setModel(ntmp.afficher_n());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajout effectue\n"
                                      "click cancel to exit."), QMessageBox::Cancel);
        }

    else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                   QObject::tr("ajout non eeffectue.\n"
                                    "click cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_pushButton_3_clicked()
{
    //reecuperation des information saisies dans les 3 champs
        //convertit la chaine saisie en un entier car lattribut id est de type int
        int id=ui->lineEdit_id_3->text().toInt();
        QString nom=ui->lineEdit_nom_3->text();
        QString numero=ui->lineEdit_num_3->text();
        QString  type=ui->lineEdit_type_3->text();
        QString disponibilite=ui->lineEdit_dispo_3->text();
        QString nbre_equip=ui->lineEdit_nbre_3->text();
        studio S(id,nom,numero,type,disponibilite,nbre_equip); //instancier un objet de la classe studio
                                                               //en utilisant les inforrmations saisies dans linterface
         if(Stmp.rechercher(id))
         {
        bool test=S.modifier(id); //inserer lobjet studio inssdtancie dans la table studio
                               //et recuperer la valeur de retour de query.exec()
        if(test)
        {

            ui->tableView->setModel(Stmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajout effectue\n"
                                      "click cancel to exit."), QMessageBox::Cancel);
        }


    else

            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                   QObject::tr("ajout non eeffectue.\n"
                                    "click cancel to exit."),QMessageBox::Cancel);


}}



void MainWindow::on_pushButton_14_clicked()
{
    QString selon=ui->comboBox->currentText();
    QString rech=ui->lineEdit_40->text();
    ui->tableView->setModel(Stmp.afficher_rech(selon,rech));

}

void MainWindow::on_pushButton_9_clicked()
{
    int id=ui->lineEdit_40->text().toInt();
    ui->tableView->setModel(Stmp.afficher_tri(id));
}

void MainWindow::on_pushButton_16_clicked()
{
    int id=ui->lineEdit_40->text().toInt();
  ui->tableView->setModel(Stmp.afficher());
}


void MainWindow::affrech()
{
    ui->tableView->setModel(Stmp.afficher_rech(ui->comboBox->currentText(),ui->lineEdit_40->text()));
}



void MainWindow::on_pushButton_60_clicked()
{
    QString selon=ui->comboBox_2->currentText();
    QString rech=ui->lineEdit_39->text();
    ui->tableView_2->setModel(ntmp.afficher_rech_n(selon,rech));
}

void MainWindow::on_pushButton_13_clicked()
{
    int id_n=ui->lineEdit_39->text().toInt();
    ui->tableView_2->setModel(ntmp.afficher_tri_n(id_n));
}

void MainWindow::on_pushButton_70_clicked()
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
    int id_n=ui->tableView_2->model()->index(row,0).data().toInt();
    bool test=ntmp.supprimer_n(id_n);
    if(test)
      {
        //refrech actualiser
        ui->tableView_2->setModel(ntmp.afficher_n());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression effectue\n"
                                  "click cancel to exit."), QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("suppression non effectue.\n"
                                "click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::affrech_n()
{
    ui->tableView_2->setModel(ntmp.afficher_rech_n(ui->comboBox_2->currentText(),ui->lineEdit_39->text()));
}
