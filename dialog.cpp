#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QDebug>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::information(this,"MONISHA 212218104112","THIS IS AN INFORMATION");
}

void Dialog::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"MONISHA","Do you like icecream",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No)
    {
        QMessageBox::StandardButton reply=QMessageBox::information(this,"MONISHA","Doesn't favourite for all");
        QApplication::quit();
    }
    else
    {
        QMessageBox::StandardButton reply=QMessageBox::information(this,"MONISHA","Icream is favourite for all");
       qDebug() << "yes,icream is favourite for all";
   }
}

void Dialog::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"Custom message","This is an Custom Message",
                                                            QMessageBox::Yes | QMessageBox::YesToAll | QMessageBox::No | QMessageBox::NoToAll );
    if(reply == QMessageBox::Yes)
    {
        qDebug() << "Nothing is Displayed.";
        QApplication::quit();
    }
    else if(reply == QMessageBox::YesToAll)
    {
        QMessageBox::StandardButton reply=QMessageBox::warning(this,"Display message","Display the message with Warning as Yes to all.");
   }
    else if(reply == QMessageBox::No)
    {
        QMessageBox::StandardButton reply=QMessageBox::critical(this,"Display message","No message displayed");
}
    else
    {
        QMessageBox::StandardButton reply=QMessageBox::warning(this,"No Display message","Don't Display the message with Warning as Yes to all.");
    }

}

void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::warning(this,"Critical Message","This is an Warning Message");
}
