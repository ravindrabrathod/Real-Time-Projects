#include "sighin_up.h"
#include "ui_sighin_up.h"
#include"ui_sighinpage.h"
sighin_up::sighin_up(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sighin_up)
{
    ui->setupUi(this);
}

sighin_up::~sighin_up()
{
    delete ui;
}


void sighin_up::on_pushButton_sighup_clicked()
{
    obj=new sighuppage(this); //call signup page
    obj->show();  //show signup page
}


void sighin_up::on_pushButton_sighin_clicked()
{
    in=new sighinpage(this); //call sign in page
    in->show(); // show the signin page

}

