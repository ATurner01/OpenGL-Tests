#ifndef CW2_SIMPLE_WIDGETS_HPP
#define CW2_SIMPLE_WIDGETS_HPP

#include <QGLWidget>

typedef struct coords{
    float x,y,z;
} coords;


class SimpleWidgets: public QGLWidget {
    Q_OBJECT
public:
    SimpleWidgets(QWidget *parent);

protected:
    void initialiseGL();
    void resizeGL(int w, int h);
    void paintGL();

    float gluX, gluY, gluZ, gluXAt, gluYAt, gluZAt, gluXUp, gluYUp, gluZUp;
    float orthoXMin, orthoYMin, orthoZMin, orthoXMax, orthoYMax, orthoZMax;

private:
    void cuboid(coords pos);

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


#endif //CW2_SIMPLE_WIDGETS_HPP
