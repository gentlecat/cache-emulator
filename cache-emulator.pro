#-------------------------------------------------
#
# Project created by QtCreator 2012-05-06T18:59:16
#
#-------------------------------------------------

QT       += core gui

TARGET = cache-emulator
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    stdafx.cpp \
    Cache.cpp \
    CacheEntry.cpp \
    Memory.cpp

HEADERS  += MainWindow.h \
    stdafx.h \
    Cache.h \
    CacheEntry.h \
    Memory.h

FORMS    += MainWindow.ui

win32:RC_FILE += app.rc

OTHER_FILES += \
    README.md
