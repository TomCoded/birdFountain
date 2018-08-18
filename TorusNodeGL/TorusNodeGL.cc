//TorusNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "TorusNodeGL.h"
#include <GL/glut.h>

TorusNodeGL::TorusNodeGL():
  smallRadius(1),
  largeRadius(2),
  slices(30),
  stacks(30)
{}

TorusNodeGL::TorusNodeGL(TorusNodeGL &other) 
{
  if(this!=&other)
    {
      smallRadius=other.smallRadius;
      largeRadius=other.largeRadius;
      slices=other.slices;
      stacks=other.stacks;
    }
}

TorusNodeGL::TorusNodeGL(double smallRadius,
			 double largeRadius,
			 int slices,
			 int stacks):
  smallRadius(smallRadius),
  largeRadius(largeRadius),
  slices(slices),
  stacks(stacks)
{}

TorusNodeGL::~TorusNodeGL()
{}

void TorusNodeGL::ActionGL()
{
  if(!wireFrame)
    glutSolidTorus(smallRadius,largeRadius,slices,stacks);
  else
    glutWireTorus(smallRadius,largeRadius,slices,stacks);
}

ostream & TorusNodeGL::out(ostream& o) const
{
  o << '(' << smallRadius 
    << ',' << largeRadius
    << ',' << slices
    << ',' << stacks
    << ')';
  return o;
}

istream & TorusNodeGL::in(istream& is)
{
  char c;
  is >> c;
  if(c != '(')
    {
      cout << "Bad format for TorusNodeGL: " << c << endl;
      exit(1);
    }
  is >> smallRadius >> c;
  if(c != ',')
    {
      cout << "Bad format for TorusNodeGL\n";
      exit(1);
    }
  is >> largeRadius >> c;
  if(c != ',')
    {
      cout << "Bad format for TorusNodeGL\n";
      exit(1);
    }
  is >> slices >> c;
  if(c != ',')
    {
      cout << "Bad format for TorusNodeGL\n";
      exit(1);
    }
  is >> stacks >> c;
  if(c != ')')
    {
      cout << "Bad format for TorusNodeGL\n";
      exit(1);
    }
  return is;
}

istream& operator>>(istream &is, TorusNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const TorusNodeGL& p)
{
  return p.out(o);
}
