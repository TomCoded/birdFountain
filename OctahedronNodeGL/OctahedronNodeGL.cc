//OctahedronNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "OctahedronNodeGL.h"
#include <GL/glut.h>

OctahedronNodeGL::OctahedronNodeGL()
{}

OctahedronNodeGL::OctahedronNodeGL(OctahedronNodeGL &other) 
{}

OctahedronNodeGL::~OctahedronNodeGL()
{}

void OctahedronNodeGL::ActionGL()
{
  if(!wireFrame) 
    glutSolidOctahedron();
  else
    glutWireOctahedron();
}

ostream & OctahedronNodeGL::out(ostream& o) const
{
  return o;
}

istream & OctahedronNodeGL::in(istream& is)
{
  return is;
}

istream& operator>>(istream &is, OctahedronNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const OctahedronNodeGL& p)
{
  return p.out(o);
}
