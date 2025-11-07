#ifndef SIGHIN_UP_H
#define SIGHIN_UP_H

#include <QMainWindow> //for manage mainwindow
#include "sighuppage.h"
#include"sighinpage.h"

QT_BEGIN_NAMESPACE // starting of class namespace
namespace Ui { class sighin_up; }
QT_END_NAMESPACE // end of class namespace

class sighin_up : public QMainWindow
{
    Q_OBJECT //it is a macro use to signal and slots

public:
    sighin_up(QWidget *parent = nullptr); //constructor
    ~sighin_up();  //destructor

private slots:

    void on_pushButton_sighup_clicked();


    void on_pushButton_sighin_clicked();

private:
    Ui::sighin_up *ui; //access for signin page
    sighuppage *obj; //pointer creates for signup page
    sighinpage *in; //pointer creates for signin page


};
#endif // SIGHIN_UP_H
