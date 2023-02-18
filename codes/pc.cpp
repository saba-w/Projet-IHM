#include "pc.h"
#include "ui_pc.h"

#include <QChart>
#include <QLineSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QChartView>

#include <QString>
#include <QDate>

bool calendar6 = true;
QDate newdate5(2020,05,13);
QDate olddate5(2020,06,16);

using namespace QtCharts;

pc::pc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pc)
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
    ui->date->setText(newdate5.toString("dd/MM/yyyy") + " - " + olddate5.toString("dd/MM/yyyy"));
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

    //Assurance Pc
    QLineSeries *seriespc = new QLineSeries();

    seriespc->append(0, 6);
    seriespc->append(2, 14);
    seriespc->append(3, 28);
    seriespc->append(7, 44);
    seriespc->append(10, 65);

    QChart *chartpc = new QChart();
    chartpc->legend()->hide();
    chartpc->addSeries(seriespc);
    chartpc->createDefaultAxes();
    chartpc->setTitle("Assurance PC");

    ui->assurancePC->setChart(chartpc);

}

pc::~pc()
{
    delete ui;
}

void pc::on_mode_toggled(bool checked)
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

void pc::on_cal_clicked()
{
    if(calendar6)
        {
            ui->calendar->show();
            calendar6 = false ;
        }

        else
        {
            ui->calendar->hide();
            calendar6 = true ;

        }
}

void pc::on_calendar_selectionChanged()
{
    newdate5 = ui->calendar->selectedDate();

    if (olddate5 > newdate5)
        ui->date->setText(newdate5.toString("dd/MM/yyyy") +" - " + olddate5.toString("dd/MM/yyyy"));
    else
        ui->date->setText(olddate5.toString("dd/MM/yyyy") +" - " + newdate5.toString("dd/MM/yyyy"));

      olddate5 = ui->calendar->selectedDate();
}
