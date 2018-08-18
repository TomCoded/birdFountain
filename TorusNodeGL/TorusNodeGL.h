//TorusNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the TorusNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>
//#include <TransformMaker/TransformMaker.h>

class TorusNodeGL : public NodeGL
{
 public:
  TorusNodeGL();
  TorusNodeGL(TorusNodeGL&);
  TorusNodeGL(//Transform4Dd planetTransform,
	      //MaterialNodeGL planetMaterial,
	      double smallRadius,
	      double largeRadius,
	       int slices,
	       int stacks
	       );
  ~TorusNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
  double smallRadius;
  double largeRadius;
  int stacks;
  int slices;
};

istream& operator>>(istream &is, TorusNodeGL& p);

ostream& operator<<(ostream &o, const TorusNodeGL& p);
