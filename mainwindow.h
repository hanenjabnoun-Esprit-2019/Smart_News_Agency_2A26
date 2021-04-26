#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicite.h"
#include "sponsors.h"

#include <QMainWindow>
<<<<<<< HEAD
#include<QSystemTrayIcon>
=======
#include "maintenance.h"
#include "equipement.h"
#include <QTextStream>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>


>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
<<<<<<< HEAD
    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_tableView_activated(const QModelIndex &index);
=======
    void on_pushButton_13_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

<<<<<<< HEAD
    void on_pushButton_19_clicked();
=======
    void on_pushButton_5_clicked();
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e

    void on_pushButton_16_clicked();

<<<<<<< HEAD
    void on_pushButton_15_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_16_clicked();

private:
    Ui::MainWindow *ui;
    publicite tmpm;
    sponsors tmpm2;
=======
    void on_pushButton_12_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_23_clicked();

private:
    Ui::MainWindow *ui;
    maintenance tmpm;
    equipement tmpm2;
>>>>>>> c8ed7c26bb35581c6fb6cc6271652b1bebaa2c1e
};
#endif // MAINWINDOW_H
