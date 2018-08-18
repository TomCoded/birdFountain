//XFormNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the XFormNodeGL class declaration.

#include <NodeGL.h>

class XFormNodeGL : public NodeGL
{
 public:
  XFormNodeGL();
  XFormNodeGL(XFormNodeGL&);
  ~XFormNodeGL();

  ActionGL();
 protected:
};
