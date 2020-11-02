#include <GL/glu.h>
#include <QGLWidget>
#include "HelloCubeWidget.h"

// constructor
HelloCubeWidget::HelloCubeWidget(QWidget *parent)
	: QGLWidget(parent)
	{ // constructor
       

	} // constructor

// called when OpenGL context is set up
void HelloCubeWidget::initializeGL()
	{ // initializeGL()
	// set the widget background colour
	glClearColor(0.8, 0.3, 0.3, 0.0);
 
	} // initializeGL()

// called every time the widget is resized
void HelloCubeWidget::resizeGL(int w, int h)
	{ // resizeGL()
	// set the viewport to the entire widget
	glViewport(0, 0, w, h);
        
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);

	} // resizeGL()


void HelloCubeWidget::cube(){



  glColor3f(0.0,1.0,0.0);
  glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f( 1.0, -1.0, 1.0);
    glVertex3f( 1.0,  1.0, 1.0);
    glVertex3f(-1.0,  1.0, 1.0);
  glEnd();

  glColor3f(0.0,0.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f( 1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f( 1.0,  1.0,  1.0);
  glEnd();

  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
  glEnd();

  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
  glEnd();

  glColor3f(0.0,0.0,0.0);
  glBegin(GL_POLYGON);
    glVertex3f( 1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0, -1.0);
    glVertex3f(-1.0,  1.0,  1.0);
    glVertex3f( 1.0,  1.0,  1.0);
  glEnd();

  glColor3f(1.0,0,1.0);
  glBegin(GL_POLYGON);
    glVertex3f( 1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0,  1.0);
    glVertex3f( 1.0, -1.0,  1.0);
  glEnd();

}
	
// called every time the widget needs painting
void HelloCubeWidget::paintGL()
	{ // paintGL()
	// clear the widget
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// You must set the matrix mode to model view directly before enabling the depth test
      	glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST); // comment out depth test to observe the
        // result


	this->cube();

	glLoadIdentity();
       	gluLookAt(1.,1.,1., 0.0,0.0,0.0, 0.0,1.0,0.0);

	// flush to screen
	glFlush();	

	} // paintGL()
