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
    core/stdafx.cpp \
    core/Memory.cpp \
    core/main.cpp \
    core/CacheEntry.cpp \
    core/Cache.cpp \
    ui/MainWindow.cpp \
    ui/AboutDialog.cpp

FORMS += \
    ui/MainWindow.ui \
    ui/AboutDialog.ui
