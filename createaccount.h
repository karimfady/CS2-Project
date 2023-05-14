
#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H


#include <QMainWindow>

namespace Ui {
class createaccount;
}

class createaccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit createaccount(QWidget *parent = nullptr);
    ~createaccount();

private slots:

    bool checkEmailAndPassword(QString,QString);

    bool emailValid(QString);

    bool passwordValid(QString);

    bool checkEmailUsed(QString email);

    void on_creationButton_clicked();

    void on_home_clicked();

   \

private:
    Ui::createaccount *ui;

};

#endif // CREATEACCOUNT_H
