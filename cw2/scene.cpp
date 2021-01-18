#include <GL/glu.h>
#include <GL/glut.h>
#include <QGLWidget>
#include "scene.hpp"
#include "materials.hpp"


Scene::Scene(QWidget *parent): QGLWidget(parent){
  gluX = -28.0;
  gluY = 7.0;
  gluZ =  4.0;
  gluXAt = 0.0;
  gluYAt = 0.0;
  gluZAt = 0.0;
  gluXUp = 0.0;
  gluYUp = 1.0;
  gluZUp = 0.0;

  orthoXMin = -150.0;
  orthoYMin = -150.0;
  orthoZMin = -300.0;
  orthoXMax = 150.0;
  orthoYMax = 150.0;
  orthoZMax = 300.0;

  angle = 0.0;
  light = 1;

  basic = new SimpleWidgets();
  complex = new ComplexWidgets();

}

void Scene::initialiseGL(){
  glClearColor(0.8, 0.3, 0.3, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(orthoXMin,orthoXMax, orthoYMin,orthoYMax, orthoZMin,orthoZMax);
}

void Scene::resizeGL(int w, int h){
  glViewport(0, 0, w, h);
  //Try to line up the light source with the model of the light in the scene
  GLfloat light_pos[] = {0., -75., 0., 0.};

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(orthoXMin,orthoXMax, orthoYMin,orthoYMax, orthoZMin,orthoZMax);
}

void Scene::paintGL(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);

  //Enable the main light source if the value is 1, otherwise disable it
  if (light){
    glEnable(GL_LIGHT0);
  }
  else {
    glDisable(GL_LIGHT0);
  }

  glLoadIdentity();
  gluLookAt(gluX,gluY,gluZ, gluXAt,gluYAt,gluZAt, gluXUp,gluYUp,gluZUp);


  glPushMatrix();
  //Draw the ceiling
  glRotatef(90, -1.,0.,0.);
  basic->plane(100, &whiteShinyMaterial);
  //Draw the floor
  glRotatef(180, 1.,0.,0.);
  basic->plane(100,&whiteShinyMaterial);
  glPopMatrix();

  //Draw the walls
  glPushMatrix();
  basic->plane(100, &whiteShinyMaterial);
  glTranslatef(0.,0.,-200.);
  basic->plane(100, &whiteShinyMaterial);
  glTranslatef(0.,0.,100.);
  glRotatef(90, 0.,1.,0.);
  glTranslatef(-100.,0.,0.);
  basic->plane(100, &whiteShinyMaterial);
  glPopMatrix();

  //Draw the counter
  glPushMatrix();
  glTranslatef(50.,-79.,-35.);
  basic->cuboid(50,20,10, &woodenMaterial);
  //Place some bottles of the front counter
  glPushMatrix();
  glTranslatef(0.,30.,0.);
  complex->bottle(&greenShinyMaterial);
  glTranslatef(20.,0.,5.);
  complex->bottle(&greenShinyMaterial);
  glTranslatef(-55.,0.,0.);
  complex->bottle(&greenShinyMaterial);
  glPopMatrix();
  //Draw the side of the counter
  glTranslatef(-50.,0.,-5.);
  basic->cuboid(5,20,15, &woodenMaterial);
  //Draw the back of the counter
  glTranslatef(55.,0,-50);
  basic->cuboid(45, 20, 10, &woodenMaterial);
  //Place some bottles on the back counter
  glTranslatef(0.,30.,0.);
  complex->bottle(&greenShinyMaterial);
  glTranslatef(10.,0.,0.);
  complex->bottle(&redShinyMaterial);
  glTranslatef(10.,0.,0.);
  complex->bottle(&redShinyMaterial);
  glTranslatef(10.,0.,0.);
  complex->bottle(&greenShinyMaterial);
  glTranslatef(-40.,0.,0.);
  complex->bottle(&blueShinyMaterial);
  glTranslatef(-10.,0.,0.);
  complex->bottle(&greenShinyMaterial);
  glTranslatef(-10.,0.,0.);
  complex->bottle(&redShinyMaterial);
  glTranslatef(-10,0.,0.);
  complex->bottle(&blueShinyMaterial);
  glPopMatrix();

  //Draw some furniture
  //We want to keep connected pieces of furniture together so we make sure
  // they all use the same coordinate system
  glPushMatrix();
  glTranslatef(0.,-70.,50.);
  complex->table(&woodenMaterial);
  glPushMatrix();
  glTranslatef(0.,9.,10.);
  complex->glass(&brassMaterial);
  glTranslatef(0.,0.,-20.);
  glRotatef(180., 0.,1.,0.);
  complex->glass(&brassMaterial);
  glPopMatrix();
  glTranslatef(0.,-10.,-25.);
  complex->chair(&woodenMaterial);
  glTranslatef(0.,0.,50);
  glRotatef(180, 0.,1.,0.);
  complex->chair(&woodenMaterial);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.,-80.,0.);
  glRotatef(180., 0.,1.,0.);
  glTranslatef(0.,0.,10.);
  complex->chair(&woodenMaterial);
  glTranslatef(-30.,0.,0.);
  complex->chair(&woodenMaterial);
  glTranslatef(-30.,0.,0.);
  complex->chair(&woodenMaterial);
  glTranslatef(-30.,0.,0.);
  complex->chair(&woodenMaterial);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(98.,-78.,50.);
  glRotatef(90, 0.,1.,0.);
  complex->fireplace(&redMatMaterial);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.,78.,0.);
  complex->lightWithFan(&brassMaterial, angle);
  glPopMatrix();

  glFlush();
}


//The code below defines all the slots used by this class

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

void Scene::toggleLight(int toggle){
  this->light = toggle;
  this->repaint();
}

void Scene::updateAngle(){
  this->angle += 1.0;
  this->repaint();
}