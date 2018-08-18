//MaterialNodeGL.cpp   -*- C++ -*-
//
//(C)  Tom White

#include "TranslationFormNodeGL.h"
#include <functions/functions.h>
#include <TransformMaker/TransformMaker.h>
#include <Transform4Dd.h>
#include <GL/glut.h>

TranslationFormNodeGL::TranslationFormNodeGL()
{
  translation = MakeTranslation(0.0,0.0,0.0);
}

TranslationFormNodeGL::TranslationFormNodeGL(double x,
					     double y,
					     double z
					     )
{
  translation = MakeTranslation(x,y,z);
}

TranslationFormNodeGL::TranslationFormNodeGL(TranslationFormNodeGL &other) 
{
  if(this != &other)
    {
      translation=other.translation;
    }
}

TranslationFormNodeGL::~TranslationFormNodeGL()
{}

//precondition: working with GL_MODELVIEW,
// glPushMatrix() already called if user wants to preserve
//  original matrix.
void TranslationFormNodeGL::ActionGL()
{
  const double * trans = GetArray(translation);
  glMultMatrixd(trans);
  delete trans;
}









