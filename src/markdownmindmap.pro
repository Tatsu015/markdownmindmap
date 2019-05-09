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
    controller/application.cpp \
    model/document.cpp \
    view/action/abstractaction.cpp \
    view/action/exitaction.cpp \
    view/action/newaction.cpp \
    view/action/openaction.cpp \
    view/action/saveaction.cpp \
    view/codeeditor/codeeditor.cpp \
    view/graphicsview/graphicsview.cpp \
    view/window/mainwindow.cpp \
    viewmodel/graphicsitem/connection.cpp \
    viewmodel/graphicsitem/node.cpp \
    viewmodel/parser/markdownparser.cpp \
    viewmodel/scene/layoutproxy/abstractlayoutproxy.cpp \
    viewmodel/scene/layoutproxy/lefttorighttreelayoutproxy.cpp \
    viewmodel/scene/scene.cpp \
    main.cpp \
    utility/systemconfig.cpp

HEADERS += \
    controller/application.h \
    model/document.h \
    view/action/abstractaction.h \
    view/action/exitaction.h \
    view/action/newaction.h \
    view/action/openaction.h \
    view/action/saveaction.h \
    view/codeeditor/codeeditor.h \
    view/graphicsview/graphicsview.h \
    view/window/mainwindow.h \
    viewmodel/graphicsitem/connection.h \
    viewmodel/graphicsitem/node.h \
    viewmodel/parser/markdownparser.h \
    viewmodel/scene/layoutproxy/abstractlayoutproxy.h \
    viewmodel/scene/layoutproxy/lefttorighttreelayoutproxy.h \
    viewmodel/scene/scene.h \
    utility/systemconfig.h

FORMS += \
    view/window/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
