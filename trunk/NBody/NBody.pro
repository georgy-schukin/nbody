TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -openmp
QMAKE_LFLAGS += -openmp

SOURCES += \
    nbody.cpp \
    body.cpp

HEADERS += \
    vector2d.h \
    domain2d.h \
    body.h

