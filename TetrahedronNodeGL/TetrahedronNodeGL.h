//TetrahedronNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the TetrahedronNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>

class TetrahedronNodeGL : public NodeGL
{
 public:
  TetrahedronNodeGL();
  TetrahedronNodeGL(TetrahedronNodeGL&);
  ~TetrahedronNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
};

istream& operator>>(istream &is, TetrahedronNodeGL& p);

ostream& operator<<(ostream &o, const TetrahedronNodeGL& p);
