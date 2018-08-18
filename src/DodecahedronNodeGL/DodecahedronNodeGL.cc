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

std::ostream & DodecahedronNodeGL::out(std::ostream& o) const
{
  return o;
}

std::istream & DodecahedronNodeGL::in(std::istream& is)
{
  return is;
}

std::istream& operator>>(std::istream &is, DodecahedronNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const DodecahedronNodeGL& p)
{
  return p.out(o);
}
