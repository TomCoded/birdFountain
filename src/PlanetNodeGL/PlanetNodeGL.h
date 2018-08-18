//PlanetNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the PlanetNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <iostream>
//#include <MaterialNodeGL/MaterialNodeGL.h>
//#include <TransformMaker/TransformMaker.h>

class PlanetNodeGL : public NodeGL
{
 public:
  PlanetNodeGL();
  PlanetNodeGL(PlanetNodeGL&);
  PlanetNodeGL(//Transform4Dd planetTransform,
	       //	       MaterialNodeGL planetMaterial,
	       double planetRadius,
	       int slices,
	       int stacks
	       );
  ~PlanetNodeGL();

  //  void setInfo(//Transform4Dd &planetTransform,
	       //	       MaterialNodeGL &planetMaterial
  //	       );

  void ActionGL();

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  //  Transform4Dd planetTransform;
  //  MaterialNodeGL planetMaterial;
  double planetRadius;
  int stacks;
  int slices;
};

std::istream& operator>>(std::istream &is, PlanetNodeGL& p);

std::ostream& operator<<(std::ostream &o, const PlanetNodeGL& p);
