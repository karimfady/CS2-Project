#ifndef PLAGIARISMPAGE_H
#define PLAGIARISMPAGE_H

#include <QMainWindow>
#include "COR.h"
namespace Ui {
class plagiarismpage;
}

class plagiarismpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit plagiarismpage(QWidget *parent = nullptr);
    ~plagiarismpage();
     int i=0;
      QStringList f;
COR c;
private slots:

    void on_home_clicked();

    void on_plafiarizedfrombutton_clicked();

    void on_plagiarizedfilebutton_clicked();

    void on_checkPlagiarism_clicked();


private:
    Ui::plagiarismpage *ui;
};

#endif // PLAGIARISMPAGE_H
