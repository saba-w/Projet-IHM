#ifndef HAB_H
#define HAB_H

#include <QDialog>

namespace Ui {
class hab;
}

class hab : public QDialog
{
    Q_OBJECT

public:
    explicit hab(QWidget *parent = nullptr);
    ~hab();

private slots:

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::hab *ui;
};

#endif // HAB_H
