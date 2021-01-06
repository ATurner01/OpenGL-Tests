#include "window.hpp"

Window::Window(QWidget *parent): QWidget(parent){
  //Setup top of the window

  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  menu = new QGridLayout();
  lookLabel = new QLabel("gluLookAt Position");
  xBar = new QSlider(Qt::Horizontal);
  yBar = new QSlider(Qt::Horizontal);
  zBar= new QSlider(Qt::Horizontal);
  cube = new SimpleWidgets(this);

  xBar->setRange(-180, 180);
  xBar->setTickPosition(QSlider::TicksBelow);
  xBar->setTickInterval(10);
  xBar->setValue(1);

  yBar->setRange(-180, 180);
  yBar->setTickPosition(QSlider::TicksBelow);
  yBar->setTickInterval(10);
  yBar->setValue(-1);

  zBar->setRange(-180, 180);
  zBar->setTickPosition(QSlider::TicksBelow);
  zBar->setTickInterval(10);
  zBar->setValue(-1);

  //menu->addWidget(lookLabel, 0, 0);
  menu->addWidget(xBar, 1, 0);
  menu->addWidget(yBar, 2, 0);
  menu->addWidget(zBar, 3, 0);

  layout->addWidget(cube);
  layout->addLayout(menu);

  makeConnections();

}

void Window::makeConnections(){
  connect(xBar, SIGNAL(valueChanged(int)), cube, SLOT(gluXValue(int)));

  connect(yBar, SIGNAL(valueChanged(int)), cube, SLOT(gluYValue(int)));

  connect(zBar, SIGNAL(valueChanged(int)), cube, SLOT(gluZValue(int)));
}