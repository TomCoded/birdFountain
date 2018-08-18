//SinTranslateNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "SinTranslateNodeGL.h"
#include <Defs.h>
#include <GL/glut.h>

SinTranslateNodeGL::SinTranslateNodeGL():
  amplitude(1),
  start(0),
  velocity(0.4),
  current(0),
  translation(1,0,0)
{}

SinTranslateNodeGL::SinTranslateNodeGL(SinTranslateNodeGL &other) 
{
  if(this!=&other)
    {
      amplitude=other.amplitude;
      start=other.start;
      velocity=other.velocity;
      current=other.current;
      translation=other.translation;
    }
}

SinTranslateNodeGL::SinTranslateNodeGL(Point3Dd translation,
				       double amplitude,
				       double start,
				       double velocity):
  amplitude(amplitude),
  translation(translation)
{
  DEGREES_TO_RADIANS(start);
  DEGREES_TO_RADIANS(velocity);
  current=start;
}

SinTranslateNodeGL::~SinTranslateNodeGL()
{}

void SinTranslateNodeGL::ActionGL()
{
  glPushMatrix();
  current+=velocity;
  double multiplier = amplitude * sin(current);
  glTranslated(multiplier*translation.x,
	       multiplier*translation.y,
	       multiplier*translation.z
	       );
}

std::ostream & SinTranslateNodeGL::out(std::ostream& o) const
{
  o << '(' << translation
    << ',' << amplitude
    << ',' << start
    << ',' << velocity
    << ')';
  return o;
}

std::istream & SinTranslateNodeGL::in(std::istream& is)
{
  char c;
  is >> c;
  if(c != '(')
    {
      std::cout << "Bad format for SinTranslateNodeGL: " << c << std::endl;
      exit(1);
    }
  is >> translation >> c;
  if(c != ',')
    {
      std::cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  is >> amplitude >> c;
  if(c != ',')
    {
      std::cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  is >> start >> c;
  if(c != ',')
    {
      std::cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  is >> velocity >> c;
  if(c != ')')
    {
      std::cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  DEGREES_TO_RADIANS(start);
  DEGREES_TO_RADIANS(velocity);
  current=start;
  return is;
}

std::istream& operator>>(std::istream &is, SinTranslateNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const SinTranslateNodeGL& p)
{
  return p.out(o);
}
