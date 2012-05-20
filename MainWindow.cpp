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

    // Filling info
    ui->word->setText(QString::number(WORD) + " bit");
    ui->memoryCapacity->setText(QString::number(MEMORY_CAPACITY) + " bit");
    ui->wordsInMemory->setText(QString::number(WORDS_IN_MEMORY));
    ui->cacheCapacity->setText(QString::number(ENTRIES_IN_CACHE * BLOCK_LENGTH) + " bit");
    ui->wordsInCache->setText(QString::number(ENTRIES_IN_CACHE * WORDS_IN_BLOCK));

    refreshCacheDisplay();
    connect(ui->readButton, SIGNAL(clicked()), this, SLOT(read()));
    connect(ui->writeButton, SIGNAL(clicked()), this, SLOT(write()));

    // Connecting actions
    connect(ui->actionRandomize, SIGNAL(triggered()), this, SLOT(randomizeMemory()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(openAboutDialog()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshCacheDisplay()
{
   // Entry 0
    ui->tag_0->setText(QString::number(cache.getTag(0)));
    ui->data_0_0->setText(getString(cache.getEntryData(0, 0)));
    ui->data_0_1->setText(getString(cache.getEntryData(0, 1)));
    ui->data_0_2->setText(getString(cache.getEntryData(0, 2)));
    ui->data_0_3->setText(getString(cache.getEntryData(0, 3)));
    ui->age_0->setText(QString::number(cache.getAge(0)));

    // Entry 1
    ui->tag_1->setText(QString::number(cache.getTag(1)));
    ui->data_1_0->setText(getString(cache.getEntryData(1, 0)));
    ui->data_1_1->setText(getString(cache.getEntryData(1, 1)));
    ui->data_1_2->setText(getString(cache.getEntryData(1, 2)));
    ui->data_1_3->setText(getString(cache.getEntryData(1, 3)));
    ui->age_1->setText(QString::number(cache.getAge(1)));

    // Entry 2
    ui->tag_2->setText(QString::number(cache.getTag(2)));
    ui->data_2_0->setText(getString(cache.getEntryData(2, 0)));
    ui->data_2_1->setText(getString(cache.getEntryData(2, 1)));
    ui->data_2_2->setText(getString(cache.getEntryData(2, 2)));
    ui->data_2_3->setText(getString(cache.getEntryData(2, 3)));
    ui->age_2->setText(QString::number(cache.getAge(2)));

    // Entry 3
    ui->tag_3->setText(QString::number(cache.getTag(3)));
    ui->data_3_0->setText(getString(cache.getEntryData(3, 0)));
    ui->data_3_1->setText(getString(cache.getEntryData(3, 1)));
    ui->data_3_2->setText(getString(cache.getEntryData(3, 2)));
    ui->data_3_3->setText(getString(cache.getEntryData(3, 3)));
    ui->age_3->setText(QString::number(cache.getAge(3)));

    // Entry 4
    ui->tag_4->setText(QString::number(cache.getTag(4)));
    ui->data_4_0->setText(getString(cache.getEntryData(4, 0)));
    ui->data_4_1->setText(getString(cache.getEntryData(4, 1)));
    ui->data_4_2->setText(getString(cache.getEntryData(4, 2)));
    ui->data_4_3->setText(getString(cache.getEntryData(4, 3)));
    ui->age_4->setText(QString::number(cache.getAge(4)));

    // Entry 5
    ui->tag_5->setText(QString::number(cache.getTag(5)));
    ui->data_5_0->setText(getString(cache.getEntryData(5, 0)));
    ui->data_5_1->setText(getString(cache.getEntryData(5, 1)));
    ui->data_5_2->setText(getString(cache.getEntryData(5, 2)));
    ui->data_5_3->setText(getString(cache.getEntryData(5, 3)));
    ui->age_5->setText(QString::number(cache.getAge(5)));

    // Entry 6
    ui->tag_6->setText(QString::number(cache.getTag(6)));
    ui->data_6_0->setText(getString(cache.getEntryData(6, 0)));
    ui->data_6_1->setText(getString(cache.getEntryData(6, 1)));
    ui->data_6_2->setText(getString(cache.getEntryData(6, 2)));
    ui->data_6_3->setText(getString(cache.getEntryData(6, 3)));
    ui->age_6->setText(QString::number(cache.getAge(6)));

    // Entry 7
    ui->tag_7->setText(QString::number(cache.getTag(7)));
    ui->data_7_0->setText(getString(cache.getEntryData(7, 0)));
    ui->data_7_1->setText(getString(cache.getEntryData(7, 1)));
    ui->data_7_2->setText(getString(cache.getEntryData(7, 2)));
    ui->data_7_3->setText(getString(cache.getEntryData(7, 3)));
    ui->age_7->setText(QString::number(cache.getAge(7)));
}

void MainWindow::read()
{
    bool converted;
    unsigned int address = ui->readAddress->text().toInt(&converted, 10);
    if (converted)
    {
        bool hit;
        QString output = getString(cache.read(address, hit));
        hit ? print(output + " (cache hit)") : print(output + " (cache miss)");
        refreshCacheDisplay();
    }
    else
    {
        print("Wrong address!");
    }
}

void MainWindow::write()
{
    bool converted;
    unsigned int address = ui->writeAddress->text().toInt(&converted, 10);
    if (converted)
    {
        int integer = ui->writeInt->text().toInt(&converted, 10);
        if (converted)
        {
            bool hit;
            cache.write(bitset<WORD>(integer), address, hit);
            hit ? print("Cache hit.") : print("Cache miss.");
            refreshCacheDisplay();
        }
        else
        {
            print("Wrong number!");
        }
    }
    else
    {
        print("Wrong address!");
    }
}

void MainWindow::randomizeMemory()
{
    cache.randomizeMemory();
    refreshCacheDisplay();
}

void MainWindow::openAboutDialog()
{
    aboutDialog = new AboutDialog(this);
    aboutDialog->show();
}

void MainWindow::print(const QString &text)
{
    ui->console->appendPlainText(text);
}

QString MainWindow::getString(const bitset<WORD> &word)
{
    QString output;
    for (int bit=word.size()-1; bit>=0; bit--)
    {
        word[bit] ? output.append("1") : output.append("0");
    }
    return output;
}
