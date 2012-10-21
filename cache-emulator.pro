QT       += core gui

TARGET = cache-emulator
TEMPLATE = app

win32:RC_FILE += app.rc

OTHER_FILES += \
    README.md

HEADERS += \
    application/stdafx.h \
    application/Memory.h \
    application/MainWindow.h \
    application/CacheEntry.h \
    application/Cache.h \
    application/AboutDialog.h

SOURCES += \
    application/stdafx.cpp \
    application/Memory.cpp \
    application/MainWindow.cpp \
    application/main.cpp \
    application/CacheEntry.cpp \
    application/Cache.cpp \
    application/AboutDialog.cpp

FORMS += \
    application/MainWindow.ui \
    application/AboutDialog.ui
