#include <GL/glu.h>
#include "complex_widgets.hpp"


ComplexWidgets::ComplexWidgets(){
  simple = new SimpleWidgets();
}

/**
 * Creates a table
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
 * Creates a chair
 * @param material the material used for the object
 */
void ComplexWidgets::chair(materialStruct *material) {

  glPushMatrix();

  glPushMatrix();
  //Lower the scene slightly to make the chair closer to the ground
  glTranslatef(0.,-5.,0.);
  //Draw the seat
  simple->cuboid(5.,1.,5., material);
  //Draw the legs
  glRotatef(90, 1.,0.,0.);
  glTranslatef(5.,-5.,7.);
  glScalef(1.,1.,4.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(-10.,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(0.,10.,0.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(10.,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glPopMatrix();

  //Draw the back of the chair
  glPushMatrix();
  glRotatef(90, 1.,0.,0.);
  glTranslatef(5.,-5.,0.);
  glScalef(1.,1.,4.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(-5.,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glTranslatef(-5,0.,0.);
  simple->cylinder(1., 50, 1, material);
  glPopMatrix();
  glTranslatef(0.,7.,-5.);
  simple->cuboid(5.,1.,1., material);

  glPopMatrix();
}

/**
 * Creates a bottle
 * @param material the material used for the object
 */
void ComplexWidgets::bottle(materialStruct *material) {

}

/**
 * Creates a glass
 * @param material the material used for the object
 */
void ComplexWidgets::glass(materialStruct *material) {

}

/**
 * Creates a fireplace
 * @param material the material used for the object
 */
void ComplexWidgets::fireplace(materialStruct *material) {

  //Create the fireplace
  glPushMatrix();
  simple->cuboid(20.,20.,1., material);
  glTranslatef(0.,-20.,-9.);
  simple->cuboid(20.,1.,10., material);
  glTranslatef(15.,20.,3.);
  simple->cuboid(5.,20.,5., material);
  glTranslatef(-30.,0.,0.);
  simple->cuboid(5.,20.,5., material);
  glTranslatef(15.,15.,0.);
  simple->cuboid(10.,5.,5., material);

  //Create the wood logs inside the fireplace
  glRotatef(90, 0.,1.,0.);
  glTranslatef(-3.,-33.,-8.);
  glScalef(2.,2.,1.);
  simple->cylinder(1., 50, 10, &woodenMaterial);
  glTranslatef(2.5,0.,0.);
  simple->cylinder(1., 50, 10, &woodenMaterial);
  glTranslatef(-0.5,2.,0.);
  simple->cylinder(1., 50, 10, &woodenMaterial);
  glPopMatrix();
}
