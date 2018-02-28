TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Base/chromosome.cpp \
    Base/chromosome.cpp \
    myLibraries/BasisForDeveloping/config.cpp \
    myLibraries/BasisForDeveloping/data.cpp \
    myLibraries/BasisForDeveloping/datatype.cpp \
    myLibraries/BasisForDeveloping/utility.cpp \
    myLibraries/Fraction/fraction.cpp \
    myLibraries/Fraction/main.cpp \
    myLibraries/Graph/Teste/runteste.cpp \
    myLibraries/Graph/customalgorithm.cpp \
    myLibraries/Graph/edge.cpp \
    myLibraries/Graph/graph.cpp \
    myLibraries/Graph/main.cpp \
    myLibraries/Graph/vertex.cpp \
    myLibraries/ThreadManager/interconnection.cpp \
    myLibraries/ThreadManager/main.cpp \
    myLibraries/ThreadManager/message.cpp \
    myLibraries/ThreadManager/task.cpp \
    myLibraries/YException/customexception.cpp \
    main.cpp \
    Base/templateclassid.cpp

HEADERS += \
    Base/chromosome.h \
    Base/chromosome.h \
    myLibraries/BasisForDeveloping/basisfordeveloping_global.h \
    myLibraries/BasisForDeveloping/config.h \
    myLibraries/BasisForDeveloping/data.h \
    myLibraries/BasisForDeveloping/datatype.h \
    myLibraries/BasisForDeveloping/utility.h \
    myLibraries/Fraction/fraction.h \
    myLibraries/Fraction/utilities.h \
    myLibraries/Graph/Teste/runteste.h \
    myLibraries/Graph/customalgorithm.h \
    myLibraries/Graph/edge.h \
    myLibraries/Graph/graph.h \
    myLibraries/Graph/vertex.h \
    myLibraries/ThreadManager/interconnection.h \
    myLibraries/ThreadManager/message.h \
    myLibraries/ThreadManager/task.h \
    myLibraries/YException/customexception.h \
    myLibraries/YException/yexception_global.h \
    Base/import/chromosome.h \
    Base/templateclassid.h \
    Base/import/generaterandomgene.h
