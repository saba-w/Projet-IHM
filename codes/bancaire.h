#ifndef BANCAIRE_H
#define BANCAIRE_H
#include "immo.h"
#include <QDialog>

namespace Ui {
class bancaire;
}

class bancaire : public QDialog
{
    Q_OBJECT

public:
    explicit bancaire(QWidget *parent = nullptr);
    ~bancaire();

private slots:

    void on_valide1_clicked();

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::bancaire *ui;
    immo *immui;

};

#endif // BANCAIRE_H
