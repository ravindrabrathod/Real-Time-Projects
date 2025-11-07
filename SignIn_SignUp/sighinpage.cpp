#include "sighinpage.h"         // for sign in page
#include "ui_sighinpage.h"      // automatic compiler give to use buttons ,textboxes,etc
#include <QDebug>               // display msg
#include <QMessageBox>          // show errors or information to user
#include <QSqlQuery>            // write and run SQL queries & managed like SELECT,INSERT
#include <QSqlDatabase>         // Helps us connect to and use a database


sighinpage::sighinpage(QWidget *parent) :
    QDialog(parent),// Call the parent class
    ui(new Ui::sighinpage) // Create a new UI object for this sighinpage window
{
    ui->setupUi(this);// Set up the user interface
    db = QSqlDatabase::addDatabase("QSQLITE"); //add data base
    db.setDatabaseName("C:/Users/Asus/OneDrive/Desktop/DB/sec.db");//path of data base



    if(!db.open()) //condition
    {
        QMessageBox::critical(this, "Database error",
                            "Cannot open database:");
        return;
    }
    else
    {
        qDebug() << "Database opened successfully!";
    }
}

sighinpage::~sighinpage()
{
    delete ui;
}

void sighinpage::on_pushButton_clicked() // when we clicked pushbutton
{
    QString username=ui->lineEdit_username1->text().trimmed();//it will remove extra spaces
    QString password=ui->lineEdit_password1->text();
    QSqlQuery table;
    table.prepare("SELECT * FROM users WHERE name = :name AND password = :password");
    // Prepare the SQL query with placeholders for username and password
    table.bindValue(":name", username);           // Bind username to query
    table.bindValue(":password", password);       // Bind password to query
    if(table.exec() && table.next()){ //it will check from db and the user info ,pass next

        loginwelcomepage *obj2;
        obj2=new loginwelcomepage(this); // go to new dialog box
        obj2->exec();  // go to new dialog box
        delete obj2;
    }
    else
    {
        // Show warning message if login fails
        QMessageBox::warning(this, "Login Failed", "Invalid username and password");
    }


}

