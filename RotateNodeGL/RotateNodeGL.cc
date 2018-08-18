//RotateNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "RotateNodeGL.h"
#include <functions/functions.h>
#include <GL/glut.h>
#include <Scene/Scene.h>

extern Scene * g_Scene;

RotateNodeGL::RotateNodeGL():
  axis(0,0,1),
  currentAngle(0)
{}

RotateNodeGL::RotateNodeGL(double currentAngle,
			   Point3Dd axis
		       ):
  axis(axis),
  currentAngle(currentAngle)
{}

RotateNodeGL::RotateNodeGL(RotateNodeGL &other) 
{
  if(this != &other)
    {
      axis=other.axis;
      currentAngle=other.currentAngle;
    }
}

RotateNodeGL::~RotateNodeGL()
{}

//precondition: working with GL_MODELVIEW,
void RotateNodeGL::ActionGL()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glRotated(currentAngle,axis.x,axis.y,axis.z);
}









