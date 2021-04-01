#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableView->setModel(tmpi.afficher_i()); // affichage table invite
    ui->tableView_2->setModel(tmpa.afficher_a()); // affichage table avi/rec
    ui->tableView_3->setModel(tmpi.stat()); //affichage table stats
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //ajouter
{
    int id=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    QString profession=ui->lineEdit_4->text();
    int num_tel=ui->lineEdit_5->text().toInt();
    QString programme=ui->lineEdit_6->text();

    invite v (id,nom,prenom,profession,num_tel,programme);
    bool test=v.ajout_i();
    if(test)
    { ui->tableView->setModel(tmpi.afficher_i());
        ui->tableView_3->setModel(tmpi.stat());
        QMessageBox::information(nullptr, QObject::tr("invite ajoute"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("invite non ajoute"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_5_clicked() //suppression avancé de la table
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
    int id=ui->tableView->model()->index(row,0).data().toInt();
    if(tmpi.rechercher_i(id)){
        bool test=tmpi.supprimer_i(id);
        if(test)
        {
            ui->tableView->setModel(tmpi.afficher_i());
            ui->tableView_3->setModel(tmpi.stat());
            QMessageBox::information(nullptr, QObject::tr("invite supprime"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("invite non supprime"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("invite introuvable"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked() //modifier
{
int id=ui->lineEdit_7->text().toInt();
QString nom=ui->lineEdit_8->text();
QString prenom=ui->lineEdit_9->text();
QString profession=ui->lineEdit_10->text();
int num_tel=ui->lineEdit_11->text().toInt();
QString programme=ui->lineEdit_12->text();
invite v (id,nom,prenom,profession,num_tel,programme);
if(tmpi.rechercher_i(id)){
    bool test=v.modifier_i(id);
    if(test)
    {
        ui->tableView->setModel(tmpi.afficher_i());
        ui->tableView_3->setModel(tmpi.stat());
        QMessageBox::information(nullptr, QObject::tr("invite modifie"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("invite non modifie"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("invite introuvable"),
                QObject::tr("failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pushButton_7_clicked() // recherche avancé
{
    int id=ui->lineEdit_14->text().toInt();
     ui->tableView->setModel(tmpi.afficher_i_rech(id));

    }


void MainWindow::on_pushButton_9_clicked() //ajouter 2
{
    int id=ui->lineEdit_15->text().toInt();
    QString destinataire=ui->lineEdit_16->text();
    QString type=ui->lineEdit_17->text();

    avis a (id,destinataire,type);
    bool test=a.ajout_a();
    if(test)
    { ui->tableView_2->setModel(tmpa.afficher_a());
        QMessageBox::information(nullptr, QObject::tr("avi ajoute"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("avi non ajoute"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_14_clicked() //supprimer 2
{
    int id=ui->lineEdit_21->text().toInt();
    if(tmpa.rechercher_a(id)){
        bool test=tmpa.supprimer_a(id);
        if(test)
        {
            ui->tableView_2->setModel(tmpa.afficher_a());
            QMessageBox::information(nullptr, QObject::tr("avi supprime"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("avi non supprime"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("avi introuvable"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_12_clicked() //modifier 2
{
    int id=ui->lineEdit_19->text().toInt();
    QString destinataire=ui->lineEdit_20->text();
    QString type=ui->lineEdit_18->text();
    avis a (id,destinataire,type);
    if(tmpa.rechercher_a(id)){
        bool test=a.modifier_a(id);
        if(test)
        {
            ui->tableView_2->setModel(tmpa.afficher_a());
            QMessageBox::information(nullptr, QObject::tr("avi modifie"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("avi non modifie"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("avi introuvable"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_8_clicked() //affichage trié
{
    ui->tableView->setModel(tmpi.afficher_i_tri());
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->tableView->setModel(tmpi.afficher_i());
}

void MainWindow::on_pushButton_19_clicked() //suppression simple invite
{
    int id=ui->lineEdit_13->text().toInt();
    if(tmpi.rechercher_i(id)){
        bool test=tmpi.supprimer_i(id);
        if(test)
        {
            ui->tableView->setModel(tmpi.afficher_i());
            QMessageBox::information(nullptr, QObject::tr("invite supprime"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("invite non supprime"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("invite introuvable"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_11_clicked() //suppression avancé avis
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
    int id=ui->tableView_2->model()->index(row,0).data().toInt();
    if(tmpa.rechercher_a(id)){
        bool test=tmpa.supprimer_a(id);
        if(test)
        {
            ui->tableView_2->setModel(tmpa.afficher_a());

            QMessageBox::information(nullptr, QObject::tr("avis/rec supprime"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("avis/rec non supprime"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("avis/rec introuvable"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
