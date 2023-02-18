#include "mainwindow.h"
#include "last.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDate>

#include <QChart>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QChartView>

using namespace QtCharts;

bool calendar = true;
QDate newDate(2020,05,13);
QDate oldDate(2020,06,16);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("La Banque");
    setWindowIcon(QIcon(":/logo.png"));

    ui->icon1->setIcon(QIcon(":/icon1.png"));
    ui->icon1->setIconSize(QSize(25,25));
    //////////////////////////////////

    ui->mode->setIcon(QIcon(":/icon5.2.png"));
    ui->mode->setIconSize(QSize(100,100));
    ui->mode->setCheckable(true);

    ////////////////////////////
    ui->print->setIcon(QIcon(":/icon2.png"));
    ui->print->setIconSize(QSize(50,50));
    ///////////////////////////

    ui->download->setIcon(QIcon(":/icon3.png"));
    ui->download->setIconSize(QSize(70,50));
    ////////////////////////////

    ui->cal->setIcon(QIcon(":/icon6.png"));
    ui->cal->setIconSize(QSize(30,30));
    ////////////////////////////

    ui->readOut->setIcon(QIcon(":/icon4.2.png"));
    ui->readOut->setIconSize(QSize(50,50));
    ///////////////////////////

    ui->home->addItem("Home");
    ui->home->addItem("Canal Bancaire");
    ui->home->addItem("Canal D'assurance");
    ui->home->addItem("Canal Boursier");
    ui->home->addItem("Employée");
    //////////////////////////

    ui->file->addItem("File");
    ui->file->addItem("New");
    ui->file->addItem("Open");
    ui->file->addItem("Save as");
    ui->file->addItem("Exit");
    /////////////////////////////

    ui->edit->addItem("Edit");
    ui->edit->addItem("Copy");
    ui->edit->addItem("Paste");
    ui->edit->addItem("Cut");
    ui->edit->addItem("Undo");
    ui->edit->addItem("Redo");
    /////////////////////////////

    ui->view->addItem("View");
    ui->view->addItem("Zoom in");
    ui->view->addItem("Zoom out");
    /////////////////////////////

    ui->help->addItem("Help");
    ui->help->addItem("Welcome");
    ui->help->addItem("Getting started");
    ui->help->addItem("About");
    ui->help->addItem("Check for updates");
    /////////////////////////////

    ui->calendar->hide();
    ui->date->setText(newDate.toString("dd/MM/yyyy") + " - " + oldDate.toString("dd/MM/yyyy"));
    /////////////////////////////
    ui->agence->addItem("Toutes les agences");
    for (int i=0;i<5 ;i++ ) {
        ui->agence->addItem("Agence" + QString::number(i+1));
    }
    ///////////////////////////////////////////////
    //Graphe1
    QBarSet *setpb = new QtCharts::QBarSet("Volume des ventes");
    *setpb << 30 << 50 << 20 << 10;
    QBarSeries *seriespb = new QBarSeries();
    seriespb->append(setpb);
    QChart *chartpb = new QChart();
    chartpb->addSeries(seriespb);
    chartpb->setTitle("Produits bancaires");
    chartpb->setAnimationOptions(QChart::NoAnimation);

    QStringList categoriespb;
    categoriespb << "p" << "co" << "ch" << "ca";
    QBarCategoryAxis *axispb = new QBarCategoryAxis();
    axispb->append(categoriespb);
    chartpb->createDefaultAxes();
    chartpb->setAxisX(axispb,seriespb);
    chartpb->legend()->setVisible(true);
    chartpb->legend()->setAlignment(Qt::AlignBottom);

    ui->g1->setChart(chartpb);
    ///////////////////////////////////////////////////
    //Graphe2
    QBarSet *set0 = new QtCharts::QBarSet("Volumes des ventes");
    *set0 << 70 << 82 << 35;
    QBarSeries *seriespa = new QBarSeries();
    seriespa->append(set0);
    QChart *chartpa = new QChart();
    chartpa->addSeries(seriespa);
    chartpa->setTitle("Produits d'assurances");
    chartpa->setAnimationOptions(QChart::NoAnimation);

    QStringList categoriespa;
    categoriespa << "pc" << "velo" << "hab";
    QBarCategoryAxis *axispa = new QBarCategoryAxis();
    axispa->append(categoriespa);
    chartpa->createDefaultAxes();
    chartpa->setAxisX(axispa,seriespa);
    chartpa->legend()->setVisible(true);
    chartpa->legend()->setAlignment(Qt::AlignBottom);

    ui->g2->setChart(chartpa);
    ///////////////////////////////////////////////
    //Graphe3
    QBarSet *set1 = new QtCharts::QBarSet("Volumes des ventes");
    *set1 << 77;
    QBarSeries *seriesbo = new QBarSeries();
    seriesbo->append(set1);
    QChart *chartbo = new QChart();
    chartbo->addSeries(seriesbo);
    chartbo->setTitle("Produits boursiers");
    chartbo->setAnimationOptions(QChart::NoAnimation);

    QStringList categoriesbo;
    categoriesbo << "action";
    QBarCategoryAxis *axisbo = new QBarCategoryAxis();
    axisbo->append(categoriesbo);
    chartbo->createDefaultAxes();
    chartbo->setAxisX(axisbo,seriesbo);
    chartbo->legend()->setVisible(true);
    chartbo->legend()->setAlignment(Qt::AlignBottom);

    ui->g3->setChart(chartbo);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_icon1_clicked()
{
    int ind;
    ind = ui->home->currentIndex();

    switch (ind) {
    case 1:
        baui = new bancaire(this);
        baui->show();
        break;
    case 2:
        aui = new assurance(this);
        aui->show();
        break;
    case 3:
        boui = new boursier(this);
        boui->show();
        break;
    case 4:
        lui = new last(this);
        lui->show();
        break;
    }
}

