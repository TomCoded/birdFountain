//PlanetNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "PlanetNodeGL.h"
#include <GL/glut.h>

PlanetNodeGL::PlanetNodeGL():
  planetRadius(1),
  slices(30),
  stacks(30)
{}

PlanetNodeGL::PlanetNodeGL(PlanetNodeGL &other) 
{
  if(this!=&other)
    {
      planetRadius=other.planetRadius;
      slices=other.slices;
      stacks=other.stacks;
    }
}

PlanetNodeGL::PlanetNodeGL(double planetRadius,
			   int slices,
			   int stacks):
  planetRadius(planetRadius),
  slices(slices),
  stacks(stacks)
{}

PlanetNodeGL::~PlanetNodeGL()
{}

void PlanetNodeGL::ActionGL()
{
  if(!wireFrame)
    glutSolidSphere(planetRadius,slices,stacks);
  else
    glutWireSphere(planetRadius,slices,stacks);
}

ostream & PlanetNodeGL::out(ostream& o) const
{
  o << '(' << planetRadius 
    << ',' << slices
    << ',' << stacks
    << ')';
  return o;
}

istream & PlanetNodeGL::in(istream& is)
{
  char c;
  is >> c;
  if(c != '(')
    {
      cout << "Bad format for PlanetNodeGL: " << (int)c << endl;
      exit(1);
    }
  is >> planetRadius >> c;
  if(c != ',')
    {
      cout << "Bad format for PlanetNodeGL !,\n";
      exit(1);
    }
  is >> slices >> c;
  if(c != ',')
    {
      cout << "Bad format for PlanetNodeGL !,2\n";
      exit(1);
    }
  is >> stacks >> c;
  if(c != ')')
    {
      cout << "Bad format for PlanetNodeGL !)\n";
      exit(1);
    }
  return is;
}

istream& operator>>(istream &is, PlanetNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const PlanetNodeGL& p)
{
  return p.out(o);
}
