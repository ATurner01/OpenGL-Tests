#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <GL/glut.h>
#include <window.hpp>

int main(int argc, char** argv){
  QApplication app(argc, argv);
  glutInit(&argc, argv);

  Window *window = new Window(NULL);
  window->resize(1024, 1024);
  window->show();
  app.exec();

  delete window;

  return 0;
}