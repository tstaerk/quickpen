#include "mainwindow.h"
#include "moreform.h"
#include "ui_moreform.h"
#include <QDebug>
#include <QFileDialog>

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
    parent->deletemoreform();
}

void MoreForm::on_black_clicked()
{
    parent->setpencolor(QColor("black"));
    parent->deletemoreform();
}

void MoreForm::on_yellow_clicked()
{
    parent->setpencolor(QColor("yellow"));
    parent->deletemoreform();
}

void MoreForm::on_gray_clicked()
{
    parent->setpencolor(QColor("gray"));
    parent->deletemoreform();
}

void MoreForm::on_green_clicked()
{
    parent->setpencolor(QColor("green"));
    parent->deletemoreform();
}

void MoreForm::on_blue_clicked()
{
    parent->setpencolor(QColor("blue"));
    parent->deletemoreform();
}

void MoreForm::on_white_clicked()
{
    parent->setpencolor(QColor("white"));
    parent->deletemoreform();
}

void MoreForm::on_purple_clicked()
{
    parent->setpencolor(QColor("purple"));
    parent->deletemoreform();
}

void MoreForm::on_turquoise_clicked()
{
    parent->setpencolor(QColor("turquoise"));
    parent->deletemoreform();
}

void MoreForm::on_savebutton_clicked()
{
    //TODO: What if the user cancels the dialog?
    parent->saveactualpage(QFileDialog::getSaveFileName(0));
}

void MoreForm::on_clearbutton_clicked()
{
    parent->clearactualpage();
    parent->deletemoreform();
}

void MoreForm::on_exitbutton_clicked()
{
    parent->deleteLater();
}
