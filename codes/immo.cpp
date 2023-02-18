#include "immo.h"
#include "ui_immo.h"

#include <QChart>
#include <QLineSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QChartView>

#include <QString>
#include <QDate>

bool calendar1 = true;
QDate newdate3(2020,05,13);
QDate olddate3(2020,06,16);

using namespace QtCharts;

immo::immo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::immo)
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
    ui->date->setText(newdate3.toString("dd/MM/yyyy") + " - " + olddate3.toString("dd/MM/yyyy"));
    //////////////////////////////

    ui->readOut->setIcon(QIcon(":/icon4.png"));
    ui->readOut->setIconSize(QSize(50,50));
    ////////////////////////////

    ui->home->addItem("Home");
    ui->home->addItem("Canal Bancaire");
    ui->home->addItem("Canal D'assurance");
    ui->home->addItem("Canal boursier");
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

    ui->agence->addItem("Toutes les agences");
    for (int i=0;i<5 ;i++ ) {
        ui->agence->addItem("Agence" + QString::number(i+1));
    }

    //Immobiliers
    QLineSeries *seriesimo = new QLineSeries();

    seriesimo->append(0, 16);
    seriesimo->append(2, 24);
    seriesimo->append(3, 38);
    seriesimo->append(7, 64);
    seriesimo->append(10, 125);

    QChart *chartimo = new QChart();
    chartimo->legend()->hide();
    chartimo->addSeries(seriesimo);
    chartimo->createDefaultAxes();
    chartimo->setTitle("Prets Immobiliers");

    ui->immo_2->setChart(chartimo);

}

immo::~immo()
{
    delete ui;
}

void immo::on_mode_toggled(bool checked)
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

    }
}

void immo::on_cal_clicked()
{
    if(calendar1)
        {
            ui->calendar->show();
            calendar1 = false ;
        }

        else
        {
            ui->calendar->hide();
            calendar1 = true ;

        }
}

void immo::on_calendar_selectionChanged()
{
    newdate3 = ui->calendar->selectedDate();

    if (olddate3 > newdate3)
        ui->date->setText(newdate3.toString("dd/MM/yyyy") +" - " + olddate3.toString("dd/MM/yyyy"));
    else
        ui->date->setText(olddate3.toString("dd/MM/yyyy") +" - " + newdate3.toString("dd/MM/yyyy"));

      olddate3 = ui->calendar->selectedDate();
}
