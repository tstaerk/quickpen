#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int page;
    void setpencolor(QColor color);
    void setbuttonsactive();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QColor pencolor;

private slots:
    void on_nextbutton_clicked();
    void on_actionSave_triggered();
    void on_prevbutton_clicked();
    void on_morebutton_clicked();
};

#endif // MAINWINDOW_H
