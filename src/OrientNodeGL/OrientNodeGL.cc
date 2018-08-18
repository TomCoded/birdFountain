//OrientNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "OrientNodeGL.h"
#include <functions/functions.h>
#include <TransformMaker/TransformMaker.h>
#include <Transform4Dd.h>
#include <GL/glut.h>
#include <Camera/Camera.h>
#include <Scene/Scene.h>

extern Scene * g_Scene;

OrientNodeGL::OrientNodeGL():
  fromAxis(1,0,0),
  toAxis(0,1,0)
{
  fromAxis.normalize();
  toAxis.normalize();
  rotateAxis = fromAxis.cross(toAxis);
  rotateAxis.normalize();
  currentAngle = acos(fromAxis.dot(toAxis));
  currentAngle = currentAngle*(180/3.14159265);
}

OrientNodeGL::OrientNodeGL(Point3Dd fromAxis,
			   Point3Dd toAxis
			   ):
  fromAxis(fromAxis),
  toAxis(toAxis)
{
  fromAxis.normalize();
  toAxis.normalize();
  rotateAxis = fromAxis.cross(toAxis);
  rotateAxis.normalize();
  currentAngle = acos(fromAxis.dot(toAxis));
  currentAngle = currentAngle*(180/3.14159265);
}

OrientNodeGL::OrientNodeGL(OrientNodeGL &other) 
{
  if(this != &other)
    {
      toAxis=other.toAxis;
      fromAxis=other.fromAxis;
      rotateAxis=other.rotateAxis;
      currentAngle=other.currentAngle;
    }
}

OrientNodeGL::~OrientNodeGL()
{}

void OrientNodeGL::ActionGL()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glRotated(currentAngle,
	    rotateAxis.x,
	    rotateAxis.y,
	    rotateAxis.z
	    );
}









