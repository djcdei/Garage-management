QT       += core gui
QT += network
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admindialog.cpp \
    advertisement.cpp \
    camera.cpp \
    carspacedialog.cpp \
    keyborad.cpp \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    serial.cpp \
    sqlite3.cpp

HEADERS += \
    admindialog.h \
    advertisement.h \
    camera.h \
    carspacedialog.h \
    keyborad.h \
    mainwindow.h \
    mybutton.h \
    serial.h \
    sqlite3.h

FORMS += \
    admindialog.ui \
    carspacedialog.ui \
    keyborad.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
