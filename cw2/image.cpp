#include "image.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

Image::Image(const std::string &file){
  p_qimage = new QImage(QString(file.c_str()));

  width = p_qimage->width();
  height = p_qimage->height();
  image = new GLubyte[width*height];

  unsigned int nm = width*height;
  for (unsigned int i = 0 ; i < nm ; ++i){
    std::div_t part = std::div((int)i, (int)width);
    QRgb colval = p_qimage->pixel(width-part.rem-1, part.quot);
    image[3*nm-3*i-3] = qRed(colval);
    image[3*nm-3*i-2] = qGreen(colval);
    image[3*nm-3*i-1] = qBlue(colval);
  }
}

const GLubyte* Image::imageField() const {
  return image;
}

Image::~Image(){
  delete image;
  delete p_qimage;
}