void MainWindow::on_ban_clicked()
{
    baui = new bancaire(this);
    baui->show();
}

void MainWindow::on_assu_clicked()
{
    aui = new assurance(this);
    aui->show();
}

void MainWindow::on_bou_clicked()
{
    boui = new boursier(this);
    boui->show();
}

void MainWindow::on_mode_toggled(bool checked)
{
    if(checked)
        {
            ui->mode->setIcon(QIcon(":/icon5.png"));
            ui->mode->setIconSize(QSize(180,180));
            setStyleSheet("background-color : rgb(11, 22, 17); color : white ; font: 10pt 'MS Shell Dlg 2';");

             ui->home->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->file->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->edit->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->view->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->help->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

             ui->agence->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->date->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

             ui->icon1->setIcon(QIcon(":/icon1.2.png"));
             ui->icon1->setIconSize(QSize(30,30));

             ui->readOut->setIcon(QIcon(":/icon4.png"));
             ui->readOut->setIconSize(QSize(50,50));

             ui->cal->setIcon(QIcon(":/icon6.2.png"));
             ui->cal->setIconSize(QSize(30,30));

             ui->ban->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->bou->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->assu->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

             ui->a1->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a2->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a3->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a4->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a5->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a6->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a7->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a8->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
             ui->a9->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

           ui->mode->setStyleSheet("background-color : rgb(156, 156, 156) ;");
        }
        else
        {

            ui->mode->setIcon(QIcon(":/icon5.2.png"));
            ui->mode->setIconSize(QSize(100,100));
            setStyleSheet("color : black ; font: 10pt 'MS Shell Dlg 2';");

            ui->icon1->setIcon(QIcon(":/icon1.png"));
            ui->icon1->setIconSize(QSize(25,25));

            ui->readOut->setIcon(QIcon(":/icon4.2.png"));
            ui->readOut->setIconSize(QSize(50,50));

            ui->cal->setIcon(QIcon(":/icon6.png"));
            ui->cal->setIconSize(QSize(30,30));

            ui->home->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->file->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->edit->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->view->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->help->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

            ui->agence->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->date->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

            ui->ban->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->bou->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->assu->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

            ui->a1->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a2->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a3->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a4->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a5->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a6->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a7->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a8->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
            ui->a9->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

        }
}

void MainWindow::on_cal_clicked()
{
    if(calendar)
        {
            ui->calendar->show();
            calendar = false ;
        }

        else
        {
            ui->calendar->hide();
            calendar = true ;

        }
}



void MainWindow::on_calendar_selectionChanged()
{
    newDate = ui->calendar->selectedDate();

    if (oldDate > newDate)
        ui->date->setText(newDate.toString("dd/MM/yyyy") +" - " + oldDate.toString("dd/MM/yyyy"));
    else
        ui->date->setText(oldDate.toString("dd/MM/yyyy") +" - " + newDate.toString("dd/MM/yyyy"));

      oldDate = ui->calendar->selectedDate();
}

//Graphe1
void MainWindow::on_a1_clicked()
{
    QBarSet *set0 = new QtCharts::QBarSet("CA des ventes");
    *set0 << 12030 << 2350 << 620 << 410;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Produits bancaires");
    chart->setAnimationOptions(QChart::NoAnimation);

    QStringList categories;
    categories << "p" << "co" << "ch" << "ca";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->g1->setChart(chart);
}


void MainWindow::on_a2_clicked()
{
    QBarSet *set0 = new QtCharts::QBarSet("Volume des ventes");
    *set0 << 30 << 50 << 20 << 10;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Produits bancaires");
    chart->setAnimationOptions(QChart::NoAnimation);

    QStringList categories;
    categories << "p" << "co" << "ch" << "ca";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->g1->setChart(chart);
}

