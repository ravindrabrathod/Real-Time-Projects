#ifndef SIGHINPAGE_H
#define SIGHINPAGE_H
#include<loginwelcomepage.h> //want to use the class or code written in the file named loginwelcomepage.h."

#include <QDialog> //used to create popup windows or secondary windows.
#include<QSqlDatabase> //connection with db
namespace Ui {
class sighinpage; //forward declaration
}

class sighinpage : public QDialog
{
    Q_OBJECT //it is a macros used for signals and slots

public:
    explicit sighinpage(QWidget *parent = nullptr);
    ~sighinpage();

private slots:


    void on_pushButton_clicked();

private:
    Ui::sighinpage *ui;
    QSqlDatabase db;


};

#endif // SIGHINPAGE_H
