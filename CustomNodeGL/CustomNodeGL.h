#ifndef CUSTOMNODEGL_H_
#define CUSTOMNODEGL_H_
//CustomNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the CustomNodeGL class declaration.

#include <vector>
#include <string>
#include <NodeGL/NodeGL.h>
#include <Point3Dd.h>



class CustomNodeGL : public NodeGL
{
 public:
  CustomNodeGL();
  CustomNodeGL(CustomNodeGL&);
  CustomNodeGL(std::vector<NodeGL *> * NodeGLs,
	       int nID
	       );
  ~CustomNodeGL();

  void ActionGL();

  //  int nGetID();
  std::string szGetName();

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  int nID;
  int nRefCount;
  CustomNodeGL * nextNode;
  CustomNodeGL * lastNode;
  std::string nodeName;
  
  std::vector<NodeGL *> * NodeGLs;

};

std::istream& operator>>(std::istream &is, CustomNodeGL& p);

std::ostream& operator<<(std::ostream &o, const CustomNodeGL& p);

#endif
