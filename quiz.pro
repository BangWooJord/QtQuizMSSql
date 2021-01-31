QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mainwrap.cpp \
    regwindow.cpp \
    secwindow.cpp

HEADERS += \
    mainwindow.h \
    mainwrap.h \
    regwindow.h \
    secwindow.h

FORMS += \
    mainwindow.ui \
    mainwrap.ui \
    regwindow.ui \
    secwindow.ui

TRANSLATIONS += \
    quiz_uk_UA.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
