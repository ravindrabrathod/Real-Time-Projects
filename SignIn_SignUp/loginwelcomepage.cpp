#include "loginwelcomepage.h"
#include "ui_loginwelcomepage.h"

loginwelcomepage::loginwelcomepage(QWidget *parent) : //constructor
    QDialog(parent),  // This calls the parent class constructor (QDialog)
    ui(new Ui::loginwelcomepage)// This creates the UI for this page
{
    ui->setupUi(this);//set up
}

loginwelcomepage::~loginwelcomepage() //destructor
{
    delete ui;
}
