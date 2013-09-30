#ifndef UI_ABOUTDIALOG_H_
#define UI_ABOUTDIALOG_H_

#include <QDialog>

namespace UI {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();
    
private:
    UI::AboutDialog *ui;
};

#endif // UI_ABOUTDIALOG_H_
