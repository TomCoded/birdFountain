//PlanetNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the PlanetNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <iostream.h>
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

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
  //  Transform4Dd planetTransform;
  //  MaterialNodeGL planetMaterial;
  double planetRadius;
  int stacks;
  int slices;
};

istream& operator>>(istream &is, PlanetNodeGL& p);

ostream& operator<<(ostream &o, const PlanetNodeGL& p);
