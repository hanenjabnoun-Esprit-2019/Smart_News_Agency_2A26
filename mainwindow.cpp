#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
<<<<<<< HEAD
#include "smtp.h"
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSystemTrayIcon>
=======
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    ui->tableView_2->setModel(tmpm.afficher());
     ui->tableView->setModel(tmpm2.afficher());
     QPieSeries *series = new QPieSeries();
        QSqlQuery q("select type,count(*) from publicite group by type");
=======
 /*   QPixmap pix1("C:/Users/Asus/Desktop/baack.jpg");
       ui->label_13->setPixmap(pix1);*/

    ui->tableView->setModel(tmpm.afficher());
    ui->tableView_2->setModel(tmpm2.afficher());
    QPieSeries *series = new QPieSeries();
       QSqlQuery q("select type,count(*) from maintenance group by type");

>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e

        while(q.next())
        {series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques");
       chart->setBackgroundBrush(Qt::transparent);
       QChartView *chartview = new QChartView(chart);
       chartview->setRenderHint(QPainter::Antialiasing);
       chartview->setParent(ui->horizontalFrame);
       chartview->resize(400,300);

<<<<<<< HEAD
         while(q.next())
         {series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques");
        chart->setBackgroundBrush(Qt::transparent);
        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->horizontalFrame);
        chartview->resize(400,300);
=======
       chart->setAnimationOptions(QChart::AllAnimations);
       chart->legend()->setVisible(true);
       chart->legend()->setAlignment(Qt::AlignRight);
       series->setLabelsVisible(true);
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e

        chart->setAnimationOptions(QChart::AllAnimations);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        series->setLabelsVisible(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}


<<<<<<< HEAD
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
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité ajouté","Succés",QSystemTrayIcon::Information,10000);


}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité non ajouté","Echéc",QSystemTrayIcon::Critical,10000);
    }




}

