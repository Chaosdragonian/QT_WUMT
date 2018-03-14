#-------------------------------------------------
#
# Project created by QtCreator 2018-02-23T16:07:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = basic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

TRANSLATIONS    = lang/cs_cs.ts \
                  lang/da_da.ts \
                  lang/de_de.ts \
                  lang/de_ch.ts \
                  lang/en_gb.ts \
                  lang/en_us.ts


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    checkupdate.cpp

HEADERS += \
        mainwindow.h \
    wuapi.h \
    wuerror.h \
    checkupdate.h

FORMS += \
        mainwindow.ui

win32: LIBS += -lwuguid

win32: LIBS += -latls
