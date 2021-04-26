#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include "smtp.h"
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(tmpm.afficher());
     ui->tableView->setModel(tmpm2.afficher());
     QPieSeries *series = new QPieSeries();
        QSqlQuery q("select type,count(*) from publicite group by type");


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

        chart->setAnimationOptions(QChart::AllAnimations);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        series->setLabelsVisible(true);


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
    }

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
                                        "<center> <H1>Liste des sponsors</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

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
