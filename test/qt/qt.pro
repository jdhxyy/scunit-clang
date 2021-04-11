TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    ../../scunit.c

INCLUDEPATH += ../../

HEADERS += \
    ../../scunit.h
