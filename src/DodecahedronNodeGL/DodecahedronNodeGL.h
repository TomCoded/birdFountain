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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
};

std::istream& operator>>(std::istream &is, DodecahedronNodeGL& p);

std::ostream& operator<<(std::ostream &o, const DodecahedronNodeGL& p);
