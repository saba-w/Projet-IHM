#include "bancaire.h"
#include "ui_bancaire.h"

#include <QChart>
#include <QLineSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QChartView>

#include <QString>
#include <QDate>

bool calendar8 = true;
QDate newdate7(2020,05,13);
QDate olddate7(2020,06,16);

using namespace QtCharts;

bancaire::bancaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bancaire)
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
    ui->calendar->hide();
    ui->date->setText(newdate7.toString("dd/MM/yyyy") + " - " + olddate7.toString("dd/MM/yyyy"));
    /////////////////////////////

    ui->readOut->setIcon(QIcon(":/icon4.png"));
    ui->readOut->setIconSize(QSize(50,50));
    ////////////////////////////

    ui->home->addItem("Home");
    ui->home->addItem("Canal Bancaire");
    ui->home->addItem("Canal D'assurance");
    ui->home->addItem("Canal Boursier");
    ui->home->addItem("Employée");
    ////////////////////////

    ui->prets->addItem("Prets");
    ui->prets->addItem("Immobiliers");
    ui->prets->addItem("Consommation");
    ui->prets->addItem("Voiture");
    //////////////////////////

    ui->comptes->addItem("Compte");
    ui->comptes->addItem("Courant");
    ui->comptes->addItem("Epargne");
    //////////////////////////

    ui->cartes->addItem("Cartes");
    ui->cartes->addItem("Visa classique");
    ui->cartes->addItem("Visa Electron");
    ui->cartes->addItem("MasterCard");
    ui->cartes->addItem("MasterCard Maestro");
    //////////////////////////

    ui->chequiers->addItem("Chequiers");
    ui->chequiers->addItem("Classique");
    ui->chequiers->addItem("Portefeuille");
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
    ui->agence->addItem("Toutes les agences");
    for (int i=0;i<5 ;i++ ) {
        ui->agence->addItem("Agence" + QString::number(i+1));
    }

    //Prets
    QLineSeries *seriesp = new QLineSeries();

    seriesp->append(0, 8);
    seriesp->append(2, 12);
    seriesp->append(3, 18);
    seriesp->append(7, 24);
    seriesp->append(10, 65);

    QChart *chartp = new QChart();
    chartp->legend()->hide();
    chartp->addSeries(seriesp);
    chartp->createDefaultAxes();
    chartp->setTitle("Prets");

    ui->pret->setChart(chartp);

    //Compte
    QLineSeries *seriescp = new QLineSeries();

    seriescp->append(0, 6);
    seriescp->append(2, 4);
    seriescp->append(3, 8);
    seriescp->append(7, 4);
    seriescp->append(10, 5);

    QChart *chartcp = new QChart();
    chartcp->legend()->hide();
    chartcp->addSeries(seriescp);
    chartcp->createDefaultAxes();
    chartcp->setTitle("Comptes");

    ui->compte->setChart(chartcp);

    //Chequier
    QLineSeries *seriesch = new QLineSeries();

    seriesch->append(0, 3);
    seriesch->append(2, 4);
    seriesch->append(3, 8);
    seriesch->append(7, 4);
    seriesch->append(10, 5);

    QChart *chartch = new QChart();
    chartch->legend()->hide();
    chartch->addSeries(seriesch);
    chartch->createDefaultAxes();
    chartch->setTitle("Chequiers");

    ui->chequier->setChart(chartch);

    //Cartes
    QLineSeries *seriesc = new QLineSeries();

    seriesc->append(0, 16);
    seriesc->append(2, 24);
    seriesc->append(3, 18);
    seriesc->append(7, 24);
    seriesc->append(10, 35);

    QChart *chartc = new QChart();
    chartc->legend()->hide();
    chartc->addSeries(seriesc);
    chartc->createDefaultAxes();
    chartc->setTitle("Cartes");

    ui->carte->setChart(chartc);
}

bancaire::~bancaire()
{
    delete ui;
}


void bancaire::on_valide1_clicked()
{
    if (ui->prets->currentIndex() == 1){
        immui = new immo(this);
        immui->show();
    }
}

void bancaire::on_mode_toggled(bool checked)
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

         ui->prets->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->comptes->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->chequiers->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->cartes->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

         ui->valide1->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->valide2->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->valide3->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->valide4->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

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

        ui->prets->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->comptes->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->chequiers->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->cartes->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

        ui->valide1->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->valide2->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->valide3->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->valide4->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");


    }
}

void bancaire::on_cal_clicked()
{
    if(calendar8)
        {
            ui->calendar->show();
            calendar8 = false ;
        }

        else
        {
            ui->calendar->hide();
            calendar8 = true ;

        }
}

void bancaire::on_calendar_selectionChanged()
{
    newdate7 = ui->calendar->selectedDate();

    if (olddate7 > newdate7)
        ui->date->setText(newdate7.toString("dd/MM/yyyy") +" - " + olddate7.toString("dd/MM/yyyy"));
    else
        ui->date->setText(olddate7.toString("dd/MM/yyyy") +" - " + newdate7.toString("dd/MM/yyyy"));

      olddate7 = ui->calendar->selectedDate();
}
