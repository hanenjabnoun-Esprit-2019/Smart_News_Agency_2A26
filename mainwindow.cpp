#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpm.afficher());
    ui->tableView_2->setModel(tmpm2.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


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
                               QObject::tr("failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

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
    }





}

void MainWindow::on_pushButton_16_clicked()
{
    int id=ui->lineEdit_12->text().toInt();
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

void MainWindow::on_pushButton_12_clicked()
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
                                        "<center> <H1>Liste des maintenances</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

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
