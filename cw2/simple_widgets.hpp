#ifndef CW2_SIMPLE_WIDGETS_HPP
#define CW2_SIMPLE_WIDGETS_HPP

#include <QGLWidget>

typedef struct coords{
    int x,y,z;
} coords;


class SimpleWidgets: public QGLWidget {
public:
    SimpleWidgets(QWidget *parent);

protected:
    void initialiseGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    void cube(float pos);

};


#endif //CW2_SIMPLE_WIDGETS_HPP
