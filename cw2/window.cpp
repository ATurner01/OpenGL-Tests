#include "window.hpp"

Window::Window(QWidget *parent): QWidget(parent){
  //Setup top of the window
  menu = new QMenuBar(this);
  file = menu->addMenu("&File");
  quit = new QAction("&Quit", this);

  //Connect quit slot so that it closes the window when pressed
  connect(quit, &QAction::triggered, qApp, &QApplication::closeAllWindows,
          Qt::QueuedConnection);

  file->addAction(quit);

  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  cube = new SimpleWidgets(this);
  //layout->addWidget(menu);
  layout->addWidget(cube);
}