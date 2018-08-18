//LightNodeGL.cpp   -*- C++ -*-
//
//(C)  Tom White

#include "LightNodeGL.h"
#include <functions/functions.h>
#include <TransformMaker/TransformMaker.h>
#include <Transform4Dd.h>
#include <GL/glut.h>

LightNodeGL::LightNodeGL():
  ambient(0.5,0.5,0.5),
  diffuse(0,0,0),
  specular(0,0,0),
  position(0,8,0,1),
  LightID(GL_LIGHT0)
{
}

LightNodeGL::LightNodeGL(Point3Df ambient,
			 Point3Df diffuse,
			 Point3Df specular,
			 Point4Df position,
			 int LightID
			 ):
  ambient(ambient),
  diffuse(diffuse),
  specular(specular),
  position(position),
  LightID(LightID)
{
}

//Is the same light to openGL as the one copied.
LightNodeGL::LightNodeGL(LightNodeGL &other) 
{
  if(this != &other)
    {
      ambient=other.ambient;
      diffuse=other.diffuse;
      specular=other.specular;
      position=other.position;
      LightID=other.LightID;
    }
}

LightNodeGL::~LightNodeGL()
{}

//precondition: working with GL_MODELVIEW,
// glPushMatrix() already called if user wants to preserve
//  original matrix.
void LightNodeGL::ActionGL()
{
  /*  cout << "Light " << LightID 
       << "Ambient " << ambient
       << "Diffuse " << diffuse
       << "Specular " << specular
       << "Position " << position
       << endl;
  */ glEnable(LightID);
  glLightfv(LightID,GL_AMBIENT,ambient.data);
  glLightfv(LightID,GL_DIFFUSE,diffuse.data);
  glLightfv(LightID,GL_SPECULAR,specular.data);
  glLightfv(LightID,GL_POSITION,position.data);
}









