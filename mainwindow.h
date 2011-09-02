#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MoreForm;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int page;
    void setpencolor(QColor color);
    void deletemoreform();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    MoreForm* mf;
    QColor pencolor;

private slots:
    void saveactualpage();
    void loadpage(int page);
    void on_nextbutton_clicked();
    void on_prevbutton_clicked();
    void on_morebutton_clicked();
};

#endif // MAINWINDOW_H
