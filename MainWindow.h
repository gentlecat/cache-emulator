#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stdafx.h"
#include <QMainWindow>
#include "Cache.h"

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
    void read();
    void write();

private:
    Ui::MainWindow *ui;
    void print(const QString &text);
    QString getString(const bitset<WORD> &word);
};

#endif // MAINWINDOW_H
