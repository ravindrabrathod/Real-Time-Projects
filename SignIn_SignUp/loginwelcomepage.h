#ifndef LOGINWELCOMEPAGE_H   // not included before
#define LOGINWELCOMEPAGE_H   // then define it now
#include <QDialog>  // used for popup windows

// class for the ui
namespace Ui {
    class loginwelcomepage;  // Forward declare
}

// Create a new class called loginwelcomepage
class loginwelcomepage : public QDialog
{
    Q_OBJECT  // it is macros for using signals and slots in Qt
public:

    // Constructor
    explicit loginwelcomepage(QWidget *parent = nullptr);

    // Destructor
    ~loginwelcomepage();

private:

    Ui::loginwelcomepage *ui;
};

#endif// End

