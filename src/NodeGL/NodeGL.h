//NodeGL.h     -*- C++ -*-
//
//(C)  Tom White
// Holds the NodeGL class declaration.
//  It is a virtual class.

#ifndef NODEGL_H_
#define NODEGL_H_

class NodeGL
{
public:
  NodeGL();
  NodeGL(NodeGL&);
  ~NodeGL();

  //runs a series of openGL actions
  virtual void ActionGL() = 0;

  //sets this object to wireframe or non-wireframe
  //returns 1 if status changed.
  int setWireFrame(int n);

protected:
  int wireFrame;
};

#endif
