#include <GL/glu.h>
#include <QGLWidget>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "scene.hpp"


Scene::Scene(QWidget *parent): QGLWidget(parent){
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

  basic = new SimpleWidgets();

}

void Scene::initialiseGL(){
  glClearColor(0.8, 0.3, 0.3, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(orthoXMin,orthoXMax, orthoYMin,orthoYMax, orthoZMin,orthoZMax);
}

void Scene::resizeGL(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(orthoXMin,orthoXMax, orthoYMin,orthoYMax, orthoZMin,orthoZMax);
}

void Scene::paintGL(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);

  glLoadIdentity();
  gluLookAt(gluX,gluY,gluZ, gluXAt,gluYAt,gluZAt, gluXUp,gluYUp,gluZUp);

  glPushMatrix();
  basic->cuboid(coords{0.5,0.5,0.5});
  glTranslatef(-2,-2.,0.);
  basic->cuboid(coords{1.0,1.0,1.0});
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-1.,2.,0.);
  basic->cuboid(coords{1.0,1.0,1.0});
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.,2.,2.);
  basic->cuboid(coords{1.0,1.0,0.5});
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-200.,-200.,0.);
  basic->cuboid(coords{50.0, 25.0, 25.0});
  glPopMatrix();

  glFlush();
}

void Scene::gluXValue(int x){
  this->gluX = (float) x;
  this->repaint();
}

void Scene::gluYValue(int y){
  this->gluY = (float) y;
  this->repaint();
}

void Scene::gluZValue(int z){
  this->gluZ = (float) z;
  this->repaint();
}

void Scene::gluXAtValue(int xAt){
  this->gluXAt = (float) xAt;
  this->repaint();
}

void Scene::gluYAtValue(int yAt){
  this->gluYAt = (float) yAt;
  this->repaint();
}

void Scene::gluZAtValue(int zAt){
  this->gluZAt = (float) zAt;
  this->repaint();
}

void Scene::gluXUpValue(int xUp){
  this->gluXUp = (float) xUp;
  this->repaint();
}

void Scene::gluYUpValue(int yUp){
  this->gluYUp = (float) yUp;
  this->repaint();
}

void Scene::gluZUpValue(int zUp){
  this->gluZUp = (float) zUp;
  this->repaint();
}

void Scene::orthoXMinValue(double xMin){
  this->orthoXMin = (float) xMin;
  this->repaint();
}

void Scene::orthoYMinValue(double yMin){
  this->orthoYMin = (float) yMin;
  this->repaint();
}

void Scene::orthoZMinValue(double zMin){
  this->orthoZMin = (float) zMin;
  this->repaint();
}

void Scene::orthoXMaxValue(double xMax){
  this->orthoXMax = (float) xMax;
  this->repaint();
}

void Scene::orthoYMaxValue(double yMax){
  this->orthoYMax = (float) yMax;
  this->repaint();
}

void Scene::orthoZMaxValue(double zMax){
  this->orthoZMax = (float) zMax;
  this->repaint();
}
