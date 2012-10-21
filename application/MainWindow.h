#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stdafx.h"
#include <QMainWindow>
#include "AboutDialog.h"
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
    void randomizeMemory();
    void openAboutDialog();

private:
    Ui::MainWindow *ui;
    AboutDialog *aboutDialog;
    void print(const QString &text);
    QString getString(const bitset<WORD> &word);
};

#endif // MAINWINDOW_H
