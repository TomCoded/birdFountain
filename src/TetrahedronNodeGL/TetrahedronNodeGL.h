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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
};

std::istream& operator>>(std::istream &is, TetrahedronNodeGL& p);

std::ostream& operator<<(std::ostream &o, const TetrahedronNodeGL& p);
