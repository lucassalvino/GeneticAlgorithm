TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base/BaseClassId.cpp \
    Base/population.cpp \
    Base/operators.cpp \
    Base/chromosome.cpp

HEADERS += \
    Base/chromosome.h \
    Base/definesmacros.h \
    Base/generaterandomgene.h \
    Base/environment.h \
    Base/operators.h \
    Base/utility.h \
    Base/calculateevaluation.h \
    Base/population.h \
    Base/generaterandomchromosome.h \
    Base/include/baseclassid.hpp \
    Base/include/population.hpp \
    Base/include/operators.hpp \
    Base/include/chromosome.hpp
