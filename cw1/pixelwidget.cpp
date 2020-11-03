#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QLabel>
#include <QDesktopWidget>
#include <iostream>
#include <fstream>
#include "pixelwidget.hpp"


void PixelWidget::DefinePixelValues(){ //add pixels here; write methods like this for the assignments
  SetPixel(10,30,RGBVal(255,0,0));
  SetPixel(10,40,RGBVal(0,255,0));
  SetPixel(10,50,RGBVal(0,0,255));
}

void PixelWidget::DrawLine(float start_x, float start_y, float end_x, float
end_y, const RGBVal& start_rgb, const RGBVal& end_rgb){
  float x = start_x, y = start_y;
  float t = 0.01; // Step value

  // A vector parallel to the original provided
  float p_x = end_x - start_x;
  float p_y = end_y - start_y;

  while (x <= end_x || y <= end_y){
    x = x + (p_x * t);
    y = y + (p_y * t);
    SetPixel(x,y,start_rgb);
  }
}

void PixelWidget::DrawTriangle(float x1, float y1, float x2, float y2, float x3,
                               float y3, const RGBVal& rgb1, const RGBVal& rgb2,
                               const RGBVal& rgb3) {

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
  DrawLine(1.0,30.0,50.0,40.0,RGBVal(255,255,255),RGBVal(255,255,255));

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
