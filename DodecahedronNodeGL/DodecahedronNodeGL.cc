//DodecahedronNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "DodecahedronNodeGL.h"
#include <GL/glut.h>

DodecahedronNodeGL::DodecahedronNodeGL()
{}

DodecahedronNodeGL::DodecahedronNodeGL(DodecahedronNodeGL &other) 
{}

DodecahedronNodeGL::~DodecahedronNodeGL()
{}

void DodecahedronNodeGL::ActionGL()
{
  if(!wireFrame) 
    glutSolidDodecahedron();
  else
    glutWireDodecahedron();
}

ostream & DodecahedronNodeGL::out(ostream& o) const
{
  return o;
}

istream & DodecahedronNodeGL::in(istream& is)
{
  return is;
}

istream& operator>>(istream &is, DodecahedronNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const DodecahedronNodeGL& p)
{
  return p.out(o);
}
