QT += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = orzasteel.qt
TEMPLATE = app

SOURCES += src/qt/main.cpp\
        src/qt/Window.cpp

HEADERS  += src/qt/Window.h

FORMS    += src/qt/Window.ui\
    src/qt/Settings/Settings.ui\
    src/qt/Settings/PedalEditor.ui \
    src/qt/Settings/PedalEditArea.ui

