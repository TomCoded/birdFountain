//TetrahedronNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "TetrahedronNodeGL.h"
#include <GL/glut.h>

TetrahedronNodeGL::TetrahedronNodeGL()
{}

TetrahedronNodeGL::TetrahedronNodeGL(TetrahedronNodeGL &other) 
{}

TetrahedronNodeGL::~TetrahedronNodeGL()
{}

void TetrahedronNodeGL::ActionGL()
{
  if(!wireFrame) 
    glutSolidTetrahedron();
  else
    glutWireTetrahedron();
}

ostream & TetrahedronNodeGL::out(ostream& o) const
{
  return o;
}

istream & TetrahedronNodeGL::in(istream& is)
{
  return is;
}

istream& operator>>(istream &is, TetrahedronNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const TetrahedronNodeGL& p)
{
  return p.out(o);
}
