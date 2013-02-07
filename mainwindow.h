#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    
private slots:
    void on_action_triggered();
    void openDbEditor();
private:
    Ui::MainWindow *ui;
    dataBase* db;
};

#endif // MAINWINDOW_H
