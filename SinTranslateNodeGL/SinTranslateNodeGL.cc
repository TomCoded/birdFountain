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

ostream & SinTranslateNodeGL::out(ostream& o) const
{
  o << '(' << translation
    << ',' << amplitude
    << ',' << start
    << ',' << velocity
    << ')';
  return o;
}

istream & SinTranslateNodeGL::in(istream& is)
{
  char c;
  is >> c;
  if(c != '(')
    {
      cout << "Bad format for SinTranslateNodeGL: " << c << endl;
      exit(1);
    }
  is >> translation >> c;
  if(c != ',')
    {
      cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  is >> amplitude >> c;
  if(c != ',')
    {
      cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  is >> start >> c;
  if(c != ',')
    {
      cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  is >> velocity >> c;
  if(c != ')')
    {
      cout << "Bad format for SinTranslateNodeGL\n";
      exit(1);
    }
  DEGREES_TO_RADIANS(start);
  DEGREES_TO_RADIANS(velocity);
  current=start;
  return is;
}

istream& operator>>(istream &is, SinTranslateNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const SinTranslateNodeGL& p)
{
  return p.out(o);
}
