//IcosahedronNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the IcosahedronNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>

class IcosahedronNodeGL : public NodeGL
{
 public:
  IcosahedronNodeGL();
  IcosahedronNodeGL(IcosahedronNodeGL&);
  ~IcosahedronNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
};

istream& operator>>(istream &is, IcosahedronNodeGL& p);

ostream& operator<<(ostream &o, const IcosahedronNodeGL& p);
