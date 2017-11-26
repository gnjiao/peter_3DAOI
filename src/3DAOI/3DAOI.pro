TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

HEADERS += \
    SDK/customexception.hpp\
    SDK/rectangle.hpp \
    Job/measureobj.hpp \
    Job/measurelist.hpp\
    App/appsetting.hpp \
    App/capturesetting.hpp \
    Job/board.hpp

SOURCES += main.cpp \
    SDK/customexception.cpp\
    SDK/rectangle.cpp\
    Job/measureobj.cpp \
    Job/measurelist.cpp\
    App/appsetting.cpp \
    App/capturesetting.cpp\
    Job/board.cpp



