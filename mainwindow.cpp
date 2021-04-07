#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tmpm.afficher());
     ui->tableView->setModel(tmpm2.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_12_clicked()
{
    int id=ui->lineEdit_14->text().toInt();
    QString nom=ui->lineEdit_23->text();
    QString type=ui->lineEdit_15->text();
    QString domaine=ui->lineEdit_16->text();
    QString duree=ui->lineEdit_17->text();

    publicite p(id,nom,type,domaine,duree);
    bool test=p.ajouter();
    if(test)
    { ui->tableView_2->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("publicite ajouté"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("publicite non ajouté"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pushButton_19_clicked()
{
    int id=ui->lineEdit_25->text().toInt();
    if(tmpm.rechercher(id))
    {
   bool test=tmpm.supprimer(id);
    if(test)
    { ui->tableView_2->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("publicié supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("publicité non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("publicié introuvable"),
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_17_clicked()
{   ui->tableView_2->setModel(tmpm.afficher());
    int id=ui->lineEdit_18->text().toInt();
    QString nom=ui->lineEdit_24->text();
    QString type=ui->lineEdit_21->text();
    QString domaine=ui->lineEdit_22->text();
    QString duree=ui->lineEdit_20->text();

    publicite p(id,nom,type,domaine,duree);
    p.modifier(id);
    bool test=p.modifier(id);
    if(test)
    { ui->tableView_2->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("publitié modfié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("publicité non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}














void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString type=ui->lineEdit_3->text();
    QString duree=ui->lineEdit_4->text();
    QString offre=ui->lineEdit_5->text();
    QString adresse=ui->lineEdit_27->text();
    QString num_tel=ui->lineEdit_28->text();
    QString profession=ui->lineEdit_26->text();



    sponsors s(id,nom,type,duree,offre,adresse,num_tel,profession);
    bool test=s.ajouter();
    if(test)
    { ui->tableView->setModel(tmpm2.afficher());
        QMessageBox::information(nullptr, QObject::tr("sponsors ajouté"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("sponsors non ajouté"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pushButton_clicked()
{  ui->tableView->setModel(tmpm2.afficher());
    int id=ui->lineEdit_8->text().toInt();
    QString nom=ui->lineEdit_7->text();
    QString type=ui->lineEdit_9->text();
    QString duree=ui->lineEdit_10->text();
    QString offre=ui->lineEdit_6->text();
    QString adresse=ui->lineEdit_30->text();
    QString num_tel=ui->lineEdit_31->text();
    QString profession=ui->lineEdit_29->text();


    sponsors s(id,nom,type,duree,offre,adresse,num_tel,profession);
    s.modifier(id);
    bool test=s.modifier(id);
    if(test)
    { ui->tableView->setModel(tmpm2.afficher());
        QMessageBox::information(nullptr, QObject::tr("sponsors modfié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("sponsors non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pushButton_8_clicked()
{ int id=ui->lineEdit_12->text().toInt();
    if(tmpm2.rechercher(id))
    {
   bool test=tmpm2.supprimer(id);
    if(test)
    { ui->tableView->setModel(tmpm2.afficher());
        QMessageBox::information(nullptr, QObject::tr("sponsors supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("sponsors non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("sponsors introuvable"),
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_15_clicked()
{
     ui->tableView_2->setModel(tmpm.afficher_tri());
}

void MainWindow::on_pushButton_5_clicked()
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
    int id=ui->tableView_2->model()->index(row,0).data().toInt();
    if(tmpm.rechercher(id))
    {
   bool test=tmpm.supprimer(id);
    if(test)
    { ui->tableView_2->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("publicié supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("publicité non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("publicié introuvable"),
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_14_clicked()
{
    int id=ui->lineEdit_19->text().toInt();
    ui->tableView_2->setModel(tmpm.afficher_rech(id));
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->tableView_2->setModel(tmpm.afficher());
}

void MainWindow::on_pushButton_7_clicked()
{
    QString selon=ui->comboBox->currentText();
    QString rech=ui->lineEdit_11->text();
     ui->tableView->setModel(tmpm2.afficherRech(selon,rech));
}

void MainWindow::on_pushButton_10_clicked()
{
    Smtp* smtp = new Smtp("mariem.gnaoui@esprit.tn", "191JFT1245", "smtp.gmail.com", 465);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("mariem.gnaoui@esprit.tn",ui->lineEdit_34->text(), ui->lineEdit_32->text(),ui->lineEdit_33->text());
}
