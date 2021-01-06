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

    float gluX, gluY, gluZ;

private:
    void rectangle(coords pos);

public slots:
    void gluXValue(int);
    void gluYValue(int);
    void gluZValue(int);
};


#endif //CW2_SIMPLE_WIDGETS_HPP
