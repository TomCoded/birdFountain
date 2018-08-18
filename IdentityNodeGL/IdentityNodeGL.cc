//IdentityNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "IdentityNodeGL.h"
#include <GL/glut.h>

IdentityNodeGL::IdentityNodeGL()
{}

IdentityNodeGL::IdentityNodeGL(IdentityNodeGL &other) 
{}

IdentityNodeGL::~IdentityNodeGL()
{}

void IdentityNodeGL::ActionGL()
{
  glLoadIdentity();
}

ostream & IdentityNodeGL::out(ostream& o) const
{
  return o;
}

istream & IdentityNodeGL::in(istream& is)
{
  return is;
}

istream& operator>>(istream &is, IdentityNodeGL& p)
{
  return p.in(is);
}

ostream& operator<<(ostream &o, const IdentityNodeGL& p)
{
  return p.out(o);
}
