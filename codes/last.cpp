#include "last.h"
#include "ui_last.h"

#include <QChart>
#include <QPieSeries>
#include <QPieSlice>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QChartView>

#include <QString>
#include <QDate>

bool calendar5 = true;
QDate newdate4(2020,05,13);
QDate olddate4(2020,06,16);

using namespace QtCharts;

last::last(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::last)
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

    ui->search->setIcon(QIcon(":/icon10.png"));
    ui->search->setIconSize(QSize(30,30));
    ui->search2->setIcon(QIcon(":/icon10.png"));
    ui->search2->setIconSize(QSize(30,30));
    ////////////////////////////

    ui->cal->setIcon(QIcon(":/icon6.png"));
    ui->cal->setIconSize(QSize(30,30));
    ui->calendar->hide();
    ui->date->setText(newdate4.toString("dd/MM/yyyy") + " - " + olddate4.toString("dd/MM/yyyy"));
    //////////////////////////////

    ui->readOut->setIcon(QIcon(":/icon4.png"));
    ui->readOut->setIconSize(QSize(50,50));
    ////////////////////////////

    ui->profile->setIcon(QIcon(":/icon9.png"));
    ui->profile->setIconSize(QSize(90,90));
    ////////////////////////////

    ui->mail->setIcon(QIcon(":/icon7.png"));
    ui->mail->setIconSize(QSize(60,60));
    ////////////////////////////

    ui->phone->setIcon(QIcon(":/icon8.png"));
    ui->phone->setIconSize(QSize(50,50));
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

    ui->agence->addItem("Toutes les agences");
    for (int i=0;i<5 ;i++ ) {
        ui->agence->addItem("Agence" + QString::number(i+1));
    }

    //Performance
    QPieSeries *series = new QPieSeries();
    series->append("I",.40);
    series->append("V",.20);
    series->append("C",.15);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Performance");

    ui->perf->setChart(chart);

}

last::~last()
{
    delete ui;
}

void last::on_icon1_clicked()
{
    int ind;
    ind = ui->home->currentIndex();

    switch (ind) {
    case 1:
        bauiEm = new bancaire(this);
        bauiEm->show();
        break;
    case 2:
        auiEm = new assurance(this);
        auiEm->show();
        break;
    case 3:
        bouiEm = new boursier(this);
        bouiEm->show();
        break;
    case 4:
        luiEm = new last(this);
        luiEm->show();
        break;
    }
}


void last::on_mode_toggled(bool checked)
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
         ui->namesearch->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

         ui->icon1->setIcon(QIcon(":/icon1.2.png"));
         ui->icon1->setIconSize(QSize(30,30));

         ui->readOut->setIcon(QIcon(":/icon4.png"));
         ui->readOut->setIconSize(QSize(50,50));

         ui->cal->setIcon(QIcon(":/icon6.2.png"));
         ui->cal->setIconSize(QSize(30,30));
         ui->date->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->search->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->search2->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");
         ui->choix->setStyleSheet("color : black ; background-color : rgb(156, 156, 156);");

         ui->profile->setIcon(QIcon(":/icon9.png"));
         ui->profile->setIconSize(QSize(90,90));
         ui->mail->setIcon(QIcon(":/icon7.png"));
         ui->mail->setIconSize(QSize(60,60));
         ui->phone->setIcon(QIcon(":/icon8.png"));
         ui->phone->setIconSize(QSize(50,50));

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
        ui->date->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->search->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->search2->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->choix->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

        ui->home->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->file->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->edit->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->view->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->help->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

        ui->agence->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");
        ui->namesearch->setStyleSheet("color : black ; background-color : rgb(218, 218, 218);");

        ui->profile->setIcon(QIcon(":/icon9.png"));
        ui->profile->setIconSize(QSize(90,90));
        ui->mail->setIcon(QIcon(":/icon7.2.png"));
        ui->mail->setIconSize(QSize(60,60));
        ui->phone->setIcon(QIcon(":/icon8.png"));
        ui->phone->setIconSize(QSize(50,50));

    }
}

void last::on_cal_clicked()
{
    if(calendar5)
        {
            ui->calendar->show();
            calendar5 = false ;
        }

        else
        {
            ui->calendar->hide();
            calendar5 = true ;

        }
}

void last::on_calendar_selectionChanged()
{
    newdate4 = ui->calendar->selectedDate();

    if (olddate4 > newdate4)
        ui->date->setText(newdate4.toString("dd/MM/yyyy") +" - " + olddate4.toString("dd/MM/yyyy"));
    else
        ui->date->setText(olddate4.toString("dd/MM/yyyy") +" - " + newdate4.toString("dd/MM/yyyy"));

      olddate4 = ui->calendar->selectedDate();
}
