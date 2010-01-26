#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawscene.h"
#include <QFile>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new drawscene());
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

void MainWindow::on_actionSave_triggered()
{
    const char *png="PNG";
    QImage* image=new QImage(QSize(400,400),QImage::Format_Mono);
    image->fill(1);
    QPainter* painter=new QPainter(image);
    ui->graphicsView->scene()->render(painter);


    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image->save(&buffer, "PNG");
    QFile* file1=new QFile("/tmp/test5.png");
    file1->open(QIODevice::WriteOnly);
    image->save(file1, "PNG");
}
