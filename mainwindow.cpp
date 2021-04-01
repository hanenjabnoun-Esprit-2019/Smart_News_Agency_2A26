#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpe.afficher_e()); // afficher les employés
     ui->tableView_2->setModel(tmpd.afficher_d());  // afficher les departements
     ui->tableView_3->setModel(tmpe.stat());  //voir statistique
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pushButton_clicked() //ajout_emp
{
    int id=ui->lineEdit->text().toInt ();
    QString nom =ui->lineEdit_2->text();
    QString prenom =ui->lineEdit_3->text();
     QString role=ui->lineEdit_4->text();
     int salaire =ui->lineEdit_5->text().toInt();
       QString profession =ui->lineEdit_6->text();
       int numero=ui->lineEdit_7->text().toInt();
       employe  e (id , nom , prenom , role , salaire ,profession , numero );
       bool test= e.ajouter_e();
       if(test)

       {  ui->tableView->setModel(tmpe.afficher_e());
           ui->tableView_3->setModel(tmpe.stat());
          QSystemTrayIcon * notifier=new QSystemTrayIcon(this);
          notifier->setIcon(QIcon(""));
          notifier->show();
          notifier->showMessage("Employé ajouté","OK",QSystemTrayIcon::Information,10000);   //notifcation


   }
       else
           QSystemTrayIcon * notification=new QSystemTrayIcon(this);
       QSystemTrayIcon * notifier=new QSystemTrayIcon(this);
       notifier->setIcon(QIcon(""));
       notifier->show();
       notifier->showMessage("Employé non ajouté","OK",QSystemTrayIcon::Critical,10000);   //notifcation

}










void MainWindow::on_pushButton_7_clicked() //supp_emp
{
    int id=ui->lineEdit_16->text().toInt();
    if (tmpe.rechercher_e(id))
    {
  bool test=  tmpe.supprimer_e(id);

    if(test)

    {
        ui->tableView_3->setModel(tmpe.stat());
        ui->tableView->setModel(tmpe.afficher_e());
        QMessageBox::information(nullptr, QObject::tr("employe supprimé "),
                    QObject::tr(" successful ! bravo \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("employe non supprimé"),
                    QObject::tr(" failed ! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("employe introuvable"),
                               QObject::tr(" failed ! \n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}










void MainWindow::on_pushButton_4_clicked() //mod_emp
{
    int id=ui->lineEdit_15->text().toInt ();
    QString nom =ui->lineEdit_14->text();
    QString prenom =ui->lineEdit_9->text();
     QString role=ui->lineEdit_13->text();
     int salaire =ui->lineEdit_12->text().toInt();
       QString profession =ui->lineEdit_10->text();
       int numero=ui->lineEdit_11->text().toInt();
       employe  e (id , nom , prenom , role , salaire ,profession , numero );
       if (tmpe.rechercher_e(id))
       {
        bool test= e.modifier_e(id);

        if(test)
        {  ui->tableView_3->setModel(tmpe.stat());
            ui->tableView->setModel(tmpe.afficher_e());
            QMessageBox::information(nullptr, QObject::tr("employe modifié"),
                        QObject::tr(" successful ! bravo \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("employe non modifié "),
                        QObject::tr(" failed ! \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
        else QMessageBox::critical(nullptr, QObject::tr("employe introuvable"),
                                   QObject::tr(" failed ! \n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

    }







void MainWindow::on_pushButton_10_clicked() //ajout_dep
{
    int id=ui->lineEdit_23->text().toInt ();
    QString nom =ui->lineEdit_22->text();
    QString type =ui->lineEdit_17->text();
     int nomb_pers =ui->lineEdit_19->text().toInt();
       QString nom_chef =ui->lineEdit_20->text();
       int nbre_empl=ui->lineEdit_18->text().toInt();
       departement d(id , nom , type ,nomb_pers, nom_chef ,nbre_empl);
       bool test= d.ajouter_d();
       if(test)
       {  ui->tableView_2->setModel(tmpd.afficher_d());
           QMessageBox::information(nullptr, QObject::tr("departement ajouté "),
                       QObject::tr(" successful ! bravo \n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("departement non ajouté"),
                       QObject::tr(" failed ! \n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}







void MainWindow::on_pushButton_15_clicked()  //supp_dep
{
    int id=ui->lineEdit_32->text().toInt();
    if (tmpd.rechercher_d(id))
    {
  bool test=  tmpd.supprimer_d(id);

    if(test)
    {  ui->tableView_2->setModel(tmpd.afficher_d());
        QMessageBox::information(nullptr, QObject::tr("departement supprimé "),
                    QObject::tr(" successful ! bravo \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("departement non supprimé"),
                    QObject::tr(" failed ! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("departementintrouvable"),
                               QObject::tr(" failed ! \n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}








void MainWindow::on_pushButton_13_clicked() //modifier_dep
{
    int id=ui->lineEdit_31->text().toInt ();
    QString nom =ui->lineEdit_30->text();
    QString type =ui->lineEdit_25->text();
    int nomb_pers=ui->lineEdit_29->text().toInt();
       QString nom_chef =ui->lineEdit_21->text();
       int nbre_empl=ui->lineEdit_26->text().toInt();
      departement d(id , nom , type ,nomb_pers, nom_chef ,nbre_empl);
       if (tmpd.rechercher_d(id))
       {
        bool test= d.modifier_d(id);

        if(test)
        {  ui->tableView_2->setModel(tmpd.afficher_d());
            QMessageBox::information(nullptr, QObject::tr("departement modifié"),
                        QObject::tr(" successful ! bravo \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("departement non modifié "),
                        QObject::tr(" failed ! \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
        else QMessageBox::critical(nullptr, QObject::tr("departement introuvable"),
                                   QObject::tr(" failed ! \n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

}











void MainWindow::on_pushButton_3_clicked() //recherche emp
{
       int id=ui->lineEdit_8->text().toInt ();

ui->tableView->setModel(tmpe.afficher_e_rech(id));

}














void MainWindow::on_pushButton_12_clicked() //tri departement
{
    ui->tableView_2->setModel(tmpd.afficher_d_tri());
}







void MainWindow::on_pushButton_11_clicked()  //actualiser
{
    ui->tableView->setModel(tmpe.afficher_e());
}









void MainWindow::on_pushButton_17_clicked() //supprimer avec selection
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
    int id=ui->tableView->model()->index(row,0).data().toInt();
    if (tmpe.rechercher_e(id))
    {
  bool test=  tmpe.supprimer_e(id);

    if(test)
    {  ui->tableView->setModel(tmpe.afficher_e());
        QMessageBox::information(nullptr, QObject::tr("employé supprimé "),
                    QObject::tr(" successful ! bravo \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("employé non supprimé"),
                    QObject::tr(" failed ! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("employé introuvable"),
                               QObject::tr(" failed ! \n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}










void MainWindow::on_commandLinkButton_clicked() //?
{
    ui->tabWidget_3->setCurrentIndex(4);
}
