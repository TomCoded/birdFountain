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

ostream & CubeNodeGL::out(ostream& o) const
{
  o << size;
  return o;
}

istream & CubeNodeGL::in(istream& is)
{
  is >> size;
  return is;
}

istream& operator>>(istream &is, CubeNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const CubeNodeGL& p)
{
  return p.out(o);
}
