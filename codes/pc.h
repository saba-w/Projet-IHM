#ifndef PC_H
#define PC_H

#include <QDialog>

namespace Ui {
class pc;
}

class pc : public QDialog
{
    Q_OBJECT

public:
    explicit pc(QWidget *parent = nullptr);
    ~pc();

private slots:

    void on_mode_toggled(bool checked);

    void on_cal_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::pc *ui;
};

#endif // PC_H
