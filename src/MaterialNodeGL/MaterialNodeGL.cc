//MaterialNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "MaterialNodeGL.h"
#include <GL/glut.h>

MaterialNodeGL::MaterialNodeGL() :
  ambient(0.5,0.5,0.5),
  diffuse(0,0,0),
  specular(0,0,0),
  specExp(0)
{}

MaterialNodeGL::MaterialNodeGL(Point3Df ambient,
			       Point3Df diffuse,
			       Point3Df specular,
			       float specExp
			       ):
  ambient(ambient),
  diffuse(diffuse),
  specular(specular),
  specExp(specExp)
{}

MaterialNodeGL::MaterialNodeGL(MaterialNodeGL &other) 
{
  if(this != &other)
    {
      ambient=other.ambient;
      diffuse=other.diffuse;
      specular=other.specular;
      specExp=other.specExp;
    }
}

MaterialNodeGL::~MaterialNodeGL()
{}

void MaterialNodeGL::ActionGL()
{
  glMaterialfv(GL_FRONT,GL_AMBIENT,ambient.data);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse.data);
  glMaterialfv(GL_FRONT,GL_SPECULAR,specular.data);
  glMaterialf(GL_FRONT,GL_SHININESS,specExp);
}

std::ostream & MaterialNodeGL::out(std::ostream& o) const
{
  o << '(' << ambient 
    << ',' << diffuse
    << ',' << specular
    << ',' << specExp
    << ')';
}

std::istream & MaterialNodeGL::in(std::istream& is)
{
  char c;
  is >> c;
  if(c != '(')
    {
      std::cout << "Bad format for MaterialNodeGL\n";
      exit(1);
    }
  is >> ambient >> c;
  if(c != ',')
    {
      std::cout << "Bad format for MaterialNodeGL\n";
      exit(1);
    }
  is >> diffuse >> c;
  if(c != ',')
    {
      std::cout << "Bad format for MaterialNodeGL\n";
      exit(1);
    }
  is >> specular >> c;
  if(c != ',')
    {
      std::cout << "Bad format for MaterialNodeGL\n";
      exit(1);
    }
  is >> specExp >> c;
  if(c != ')')
    {
      std::cout << "Bad format for MaterialNodeGL\n";
      exit(1);
    }
  return is;
}

std::istream& operator>>(std::istream &is, MaterialNodeGL& m)
{
  return m.in(is);
}

std::ostream& operator<<(std::ostream &o, const MaterialNodeGL& m)
{
  return m.out(o);
}







