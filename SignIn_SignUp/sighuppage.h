#ifndef SIGHUPPAGE_H
#define SIGHUPPAGE_H
#include <QDialog>           //used to create popup windows or secondary windows.
#include <QSqlDatabase>  // used to code in this header

namespace Ui {
class sighuppage;
}

class sighuppage : public QDialog
{
    Q_OBJECT

public:
    explicit sighuppage(QWidget *parent = nullptr);
    ~sighuppage();

private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::sighuppage *ui;
    QSqlDatabase db;  //database connection object
};

#endif // SIGHUPPAGE_H
