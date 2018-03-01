TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base/chromosome.cpp \
    Base/templateclassid.cpp

HEADERS += \
    Base/import/chromosome.h \
    Base/import/generaterandomgene.h \
    Base/chromosome.h \
    Base/templateclassid.h
