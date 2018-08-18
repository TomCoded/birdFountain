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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  double smallRadius;
  double largeRadius;
  int stacks;
  int slices;
};

std::istream& operator>>(std::istream &is, TorusNodeGL& p);

std::ostream& operator<<(std::ostream &o, const TorusNodeGL& p);
