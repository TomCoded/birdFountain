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

std::ostream & TeapotNodeGL::out(std::ostream& o) const
{
  o << size;
  return o;
}

std::istream & TeapotNodeGL::in(std::istream& is)
{
  is >> size;
  return is;
}

std::istream& operator>>(std::istream &is, TeapotNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const TeapotNodeGL& p)
{
  return p.out(o);
}
