#ifndef PLAGIARISMPAGE_H
#define PLAGIARISMPAGE_H

#include <QMainWindow>

namespace Ui {
class plagiarismpage;
}

class plagiarismpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit plagiarismpage(QWidget *parent = nullptr);
    ~plagiarismpage();

private slots:


    void on_choosefromcomputer_clicked();


    void on_home_clicked();

private:
    Ui::plagiarismpage *ui;
};

#endif // PLAGIARISMPAGE_H
