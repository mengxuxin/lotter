#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T10:48:10
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CCLottery
TEMPLATE = app

DESTDIR = $$PWD/bin

CONFIG += c++11


UI_DIR      = compiled/ui
MOC_DIR     = compiled/moc
OBJECTS_DIR = compiled/obj
RCC_DIR     = compiled/qrc


SOURCES += main.cpp\
        CCLottery.cpp \
    lotteryingWin.cpp \
    lotteryData.cpp \
    LotterySettingsWin.cpp \
    DBUtil.cpp

HEADERS  += CCLottery.h \
    lotteryingWin.h \
    lotteryData.h \
    LotterySettingsWin.h \
    DBUtil.h \
    Singleton.h

FORMS    += CCLottery.ui \
    LotterySettingsWiningswin.ui \
    MainWindow.ui \
    LotteryView.ui

RESOURCES += \
    lottery.qrc
