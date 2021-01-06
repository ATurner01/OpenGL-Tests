#include <GL/glu.h>
#include <QGLWidget>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "simple_widgets.hpp"


SimpleWidgets::SimpleWidgets(QWidget *parent): QGLWidget(parent){
  gluX = 1.0;
  gluY = -1.0;
  gluZ = -1.0;
}

void SimpleWidgets::rectangle(coords pos){
  float xScale = pos.x;
  float yScale = pos.y;
  float zScale = pos.z;

  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
  glVertex3f(-xScale,-yScale, zScale);
  glVertex3f( xScale,-yScale, zScale);
  glVertex3f( xScale, yScale, zScale);
  glVertex3f(-xScale, yScale, zScale);
  glEnd();

  glColor3f(0.0,1.0,0.0);
  glBegin(GL_POLYGON);
  glVertex3f( xScale,-yScale, zScale);
  glVertex3f( xScale,-yScale,-zScale);
  glVertex3f( xScale, yScale,-zScale);
  glVertex3f( xScale, yScale, zScale);
  glEnd();

  glColor3f(0.0,0.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f(-xScale,-yScale,-zScale);
  glVertex3f( xScale,-yScale,-zScale);
  glVertex3f( xScale, yScale,-zScale);
  glVertex3f(-xScale, yScale,-zScale);
  glEnd();

  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POLYGON);
  glVertex3f(-xScale, yScale, zScale);
  glVertex3f(-xScale,-yScale, zScale);
  glVertex3f(-xScale,-yScale,-zScale);
  glVertex3f(-xScale, yScale,-zScale);
  glEnd();

  glColor3f(0.0,1.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f( xScale, yScale,-zScale);
  glVertex3f(-xScale, yScale,-zScale);
  glVertex3f(-xScale, yScale, zScale);
  glVertex3f( xScale, yScale, zScale);
  glEnd();

  glColor3f(1.0,0.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f( xScale,-yScale,-zScale);
  glVertex3f(-xScale,-yScale,-zScale);
  glVertex3f(-xScale,-yScale, zScale);
  glVertex3f( xScale,-yScale, zScale);
  glEnd();
}

void SimpleWidgets::initialiseGL(){
  glClearColor(0.8, 0.3, 0.3, 0);
}

void SimpleWidgets::resizeGL(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
}

void SimpleWidgets::paintGL(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);

  glLoadIdentity();
  gluLookAt(gluX,gluY,gluZ, 0.0,0.0,0.0, 0.0,1.0,0.0);

  glPushMatrix();
  this->rectangle(coords{0.5,0.5,0.5});
  glTranslatef(-2,-2.,0.);
  this->rectangle(coords{1.0,1.0,1.0});
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-1.,2.,0.);
  this->rectangle(coords{1.0,1.0,1.0});
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.,2.,2.);
  this->rectangle(coords{1.0,1.0,0.5});
  glPopMatrix();

  glFlush();
}

void SimpleWidgets::gluXValue(int x){
  this->gluX = (float) x;
  this->repaint();
}

void SimpleWidgets::gluYValue(int y){
  this->gluY = (float) y;
  this->repaint();
}

void SimpleWidgets::gluZValue(int z){
  this->gluZ = (float) z;
  this->repaint();
}