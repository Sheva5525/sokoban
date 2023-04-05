QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources\info.cpp \
    Sources\logic.cpp \
    Sources\main.cpp \
    Sources\mainwindow.cpp \
    Sources\set_level.cpp \
    Sources\sokoban.cpp

HEADERS += \
    Headers\info.h \
    Headers\logic.h \
    Headers\mainwindow.h \
    Headers\set_level.h \
    Headers\sokoban.h

FORMS += \
    Forms\info.ui \
    Forms\mainwindow.ui \
    Forms\set_level.ui \
    Forms\sokoban.ui

win32:RC_FILE += res\appIco.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res\373737.qrc

DISTFILES += \
    res\appIco.rc \
    res/bg.jpg \
    res/block_01.png \
    res/crate_02.png \
    res/crate_27.png \
    res/player_02.png \
    res/player_11.png \
    res/player_20.png \
    res/player_23.png
