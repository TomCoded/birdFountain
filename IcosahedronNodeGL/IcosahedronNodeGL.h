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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
};

std::istream& operator>>(std::istream &is, IcosahedronNodeGL& p);

std::ostream& operator<<(std::ostream &o, const IcosahedronNodeGL& p);
