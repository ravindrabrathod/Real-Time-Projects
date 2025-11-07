QT       += core gui sql
#core- want to use basic features
#gui- make a user interface
#sql- work with databases in my app


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    loginwelcomepage.cpp \
    main.cpp \
    sighin_up.cpp \
    sighinpage.cpp \
    sighuppage.cpp

HEADERS += \
    loginwelcomepage.h \
    sighin_up.h \
    sighinpage.h \
    sighuppage.h

FORMS += \
    loginwelcomepage.ui \
    sighin_up.ui \
    sighinpage.ui \
    sighuppage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics.qrc
