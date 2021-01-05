#ifndef CW2_WINDOW_HPP
#define CW2_WINDOW_HPP

#include <QtWidgets>
#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include "simple_widgets.hpp"

class Window: public QWidget {
    Q_OBJECT
public:
    Window(QWidget *parent);

    QMenuBar *menu;
    QMenu *file;
    QAction *quit;

    QBoxLayout *layout;
    SimpleWidgets *cube;

};


#endif //CW2_WINDOW_HPP
