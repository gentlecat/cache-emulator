#ifndef UI_MAINWINDOW_H_
#define UI_MAINWINDOW_H_

#include <QMainWindow>

#include "../core/stdafx.h"
#include "../core/Cache.h"
#include "AboutDialog.h"

using std::bitset;

namespace UI {
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
    void print(const QString &text);
    QString getString(const bitset<WORD> &word);

    UI::MainWindow *ui;
    AboutDialog *aboutDialog;
};

#endif // UI_MAINWINDOW_H_
