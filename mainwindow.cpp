#include "mainwindow.h"
#include "moreform.h"
#include "ui_mainwindow.h"
#include "ui_moreform.h"
#include "drawscene.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawscene* ds=new drawscene();
    ui->graphicsView->setScene(ds);
    mf=0;
    loadpage(page=1);
}

MainWindow::~MainWindow()
{
    saveactualpage();
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::setpencolor(QColor color)
{
    ((drawscene*)ui->graphicsView->scene())->setpencolor(color);
}

void MainWindow::deletemoreform()
{
    mf->deleteLater();
    ui->graphicsView->show();
    mf=0;
    ui->morebutton->setText(tr("More"));
}

void MainWindow::clearactualpage()
{
    ui->graphicsView->scene()->clear();
}

void MainWindow::saveactualpage(QString filename)
{
    QImage* image=new QImage(QSize((int)ui->graphicsView->scene()->width(),(int)ui->graphicsView->scene()->height()),QImage::Format_RGB32);
    QPainter* painter=new QPainter(image);
    ui->graphicsView->scene()->render(painter);

    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image->save(&buffer, "PNG");
    if (filename==QString()) filename=QString("/tmp/quickpen-").append(QString::number(page).append(QString(".png")));
    QFile* file1=new QFile(filename);
    file1->open(QIODevice::WriteOnly);
    image->save(file1, "PNG");
}

void MainWindow::loadpage(int page)
{
    ui->graphicsView->scene()->clear();
    QString filename=QString("/tmp/quickpen-").append(QString::number(page).append(QString(".png")));
    QFile* file1=new QFile(filename);
    if (file1->open(QIODevice::ReadOnly))
    {
        QImage image=QImage(QSize((int)ui->graphicsView->scene()->width(),(int)ui->graphicsView->scene()->height()),QImage::Format_RGB32);
        image.load(file1, "PNG");
        ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(image));
    }
}

void MainWindow::on_nextbutton_clicked()
{
    saveactualpage();
    loadpage(++page);
}

void MainWindow::on_prevbutton_clicked()
{
    saveactualpage();
    loadpage(--page);
}

void MainWindow::on_morebutton_clicked()
{
    if (mf)
    {
        deletemoreform();
    }
    else
    {
        mf=new MoreForm(this);
        ui->morebutton->setText(tr("Less"));
        ui->graphicsView->hide();
        ui->gridLayout->addWidget(mf,1,0,1,3);
    }
}

