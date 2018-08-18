//SpinNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "SpinNodeGL.h"
#include <functions/functions.h>
#include <GL/glut.h>
#include <Scene/Scene.h>

extern Scene * g_Scene;

SpinNodeGL::SpinNodeGL():
  axis(0,0,1),
  velocity(1),
  currentAngle(0)
{}

SpinNodeGL::SpinNodeGL(Point3Dd axis,
		       double velocity
		       ):
  axis(axis),
  velocity(velocity),
  currentAngle(0)
{}

SpinNodeGL::SpinNodeGL(SpinNodeGL &other) 
{
  if(this != &other)
    {
      axis=other.axis;
      velocity=other.velocity;
      currentAngle=other.currentAngle;
    }
}

SpinNodeGL::~SpinNodeGL()
{}

//precondition: working with GL_MODELVIEW,
void SpinNodeGL::ActionGL()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glRotated(currentAngle,axis.x,axis.y,axis.z);
  currentAngle+=velocity;
}









