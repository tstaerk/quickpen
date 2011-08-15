#include "mainwindow.h"
#include "moreform.h"
#include "ui_moreform.h"
#include <QDebug>

MoreForm::MoreForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoreForm)
{
    ui->setupUi(this);
}

MoreForm::~MoreForm()
{
    delete ui;
}

void MoreForm::on_red_clicked()
{
    qDebug() << "on_red_clicked";
    ((MainWindow*) this->parent())->setpencolor(QColor("red"));
    this->deleteLater();
}
