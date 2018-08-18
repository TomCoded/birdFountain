//ConeNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the ConeNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>
//#include <TransformMaker/TransformMaker.h>

class ConeNodeGL : public NodeGL
{
 public:
  ConeNodeGL();
  ConeNodeGL(ConeNodeGL&);
  ConeNodeGL(//Transform4Dd planetTransform,
	      //MaterialNodeGL planetMaterial,
	      double smallRadius,
	      double largeRadius,
	       int slices,
	       int stacks
	       );
  ~ConeNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
  double radius;
  double height;
  int stacks;
  int slices;
};

istream& operator>>(istream &is, ConeNodeGL& p);

ostream& operator<<(ostream &o, const ConeNodeGL& p);
