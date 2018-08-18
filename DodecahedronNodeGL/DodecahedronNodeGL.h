//DodecahedronNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the DodecahedronNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>

class DodecahedronNodeGL : public NodeGL
{
 public:
  DodecahedronNodeGL();
  DodecahedronNodeGL(DodecahedronNodeGL&);
  ~DodecahedronNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
};

istream& operator>>(istream &is, DodecahedronNodeGL& p);

ostream& operator<<(ostream &o, const DodecahedronNodeGL& p);
