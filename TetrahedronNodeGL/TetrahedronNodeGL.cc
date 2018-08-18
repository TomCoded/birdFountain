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

std::ostream & TetrahedronNodeGL::out(std::ostream& o) const
{
  return o;
}

std::istream & TetrahedronNodeGL::in(std::istream& is)
{
  return is;
}

std::istream& operator>>(std::istream &is, TetrahedronNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const TetrahedronNodeGL& p)
{
  return p.out(o);
}
