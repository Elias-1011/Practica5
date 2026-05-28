TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        caja.cpp \
        main.cpp \
        obstaculo.cpp \
        particula.cpp \
        simulador.cpp \
        vector2d.cpp

HEADERS += \
    caja.h \
    obstaculo.h \
    particula.h \
    simulador.h \
    vector2d.h
