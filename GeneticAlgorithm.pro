TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base/templateclassid.cpp

HEADERS += \
    Base/chromosome.h \
    Base/templateclassid.h \
    Base/definesmacros.h \
    Base/generaterandomgene.h \
    Base/environment.h \
    Base/operators.h \
    Base/utility.h \
    Base/calculateevaluation.h
