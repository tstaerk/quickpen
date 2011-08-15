#include "mainwindow.h"
#include "moreform.h"
#include "ui_mainwindow.h"
#include "drawscene.h"
#include <QDebug>
#include <QFile>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawscene* ds=new drawscene();
    ui->graphicsView->setScene(ds);
    page=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::setpencolor(QColor color)
{
    qDebug()<<"MainWindow::setpencolor";
    ui->graphicsView->scene()->setPalette(color);
    ((drawscene*)ui->graphicsView->scene())->setpencolor(color);
}

void MainWindow::on_actionSave_triggered()
{
    QImage* image=new QImage(QSize((int)ui->graphicsView->scene()->width(),(int)ui->graphicsView->scene()->height()),QImage::Format_RGB32);
    image->fill(1);
    QPainter* painter=new QPainter(image);
    ui->graphicsView->scene()->render(painter);


    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image->save(&buffer, "PNG");
    QString filename=QString("/tmp/quickpen-").append(QString::number(page).append(QString(".png")));
    QFile* file1=new QFile(filename);
    file1->open(QIODevice::WriteOnly);
    image->save(file1, "PNG");
}

void MainWindow::on_nextbutton_clicked()
{
    on_actionSave_triggered();
    page++;
    ui->graphicsView->scene()->clear();
    QImage image=QImage(QSize((int)ui->graphicsView->scene()->width(),(int)ui->graphicsView->scene()->height()),QImage::Format_RGB32);
    image.fill(1);
    QString filename=QString("/tmp/quickpen-").append(QString::number(page).append(QString(".png")));
    QFile* file1=new QFile(filename);
    file1->open(QIODevice::ReadOnly);
    image.load(file1, "PNG");
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_prevbutton_clicked()
{
    on_actionSave_triggered();
    page--;
    QImage image=QImage(QSize((int)ui->graphicsView->scene()->width(),(int)ui->graphicsView->scene()->height()),QImage::Format_RGB32);
    image.fill(1);
    QString filename=QString("/tmp/quickpen-").append(QString::number(page).append(QString(".png")));
    QFile* file1=new QFile(filename);
    file1->open(QIODevice::ReadOnly);
    image.load(file1, "PNG");
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_morebutton_clicked()
{
    MoreForm* mf=new MoreForm(this);
    ui->gridLayout->addWidget(mf);
}
