//IcosahedronNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "IcosahedronNodeGL.h"
#include <GL/glut.h>

IcosahedronNodeGL::IcosahedronNodeGL()
{}

IcosahedronNodeGL::IcosahedronNodeGL(IcosahedronNodeGL &other) 
{}

IcosahedronNodeGL::~IcosahedronNodeGL()
{}

void IcosahedronNodeGL::ActionGL()
{
  if(!wireFrame) 
    glutSolidIcosahedron();
  else
    glutWireIcosahedron();
}

std::ostream & IcosahedronNodeGL::out(std::ostream& o) const
{
  return o;
}

std::istream & IcosahedronNodeGL::in(std::istream& is)
{
  return is;
}

std::istream& operator>>(std::istream &is, IcosahedronNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const IcosahedronNodeGL& p)
{
  return p.out(o);
}
