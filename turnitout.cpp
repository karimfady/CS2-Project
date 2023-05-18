#include "turnitout.h"
#include "ui_turnitout.h"
#include <QFile>
#include <QMessageBox>


TurnItOut::TurnItOut(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TurnItOut)
{
    ui->setupUi(this);
}

TurnItOut::~TurnItOut()
{
    delete ui;
}
bool TurnItOut::checkEmailAndPassword(QString email,QString password)
{
    QString tempemail=" ";
    QString temppassword=" ";
    int i=0,j=0;
    QFile e("emailssss.txt");
    if (e.open(QIODevice::ReadOnly ))
    {
       QTextStream in(&e);
       while (!in.atEnd()&&ui->email->text()!=tempemail)
       {
           tempemail = in.readLine();
             i++;
        }
    }
    e.close();
       QFile p("passwordssss.txt");
       if (p.open(QIODevice::ReadOnly ))
       {
          QTextStream out(&p);
          while (!out.atEnd()&&ui->email->text()!=tempemail)
          {
              temppassword = out.readLine();
                j++;
           }
       }
       p.close();
       if(i==j)
          {
           return true;
       }
       else
       {
           return false;
       }

}

void TurnItOut::on_createaccount_clicked()
{
changescreen=new createaccount();
changescreen->show();
this->close();
}


void TurnItOut::on_login_clicked()
{
   //if((checkEmailAndPassword(ui->email->text(),ui->password->text()))==true)
   //{
       plg=new plagiarismpage();
       plg->show();
       this->close();
   //}
   //else
    //QMessageBox::information(this, "Cannot login", "Incorrect login credentials.");*/
   // checkEmailAndPassword(ui->email->text(),ui->password->text());
}



