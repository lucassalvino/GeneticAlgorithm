TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base/BaseClassId.cpp \
    Base/population.cpp \
    Base/operators.cpp \
    Base/chromosome.cpp \
    Base/managergeneticalgorithm.cpp \
    Base/generation.cpp \
    Exemplo/Graph/Teste/runteste.cpp \
    Exemplo/Graph/customalgorithm.cpp \
    Exemplo/Graph/edge.cpp \
    Exemplo/Graph/graph.cpp \
    Exemplo/Graph/vertex.cpp

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
    Base/include/chromosome.hpp \
    Base/managergeneticalgorithm.h \
    Base/include/managergeneticalgorithm.hpp \
    Base/generation.h \
    Base/include/generation.hpp \
    Base/include/generaterandomgene.hpp \
    Base/include/generaterandomchromosome.hpp \
    Exemplo/customgeneraterandomchromosome.h \
    Exemplo/executaagcaminhografo.h \
    Exemplo/Graph/Teste/runteste.h \
    Exemplo/Graph/customalgorithm.h \
    Exemplo/Graph/edge.h \
    Exemplo/Graph/graph.h \
    Exemplo/Graph/vertex.h \
    Exemplo/customgeneraterandomchromosome.h \
    Exemplo/executaagcaminhografo.h
