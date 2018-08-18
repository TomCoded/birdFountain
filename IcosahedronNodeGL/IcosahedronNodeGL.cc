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

ostream & IcosahedronNodeGL::out(ostream& o) const
{
  return o;
}

istream & IcosahedronNodeGL::in(istream& is)
{
  return is;
}

istream& operator>>(istream &is, IcosahedronNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const IcosahedronNodeGL& p)
{
  return p.out(o);
}
