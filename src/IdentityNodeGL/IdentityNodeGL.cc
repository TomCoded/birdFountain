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

std::ostream & IdentityNodeGL::out(std::ostream& o) const
{
  return o;
}

std::istream & IdentityNodeGL::in(std::istream& is)
{
  return is;
}

std::istream& operator>>(std::istream &is, IdentityNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const IdentityNodeGL& p)
{
  return p.out(o);
}
