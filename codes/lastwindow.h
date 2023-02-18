#ifndef LASTWINDOW_H
#define LASTWINDOW_H

#include <QMainWindow>

namespace Ui {
class LastWindow;
}

class LastWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LastWindow(QWidget *parent = nullptr);
    ~LastWindow();

private slots:
    void on_icon1_clicked();

private:
    Ui::LastWindow *ui;
};

#endif // LASTWINDOW_H
