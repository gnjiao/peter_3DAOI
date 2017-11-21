TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

SOURCES += main.cpp \
    SDK/rectangle.cpp \
    Job/measureobj.cpp \
    App/appsetting.cpp

HEADERS += \
    SDK/rectangle.hpp \
    Job/measureobj.hpp \
    App/appsetting.hpp
