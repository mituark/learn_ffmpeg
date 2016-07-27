#-------------------------------------------------
#
# Project created by QtCreator 2016-07-21T03:09:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MME
TEMPLATE = app
UI_DIR += ../MMETmp
MOC_DIR += ../MMETmp
OBJECTS_DIR += ../MMETmp
DESTDIR += ../MMETmp

SOURCES += main.cpp\
        mainwindow.cpp \
    Utils/utils.cpp \
    FFmpeg/ffmpeg.cpp \
    FFmpeg/Test/t_1_hellowffmpeg.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    Utils/utils.h \
    mme.h \
    FFmpeg/ffmpeg.h \
    FFmpeg/Test/t_1_hellowffmpeg.h \
    player.h

FORMS    += mainwindow.ui

RESOURCES += \
    Res/Rec.qrc


INCLUDEPATH +=  /usr/include
LIBS += -L/usr/lib/ -lavcodec \
     -lavdevice \
     -lavfilter \
     -lavformat \
     -lavutil \
     -lpostproc \
     -lswscale
