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
    parent->setpencolor(QColor("red"));
    this->deleteLater();
}

void MoreForm::on_black_clicked()
{
    parent->setpencolor(QColor("black"));
    this->deleteLater();
}

void MoreForm::on_yellow_clicked()
{
    parent->setpencolor(QColor("yellow"));
    this->deleteLater();
}

void MoreForm::on_gray_clicked()
{
    parent->setpencolor(QColor("gray"));
    this->deleteLater();
}

void MoreForm::on_green_clicked()
{
    parent->setpencolor(QColor("green"));
    this->deleteLater();
}

void MoreForm::on_blue_clicked()
{
    parent->setpencolor(QColor("blue"));
    this->deleteLater();
}

void MoreForm::on_white_clicked()
{
    parent->setpencolor(QColor("white"));
    this->deleteLater();
}

void MoreForm::on_purple_clicked()
{
    parent->setpencolor(QColor("purple"));
    this->deleteLater();
}

void MoreForm::on_turquoise_clicked()
{
    parent->setpencolor(QColor("turquoise"));
    this->deleteLater();
}
