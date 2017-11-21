TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

HEADERS += \
    SDK/customexception.hpp\
    SDK/rectangle.hpp \
    Job/measureobj.hpp \
    App/appsetting.hpp

SOURCES += main.cpp \
    SDK/customexception.cpp\
    SDK/rectangle.cpp\
    Job/measureobj.cpp \
    App/appsetting.cpp



