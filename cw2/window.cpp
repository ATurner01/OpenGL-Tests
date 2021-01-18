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

  //Setup additional input fields for the gluLookAt values
  xVal = new QSpinBox();
  yVal = new QSpinBox();
  zVal = new QSpinBox();
  xAtVal = new QSpinBox();
  yAtVal = new QSpinBox();
  zAtVal = new QSpinBox();
  xUpVal = new QSpinBox();
  yUpVal = new QSpinBox();
  zUpVal = new QSpinBox();

  //Setup the checkbox to control lighting
  light = new QCheckBox("Toggle Light");

  //Setup a timer to control the rotation of objects
  timer = new QTimer(this);

  //Setup the widgets that make up the scene
  scene = new Scene(this);

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

  //Configure the spin boxes to match the sliders
  xVal->setRange(-180, 180);
  yVal->setRange(-180, 180);
  zVal->setRange(-180, 180);
  xVal->setValue(1);
  yVal->setValue(-1);
  zVal->setValue(-1);

  xAtVal->setRange(-180, 180);
  yAtVal->setRange(-180, 180);
  zAtVal->setRange(-180, 180);
  xAtVal->setValue(0);
  yAtVal->setValue(0);
  zAtVal->setValue(0);

  xUpVal->setRange(-180, 180);
  yUpVal->setRange(-180, 180);
  zUpVal->setRange(-180, 180);
  xUpVal->setValue(0);
  yUpVal->setValue(1);
  zUpVal->setValue(0);

  //Sets the default state of the checkbox to checked
  light->setCheckState(Qt::Checked);

  timer->start(20);

}

void Window::arrangeWidgets(){

  //Add the widgets for controlling the scene to the menu layout
  //menu->addWidget(lookLabel, 0, 0);
  menu->addWidget(xLabel, 1, 0);
  menu->addWidget(xBar, 1, 1);
  menu->addWidget(xVal, 1, 2);

  menu->addWidget(yLabel, 2, 0);
  menu->addWidget(yBar, 2, 1);
  menu->addWidget(yVal, 2, 2);

  menu->addWidget(zLabel, 3, 0);
  menu->addWidget(zBar, 3, 1);
  menu->addWidget(zVal, 3, 2);

  menu->addWidget(xAtLabel, 1, 3);
  menu->addWidget(xAt, 1, 4);
  menu->addWidget(xAtVal, 1, 5);

  menu->addWidget(yAtLabel, 2, 3);
  menu->addWidget(yAt, 2, 4);
  menu->addWidget(yAtVal, 2, 5);

  menu->addWidget(zAtLabel, 3, 3);
  menu->addWidget(zAt, 3, 4);
  menu->addWidget(zAtVal, 3, 5);

  menu->addWidget(xUpLabel, 1, 6);
  menu->addWidget(xUp, 1, 7);
  menu->addWidget(xUpVal, 1, 8);

  menu->addWidget(yUpLabel, 2, 6);
  menu->addWidget(yUp, 2, 7);
  menu->addWidget(yUpVal, 2, 8);

  menu->addWidget(zUpLabel, 3, 6);
  menu->addWidget(zUp, 3, 7);
  menu->addWidget(zUpVal, 3, 8);

  menu->addWidget(light, 1, 9);

  //Add the widgets to the main layout of the window
  layout->addWidget(scene);
  layout->addLayout(menu);

  setLayout(layout);

}

void Window::makeConnections(){
  //Connect the value of the sliders to the fields in the widgets class
  connect(xBar, SIGNAL(valueChanged(int)), scene, SLOT(gluXValue(int)));
  connect(yBar, SIGNAL(valueChanged(int)), scene, SLOT(gluYValue(int)));
  connect(zBar, SIGNAL(valueChanged(int)), scene, SLOT(gluZValue(int)));

  connect(xAt, SIGNAL(valueChanged(int)), scene, SLOT(gluXAtValue(int)));
  connect(yAt, SIGNAL(valueChanged(int)), scene, SLOT(gluYAtValue(int)));
  connect(zAt, SIGNAL(valueChanged(int)), scene, SLOT(gluZAtValue(int)));

  connect(xUp, SIGNAL(valueChanged(int)), scene, SLOT(gluXUpValue(int)));
  connect(yUp, SIGNAL(valueChanged(int)), scene, SLOT(gluYUpValue(int)));
  connect(zUp, SIGNAL(valueChanged(int)), scene, SLOT(gluZUpValue(int)));

  //Connect the value of the spin boxes to the value of the sliders
  // and connect the value of the sliders to the value of the spin boxes
  connect(xBar, SIGNAL(valueChanged(int)), xVal, SLOT(setValue(int)));
  connect(xVal, SIGNAL(valueChanged(int)), xBar, SLOT(setValue(int)));
  connect(yBar, SIGNAL(valueChanged(int)), yVal, SLOT(setValue(int)));
  connect(yVal, SIGNAL(valueChanged(int)), yBar, SLOT(setValue(int)));
  connect(zBar, SIGNAL(valueChanged(int)), zVal, SLOT(setValue(int)));
  connect(zVal, SIGNAL(valueChanged(int)), zBar, SLOT(setValue(int)));

  connect(xAt, SIGNAL(valueChanged(int)), xAtVal, SLOT(setValue(int)));
  connect(xAtVal, SIGNAL(valueChanged(int)), xAt, SLOT(setValue(int)));
  connect(yAt, SIGNAL(valueChanged(int)), yAtVal, SLOT(setValue(int)));
  connect(yAtVal, SIGNAL(valueChanged(int)), yAt, SLOT(setValue(int)));
  connect(zAt, SIGNAL(valueChanged(int)), zAtVal, SLOT(setValue(int)));
  connect(zAtVal, SIGNAL(valueChanged(int)), zAt, SLOT(setValue(int)));

  connect(xUp, SIGNAL(valueChanged(int)), xUpVal, SLOT(setValue(int)));
  connect(xUpVal, SIGNAL(valueChanged(int)), xUp, SLOT(setValue(int)));
  connect(yUp, SIGNAL(valueChanged(int)), yUpVal, SLOT(setValue(int)));
  connect(yUpVal, SIGNAL(valueChanged(int)), yUp, SLOT(setValue(int)));
  connect(zUp, SIGNAL(valueChanged(int)), zUpVal, SLOT(setValue(int)));
  connect(zUpVal, SIGNAL(valueChanged(int)), zUp, SLOT(setValue(int)));

  //Connect the checkbox to the light in the scene
  connect(light, SIGNAL(stateChanged(int)), scene, SLOT(toggleLight(int)));

  //Setup the timer so it updates the angle of rotation
  connect(timer, SIGNAL(timeout()), scene, SLOT(updateAngle()));

}

Window::~Window(){

  delete xBar;
  delete xLabel;
  delete xVal;
  delete yBar;
  delete yLabel;
  delete yVal;
  delete zBar;
  delete zLabel;
  delete zVal;
  delete xAt;
  delete xAtLabel;
  delete xAtVal;
  delete yAt;
  delete yAtLabel;
  delete yAtVal;
  delete zAt;
  delete zAtLabel;
  delete zAtVal;
  delete xUp;
  delete xUpLabel;
  delete xUpVal;
  delete yUp;
  delete yUpLabel;
  delete yUpVal;
  delete zUp;
  delete zUpLabel;
  delete zUpVal;
  delete scene;
}