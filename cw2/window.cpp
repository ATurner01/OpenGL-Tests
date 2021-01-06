#include "window.hpp"

Window::Window(QWidget *parent): QWidget(parent){

  //Setup the layouts of the window
  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  menu = new QGridLayout();

  //Setup the labels used in the UI
  lookLabel = new QLabel("gluLookAt Position");
  xLabel = new QLabel("x: ");
  yLabel = new QLabel("y: ");
  zLabel = new QLabel("z: ");

  //Setup the sliders for changing the gluLookAt values
  xBar = new QSlider(Qt::Horizontal);
  yBar = new QSlider(Qt::Horizontal);
  zBar= new QSlider(Qt::Horizontal);

  //Setup the widgets that make up the scene
  cube = new SimpleWidgets(this);

  //Configure the sliders
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

  //Add the widgets for controlling the scene to the menu layout
  //menu->addWidget(lookLabel, 0, 0);
  menu->addWidget(xLabel, 1, 0);
  menu->addWidget(xBar, 1, 1);
  menu->addWidget(yLabel, 2, 0);
  menu->addWidget(yBar, 2, 1);
  menu->addWidget(zLabel, 3, 0);
  menu->addWidget(zBar, 3, 1);

  //Add the widgets to the main layout of the window
  layout->addWidget(cube);
  layout->addLayout(menu);

  //Sets the layout of the window and makes the connections between the
  // signals and slots used
  setLayout(layout);
  makeConnections();

}

void Window::makeConnections(){
  //Connect the value of the sliders to the fields in the widgets class
  connect(xBar, SIGNAL(valueChanged(int)), cube, SLOT(gluXValue(int)));
  connect(yBar, SIGNAL(valueChanged(int)), cube, SLOT(gluYValue(int)));
  connect(zBar, SIGNAL(valueChanged(int)), cube, SLOT(gluZValue(int)));
}