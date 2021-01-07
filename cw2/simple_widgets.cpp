#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "simple_widgets.hpp"


SimpleWidgets::SimpleWidgets(){

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
