#include <GL/glu.h>
#include "complex_widgets.hpp"


ComplexWidgets::ComplexWidgets(){
  simple = new SimpleWidgets();
}

/**
 * Creates a table at the specified location
 * @param material the material used for the object
 */
void ComplexWidgets::table(materialStruct *material) {

  glPushMatrix();
  //Draw the table top
  simple->cuboid(15.,1.,15., material);
  //Draw the legs
  glRotatef(90, 1.,0.,0.);
  glTranslatef(15.,-9.,15.);
  glScalef(1.,1.,8.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(-30.,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(0.,20.,0.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(30.,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glPopMatrix();
}

/**
 * Creates a chair at the specified location
 * @param material the material used for the object
 */
void ComplexWidgets::chair(materialStruct *material) {

  glPushMatrix();
  glTranslatef(0.,-5.,0.);
  simple->cuboid(8.,1.,8., material);
  glRotatef(90, 1.,0.,0.);
  glTranslatef(4.,-8.5,8.);
  glScalef(1.,1.,5.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(-8.,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(0.,10.,0.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(8.,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glPopMatrix();
}

/**
 * Creates a bottle at the specified location
 * @param material the material used for the object
 */
void ComplexWidgets::bottle(materialStruct *material) {

}

/**
 * Creates a glass at the specified location
 * @param material the material used for the object
 */
void ComplexWidgets::glass(materialStruct *material) {

}
