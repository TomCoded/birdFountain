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

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
  double size;
};

istream& operator>>(istream &is, TeapotNodeGL& p);

ostream& operator<<(ostream &o, const TeapotNodeGL& p);
