#include "createaccount.h"
#include "ui_createaccount.h"
#include "turnitout.h"
#include <QMessageBox>
#include <QFile>
createaccount::createaccount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createaccount)
{
    ui->setupUi(this);
}

createaccount::~createaccount()
{
    delete ui;
}

bool createaccount::checkEmailAndPassword(QString email,QString password)
{
    int i=0,j=0;
    QFile e("emailssss.txt");
    if (e.open(QIODevice::ReadOnly ))
    {
       QTextStream in(&e);
       while (!in.atEnd())
       {
          QString tempemail = in.readLine();
           if(tempemail!=email)
             i++;
        }
    }
    e.close();
       QFile p("passwordssss.txt");
       if (p.open(QIODevice::ReadOnly ))
       {
          QTextStream out(&p);
          while (!out.atEnd())
          {
             QString temppassword = out.readLine();
              if(temppassword!=password)
                j++;
           }
       }
       p.close();
       if(i==j)
           return true;
       else
           return false;

}


bool createaccount::checkEmailUsed(QString email){
    bool emailpresent=false;
    QFile e("emailssss.txt");
    if (e.open(QIODevice::ReadOnly ))
    {
       QTextStream in(&e);
       while (!in.atEnd())
       {
          QString tempemail = in.readLine();
           if(tempemail==email)
               emailpresent=true;

        }
       if(emailpresent==true)
       {
           return true;
       }
       else return false;
    }
    e.close();


}
bool createaccount::emailValid(QString email){
    bool atpresent=false;
    bool dotpresent=false;
    for(int i=0;i<email.length();i++)
    {
        if(email.at(i)=='@')
            atpresent=true;
        if(email.at(i)=='.')
            dotpresent=true;
    }
     if(dotpresent==true&&atpresent==true)
         return true;
     else
         return false;
}

bool createaccount::passwordValid(QString password){
     if(password.length()>=8)
         return true;
}

 void createaccount::on_creationButton_clicked()
{
   QString password = ui->password->text();
       QString email = ui->email->text();
       if(emailValid(email)==false)
       {
        QMessageBox::information(this, "Error!", "Invalid email address.");
       }
       if(passwordValid(password)==false)
             QMessageBox::information(this, "Error!", "Password must be atleast 8 characters.");
       if(ui->password->text()!=ui->password_2->text())
             QMessageBox::information(this, "Error!", "Passwords do not match.");
       if(checkEmailUsed(email)==true)
              QMessageBox::information(this, "Error!", "Email already used.");
       if((emailValid(email)==true)&&(passwordValid(password)==true)&&(ui->password->text()==ui->password_2->text())&&(checkEmailUsed(email)==false))
       {
             QFile p("passwordssss.txt");
             if (p.open( QIODevice::Text | QIODevice::Append ))
             {
             QTextStream outt(&p);
                outt << password << Qt::endl;
               }
                p.close();
             QFile e("emailssss.txt");
             if (e.open( QIODevice::Text | QIODevice::Append ))
             {
             QTextStream in(&e);
               in << email << Qt::endl;
             }
                 e.close();
       ///////
                 QMessageBox::information(this, "Success", "Account created successfully.");
                 this->close();
                 TurnItOut* home;
                 home=new TurnItOut();
                 home->show();
                 this->close();
       }



}



void createaccount::on_home_clicked()
{
    TurnItOut* home;
   home=new TurnItOut();
   home->show();
   this->close();
}



