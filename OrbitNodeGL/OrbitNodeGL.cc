//OrbitNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "OrbitNodeGL.h"
#include <functions/functions.h>
#include <TransformMaker/TransformMaker.h>
#include <Transform4Dd.h>
#include <GL/glut.h>
#include <Camera/Camera.h>
#include <Scene/Scene.h>

extern Scene * g_Scene;

OrbitNodeGL::OrbitNodeGL():
  currentAngle(0),
  velocity(1),
  distance(1)
{
}

OrbitNodeGL::OrbitNodeGL(double currentAngle,
			 double velocity,
			 double distance
			 ):
  currentAngle(currentAngle),
  velocity(velocity),
  distance(distance)
{
}

OrbitNodeGL::OrbitNodeGL(OrbitNodeGL &other) 
{
  if(this != &other)
    {
      currentAngle=other.currentAngle;
      velocity=other.velocity;
      distance=other.distance;
    }
}

OrbitNodeGL::~OrbitNodeGL()
{
}

//precondition: working with GL_MODELVIEW,
// glPushMatrix() already called if user wants to preserve
//  original matrix.
void OrbitNodeGL::ActionGL()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glRotated(currentAngle,0,0,1);
  glTranslated(distance,0,0);
  currentAngle+=velocity;
}









