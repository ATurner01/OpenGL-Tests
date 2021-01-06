#ifndef CW2_WINDOW_HPP
#define CW2_WINDOW_HPP

#include <QtWidgets>
#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QBoxLayout>
#include <QGridLayout>
#include "simple_widgets.hpp"

class Window: public QWidget {
    Q_OBJECT
public:
    Window(QWidget *parent);

    QBoxLayout *layout;
    QGridLayout *menu;
    QLabel *lookLabel;
    QSlider *xBar;
    QSlider *yBar;
    QSlider *zBar;

    SimpleWidgets *cube;

private:
    void makeConnections();

};


#endif //CW2_WINDOW_HPP
