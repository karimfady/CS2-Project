#ifndef TURNITOUT_H
#define TURNITOUT_H
#include <QMainWindow>
#include "createaccount.h"
#include "plagiarismpage.h"


QT_BEGIN_NAMESPACE
namespace Ui { class TurnItOut; }
QT_END_NAMESPACE

class TurnItOut : public QMainWindow
{
    Q_OBJECT

public:
    TurnItOut(QWidget *parent = nullptr);
    ~TurnItOut();


private slots:
    void on_createaccount_clicked();

   void on_login_clicked();

   bool checkEmailAndPassword(QString ,QString );



private:
    Ui::TurnItOut *ui;
    plagiarismpage* plg;
    createaccount* changescreen;

};
#endif // TURNITOUT_H
