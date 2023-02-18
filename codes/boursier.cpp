#include "boursier.h"
#include "ui_boursier.h"

#include <QChart>
#include <QLineSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QChartView>

#include <QString>
#include <QDate>

bool calendar3 = true;
QDate newdate1(2020,05,13);
QDate olddate1(2020,06,16);

using namespace QtCharts;


boursier::boursier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boursier)
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
    ui->date->setText(newdate1.toString("dd/MM/yyyy") + " - " + olddate1.toString("dd/MM/yyyy"));
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

    //Bourse
    QLineSeries *seriesb = new QLineSeries();

    seriesb->append(0, 14000);
    seriesb->append(2, 6500);
    seriesb->append(3, 1354);
    seriesb->append(7, 13560);
    seriesb->append(10, 30000);

    QChart *chartb = new QChart();
    chartb->legend()->hide();
    chartb->addSeries(seriesb);
    chartb->createDefaultAxes();
    chartb->setTitle("Bourse: Action");

    ui->bourse->setChart(chartb);

}


boursier::~boursier()
{
    delete ui;
}

void boursier::on_mode_toggled(bool checked)
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

void boursier::on_cal_clicked()
{
    if(calendar3)
        {
            ui->calendar->show();
            calendar3 = false ;
        }

        else
        {
            ui->calendar->hide();
            calendar3 = true ;

        }
}

void boursier::on_calendar_selectionChanged()
{
    newdate1 = ui->calendar->selectedDate();

    if (olddate1 > newdate1)
        ui->date->setText(newdate1.toString("dd/MM/yyyy") +" - " + olddate1.toString("dd/MM/yyyy"));
    else
        ui->date->setText(olddate1.toString("dd/MM/yyyy") +" - " + newdate1.toString("dd/MM/yyyy"));

      olddate1 = ui->calendar->selectedDate();
}
