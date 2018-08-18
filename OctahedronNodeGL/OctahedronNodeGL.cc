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

std::ostream & OctahedronNodeGL::out(std::ostream& o) const
{
  return o;
}

std::istream & OctahedronNodeGL::in(std::istream& is)
{
  return is;
}

std::istream& operator>>(std::istream &is, OctahedronNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const OctahedronNodeGL& p)
{
  return p.out(o);
}
