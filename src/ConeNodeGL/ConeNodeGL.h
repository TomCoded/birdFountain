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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  double radius;
  double height;
  int stacks;
  int slices;
};

std::istream& operator>>(std::istream &is, ConeNodeGL& p);

std::ostream& operator<<(std::ostream &o, const ConeNodeGL& p);
