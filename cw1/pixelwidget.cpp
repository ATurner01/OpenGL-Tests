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
#include "pixelwidget.hpp"


void PixelWidget::DefinePixelValues(){ //add pixels here; write methods like this for the assignments
  SetPixel(10,30,RGBVal(255,0,0));
  SetPixel(10,40,RGBVal(0,255,0));
  SetPixel(10,50,RGBVal(0,0,255));
}

void PixelWidget::DrawLine(float start_x, float start_y, float end_x, float
end_y, const RGBVal& start_rgb, const RGBVal& end_rgb){
  float t;
  float x = start_x, y = start_y;
  RGBVal rgb(start_rgb._red, start_rgb._green, start_rgb._blue);

  for (t = 0 ; t < 1 ; t += 0.01){
    SetPixel(x,y,rgb);
    // values of x and y are rounded to 2 decimal places after each calculation
    x = std::round(((t * start_x) + ((1-t) * end_x)) * 100) / 100;
    y = std::round(((t * start_y) + ((1-t) * end_y)) * 100) / 100;

    // interpolate the colour along the line based on the provided RGB values
    rgb._red = (t * start_rgb._red) + ((1-t) * end_rgb._red);
    rgb._green = (t * start_rgb._green) + ((1-t) * end_rgb._green);
    rgb._blue = (t * start_rgb._blue) + ((1-t) * end_rgb._blue);
  }
}

void PixelWidget::DrawTriangle(float x1, float y1, float x2, float y2, float x3,
                               float y3, const RGBVal& rgb1, const RGBVal& rgb2,
                               const RGBVal& rgb3) {
  DrawLine(x1,y1,x2,y2,rgb1,rgb2);
  DrawLine(x2,y2,x3,y3,rgb2,rgb3);
  DrawLine(x3,y3,x1,y1,rgb3,rgb1);
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
  DrawLine(20,20,60,60,RGBVal(0,255,0),RGBVal(255,0,0));
  //DrawLine(1.0,30.0,50.0,40.0,RGBVal(255,255,255),RGBVal(255,255,255));
  //DrawLine(10,50,40,15,RGBVal(0,0,255),RGBVal(0,255,0));
  DrawTriangle(30,10,50,55,60,55,RGBVal(255,0,0),RGBVal(0,255,0),RGBVal(0,0,
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
