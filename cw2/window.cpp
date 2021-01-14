#include "window.hpp"

Window::Window(QWidget *parent): QWidget(parent){

  createWidgets();
  configureWidgets();
  arrangeWidgets();
  makeConnections();

}

void Window::createWidgets(){

  //Setup the layouts of the window
  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  menu = new QGridLayout();

  //Setup the labels used in the UI
  lookLabel = new QLabel("gluLookAt Position");
  xLabel = new QLabel("x: ");
  yLabel = new QLabel("y: ");
  zLabel = new QLabel("z: ");
  xAtLabel = new QLabel ("At x: ");
  yAtLabel = new QLabel("At y: ");
  zAtLabel = new QLabel("At z: ");
  xUpLabel = new QLabel("Up x: ");
  yUpLabel = new QLabel("Up y: ");
  zUpLabel = new QLabel("Up z:" );
  xMinLabel = new QLabel("x min: ");
  yMinLabel = new QLabel("y min: ");
  zMinLabel = new QLabel("z min: ");
  xMaxLabel = new QLabel("x max: ");
  yMaxLabel = new QLabel("y max:" );
  zMaxLabel = new QLabel("z max: ");

  //Setup the sliders for changing the gluLookAt values
  xBar = new QSlider(Qt::Horizontal);
  yBar = new QSlider(Qt::Horizontal);
  zBar= new QSlider(Qt::Horizontal);
  xAt = new QSlider(Qt::Horizontal);
  yAt = new QSlider(Qt::Horizontal);
  zAt = new QSlider(Qt::Horizontal);
  xUp = new QSlider(Qt::Horizontal);
  yUp = new QSlider(Qt::Horizontal);
  zUp = new QSlider(Qt::Horizontal);

  xMin = new QDoubleSpinBox();
  yMin = new QDoubleSpinBox();
  zMin = new QDoubleSpinBox();
  xMax = new QDoubleSpinBox();
  yMax = new QDoubleSpinBox();
  zMax = new QDoubleSpinBox();

  //Setup the widgets that make up the scene
  cube = new Scene(this);

}

void Window::configureWidgets(){

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

  xAt->setRange(-180, 180);
  xAt->setTickPosition(QSlider::TicksBelow);
  xAt->setTickInterval(10);
  xAt->setValue(0);

  yAt->setRange(-180, 180);
  yAt->setTickPosition(QSlider::TicksBelow);
  yAt->setTickInterval(10);
  yAt->setValue(0);

  zAt->setRange(-180, 180);
  zAt->setTickPosition(QSlider::TicksBelow);
  zAt->setTickInterval(10);
  zAt->setValue(0);

  xUp->setRange(-180, 180);
  xUp->setTickPosition(QSlider::TicksBelow);
  xUp->setTickInterval(10);
  xUp->setValue(0);

  yUp->setRange(-180, 180);
  yUp->setTickPosition(QSlider::TicksBelow);
  yUp->setTickInterval(10);
  yUp->setValue(1);

  zUp->setRange(-180, 180);
  zUp->setTickPosition(QSlider::TicksBelow);
  zUp->setTickInterval(10);
  zUp->setValue(0);

  xMin->setRange(-500.0, 500.0);
  xMin->setValue(-100.0);
  xMin->setSingleStep(0.1);

  yMin->setRange(-500.0, 500.0);
  yMin->setValue(-100.0);
  yMin->setSingleStep(0.1);

  zMin->setRange(-500.0, 500.0);
  zMin->setValue(-100.0);
  zMin->setSingleStep(0.1);

  xMax->setRange(-500.0, 500.0);
  xMax->setValue(100.0);
  xMax->setSingleStep(0.1);

  yMax->setRange(-500.0, 500.0);
  yMax->setValue(100.0);
  yMax->setSingleStep(0.1);

  zMax->setRange(-500.0, 500.0);
  zMax->setValue(100.0);
  zMax->setSingleStep(0.1);

}

void Window::arrangeWidgets(){

  //Add the widgets for controlling the scene to the menu layout
  //menu->addWidget(lookLabel, 0, 0);
  menu->addWidget(xLabel, 1, 0);
  menu->addWidget(xBar, 1, 1);

  menu->addWidget(yLabel, 2, 0);
  menu->addWidget(yBar, 2, 1);

  menu->addWidget(zLabel, 3, 0);
  menu->addWidget(zBar, 3, 1);

  menu->addWidget(xAtLabel, 1, 2);
  menu->addWidget(xAt, 1, 3);

  menu->addWidget(yAtLabel, 2, 2);
  menu->addWidget(yAt, 2, 3);

  menu->addWidget(zAtLabel, 3, 2);
  menu->addWidget(zAt, 3, 3);

  menu->addWidget(xUpLabel, 1, 4);
  menu->addWidget(xUp, 1, 5);

  menu->addWidget(yUpLabel, 2, 4);
  menu->addWidget(yUp, 2, 5);

  menu->addWidget(zUpLabel, 3, 4);
  menu->addWidget(zUp, 3, 5);

  menu->addWidget(xMinLabel, 1, 6);
  menu->addWidget(xMin, 1, 7);

  menu->addWidget(yMinLabel, 2, 6);
  menu->addWidget(yMin, 2, 7);

  menu->addWidget(zMinLabel, 3, 6);
  menu->addWidget(zMin, 3, 7);

  menu->addWidget(xMaxLabel, 1, 8);
  menu->addWidget(xMax, 1, 9);

  menu->addWidget(yMaxLabel, 2, 8);
  menu->addWidget(yMax, 2, 9);

  menu->addWidget(zMaxLabel, 3, 8);
  menu->addWidget(zMax, 3, 9);

  //Add the widgets to the main layout of the window
  layout->addWidget(cube);
  layout->addLayout(menu);

  setLayout(layout);

}

void Window::makeConnections(){
  //Connect the value of the sliders to the fields in the widgets class
  connect(xBar, SIGNAL(valueChanged(int)), cube, SLOT(gluXValue(int)));
  connect(yBar, SIGNAL(valueChanged(int)), cube, SLOT(gluYValue(int)));
  connect(zBar, SIGNAL(valueChanged(int)), cube, SLOT(gluZValue(int)));

  connect(xAt, SIGNAL(valueChanged(int)), cube, SLOT(gluXAtValue(int)));
  connect(yAt, SIGNAL(valueChanged(int)), cube, SLOT(gluYAtValue(int)));
  connect(zAt, SIGNAL(valueChanged(int)), cube, SLOT(gluZAtValue(int)));

  connect(xUp, SIGNAL(valueChanged(int)), cube, SLOT(gluXUpValue(int)));
  connect(yUp, SIGNAL(valueChanged(int)), cube, SLOT(gluYUpValue(int)));
  connect(zUp, SIGNAL(valueChanged(int)), cube, SLOT(gluZUpValue(int)));

  connect(xMin, SIGNAL(valueChanged(double)), cube, SLOT(orthoXMinValue
  (double)));
  connect(yMin, SIGNAL(valueChanged(double)), cube, SLOT(orthoYMinValue
  (double)));
  connect(zMin, SIGNAL(valueChanged(double)), cube, SLOT(orthoZMinValue
  (double)));

  connect(xMax, SIGNAL(valueChanged(double)), cube, SLOT(orthoXMaxValue
  (double)));
  connect(yMax, SIGNAL(valueChanged(double)), cube, SLOT(orthoYMaxValue
  (double)));
  connect(zMax, SIGNAL(valueChanged(double)), cube, SLOT(orthoZMaxValue
  (double)));

}