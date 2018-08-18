//PopNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the PopNodeGL class declaration.

#include <NodeGL/NodeGL.h>

class PopNodeGL : public NodeGL
{
 public:
  PopNodeGL();
  PopNodeGL(PopNodeGL&);
  ~PopNodeGL();

  void ActionGL();
 protected:
};
