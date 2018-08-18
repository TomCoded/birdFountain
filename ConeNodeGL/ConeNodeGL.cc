//ConeNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "ConeNodeGL.h"
#include <GL/glut.h>

ConeNodeGL::ConeNodeGL():
  radius(1),
  height(2),
  slices(30),
  stacks(30)
{}

ConeNodeGL::ConeNodeGL(ConeNodeGL &other) 
{
  if(this!=&other)
    {
      radius=other.radius;
      height=other.height;
      slices=other.slices;
      stacks=other.stacks;
    }
}

ConeNodeGL::ConeNodeGL(double radius,
		       double height,
		       int slices,
		       int stacks):
  radius(radius),
  height(height),
  slices(slices),
  stacks(stacks)
{}

ConeNodeGL::~ConeNodeGL()
{}

void ConeNodeGL::ActionGL()
{
  if(!wireFrame)
    glutSolidCone(radius,height,slices,stacks);
  else
    glutWireCone(radius,height,slices,stacks);
}

std::ostream & ConeNodeGL::out(std::ostream& o) const
{
  o << '(' << radius 
    << ',' << height
    << ',' << slices
    << ',' << stacks
    << ')';
  return o;
}

std::istream & ConeNodeGL::in(std::istream& is)
{
  char c;
  is >> c;
  if(c != '(')
    {
      std::cout << "Bad format for ConeNodeGL: " << c << std::endl;
      exit(1);
    }
  is >> radius >> c;
  if(c != ',')
    {
      std::cout << "Bad format for ConeNodeGL\n";
      exit(1);
    }
  is >> height >> c;
  if(c != ',')
    {
      std::cout << "Bad format for ConeNodeGL\n";
      exit(1);
    }
  is >> slices >> c;
  if(c != ',')
    {
      std::cout << "Bad format for ConeNodeGL\n";
      exit(1);
    }
  is >> stacks >> c;
  if(c != ')')
    {
      std::cout << "Bad format for ConeNodeGL\n";
      exit(1);
    }
  return is;
}

std::istream& operator>>(std::istream &is, ConeNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const ConeNodeGL& p)
{
  return p.out(o);
}