void MainWindow::on_a3_clicked()
{
    QBarSet *set0 = new QtCharts::QBarSet("Pourcentages des ventes");
    *set0 << 28 << 15 << 45 << 9;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Produits bancaires");
    chart->setAnimationOptions(QChart::NoAnimation);

    QStringList categories;
    categories << "p" << "co" << "ch" << "ca";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->g1->setChart(chart);
}

//Graphe2
void MainWindow::on_a4_clicked()
{
    QBarSet *set0 = new QtCharts::QBarSet("CA des ventes");
    *set0 << 1203 << 8350 << 25620;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Produits d'assurances");
    chart->setAnimationOptions(QChart::NoAnimation);

    QStringList categories;
    categories << "pc" << "velo" << "hab";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->g2->setChart(chart);
}

void MainWindow::on_a5_clicked()
{
    QBarSet *set0 = new QtCharts::QBarSet("Volumes des ventes");
    *set0 << 70 << 82 << 35;
    QBarSeries *seriespa = new QBarSeries();
    seriespa->append(set0);
    QChart *chartpa = new QChart();
    chartpa->addSeries(seriespa);
    chartpa->setTitle("Produits d'assurances");
    chartpa->setAnimationOptions(QChart::NoAnimation);

    QStringList categoriespa;
    categoriespa << "pc" << "velo" << "hab";
    QBarCategoryAxis *axispa = new QBarCategoryAxis();
    axispa->append(categoriespa);
    chartpa->createDefaultAxes();
    chartpa->setAxisX(axispa,seriespa);
    chartpa->legend()->setVisible(true);
    chartpa->legend()->setAlignment(Qt::AlignBottom);

    ui->g2->setChart(chartpa);
}

void MainWindow::on_a6_clicked()
{
    QBarSet *set0 = new QtCharts::QBarSet("Pourcentages des ventes");
    *set0 << 45 << 23 << 68;
    QBarSeries *seriespa = new QBarSeries();
    seriespa->append(set0);
    QChart *chartpa = new QChart();
    chartpa->addSeries(seriespa);
    chartpa->setTitle("Produits d'assurances");
    chartpa->setAnimationOptions(QChart::NoAnimation);

    QStringList categoriespa;
    categoriespa << "pc" << "velo" << "hab";
    QBarCategoryAxis *axispa = new QBarCategoryAxis();
    axispa->append(categoriespa);
    chartpa->createDefaultAxes();
    chartpa->setAxisX(axispa,seriespa);
    chartpa->legend()->setVisible(true);
    chartpa->legend()->setAlignment(Qt::AlignBottom);

    ui->g2->setChart(chartpa);
}

//Graphe3
void MainWindow::on_a7_clicked()
{
    QBarSet *set0 = new QtCharts::QBarSet("CA des ventes");
    *set0 << 4250620;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Produits boursiers");
    chart->setAnimationOptions(QChart::NoAnimation);

    QStringList categories;
    categories << "action";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    ui->g3->setChart(chart);
}

void MainWindow::on_a8_clicked()
{
    QBarSet *set1 = new QtCharts::QBarSet("Volumes des ventes");
    *set1 << 77;
    QBarSeries *seriesbo = new QBarSeries();
    seriesbo->append(set1);
    QChart *chartbo = new QChart();
    chartbo->addSeries(seriesbo);
    chartbo->setTitle("Produits boursiers");
    chartbo->setAnimationOptions(QChart::NoAnimation);

    QStringList categoriesbo;
    categoriesbo << "action";
    QBarCategoryAxis *axisbo = new QBarCategoryAxis();
    axisbo->append(categoriesbo);
    chartbo->createDefaultAxes();
    chartbo->setAxisX(axisbo,seriesbo);
    chartbo->legend()->setVisible(true);
    chartbo->legend()->setAlignment(Qt::AlignBottom);

    ui->g3->setChart(chartbo);
}

void MainWindow::on_a9_clicked()
{
    QBarSet *set1 = new QtCharts::QBarSet("Pourcentages des ventes");
    *set1 << 89;
    QBarSeries *seriesbo = new QBarSeries();
    seriesbo->append(set1);
    QChart *chartbo = new QChart();
    chartbo->addSeries(seriesbo);
    chartbo->setTitle("Produits boursiers");
    chartbo->setAnimationOptions(QChart::NoAnimation);

    QStringList categoriesbo;
    categoriesbo << "action";
    QBarCategoryAxis *axisbo = new QBarCategoryAxis();
    axisbo->append(categoriesbo);
    chartbo->createDefaultAxes();
    chartbo->setAxisX(axisbo,seriesbo);
    chartbo->legend()->setVisible(true);
    chartbo->legend()->setAlignment(Qt::AlignBottom);

    ui->g3->setChart(chartbo);
}
