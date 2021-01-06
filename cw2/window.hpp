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

    //Define the layouts
    QBoxLayout *layout;
    QGridLayout *menu;

    //Define the labels
    QLabel *lookLabel;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *zLabel;

    //Define the sliders for changing gluLookAt values
    QSlider *xBar;
    QSlider *yBar;
    QSlider *zBar;

    //Define the widgets that make the scene
    SimpleWidgets *cube;

private:
    void makeConnections();

};


#endif //CW2_WINDOW_HPP
