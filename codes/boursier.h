#ifndef BOURSIER_H
#define BOURSIER_H

#include <QDialog>

namespace Ui {
class boursier;
}

class boursier : public QDialog
{
    Q_OBJECT

public:
    explicit boursier(QWidget *parent = nullptr);
    ~boursier();

private slots:

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::boursier *ui;
};

#endif // BOURSIER_H
