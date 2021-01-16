#ifndef CW2_WINDOW_HPP
#define CW2_WINDOW_HPP

#include <QtWidgets>
#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QSpinBox>
#include <QBoxLayout>
#include <QGridLayout>
#include "scene.hpp"

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
    QLabel *xAtLabel;
    QLabel *yAtLabel;
    QLabel *zAtLabel;
    QLabel *xUpLabel;
    QLabel *yUpLabel;
    QLabel *zUpLabel;

    //Define the sliders for changing gluLookAt values
    QSlider *xBar;
    QSlider *yBar;
    QSlider *zBar;
    QSlider *xAt;
    QSlider *yAt;
    QSlider *zAt;
    QSlider *xUp;
    QSlider *yUp;
    QSlider *zUp;

    //Define additional input fields for each slider
    QSpinBox *xVal;
    QSpinBox *yVal;
    QSpinBox *zVal;
    QSpinBox *xAtVal;
    QSpinBox *yAtVal;
    QSpinBox *zAtVal;
    QSpinBox *xUpVal;
    QSpinBox *yUpVal;
    QSpinBox *zUpVal;

    //Define the widgets that make the scene
    Scene *cube;

private:
    void createWidgets();
    void configureWidgets();
    void arrangeWidgets();
    void makeConnections();

};


#endif //CW2_WINDOW_HPP
