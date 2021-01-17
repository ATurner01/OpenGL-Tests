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
    int light;
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
    void toggleLight(int);
};


#endif //CW2_SCENE_HPP
