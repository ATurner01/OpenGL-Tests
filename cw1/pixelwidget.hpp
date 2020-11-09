#ifndef _PIXEL_WIDGET_
#define _PIXEL_WIDGET_

#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QLabel>
#include <QDesktopWidget>
#include <iostream>
#include <vector>
#include "RGBVal.hpp"


class PixelWidget : public QWidget {
public:

  
  // set the number of pixels that the widget is meant to display
  PixelWidget
  (
   unsigned int n_horizontal, // the first integer determines the number of horizontal pixels 
   unsigned int n_vertical    // the second integer determines the number of vertical pixels
   );

  // sets a pixel at the specified RGBVal value; ignores non-existing pixels without warning
  void SetPixel
  ( 
   unsigned int  i_x, // horizontal pixel coordinate
   unsigned int  i_y, // vertical pixel coordinate
   const RGBVal& c    // RBGVal object for RGB values
    );

  // Use the body of this function to experiment with rendering algorithms
  void DefinePixelValues();

  // Given the coordinates of a start and end point, draws a line between the
  // two points
  void DrawLine(
   float start_x,
   float start_y,
   float end_x,
   float end_y,
   const RGBVal& start_rgb,
   const RGBVal& end_rgb
   );

  void DrawTriangle(
   float x1,
   float y1,
   float x2,
   float y2,
   float x3,
   float y3,
   const RGBVal& rgb1,
   const RGBVal& rgb2,
   const RGBVal& rgb3
   );

  bool IsInside(
   float x1,
   float y1,
   float x2,
   float y2,
   float x3,
   float y3,
   float p_x,
   float p_y
   );

protected:

  virtual void paintEvent(QPaintEvent*);


private:

  unsigned int _n_vertical;
  unsigned int _n_horizontal;

  std::vector<std::vector<RGBVal> > _vec_rects;
};

#endif

