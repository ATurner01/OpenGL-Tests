#include <GL/glu.h>
#include <QGLWidget>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "simple_widgets.hpp"


SimpleWidgets::SimpleWidgets(QWidget *parent): QGLWidget(parent){
  gluX = 1.0;
  gluY = -1.0;
  gluZ = -1.0;
  gluXAt = 0.0;
  gluYAt = 0.0;
  gluZAt = 0.0;
  gluXUp = 0.0;
  gluYUp = 1.0;
  gluZUp = 0.0;

  orthoXMin = -300.0;
  orthoYMin = -300.0;
  orthoZMin = -300.0;
  orthoXMax = 300.0;
  orthoYMax = 300.0;
  orthoZMax = 300.0;

}

void SimpleWidgets::cuboid(coords pos){
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
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(orthoXMin,orthoXMax, orthoYMin,orthoYMax, orthoZMin,orthoZMax);
}

void SimpleWidgets::resizeGL(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(orthoXMin,orthoXMax, orthoYMin,orthoYMax, orthoZMin,orthoZMax);
}

void SimpleWidgets::paintGL(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);

  glLoadIdentity();
  gluLookAt(gluX,gluY,gluZ, gluXAt,gluYAt,gluZAt, gluXUp,gluYUp,gluZUp);

  glPushMatrix();
  this->cuboid(coords{0.5,0.5,0.5});
  glTranslatef(-2,-2.,0.);
  this->cuboid(coords{1.0,1.0,1.0});
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-1.,2.,0.);
  this->cuboid(coords{1.0,1.0,1.0});
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.,2.,2.);
  this->cuboid(coords{1.0,1.0,0.5});
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

void SimpleWidgets::gluXAtValue(int xAt){
  this->gluXAt = (float) xAt;
  this->repaint();
}

void SimpleWidgets::gluYAtValue(int yAt){
  this->gluYAt = (float) yAt;
  this->repaint();
}

void SimpleWidgets::gluZAtValue(int zAt){
  this->gluZAt = (float) zAt;
  this->repaint();
}

void SimpleWidgets::gluXUpValue(int xUp){
  this->gluXUp = (float) xUp;
  this->repaint();
}

void SimpleWidgets::gluYUpValue(int yUp){
  this->gluYUp = (float) yUp;
  this->repaint();
}

void SimpleWidgets::gluZUpValue(int zUp){
  this->gluZUp = (float) zUp;
  this->repaint();
}

void SimpleWidgets::orthoXMinValue(double xMin){
  this->orthoXMin = (float) xMin;
  this->repaint();
}

void SimpleWidgets::orthoYMinValue(double yMin){
  this->orthoYMin = (float) yMin;
  this->repaint();
}

void SimpleWidgets::orthoZMinValue(double zMin){
  this->orthoZMin = (float) zMin;
  this->repaint();
}

void SimpleWidgets::orthoXMaxValue(double xMax){
  this->orthoXMax = (float) xMax;
  this->repaint();
}

void SimpleWidgets::orthoYMaxValue(double yMax){
  this->orthoYMax = (float) yMax;
  this->repaint();
}

void SimpleWidgets::orthoZMaxValue(double zMax){
  this->orthoZMax = (float) zMax;
  this->repaint();
}
