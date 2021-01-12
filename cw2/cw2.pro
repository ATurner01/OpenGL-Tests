TEMPLATE = app
TARGET = cw2
INCLUDEPATH += . /opt/local/include

QT += widgets opengl gui
LIBS += -lglut -lGLU

HEADERS += window.hpp scene.hpp simple_widgets.hpp materials.hpp
SOURCES += main.cpp \
           window.cpp \
           scene.cpp \
           simple_widgets.cpp