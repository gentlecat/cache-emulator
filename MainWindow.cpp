#include "stdafx.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Memory.h"
#include "Cache.h"

using std::bitset;

Memory ram;
Cache cache(ram);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Tests:
    connect(ui->actionQuit, SIGNAL(changed()), this, SLOT(refreshCacheDisplay()));
    bool hit;
    bitset<32> set = cache.read(1,hit);
    QString str = QString::fromStdString(set.to_string());
    ui->data_0_0->setText(str);
    ui->data_0_1->setText(str);
    ui->data_0_2->setText(str);
    ui->data_0_3->setText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshCacheDisplay()
{
    ui->data_0_0->setText("IT WORKS!");
}
