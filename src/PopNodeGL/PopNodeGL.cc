//PopNodeGL.cpp   -*- C++ -*-
//
//(C)  Tom White

#include "PopNodeGL.h"
#include <iostream>
#include <GL/glut.h>

PopNodeGL::PopNodeGL() 
{}

PopNodeGL::PopNodeGL(PopNodeGL &other) 
{}

PopNodeGL::~PopNodeGL()
{}

void PopNodeGL::ActionGL()
{
  glPopMatrix();
}
