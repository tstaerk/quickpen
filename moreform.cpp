#include "mainwindow.h"
#include "moreform.h"
#include "ui_moreform.h"
#include <QDebug>

MoreForm::MoreForm(MainWindow *parent1) :
    ui(new Ui::MoreForm)
{
    ui->setupUi(this);
    parent=parent1;
}

MoreForm::~MoreForm()
{
    delete ui;
}

void MoreForm::on_red_clicked()
{
    qDebug() << "on_red_clicked";
    parent->setpencolor(QColor("red"));
    this->deleteLater();
}

void MoreForm::on_black_clicked()
{
    parent->setpencolor(QColor("black"));
    this->deleteLater();

}
