#ifndef VELO_H
#define VELO_H

#include <QDialog>

namespace Ui {
class velo;
}

class velo : public QDialog
{
    Q_OBJECT

public:
    explicit velo(QWidget *parent = nullptr);
    ~velo();

private slots:

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::velo *ui;
};

#endif // VELO_H
