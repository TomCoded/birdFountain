//OctahedronNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the OctahedronNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>

class OctahedronNodeGL : public NodeGL
{
 public:
  OctahedronNodeGL();
  OctahedronNodeGL(OctahedronNodeGL&);
  ~OctahedronNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
};

istream& operator>>(istream &is, OctahedronNodeGL& p);

ostream& operator<<(ostream &o, const OctahedronNodeGL& p);