void MainWindow::on_pushButton_19_clicked()
{
    int id=ui->lineEdit_25->text().toInt();
    if(tmpm.rechercher(id))
    {
   bool test=tmpm.supprimer(id);
    if(test)
    { ui->tableView_2->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité supprimé","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité non supprimé","Echéc",QSystemTrayIcon::Critical,10000);
    }
}
    else QMessageBox::critical(nullptr, QObject::tr("publicié introuvable"),
=======
void MainWindow::on_pushButton_13_clicked()
{
    int id=ui->lineEdit_18->text().toInt();
    QString perso=ui->lineEdit_22->text();
    QString type=ui->lineEdit_19->text();
    QString outil_nec=ui->lineEdit_20->text();
    int num=ui->lineEdit_21->text().toInt();
    QString date=ui->lineEdit_23->text();
    int prix=ui->lineEdit_24->text().toInt();
    int etat=ui->lineEdit_25->text().toInt();
    maintenance m(id,perso,type,outil_nec,num,date,prix,etat);
    bool test=m.ajouter();
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("maintenance ajouté"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("maintenance non ajouté"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pushButton_8_clicked()
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
    int id=ui->tableView->model()->index(row,0).data().toInt();
    if(tmpm.rechercher(id))
    {
   bool test=tmpm.supprimer(id);
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("maintenance supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("maintenance non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("maintenance introuvable"),
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_10_clicked()
{   ui->tableView->setModel(tmpm.afficher());
    int id=ui->lineEdit_13->text().toInt();
    QString perso=ui->lineEdit_17->text();
    QString type=ui->lineEdit_14->text();
    QString outil_nec=ui->lineEdit_15->text();
    int num=ui->lineEdit_16->text().toInt();
    QString date=ui->lineEdit_28->text();
    float prix=ui->lineEdit_26->text().toFloat();
    int etat=ui->lineEdit_27->text().toInt();
    maintenance m(id,perso,type,outil_nec,num,date,prix,etat);
    m.modifier(id);
    bool test=m.modifier(id);
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("maintenance modfié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("maintenance non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_5->text();
    QString composant=ui->lineEdit_2->text();
    int nombre=ui->lineEdit_3->text().toInt();
    int numero=ui->lineEdit_4->text().toInt();

    equipement m(id,nom,composant,nombre,numero);
    bool test=m.ajouter();
    if(test)
    { ui->tableView_2->setModel(tmpm2.afficher());
        QMessageBox::information(nullptr, QObject::tr("equipement ajouté"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("equipement non ajouté"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView_2->setModel(tmpm2.afficher());
        int id=ui->lineEdit_6->text().toInt();
        QString nom=ui->lineEdit_10->text();
        QString composant=ui->lineEdit_7->text();
        int nombre=ui->lineEdit_8->text().toInt();
        int numero=ui->lineEdit_9->text().toInt();

        equipement m(id,nom,composant,nombre,numero);
        m.modifier(id);
        bool test=m.modifier(id);
        if(test)
        { ui->tableView_2->setModel(tmpm2.afficher());
            QMessageBox::information(nullptr, QObject::tr("equipement modfié"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("equipement non modifié"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_6_clicked()
{
    int id=ui->lineEdit_11->text().toInt();
    if(tmpm2.rechercher(id))
    {
   bool test=tmpm2.supprimer(id);
    if(test)
    { ui->tableView_2->setModel(tmpm2.afficher());
        QMessageBox::information(nullptr, QObject::tr("equipement supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("equipement non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("equipement introuvable"),
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

<<<<<<< HEAD
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
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité modifié","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité non modifié","Echéc",QSystemTrayIcon::Critical,10000);
    }



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
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("sponsor ajouté","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("sponsor non ajouté","Echéc",QSystemTrayIcon::Critical,10000);
    }




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
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("sponsor modifié","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("sponsor non modifié","Echéc",QSystemTrayIcon::Critical,10000);
    }




}

void MainWindow::on_pushButton_8_clicked()
{ int id=ui->lineEdit_12->text().toInt();
    if(tmpm2.rechercher(id))
    {
   bool test=tmpm2.supprimer(id);
    if(test)
    { ui->tableView->setModel(tmpm2.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("sponsor supprimé","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("sponsor non supprimé","Echéc",QSystemTrayIcon::Critical,10000);
    }
}
    else {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("sponsor introuvable","Echec",QSystemTrayIcon::Critical,10000);
=======
void MainWindow::on_pushButton_5_clicked()
{
    if(ui->radioButton->isChecked()){
    ui->tableView_2->setModel(tmpm2.trie_id());
    }

    if(ui->radioButton_2->isChecked()){
    ui->tableView_2->setModel(tmpm2.trie_nom());
    }

    if(ui->radioButton_3->isChecked()){
    ui->tableView_2->setModel(tmpm2.trie_numero());
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e
    }

}

<<<<<<< HEAD
void MainWindow::on_pushButton_15_clicked()
{
     ui->tableView_2->setModel(tmpm.afficher_tri());
}

void MainWindow::on_pushButton_5_clicked()
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
    int id=ui->tableView_2->model()->index(row,0).data().toInt();
=======



}

void MainWindow::on_pushButton_16_clicked()
{
    int id=ui->lineEdit_12->text().toInt();
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e
    if(tmpm.rechercher(id))
    {
   bool test=tmpm.supprimer(id);
    if(test)
<<<<<<< HEAD
    { ui->tableView_2->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité supprimé","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité non supprimé","Echec",QSystemTrayIcon::Critical,10000);
    }
}
    else {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("Publicité introuvable","Echec",QSystemTrayIcon::Critical,10000);
    }
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

void MainWindow::on_pushButton_16_clicked()
=======
    { ui->tableView->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("maintenance supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("maintenance non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("maintenance introuvable"),
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_12_clicked()
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e
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
<<<<<<< HEAD
                                        "<center> <H1>Liste des sponsors</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
=======
                                        "<center> <H1>Liste des maintenances</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e

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

void MainWindow::on_pushButton_24_clicked()
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
    int id=ui->tableView_2->model()->index(row,0).data().toInt();
    if(tmpm2.rechercher(id))
    {
   bool test=tmpm2.supprimer(id);
    if(test)
    { ui->tableView_2->setModel(tmpm2.afficher());
        QMessageBox::information(nullptr, QObject::tr("equipement supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("equipement non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else QMessageBox::critical(nullptr, QObject::tr("equipement introuvable"),
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_25_clicked()
{
    QString selon=ui->comboBox->currentText();
    QString rech=ui->lineEdit_40->text();
     ui->tableView->setModel(tmpm.afficherRech(selon,rech));
}

void MainWindow::on_pushButton_23_clicked()
{
    QTableView *table;
           table = ui->tableView_2;

           QString filters("CSV files (*.csv);;All files (*.*)");
           QString defaultFilter("CSV files (*.csv)");
           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                              filters, &defaultFilter);
           QFile file(fileName);

           QAbstractItemModel *model =  table->model();
           if (file.open(QFile::WriteOnly | QFile::Truncate)) {
               QTextStream data(&file);
               QStringList strList;
               for (int i = 0; i < model->columnCount(); i++) {
                   if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                       strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                   else
                       strList.append("");
               }
               data << strList.join(";") << "\n";
               for (int i = 0; i < model->rowCount(); i++) {
                   strList.clear();
                   for (int j = 0; j < model->columnCount(); j++) {

                       if (model->data(model->index(i, j)).toString().length() > 0)
                           strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") + "\n";
               }
               file.close();
               QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
           }
}
