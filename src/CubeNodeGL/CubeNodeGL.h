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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  double size;
};

std::istream& operator>>(std::istream &is, CubeNodeGL& p);

std::ostream& operator<<(std::ostream &o, const CubeNodeGL& p);
