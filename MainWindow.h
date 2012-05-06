#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stdafx.h"
#include <QMainWindow>

using std::bitset;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void refreshCacheDisplay();

private:
    Ui::MainWindow *ui;
    QString getString(bitset<WORD>);
};

#endif // MAINWINDOW_H
