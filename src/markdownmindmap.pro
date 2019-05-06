#-------------------------------------------------
#
# Project created by QtCreator 2019-05-01T20:29:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = markdownmindmap
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    controller/layouter/decorator/abstractlayouterdecorator.cpp \
    controller/layouter/layouter.cpp \
    controller/parser/markdownparser.cpp \
    model/node.cpp \
    model/scene.cpp \
    view/graphicsview/graphicsview.cpp \
    view/window/mainwindow.cpp \
    main.cpp \
    controller/layouter/decorator/lefttorighttreelayoutdecorator.cpp \
    model/connection.cpp \
    model/document.cpp \
    view/action/openaction.cpp \
    view/action/saveaction.cpp \
    view/action/exitaction.cpp \
    view/action/abstractaction.cpp \
    controller/application.cpp \
    view/codeeditor/codeeditor.cpp

HEADERS += \
    controller/layouter/decorator/abstractlayouterdecorator.h \
    controller/layouter/layouter.h \
    controller/parser/markdownparser.h \
    model/node.h \
    model/scene.h \
    view/graphicsview/graphicsview.h \
    view/window/mainwindow.h \
    controller/layouter/decorator/lefttorighttreelayoutdecorator.h \
    model/connection.h \
    model/document.h \
    view/action/openaction.h \
    view/action/saveaction.h \
    view/action/exitaction.h \
    view/action/abstractaction.h \
    controller/application.h \
    view/codeeditor/codeeditor.h

FORMS += \
    view/window/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
