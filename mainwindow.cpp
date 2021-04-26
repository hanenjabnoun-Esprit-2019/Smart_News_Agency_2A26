#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include <QPixmap>
#include "smtp.h"
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpe.afficher_e()); // afficher les employés
     ui->tableView_2->setModel(tmpd.afficher_d());  // afficher les departements
     ui->tableView_3->setModel(tmpe.stat());  //voir statistique
     connect(ui->lineEdit_8,SIGNAL(textChanged(QString)),this,SLOT(affrech()));
     QPixmap pix("C:/Users/ASUS/Desktop/back1.jpg");
     ui->label_33->setPixmap(pix);
     ui->pushButton_18->hide();
     ui->comboBox->hide();

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
       QString email =ui->lineEdit_6->text();
       int numero=ui->lineEdit_7->text().toInt();
       int id_dep=ui->lineEdit_24->text().toInt ();
       employe  e (id , nom , prenom , role , salaire ,email , numero ,id_dep);
       bool test= e.ajouter_e();
       if(test)

       {  ui->tableView->setModel(tmpe.afficher_e());
           ui->tableView_3->setModel(tmpe.stat());
           Smtp* smtp = new Smtp("ahmed.harrabi@esprit.tn", "ahmed123", "smtp.gmail.com", 465);
              connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
              smtp->sendMail("ahmed.harrabi@esprit.tn",ui->lineEdit_6->text(), "verification","vous étes inscris...");

          QSystemTrayIcon * notifier=new QSystemTrayIcon(this);
          notifier->setIcon(QIcon(""));
          notifier->show();
          notifier->showMessage("Employé ajouté","OK",QSystemTrayIcon::Information,10000);   //notifcation


   }
       else
       {
       QSystemTrayIcon * notifier=new QSystemTrayIcon(this);
       notifier->setIcon(QIcon(""));
       notifier->show();
       notifier->showMessage("Employé non ajouté","OK",QSystemTrayIcon::Critical,10000); }  //notifcation

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
       QString email =ui->lineEdit_10->text();
       int numero=ui->lineEdit_11->text().toInt();
       employe  e (id , nom , prenom , role , salaire ,email , numero,0 );
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




void MainWindow::affrech()
{

ui->tableView->setModel(tmpe.afficher_e_rech(ui->lineEdit_8->text().toInt()));

}





void MainWindow::on_commandLinkButton_clicked() //?
{
    ui->tabWidget_3->setCurrentIndex(4);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_18->show();
    ui->comboBox->show();
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->pushButton_18->hide();
    ui->comboBox->hide();
    if(ui->comboBox->currentText()=="Background 1")
    {QPixmap pix("C:/Users/ASUS/Desktop/back1.jpg");
        ui->label_33->setPixmap(pix);}
    if(ui->comboBox->currentText()=="Background 2")
    {QPixmap pix("C:/Users/ASUS/Desktop/back2.png");
        ui->label_33->setPixmap(pix);}
    if(ui->comboBox->currentText()=="Background 3")
    {QPixmap pix("C:/Users/ASUS/Desktop/back3.jpg");
        ui->label_33->setPixmap(pix);}
}

void MainWindow::on_pushButton_19_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tableView->model()->rowCount();
                        const int columnCount = ui->tableView->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des employes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tableView->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tableView->isColumnHidden(column)) {
                                                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                doc.print(&printer);
}
