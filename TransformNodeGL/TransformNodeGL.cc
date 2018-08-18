//TransformNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "TransformNodeGL.h"
#include <functions/functions.h>
#include <TransformMaker/TransformMaker.h>
#include <Transform4Dd.h>
#include <GL/glut.h>
#include <Camera/Camera.h>
#include <Scene/Scene.h>

extern Scene * g_Scene;

TransformNodeGL::TransformNodeGL()
{
  transform = MakeTranslation(0.0,0.0,0.0);
  transformArr = GetArray(transform);
}

TransformNodeGL::TransformNodeGL(Transform4Dd transform):
  transform(transform)
{
  transformArr = GetArray(transform); //do only once this way
}

TransformNodeGL::TransformNodeGL(TransformNodeGL &other) 
{
  if(this != &other)
    {
      transform=other.transform;
      transformArr=GetArray(transform);
    }
}

TransformNodeGL::~TransformNodeGL()
{
  delete transformArr;
}

void TransformNodeGL::ActionGL()
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glMultMatrixd(transformArr);  
}









