//CubeNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the CubeNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>
//#include <TransformMaker/TransformMaker.h>

class CubeNodeGL : public NodeGL
{
 public:
  CubeNodeGL();
  CubeNodeGL(CubeNodeGL&);
  CubeNodeGL(double size);
  ~CubeNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
  double size;
};

istream& operator>>(istream &is, CubeNodeGL& p);

ostream& operator<<(ostream &o, const CubeNodeGL& p);
