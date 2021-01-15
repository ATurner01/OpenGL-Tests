#ifndef CW2_SCENE_HPP
#define CW2_SCENE_HPP

#include <QGLWidget>
#include "simple_widgets.hpp"
#include "complex_widgets.hpp"

class Scene: public QGLWidget {
    Q_OBJECT
public:
    Scene(QWidget *parent);

protected:
    void initialiseGL();
    void resizeGL(int w, int h);
    void paintGL();

    float gluX, gluY, gluZ, gluXAt, gluYAt, gluZAt, gluXUp, gluYUp, gluZUp;
    float orthoXMin, orthoYMin, orthoZMin, orthoXMax, orthoYMax, orthoZMax;
    SimpleWidgets *basic;
    ComplexWidgets *complex;

public slots:
    void gluXValue(int);
    void gluYValue(int);
    void gluZValue(int);
    void gluXAtValue(int);
    void gluYAtValue(int);
    void gluZAtValue(int);
    void gluXUpValue(int);
    void gluYUpValue(int);
    void gluZUpValue(int);

    void orthoXMinValue(double);
    void orthoYMinValue(double);
    void orthoZMinValue(double);
    void orthoXMaxValue(double);
    void orthoYMaxValue(double);
    void orthoZMaxValue(double);
};


#endif //CW2_SCENE_HPP
