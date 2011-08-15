#ifndef MOREFORM_H
#define MOREFORM_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
    class MoreForm;
    class MainWindow;
}

class MoreForm : public QWidget
{
    Q_OBJECT

public:
    explicit MoreForm(MainWindow *parent = 0);
    ~MoreForm();

private slots:
    void on_red_clicked();

    void on_black_clicked();

private:
    Ui::MoreForm *ui;
    MainWindow* parent;
};

#endif // MOREFORM_H
