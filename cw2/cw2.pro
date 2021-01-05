TEMPLATE = app
TARGET = cw2
INCLUDEPATH += . /opt/local/include

QT += widgets opengl gui
LIBS += -lGLU

HEADERS += window.hpp simple_widgets.hpp
SOURCES += main.cpp \
           window.cpp \
           simple_widgets.cpp