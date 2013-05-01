#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../core/stdafx.h"
#include "../core/Cache.h"
#include <QMainWindow>
#include "AboutDialog.h"

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
