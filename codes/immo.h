#ifndef IMMO_H
#define IMMO_H

#include <QDialog>

namespace Ui {
class immo;
}

class immo : public QDialog
{
    Q_OBJECT

public:
    explicit immo(QWidget *parent = nullptr);
    ~immo();

private slots:

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::immo *ui;
};

#endif // IMMO_H
