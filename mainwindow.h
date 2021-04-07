#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studio.h"
#include "news.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_16_clicked();

    void affrech();

    void on_pushButton_60_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_70_clicked();

    void affrech_n();

private:
    Ui::MainWindow *ui;
    studio Stmp;
    news ntmp;
};

#endif // MAINWINDOW_H
