#ifndef MATERIALNODE_H_
#define MATERIALNODE_H_
//MaterialNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the MaterialNodeGL class declaration.

#include <Point3Df.h>
#include <NodeGL/NodeGL.h>

class MaterialNodeGL : public NodeGL
{
 public:
  MaterialNodeGL();
  MaterialNodeGL(Point3Df ambient,
		 Point3Df diffuse,
		 Point3Df specular,
		 float specExp
		 );
  MaterialNodeGL(MaterialNodeGL&);

  ~MaterialNodeGL();

  void ActionGL();

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  //ambient, diffuse, and specular coefficients.
  Point3Df ambient;
  Point3Df diffuse;
  Point3Df specular;
  //specular exponent
  float specExp;

};

std::istream& operator>>(std::istream &is, MaterialNodeGL& m);

std::ostream& operator<<(std::ostream &o, const MaterialNodeGL& m);

#endif
