QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLook
TEMPLATE = app


SOURCES += main.cpp\
        vlook.cpp \
    Audio.cpp \
    vlookd.cpp

HEADERS  += vlook.h \
    Audio.h \
    main.h \
    vlookd.h

FORMS    += vlook.ui

LIBS += -L/usr/lib/x86_64-linux-gnu/ -lasound
