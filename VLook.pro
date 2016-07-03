QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLook
TEMPLATE = app
QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic
INCLUDEPATH += Audio



SOURCES += main.cpp\
        vlook.cpp \
    vlookd.cpp \
    Audio/AudioALSA.cpp

HEADERS  += vlook.h \
    main.h \
    vlookd.h \
    Audio/Audio.h \
    Audio/AudioALSA.h

FORMS    += vlook.ui

LIBS += -L/usr/lib/x86_64-linux-gnu/ -lasound

DISTFILES +=

RESOURCES += \
    res/vlook_logo.qrc
