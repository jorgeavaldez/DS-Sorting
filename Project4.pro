TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    SortingCompetition.cpp

OTHER_FILES += \
    README.md

HEADERS += \
    SortingCompetition.h

