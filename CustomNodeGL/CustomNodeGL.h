#ifndef CUSTOMNODEGL_H_
#define CUSTOMNODEGL_H_
//CustomNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the CustomNodeGL class declaration.

#include <vector.h>
#include <string>
#include <NodeGL/NodeGL.h>
#include <Point3Dd.h>



class CustomNodeGL : public NodeGL
{
 public:
  CustomNodeGL();
  CustomNodeGL(CustomNodeGL&);
  CustomNodeGL(vector<NodeGL *> * NodeGLs,
	       int nID
	       );
  ~CustomNodeGL();

  void ActionGL();

  //  int nGetID();
  string szGetName();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
  int nID;
  int nRefCount;
  CustomNodeGL * nextNode;
  CustomNodeGL * lastNode;
  string nodeName;
  
  vector<NodeGL *> * NodeGLs;

};

istream& operator>>(istream &is, CustomNodeGL& p);

ostream& operator<<(ostream &o, const CustomNodeGL& p);

#endif
