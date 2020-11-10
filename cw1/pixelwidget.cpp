#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QLabel>
#include <QDesktopWidget>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "pixelwidget.hpp"


void PixelWidget::DefinePixelValues(){ //add pixels here; write methods like this for the assignments
  SetPixel(10,30,RGBVal(255,0,0));
}

void PixelWidget::DrawLine(float start_x, float start_y, float end_x, float
end_y, const RGBVal& start_rgb, const RGBVal& end_rgb){
  float t;
  float x = start_x, y = start_y;
  RGBVal rgb(start_rgb._red, start_rgb._green, start_rgb._blue);

  for (t = 0 ; t < 1 ; t += 0.01){
    SetPixel(x,y,rgb);
    // values of x and y are rounded to 2 decimal places after each calculation
    x = round(((t * start_x) + ((1-t) * end_x)) * 100) / 100;
    y = round(((t * start_y) + ((1-t) * end_y)) * 100) / 100;

    // interpolate the colour along the line based on the provided RGB values
    rgb._red = (t * start_rgb._red) + ((1-t) * end_rgb._red);
    rgb._green = (t * start_rgb._green) + ((1-t) * end_rgb._green);
    rgb._blue = (t * start_rgb._blue) + ((1-t) * end_rgb._blue);
  }
}

void PixelWidget::DrawTriangle(float x1, float y1, float x2, float y2, float x3,
                               float y3, const RGBVal& rgb1, const RGBVal& rgb2,
                               const RGBVal& rgb3) {
  // draw the three edges of the triangle
  DrawLine(x1,y1,x2,y2,rgb1,rgb2);
  DrawLine(x2,y2,x3,y3,rgb2,rgb3);
  DrawLine(x3,y3,x1,y1,rgb3,rgb1);

  float p_x, p_y, u, v;
  float a_x,b_x,c_x;
  float a_y,b_y,c_y;
  RGBVal rgb_inner(255,255,255);

  for (u = 0 ; u < 1 ; u += 0.01){
    for (v = 0 ; v < 1 ; v += 0.01){
      // if the sum of u and v is greater than 1, we're outside the triangle
      // so we skip this point
      if (u + v > 1)
        continue;

      a_x = u * x1;
      b_x = v * x2;
      c_x = (1-u-v) * x3;

      a_y = u * y1;
      b_y = v * y2;
      c_y = (1-u-v) * y3;

      p_x = a_x + b_x + c_x;
      p_y = a_y + b_y + c_y;

      // interpolate the colour values for each point inside the triangle
      rgb_inner._red = (u * rgb1._red) + (v * rgb2._red) + (
              (1-u-v) * rgb3._red);
      rgb_inner._green = (u * rgb1._green) + (v * rgb2._green) + (
              (1-u-v) * rgb3._green);
      rgb_inner._blue = (u * rgb1._blue) + (v * rgb2._blue) +
              ((1-u-v) * rgb3._blue);

      SetPixel(p_x,p_y,rgb_inner);
    }
  }
}

bool PixelWidget::IsInside(float x1, float y1, float x2, float y2, float x3,
                           float y3, float p_x, float p_y) {

  // assume, for simplicity, that the pixel is inside the triangle by default
  bool is_within = true;

  float t[4] = {(x1-x3), (x2-x3),
                (y1-y3), (y2-y3)};

  // calculates the determinant of matrix t
  float det = (t[0] * t[3]) - (t[1] * t[2]);

  // calculates the inverse of the matrix t
  float t_inv[4] = {(t[3] / det), (-t[1] / det),
                    (-t[2] / det), (t[0] / det)};

  float a, b, c;

  a = (t_inv[0] * (p_x - x3)) + (t_inv[1] * (p_x - x3));
  b = (t_inv[2] * (p_y - y3)) + (t_inv[3] * (p_y - y3));
  c = 1 - a - b;

  // check to see if the point is contained within the 3 planes
  if (a < 0 || a > 1){
    is_within = false;
  }
  if (b < 0 || b > 1){
    is_within = false;
  }
  if (c < 0 || c > 1){
    is_within = false;
  }
  if (a + b > 1){
    is_within = false;
  }

  std::ofstream out;
  out.open("barycentric_coords.txt", std::ios_base::app);

  out << a << ", " << b << ", " << c << ", " << is_within << std::endl;

  out.close();

  return is_within;
}


// -----------------Most code below can remain untouched -------------------------
// ------but look at where DefinePixelValues is called in paintEvent--------------

PixelWidget::PixelWidget(unsigned int n_vertical, unsigned int n_horizontal):
  _n_vertical   (n_vertical),
  _n_horizontal (n_horizontal),
  _vec_rects(0)
{
  // all pixels are initialized to black
     for (unsigned int i_col = 0; i_col < n_vertical; i_col++)
       _vec_rects.push_back(std::vector<RGBVal>(n_horizontal));
}



void PixelWidget::SetPixel(unsigned int i_column, unsigned int i_row, const RGBVal& rgb)
{

  // if the pixel exists, set it
  if (i_column < _n_vertical && i_row < _n_horizontal)
    _vec_rects[i_column][i_row] = rgb;
}


void PixelWidget::paintEvent( QPaintEvent * )
{

  QPainter p( this );
  // no antialiasing, want thin lines between the cell
  p.setRenderHint( QPainter::Antialiasing, false );

  // set window/viewport so that the size fits the screen, within reason
  p.setWindow(QRect(-1.,-1.,_n_vertical+2,_n_horizontal+2));
  int side = qMin(width(), height());  
  p.setViewport(0, 0, side, side);

  // black thin boundary around the cells
  QPen pen( Qt::black );
  pen.setWidth(0.);

  // here the pixel values defined by the user are set in the pixel array
  DefinePixelValues();
  //DrawLine(20,20,60,60,RGBVal(0,255,0),RGBVal(255,0,0));
  DrawTriangle(30,10,50,55,60,55,RGBVal(255,0,0),RGBVal(0,255,0),RGBVal(0,0,
        255));
  DrawTriangle(0,30,30,30,30,60,RGBVal(255,0,0),RGBVal(0,255,0), RGBVal(0,0,
          255));

  for (unsigned int i_column = 0 ; i_column < _n_vertical; i_column++)
    for(unsigned int i_row = 0; i_row < _n_horizontal; i_row++){
      QRect rect(i_column,i_row,1,1);
      QColor c = QColor(_vec_rects[i_column][i_row]._red, _vec_rects[i_column][i_row]._green, _vec_rects[i_column][i_row]._blue);
    
      // fill with color for the pixel
      p.fillRect(rect, QBrush(c));
      p.setPen(pen);
      p.drawRect(rect);
    }
}
