#ifndef LAST_H
#define LAST_H
#include "assurance.h"
#include "bancaire.h"
#include "boursier.h"
#include <QDialog>

namespace Ui {
class last;
}

class last : public QDialog
{
    Q_OBJECT

public:
    explicit last(QWidget *parent = nullptr);
    ~last();

private slots:

    void on_mode_toggled(bool checked);

    void on_icon1_clicked();

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::last *ui;
    assurance *auiEm;
    last *luiEm;
    bancaire *bauiEm;
    boursier *bouiEm;
};

#endif // LAST_H
