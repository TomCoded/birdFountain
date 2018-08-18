//NodeGL.cpp   -*- C++ -*-
//
//(C)  Tom White
//  Holds the NodeGL class code.

#include "NodeGL.h"

NodeGL::NodeGL() {}

NodeGL::NodeGL(NodeGL&) {}

NodeGL::~NodeGL() {}

void NodeGL::ActionGL() {}

int NodeGL::setWireFrame(int n) 
{
  int temp=wireFrame;
  wireFrame=n;
  return (temp!=wireFrame);
}
