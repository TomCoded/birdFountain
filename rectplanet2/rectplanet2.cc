// rectplanet2
//
// A planet orbiting a star
//
// (C)  Bill Lenhart

#include <GL/glut.h>
#include <iostream>
#include "Point3Dd.h"
#include "Point3Df.h"
#include "Point4Dd.h"
#include "Transform4Dd.h"
#include "../TransformMaker/TransformMaker.h"
#include "../Camera/Camera.h"
#include "../Material/Material.h"

// Constants
// the location of the upper left corner of the frame
static const int CORNER_X = 200;
static const int CORNER_Y = 200;

// the viewport bounds
static const int VIEWPORTWIDTH=200;
static const int VIEWPORTHEIGHT=200;

// Menu item constants
enum {SLOW_ITEM, MEDIUM_ITEM, FAST_ITEM, QUIT_ITEM};
int currSpeed = SLOW_ITEM;

// Camera parameters
const Point4Dd eye(0.0, 0.0, 10.0,1.0);
const Point4Dd lookAt(0.0, 0.0, 0.0,1.0);
const Point4Dd up(0.0, 1.0, 0.0,0.0);

// View volume parameters (aspect ratio determined by window on screen)
const double vvFieldOfView = 60;
const double vvNear=1.0;
const double vvFar=150.0;

// color info
float bgRed = 0.0f, bgGreen = 0.0f, bgBlue = 0.0f; // black
float fgRed = 1.0f, fgGreen = 1.0f, fgBlue = 0.0f; // yellow

// current angle and change in angle
double deltaAngle = 2.0;
double angle = 0.0;

// state variables
bool isAnimated = true;
int frameCount = 0;

// celestial body info
Material sunMat(Point3Df(0.329412f, 0.223529f, 0.027451f),
		Point3Df(0.780392f, 0.568627f, 0.113725f),
		Point3Df(0.992157f,0.941176f,0.807843f),
		27.8974f,0,0);
Material planetMat;
double sunRadius = 1.5;
double planetRadius = 0.5;
double distanceToSun = 3.0;
Point3Dd sunAxis(1,3,1);
Point3Dd planetAxis(1,1,1);
double* sunTrans;
double* planetTrans;

// camera info
Camera cam;

// A transform that rotates (0,0,1) to dir
Transform4Dd rotateToAxis(const Point3Dd& dir) {
  Point3Dd axis = dir;
  axis.normalize();
  Point3Dd zAxis(0,0,1);
  Point3Dd cross = zAxis.cross(axis);
  cross.normalize();
  return MakeRotation(acos(zAxis.dot(axis)),cross);
}

// set up sun and planet
void initScene() {
  cam = Camera(eye, lookAt, up, vvFieldOfView*3.14159/180,
	       double(VIEWPORTWIDTH)/double(VIEWPORTHEIGHT),vvNear,vvFar);
  sunTrans= GetArray(rotateToAxis(sunAxis));
  // note order of multiplication!
  planetTrans = GetArray(MakeTranslation(0,0,distanceToSun)*
			 rotateToAxis(planetAxis));
}

// Menu callback: choice is value of the chosen menu entry
void menu(int choice) {
  currSpeed=choice;
  if(choice == QUIT_ITEM)
    exit(0);
}

// The GLUT window idle callback function
void idle(void) {
// increment current angle
  if(((currSpeed == SLOW_ITEM) && ((frameCount%20000) == 0)) ||
     ((currSpeed == MEDIUM_ITEM) && ((frameCount%5000) == 0)) ||
     (currSpeed == FAST_ITEM)) {
    angle+=deltaAngle;
    // and reset if too large
    if(angle >= 360.00)
      angle = 0.0;
    // force a redraw!
    glutPostRedisplay();
  }
  frameCount=(frameCount++)%20000;
}

// The GLUT window keyboard callback function
void keyboard(unsigned char key, int x, int y) {
  // we don't care where the mouse is, so ignore x & y
  switch(key) {
  case 'o' : // zoom out
    cam.eye+=cam.n*0.1;
    break;
  case 'i' : // zoom in
    cam.eye-=cam.n*0.1;
    break;
  }
  cam.resetCameraTransform();

  // Reset the camera here
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixd(cam.wld2Camgl);
}

// The GLUT window mouse callback function
void mouse(int button, int state, int x, int y) {
  // am I pressing the left mouse button
  if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
    if (isAnimated)
      glutIdleFunc(NULL);  // turn off animation
    else
      glutIdleFunc(idle);  // turn on animation
    isAnimated=!isAnimated;// change state
  }
}

// The GLUT window resizing callback function
// Notice the "correct" type for width and height parameters
// Since reshaping changes aspect ratio, we reset the view volume here.
void reshape(GLsizei scr_w, GLsizei scr_h) {
  // Set the viewport
  glViewport(0,0,scr_w,scr_h);

  // Readjust view volume
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); // replace current projection matrix
  // fieldOfView (vertical), aspect ratio, near and far
  cam.aspectRatio = double(scr_w)/double(scr_h);
  cam.setCameraCoordSys();
  gluPerspective(cam.viewAngle*180/3.14159, cam.aspectRatio,
		 -cam.near, -cam.far);
}

