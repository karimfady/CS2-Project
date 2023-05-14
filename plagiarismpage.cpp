#include "plagiarismpage.h"
#include "ui_plagiarismpage.h"
#include "turnitout.h"

#include <QFileDialog>
#include <QMessageBox>
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




void plagiarismpage::on_choosefromcomputer_clicked()
{
    QString file1=QFileDialog::getOpenFileName(this,tr("This Computer")," ","All files (*.*);;Text File (*.txt) ");
   QMessageBox::information(this,tr("File Name"),file1);
}



void plagiarismpage::on_home_clicked()
{
    TurnItOut* home;
   home=new TurnItOut();
   home->show();
   this->close();
}

