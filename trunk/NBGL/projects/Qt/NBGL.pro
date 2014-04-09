TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../../include
INCLUDEPATH += ../../../NBodyBH

QMAKE_CXXFLAGS_RELEASE += -O2

unix {
    QMAKE_CXXFLAGS += -fopenmp
    LIBS += -lGL -lGLU -lglut -lGLEW -lSOIL
    QMAKE_LFLAGS_DEBUG += -fopenmp
    QMAKE_LFLAGS_RELEASE += -fopenmp
}

win32 {
    INCLUDEPATH += "D:/Distribs/GL/include"
    LIBS += -L"D:/Distribs/GL/libs" -lopengl32 -lglu32 -lfreeglut -lglew32 -lSOIL
    QMAKE_CXXFLAGS += -openmp
    QMAKE_LFLAGS_DEBUG += -openmp
    QMAKE_LFLAGS_RELEASE += -openmp
}

SOURCES += \
    ../../src/nbgl.cpp \
    ../../src/nbodycalc.cpp \
    ../../src/nbodytreecalc.cpp \
    ../../src/nbodyvisualizer.cpp \
    ../../src/particlesystem.cpp \
    ../../src/texture.cpp \
    ../../../NBodyBH/body.cpp \
    ../../../NBodyBH/domain2d.cpp \
    ../../../NBodyBH/quadtree.cpp \
    ../../../NBodyBH/quadtreenode.cpp

HEADERS += \
    ../../include/mygl.h \
    ../../include/nbodycalc.h \
    ../../include/nbodytreecalc.h \
    ../../include/nbodyvisualizer.h \
    ../../include/particlesystem.h \
    ../../include/texture.h \
    ../../../NBodyBH/body.h \
    ../../../NBodyBH/domain2d.h \
    ../../../NBodyBH/quadtree.h \
    ../../../NBodyBH/quadtreenode.h \
    ../../../NBodyBH/vector2d.h

