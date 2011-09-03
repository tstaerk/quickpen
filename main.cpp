#include <QDebug>
#include <QtGui/QApplication>
#include <QLocale>
#include <QTextCodec>
#include <QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    qDebug() << "Your language (\"locale\") is: " << QLocale::system().name();
    translator.load(QString("quickpen_")+QLocale::system().name());
    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    return a.exec();
}
