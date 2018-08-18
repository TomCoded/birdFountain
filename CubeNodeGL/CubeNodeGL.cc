//CubeNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "CubeNodeGL.h"
#include <GL/glut.h>

CubeNodeGL::CubeNodeGL():
  size(1)
{}

CubeNodeGL::CubeNodeGL(CubeNodeGL &other) 
{
  if(this!=&other)
    {
      size=other.size;
    }
}

CubeNodeGL::CubeNodeGL(double size):
  size(size)
{}

CubeNodeGL::~CubeNodeGL()
{}

void CubeNodeGL::ActionGL()
{
  if(!wireFrame) 
    glutSolidCube(size);
  else
    glutWireCube(size);
}

std::ostream & CubeNodeGL::out(std::ostream& o) const
{
  o << size;
  return o;
}

std::istream & CubeNodeGL::in(std::istream& is)
{
  is >> size;
  return is;
}

std::istream& operator>>(std::istream &is, CubeNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const CubeNodeGL& p)
{
  return p.out(o);
}
