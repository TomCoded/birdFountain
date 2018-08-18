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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
};

std::istream& operator>>(std::istream &is, OctahedronNodeGL& p);

std::ostream& operator<<(std::ostream &o, const OctahedronNodeGL& p);
