
#include "plagiarismpage.h"
#include "ui_plagiarismpage.h"
#include "turnitout.h"
#include "COR.h"
#include "PL.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidget>
#include <string>
#include <QString>
plagiarismpage::plagiarismpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plagiarismpage)
{
    ui->setupUi(this);
}

plagiarismpage::~plagiarismpage()
{
    delete ui;
}







void plagiarismpage::on_home_clicked()
{
    TurnItOut* home;
   home=new TurnItOut();
   home->show();
   this->close();
}


void plagiarismpage::on_plafiarizedfrombutton_clicked()
{
    f.append(QFileDialog::getOpenFileNames(this,tr("This Computer")," ","All files (*.*);;Text File (*.txt) "));
       QString item=f[i];
       ui->listWidget->addItem(item);

               i++;
}



void plagiarismpage::on_plagiarizedfilebutton_clicked()
{

    QString file1=QFileDialog::getOpenFileName(this,tr("This Computer")," ","All files (*.*);;Text File (*.txt) ");
    ui->lineEdit_2->setText(file1);
}

void plagiarismpage::on_checkPlagiarism_clicked()
{
   c.setNumOfFiles(i);
   for (int index = 0; index < f.size();index++) {
       QString filename = f[index];
       c.addFile(filename, index);

   }
   c.readFiles();
   PL pl1(c);
   double bpercentage = pl1.compareUsingBruteForce(ui->lineEdit_2->text());
   double rpercentage=pl1.compareUsingRabinKarp(ui->lineEdit_2->text());
   double percentage=(bpercentage+rpercentage)/2;

   QString percentageAsQstring = QString::number(percentage);
   QMessageBox::information(this, tr("File Name"), percentageAsQstring+"%");
}

