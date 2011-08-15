#ifndef MOREFORM_H
#define MOREFORM_H

#include <QWidget>

namespace Ui {
    class MoreForm;
}

class MoreForm : public QWidget
{
    Q_OBJECT

public:
    explicit MoreForm(QWidget *parent = 0);
    ~MoreForm();

private slots:
    void on_red_clicked();

private:
    Ui::MoreForm *ui;
};

#endif // MOREFORM_H
