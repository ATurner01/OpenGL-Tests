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

// I don't like the default way the main window pops up, I want it bigger
class MyMainWindow : public QMainWindow {

public: 
  
  MyMainWindow();

private:

};

MyMainWindow::MyMainWindow()
{
  // my window asks how big the desktop is; this is a widget for QT
  resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
  // I've set my window to 70 % of the desktop  
}



int main(int argc, char **argv) {
  QApplication app(argc, argv);
  MyMainWindow window;

  // this is the canonical way of doing things: place widgets and draw on them
  // do not try to mess with MyMainWindow's 
  PixelWidget w(70,70);
  window.setCentralWidget(&w);
  window.show();

  // coordinates for the triangle used in the "IsInside" function
  float p[2] = {30,10};
  float q[2] = {50,55};
  float r[2] = {60,55};

  // opens the coordinates file, clears its content and writes the headers of
  // each column to the first line
  std::ofstream out;
  out.open("barycentric_coords.txt");
  out << "alpha" << ", beta" << ", gamma" << ", IsInside" << std::endl;
  out.close();

  std::ofstream image;
  image.open("triangle.ppm");
  image << "P3" << std::endl;
  image << "70 70" << std::endl;
  image << "255" << std::endl;
  image << "" << std::endl;

  int i,j;
  for (i=0 ; i<=70 ; ++i){
    for (j=0 ; j<=70 ; ++j){
      bool in = w.IsInside(p[0],p[1],q[0],q[1],r[0],r[1],i,j);

      if (in == 1){
        image << "255 " << std::endl;
      }
      else{
        image << "0 " << std::endl;
      }
    }
  }

  image.close();

  return app.exec();
}
