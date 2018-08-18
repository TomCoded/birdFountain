//FunTranslateNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "FunTranslateNodeGL.h"
#include <Defs.h>
#include <GL/glut.h>

FunTranslateNodeGL::FunTranslateNodeGL():
  xFun(0),
  yFun(0),
  zFun(0),
  dt(0),
  t(0),
  tWrap(0)
{}


//using this is a bad idea
FunTranslateNodeGL::FunTranslateNodeGL(FunTranslateNodeGL &other) 
{
  if(this!=&other)
    {
      xFun = other.xFun;
      yFun = other.yFun;
      zFun = other.zFun;
      t=other.t;
      dt=other.dt;
      tWrap=other.tWrap;
    }
}

FunTranslateNodeGL::FunTranslateNodeGL(FunNode * xFun,
				       FunNode * yFun,
				       FunNode * zFun,
				       double velocity,
				       double start
				       ):
  xFun(xFun),
  yFun(yFun),
  zFun(zFun),
  dt(velocity),
  t(start),
  tWrap(0)
{}

FunTranslateNodeGL::FunTranslateNodeGL(FunNode * xFun,
				       FunNode * yFun,
				       FunNode * zFun,
				       double velocity,
				       double start,
				       double tWrap
				       ):
  xFun(xFun),
  yFun(yFun),
  zFun(zFun),
  dt(velocity),
  t(start),
  tWrap(tWrap)
{}

FunTranslateNodeGL::~FunTranslateNodeGL()
{
  delete xFun;
  delete yFun;
  delete zFun;
}

void FunTranslateNodeGL::ActionGL()
{
  glPushMatrix();
  glTranslated(
	       xFun->eval(t),
	       yFun->eval(t),
	       zFun->eval(t)
	       );
  t+=dt;
  if(tWrap)
    if(t>tWrap)
      t=0;
}

ostream & FunTranslateNodeGL::out(ostream& o) const
{
  o << "Funtranslation at address " << this << endl;
  return o;
}

istream & FunTranslateNodeGL::in(istream& is)
{
  char c;
  string funX;
  string funY;
  string funZ;
  is >> funX;
  is >> funY;
  is >> funZ;
  is >> dt;
  is >> t;
  is >> tWrap;
  FunParser parser;
  xFun = parser.parseString(funX);
  yFun = parser.parseString(funY);
  zFun = parser.parseString(funZ);
  return is;
}

istream& operator>>(istream &is, FunTranslateNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const FunTranslateNodeGL& p)
{
  return p.out(o);
}
