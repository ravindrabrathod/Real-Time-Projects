#include "mainwindow.h"        // Includes the MainWindow class
#include "ui_mainwindow.h"     // Includes the user interface (UI) setup

// This is the constructor. It runs when the window is created.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)   // dynamic memory reates for UI object
{
    ui->setupUi(this);         // Sets up the user interface (connects buttons, etc.)
}

// This is the destructor.
MainWindow::~MainWindow()
{
    delete ui;                 // Cleans up memory used by the UI
}



void MainWindow::on_pushButton_0_clicked()
{
    QString temp = ui->lineEdit->text();     // Get current text from input box
    ui->lineEdit->setText(temp+"0");         // Add "0" to the text
}

void MainWindow::on_pushButton_1_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"1");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"2");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"3");
}

void MainWindow::on_pushButton_4_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"4");
}

void MainWindow::on_pushButton_5_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"5");
}

void MainWindow::on_pushButton_6_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"6");
}

void MainWindow::on_pushButton_7_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"7");
}

void MainWindow::on_pushButton_8_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"8");
}

void MainWindow::on_pushButton_9_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"9");
}

void MainWindow::on_pushButton_dot_clicked()
{
    QString temp=ui->lineEdit->text();
    ui->lineEdit->setText(temp+".");  // Adds a decimal point
}

void MainWindow::on_pushButton_plus_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp +"+");
}

void MainWindow::on_pushButton_subtract_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp +"-");
}

void MainWindow::on_pushButton_multi_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp +"*");
}

void MainWindow::on_pushButton_divide_clicked()
{
    QString temp=ui->lineEdit->text();
    ui->lineEdit->setText(temp+"/");
}

void MainWindow::on_pushButton_equalto_clicked() // calculate the answer
{
    QString problem = ui->lineEdit->text();         // Get the math expression from the input box
    problem.replace("%", "/100");                   // Change % into /100 to handle percentage

    // Add spaces so we can split the string easily
    problem.replace("+", " + ");
    problem.replace("-", " - ");
    problem.replace("*", " * ");
    problem.replace("/", " / ");

    // Break the string into parts (numbers and operators)
    QStringList parts = problem.split(" ", QString::SkipEmptyParts);

    // If the user entered nothing
    if (parts.isEmpty()) {
        ui->lineEdit->setText("0");
        return;
    }

    // Start calculating from the first number
    bool ok;
    double answer = parts[0].toDouble(&ok);         // Convert first part to number

    if (!ok) {
        ui->lineEdit->setText("Invalid input");     // Show error if the input is not a number
        return;
    }

    for (int i = 1; i < parts.size(); i += 2) {
        if (i + 1 >= parts.size())
            break;   // break if no number enter after the operator

        QString op = parts[i];                      // Get operator (+, -, *, /)
        double number = parts[i + 1].toDouble(&ok); // Get next number

        if (!ok) {
            ui->lineEdit->setText("Invalid input");
            return;
        }

        // Perform the calculation
        if (op == "+") {
            answer += number;
        } else if (op == "-") {
            answer -= number;
        } else if (op == "*") {
            answer *= number;
        } else if (op == "/") {
            if (number == 0) {   // Check for divide by zero
                ui->lineEdit->setText("Error: Division by zero");
                return;
            }
            answer /= number;
        }
    }


    ui->lineEdit->setText(QString::number(answer, 'g', 15)); // general notation for need decimal or not
}

void MainWindow::on_pushButton_modulus_clicked()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp+"%");  // Adds percentage symbol
}

void MainWindow::on_pushButton_back_clicked()
{
    QString temp = ui->lineEdit->text();
    temp.chop(1);  // Removes last character from the text
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit->setText("");  // Clears the input box
}
