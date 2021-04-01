#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicite.h"
#include "sponsors.h"

#include <QMainWindow>

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
    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    publicite tmpm;
    sponsors tmpm2;
};
#endif // MAINWINDOW_H
