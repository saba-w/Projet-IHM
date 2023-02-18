#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "last.h"
#include "bancaire.h"
#include "assurance.h"
#include "boursier.h"
#include <QMainWindow>
#include <QtCharts>

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
    void on_icon1_clicked();

    void on_ban_clicked();

    void on_assu_clicked();

    void on_bou_clicked();

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

    void on_a1_clicked();

    void on_a2_clicked();

    void on_a3_clicked();

    void on_a4_clicked();

    void on_a5_clicked();

    void on_a6_clicked();

    void on_a7_clicked();

    void on_a8_clicked();

    void on_a9_clicked();

private:
    Ui::MainWindow *ui;
    last *lui;
    bancaire *baui;
    assurance *aui;
    boursier *boui;



};
#endif // MAINWINDOW_H
