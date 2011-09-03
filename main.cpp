#include <QDebug>
#include <QtGui/QApplication>
#include <QLocale>
#include <QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    qDebug() << "Your language (\"locale\") is: " << QLocale::system().name();
    translator.load(QString("quickpen_")+QLocale::system().name());
    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
