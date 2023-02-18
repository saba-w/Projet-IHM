#ifndef ASSURANCE_H
#define ASSURANCE_H

#include "pc.h"
#include "velo.h"
#include "hab.h"
#include <QDialog>

namespace Ui {
class assurance;
}

class assurance : public QDialog
{
    Q_OBJECT

public:
    explicit assurance(QWidget *parent = nullptr);
    ~assurance();

private slots:

    void on_assuPc_clicked();

    void on_assuV_clicked();

    void on_assuH_clicked();

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::assurance *ui;
    pc *pcui;
    velo * vui;
    hab* hui;

};

#endif // ASSURANCE_H
