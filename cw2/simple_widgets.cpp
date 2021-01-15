#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include "simple_widgets.hpp"


SimpleWidgets::SimpleWidgets(){

}

/**
 * Creates a plane with the specified size
 * @param scale the scale of the plane in all directions
 * @param material the material of the object
 */
void SimpleWidgets::plane(float scale, materialStruct* material){

  glMaterialfv(GL_FRONT, GL_AMBIENT, material->ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material->diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material->specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material->shininess);

  GLfloat normal[3] = {0.,0.,-scale};

  glNormal3fv(normal);
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f( scale, scale, scale);
  glVertex3f( scale,-scale, scale);
  glVertex3f(-scale,-scale, scale);
  glVertex3f(-scale, scale, scale);
  glEnd();
}

/**
 * Creates a cuboid with the specified size
 * @param x the scale of the widget in the x direction
 * @param y the scale of the widget in the y direction
 * @param x the scale of the widget in the z direction
 * @param material the material of the object
 */
void SimpleWidgets::cuboid(float x, float y, float z, materialStruct* material){
  float xScale = x;
  float yScale = y;
  float zScale = z;

  GLfloat normals[][3] = { {0.,0.,z}, {x,0.,0.}, {0.,0.,-z}, {-x,0.,0.},
                           {0.,y,0.}, {0.,-y,0.} };

  glMaterialfv(GL_FRONT, GL_AMBIENT, material->ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material->diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material->specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material->shininess);

  glNormal3fv(normals[0]);
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POLYGON);
  glVertex3f(-xScale,-yScale, zScale);
  glVertex3f( xScale,-yScale, zScale);
  glVertex3f( xScale, yScale, zScale);
  glVertex3f(-xScale, yScale, zScale);
  glEnd();

  glNormal3fv(normals[1]);
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_POLYGON);
  glVertex3f( xScale,-yScale, zScale);
  glVertex3f( xScale,-yScale,-zScale);
  glVertex3f( xScale, yScale,-zScale);
  glVertex3f( xScale, yScale, zScale);
  glEnd();

  glNormal3fv(normals[2]);
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f(-xScale,-yScale,-zScale);
  glVertex3f( xScale,-yScale,-zScale);
  glVertex3f( xScale, yScale,-zScale);
  glVertex3f(-xScale, yScale,-zScale);
  glEnd();

  glNormal3fv(normals[3]);
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POLYGON);
  glVertex3f(-xScale, yScale, zScale);
  glVertex3f(-xScale,-yScale, zScale);
  glVertex3f(-xScale,-yScale,-zScale);
  glVertex3f(-xScale, yScale,-zScale);
  glEnd();

  glNormal3fv(normals[4]);
  glColor3f(0.0,1.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f( xScale, yScale,-zScale);
  glVertex3f(-xScale, yScale,-zScale);
  glVertex3f(-xScale, yScale, zScale);
  glVertex3f( xScale, yScale, zScale);
  glEnd();

  glNormal3fv(normals[5]);
  glColor3f(1.0,0.0,1.0);
  glBegin(GL_POLYGON);
  glVertex3f( xScale,-yScale,-zScale);
  glVertex3f(-xScale,-yScale,-zScale);
  glVertex3f(-xScale,-yScale, zScale);
  glVertex3f( xScale,-yScale, zScale);
  glEnd();
}

/**
 * Creates a cylinder
 * @param scale the size of the cylinder
 * @param material the material of the object
 */
void SimpleWidgets::cylinder(float scale, int edges, int fineness,
        materialStruct* material){

  float x0, y0, x1, y1;
  float delta_z;

  delta_z = ((2*scale) - (-2*scale) / fineness) * scale;

  glMaterialfv(GL_FRONT, GL_AMBIENT, material->ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, material->diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, material->specular);
  glMaterialf(GL_FRONT, GL_SHININESS, material->shininess);

  int i, j;
  for (i=0 ; i<edges ; ++i){
    for (j=0 ; j<fineness ; ++j){
      x0 = cos(2*i*M_PI/edges) * scale;
      x1 = cos(2*(i+1)*M_PI/edges) * scale;
      y0 = sin(2*i*M_PI/edges) * scale;
      y1 = sin(2*(i+1)*M_PI/edges) * scale;

      float z = (-2 + j*delta_z) * scale;

      glBegin(GL_POLYGON);
      glVertex3f(x0,y0,z);
      glVertex3f(x0,y0,0);
      glVertex3f(x1,y1,z);
      glVertex3f(x1,y1,0);
      glVertex3f(x1,y1,z+delta_z);
      glVertex3f(x1,y1,0);
      glVertex3f(x0,y0,z+delta_z);
      glVertex3f(x0,y0,0);
      glEnd();
    }
  }
}
