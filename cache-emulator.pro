QT += core gui widgets

TARGET = cache-emulator
TEMPLATE = app

win32:RC_FILE += app.rc

OTHER_FILES += \
    README.md \
    LICENSE \
    app.rc

HEADERS += \
    core/stdafx.h \
    core/Memory.h \
    core/CacheEntry.h \
    core/Cache.h \
    ui/MainWindow.h \
    ui/AboutDialog.h

SOURCES += \
    core/main.cpp \
    core/stdafx.cpp \
    core/Cache.cpp \
    core/CacheEntry.cpp \
    core/main.cpp \
    core/Memory.cpp \
    ui/AboutDialog.cpp \
    ui/MainWindow.cpp

FORMS += \
    ui/MainWindow.ui \
    ui/AboutDialog.ui
