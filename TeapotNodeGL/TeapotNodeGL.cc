//TeapotNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "TeapotNodeGL.h"
#include <GL/glut.h>

TeapotNodeGL::TeapotNodeGL():
  size(1)
{}

TeapotNodeGL::TeapotNodeGL(TeapotNodeGL &other) 
{
  if(this!=&other)
    {
      size=other.size;
    }
}

TeapotNodeGL::TeapotNodeGL(double size):			 
  size(size)
{}

TeapotNodeGL::~TeapotNodeGL()
{}

void TeapotNodeGL::ActionGL()
{
  if(!wireFrame)
    glutSolidTeapot(size);
  else
    glutWireTeapot(size);
}

ostream & TeapotNodeGL::out(ostream& o) const
{
  o << size;
  return o;
}

istream & TeapotNodeGL::in(istream& is)
{
  is >> size;
  return is;
}

istream& operator>>(istream &is, TeapotNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const TeapotNodeGL& p)
{
  return p.out(o);
}
