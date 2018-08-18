//TeapotNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the TeapotNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>
//#include <TransformMaker/TransformMaker.h>

class TeapotNodeGL : public NodeGL
{
 public:
  TeapotNodeGL();
  TeapotNodeGL(TeapotNodeGL&);
  TeapotNodeGL(double size);
  ~TeapotNodeGL();

  void ActionGL();

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  double size;
};

std::istream& operator>>(std::istream &is, TeapotNodeGL& p);

std::ostream& operator<<(std::ostream &o, const TeapotNodeGL& p);