// The GLUT window display callback function
void display(void) {
  // We will do a local transform to the sphere
  // First, make sure we have the correct matrix stack
  glMatrixMode(GL_MODELVIEW);
  // Erase window
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMaterialfv(GL_FRONT,GL_AMBIENT,sunMat.ambient.data);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,sunMat.diffuse.data);
  glMaterialfv(GL_FRONT,GL_SPECULAR,sunMat.specular.data);
  glMaterialf(GL_FRONT,GL_SHININESS,sunMat.specExp);
  glPushMatrix(); // Now duplicate top of stack
  // create the square
  glRotated(-30.0,0.0,1.0,0.0);
  glTranslated(0.0,0.0,-2.0);
  glRotated(2*angle,0.0,0.0,1.0);
  double normal[] = {0.0,0.0,1.0};
  glBegin(GL_QUAD_STRIP);
  glNormal3dv(normal);
  glVertex4d(-2.0,-2.0,0.0,1.0);
  glVertex4d(-3.0,-3.0,0.0,1.0);
  glVertex4d(2.0,-2.0,0.0,1.0);
  glVertex4d(3.0,-3.0,0.0,1.0);
  glVertex4d(2.0,2.0,0.0,1.0);
  glVertex4d(3.0,3.0,0.0,1.0);
  glVertex4d(-2.0,2.0,0.0,1.0);
  glVertex4d(-3.0,3.0,0.0,1.0);
  glVertex4d(-2.0,-2.0,0.0,1.0);
  glVertex4d(-3.0,-3.0,0.0,1.0);
  glEnd();
  glPopMatrix(); // Now duplicate top of stack
  glPushMatrix(); // Now duplicate top of stack
  // now add sun's transform
  glMultMatrixd(sunTrans);
  glRotated(angle,0.0,0.0,1.0); // Then rotate around z-axis
  glutSolidSphere(sunRadius,30,30);
  glPopMatrix();
  glPushMatrix();
  // now add planet's transform
  glRotated(angle,1.0,1.0,0.0);
  glMultMatrixd(planetTrans);
  glRotated(angle,0.0,0.0,1.0); // Then rotate around z-axis
  glMaterialfv(GL_FRONT,GL_AMBIENT,planetMat.ambient.data);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,planetMat.diffuse.data);
  glMaterialfv(GL_FRONT,GL_SPECULAR,planetMat.specular.data);
  glMaterialf(GL_FRONT,GL_SHININESS,planetMat.specExp);
  glutSolidTeapot(planetRadius);
  glPopMatrix(); // first get rid of local transform
  glutSwapBuffers();  // swap buffer to screen; no glFlush() necessary
}

// Set up window info AFTER window is created
void initWindowInfo(void) {
  // black background
  glClearColor(bgRed, bgGreen, bgBlue, 0.0);

  // Set the drawing color to yellow
  glColor3f(fgRed, fgGreen, fgBlue);

  // Set up the camera here
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eye.x, eye.y, eye.z,
	    lookAt.x, lookAt.y, lookAt.z,
	    up.x, up.y, up.z);

  // register callbacks
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);

  // set up lighting/shading environment
  glEnable(GL_LIGHTING);
  glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER,true); // true is a non-0 int!
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  float ambient[]={0.2,0.2,0.2};
  float diffuse[]={0.6,0.6,0.6};
  float specular[]={0.8,0.8,0.8};
  float position[] = {0.0,8.0,0.0,0.0};
  glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
  glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
  glLightfv(GL_LIGHT0,GL_POSITION,position);
  glLightfv(GL_LIGHT1,GL_AMBIENT,ambient);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse);
  glLightfv(GL_LIGHT1,GL_SPECULAR,specular);
  position[0] = -7.0;
  position[1] = -6.0;
  position[2] = 9.0;
  glLightfv(GL_LIGHT1,GL_POSITION,position);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);

  // create menu
  glutCreateMenu(menu); // simultaneously registers callback
  // add entries: 2nd parameter is value returned when entry is selected
  glutAddMenuEntry("Slow",SLOW_ITEM);
  glutAddMenuEntry("Medium",MEDIUM_ITEM);
  glutAddMenuEntry("Fast",FAST_ITEM);
  glutAddMenuEntry("Quit",QUIT_ITEM);

  // attach button to menu: overrides mouse callback for MIDDLE button
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);

  // use double-buffering for smoother animation
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(VIEWPORTWIDTH, VIEWPORTHEIGHT);
  glutInitWindowPosition(CORNER_X, CORNER_Y);

  // camera must be set up before window is created
  initScene();

  glutCreateWindow("menu3D");

  initWindowInfo();

  glutMainLoop();
  return 0;
}
