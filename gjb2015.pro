TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    Resources.cpp \
    utils.cpp \
    Game.cpp \
    GameManager.cpp \
    Collisionable.cpp \
    Player.cpp \
    Board.cpp \
    Stone.cpp \
    Door.cpp \
    Button.cpp \
    Portada.cpp \
    BodyPart.cpp

HEADERS += \
    Resources.hpp \
    utils.hpp \
    Game.hpp \
    GameManager.hpp \
    Collisionable.hpp \
    Player.hpp  \
    Board.hpp \
    Stone.hpp \
    Door.hpp \
    Button.hpp \
    Portada.hpp \
    BodyPart.hpp

