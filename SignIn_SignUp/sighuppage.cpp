#include "sighuppage.h" //signup page
#include "ui_sighuppage.h" //used for use buttons and boxes automatic compiler taken
#include<QSqlDatabase>//for database connection
#include<QSqlQuery>//for handle SQL commands like insert ,select
#include<QSqlError>//for error handling of the SQL commands or error in database connection
#include<QRegularExpression>//to find a particular word form a sentence
#include<QMessageBox>//to give the information
#include<QDebug>//to print the msg
#include<QString>//to manage the text in the code
#include<QDate>//to display date,year,month
sighuppage::sighuppage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sighuppage)//new memory create for the sigup page
{

    ui->setupUi(this);
    // Hide password and confirm password fields
//      ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
//      ui->lineEdit_conformation->setEchoMode(QLineEdit::Password);

    ui->dateEdit->setMaximumDate(QDate::currentDate());// it will not allow future date
    ui->lineEdit_mobile->setInputMask("9999999999");


    // Database connection using class member
    db = QSqlDatabase::addDatabase("QSQLITE");// We are going to use a SQLite type of database,
    db.setDatabaseName("C:/Users/Asus/OneDrive/Desktop/DB/sec.db");// computer path



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
    QSqlQuery table;  // creating table for db
       table.exec("CREATE TABLE IF NOT EXISTS users("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "name TEXT UNIQUE,"
                  "password TEXT,"
                  "dob TEXT,"
                  "email TEXT,"
                  "mobileno TEXT,"
                  "gender TEXT,"
                  "address TEXT,"
                  "country TEXT)");



}

sighuppage::~sighuppage()
{
    delete ui; //free the memory
}



void sighuppage::on_pushButton_submit_clicked()
{
    QString username=ui->lineEdit_username->text().trimmed();//These lines take the text you typed into each box (username, password, etc.) and
    //saves them into temporary variables. .trimmed() removes any extra spaces at the start or end.
    QString password=ui->lineEdit_password->text();
    QString conform_password=ui->lineEdit_conformation->text();
    QString gender;
    QDate DOB=ui->dateEdit->date();
    QString Email=ui->lineEdit_email->text();
    QString mobile=ui->lineEdit_mobile->text().trimmed();
    QString address=ui->lineEdit_address->text().trimmed();
    QString country=ui->comboBox_country->currentText();

    //for username
    if(username.isEmpty()||username.length()<6||username.length()>16)
    {
        QMessageBox::warning(this,"Validation Error","username must be between 6-16 characters.");
        return;
    }
    // Check if username already exists
                QSqlQuery checkQuery;
                checkQuery.prepare("SELECT COUNT(*) FROM users WHERE name = :name");
                checkQuery.bindValue(":name", username);
                if (checkQuery.exec())
                {
                    if (checkQuery.next())
                    {
                        int count = checkQuery.value(0).toInt();
                        if (count > 0)
                        {
                            QMessageBox::warning(this, "Validation Error", "Username already exists. Please choose another.");
                            return;
                        }
                    }
                }

    //for password
    QRegularExpression passwordRegex("^(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%&*^])[A-Za-z\\d!@#$%^&*]{7,}$");
    //^ is for starting expr $ is for ending the expr
    //?=.picking a num or char after picking only it will move forward
    // (\\d) is the shortcut of taking 0-9 numbers
    //from1,2,3 condition it checking at least 7 digits are pressed.then it will go forward


    if(!passwordRegex.match(password).hasMatch()){ //checks if the password does not match the pattern.
        QMessageBox::warning(this,"Validation Error","Password must be atleast 7 characters and include:\n" "uppercase letter:\n" "number:\n" "special character");
        return;
    }
    if(password!=conform_password)
    {
       QMessageBox::warning(this,"Validation Error","passwords did not match.");
       return;
    }
        QDate defaultDate = QDate(2000, 1, 1); // Common default date
        QDate minValidDate = QDate(1900, 1, 1);
        QDate today = QDate::currentDate(); //today’s date from the system

        // If date is the default or very old, consider it as not selected
        if(DOB == defaultDate || DOB < minValidDate) {
            QMessageBox::warning(this, "Validation Error", "Please select your date of birth!");
            return;
        }

    int age=DOB.daysTo(today)/365; // calculating the age by counting days
    if(age<18)
    {
        QMessageBox::warning(this,"Validation Error","Age should be above 18");
        return;
    }


    //for email
    QRegularExpression EmailRegex("^[A-Za-z0-9]+@(gmail\\.com||yahoo\\.com)$");//emailregex use for we can use any name insted of that
    if(!EmailRegex.match(Email).hasMatch())
    {
        QMessageBox::warning(this,"Validation Error","Email must be either @gmail.com or @yahoomail.com");
        return;
    }
    //for mobile number
    QRegularExpression mobileRegex("^[6-9][0-9]{9}$");//qregularexpression used for the validations here
    if(!mobileRegex.match(mobile).hasMatch())
    {
        QMessageBox::warning(this,"Validation Error","Mobile number must be 10 digits and starts with 6-9.");
        return;
    }

    //gender selection
    if(ui->radioButton_male->isChecked()){
        gender="male";

    }
    else if(ui->radioButton_female->isChecked()){
        gender="Female";

    }
    else if(ui->radioButton_other->isChecked()){
        gender="other";

    }
    if(gender==""){
        QMessageBox::warning(this,"Validation Error","Please select gender");
        return;
    }

    //for address
    if(address.isEmpty())
    {
        QMessageBox::warning(this,"Validation Error","Address cannot be empty");
        return;
    }
    //country
    if(country=="---")
    {
        QMessageBox::warning(this,"Validation Error","Please provide country");
        return;
    }


    QSqlQuery table;
    table.prepare("INSERT INTO users(name,password,dob,gender,email,mobileno,address,country)"
                  "VALUES(:name,:password,:dob,:gender,:email,:mobileno,:address,:country)");
    // its a sql template to store the data
    // This is where you STORE each field:
    table.bindValue(":name",username);        // ← Stores username
    table.bindValue(":password",password);    // ← Stores password
    table.bindValue(":dob", DOB.toString("dd-MM-yyyy")); // ← Stores date of birth
    table.bindValue(":gender",gender);
    table.bindValue(":email",Email);          // ← Stores email
    table.bindValue(":mobileno",mobile);      // ← Stores mobile number
    table.bindValue(":address",address);      // ← Stores address
    table.bindValue(":country",country);      // ← Stores country

    // This line actually SAVES to database:
    if(!table.exec()) {
        // Error handling
    } else {
        // Success message - data is now in database!
        QMessageBox::information(this,"Success","Registration completed successfully");
        this->close();
    }

}

