#include "lastwindow.h"
#include "ui_lastwindow.h"

LastWindow::LastWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LastWindow)
{
    ui->setupUi(this);
    setWindowTitle("La Banque");
    setWindowIcon(QIcon(":/logo.png"));

    ui->icon1->setIcon(QIcon(":/icon1.png"));
   // ui->night->setCheckable(true);
    ui->icon1->setIconSize(QSize(50,50));
    //////////////////////////////////
    ui->mode->setIcon(QIcon(":/icon5.2.png"));
    ui->mode->setIconSize(QSize(100,100));
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
    /////////////////////////////
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
    ui->agence->addItem("Toutes les agences");
    for (int i=0;i<5 ;i++ ) {
        ui->agence->addItem("Agence" + QString::number(i+1));
    }


}

LastWindow::~LastWindow()
{
    delete ui;
}

void LastWindow::on_icon1_clicked()
{

}
