//SinSpinNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "SinSpinNodeGL.h"
#include <Defs.h>
#include <GL/glut.h>

SinSpinNodeGL::SinSpinNodeGL():
  amplitude(1),
  start(0),
  velocity(0.4),
  current(0),
  axis(1,0,0)
{}

SinSpinNodeGL::SinSpinNodeGL(SinSpinNodeGL &other) 
{
  if(this!=&other)
    {
      amplitude=other.amplitude;
      start=other.start;
      velocity=other.velocity;
      current=other.current;
      axis=other.axis;
    }
}

SinSpinNodeGL::SinSpinNodeGL(Point3Dd axis,
			     double amplitude,
			     double start,
			     double velocity):
  amplitude(amplitude),
  axis(axis)
{
  DEGREES_TO_RADIANS(start);
  DEGREES_TO_RADIANS(velocity);
  current=start;
}

SinSpinNodeGL::~SinSpinNodeGL()
{}

void SinSpinNodeGL::ActionGL()
{
  glPushMatrix();
  current+=velocity;
  if(current>6.2831853) current-=6.2831853;
  double multiplier = amplitude * sin(current);
  glRotated(multiplier*current,
	    axis.x,
	    axis.y,
	    axis.z
	    );
}

std::ostream & SinSpinNodeGL::out(std::ostream& o) const
{
  o << '(' << axis
    << ',' << amplitude
    << ',' << start
    << ',' << velocity
    << ')';
  return o;
}

std::istream & SinSpinNodeGL::in(std::istream& is)
{
  char c;
  is >> c;
  if(c != '(')
    {
      std::cout << "Bad format for SinSpinNodeGL: " << c << std::endl;
      exit(1);
    }
  is >> axis >> c;
  if(c != ',')
    {
      std::cout << "Bad format for SinSpinNodeGL\n";
      exit(1);
    }
  is >> amplitude >> c;
  if(c != ',')
    {
      std::cout << "Bad format for SinSpinNodeGL\n";
      exit(1);
    }
  is >> start >> c;
  if(c != ',')
    {
      std::cout << "Bad format for SinSpinNodeGL\n";
      exit(1);
    }
  is >> velocity >> c;
  if(c != ')')
    {
      std::cout << "Bad format for SinSpinNodeGL\n";
      exit(1);
    }
  DEGREES_TO_RADIANS(start);
  DEGREES_TO_RADIANS(velocity);
  current=start;
  return is;
}

std::istream& operator>>(std::istream &is, SinSpinNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const SinSpinNodeGL& p)
{
  return p.out(o);
}
