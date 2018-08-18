// mouse3D
//
// Illustrates the use of the following callback functions:
//   mouse, idle, reshape and display
//
// Displays rotating sphere
// 
// (C)  Bill Lenhart

#include <GL/glut.h>
#include <iostream>

// Constants
// the location of the upper left corner of the frame
static const int CORNER_X = 200;
static const int CORNER_Y = 200;

// the viewport bounds
static const int VIEWPORTWIDTH=200;
static const int VIEWPORTHEIGHT=200;

// Camera parameters
double eyeX = 2.0, eyeY = 3.0, eyeZ = 4.0;
double lookAtX =0.0,  lookAtY = 0.0, lookAtZ = 0.0;
double upX = 0.0, upY = 1.0, upZ = 0.0;

// View volume parameters (aspect ratio determined by window on screen)
double vvFieldOfView = 60;
double vvNear=1.0;
double vvFar=80.0;

// color info
float bgRed = 0.5f, bgGreen = 0.0f, bgBlue = 0.5f; // purple
float fgRed = 1.0f, fgGreen = 1.0f, fgBlue = 0.0f; // yellow

// current angle and change in angle
static const double deltaAngle = 1.0;
double angle = 0.0;

// Animation state
bool isAnimated = true;

// The GLUT window idle callback function
void idle(void) {
  // increment current angle
  angle+=deltaAngle;
  // and reset if too large
  if(angle >= 360.00)
    angle = 0.0;
  // force a redraw!
  glutPostRedisplay();
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
  gluPerspective(vvFieldOfView, double(scr_w)/double(scr_h),
		 vvNear, vvFar);
}

// The GLUT window display callback function
void display(void) {
  // We will do a local transform to the sphere
  // First, make sure we have the correct matrix stack
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix(); // Now duplicate top of stack
  // add a rotation to the modelview matrix
  glRotated(angle,0.0,0.0,1.0); // Then rotate around z-axis
  // Erase window
  glClear(GL_COLOR_BUFFER_BIT);
  // Draw a sphere of radius 1.5, with 10 longitude lines and 15 latitude lines
  glutWireSphere(1.5,10,15);
  glPopMatrix(); // first get rid of local transform
  glutSwapBuffers();  // swap buffer to screen; no glFlush() necessary
}

// Set up window info AFTER window is created
void initWindowInfo(void) {
  // purple background
  glClearColor(bgRed, bgGreen, bgBlue, 0.0);

  // Set the drawing color to yellow
  glColor3f(fgRed, fgGreen, fgBlue);

  // Set up the camera here, since we never adjust the camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyeX, eyeY, eyeZ,
	    lookAtX, lookAtY, lookAtZ,
	    upX, upY, upZ);

  // register callbacks
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutMouseFunc(mouse);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);

  // use double-buffering for smoother animation
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(VIEWPORTWIDTH, VIEWPORTHEIGHT);
  glutInitWindowPosition(CORNER_X, CORNER_Y);

  glutCreateWindow("mouse3D");

  initWindowInfo();

  glutMainLoop();
  return 0;
}
