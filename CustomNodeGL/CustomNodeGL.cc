//CustomNodeGL.cc   -*- C++ -*-
//
//(C)  Tom White

#include "CustomNodeGL.h"
#include <Defs.h>
#include <GL/glut.h>
#include <vector>
#include <NodeGL/NodeGL.h>

CustomNodeGL::CustomNodeGL():
  nID(-1),
  NodeGLs(0),
  nRefCount(0),
  nextNode(0),
  lastNode(0),
  nodeName("default")
{}

CustomNodeGL::CustomNodeGL(CustomNodeGL &other):
  nextNode(0)
{
  if(this!=&other)
    {
      nID = other.nID;
      NodeGLs = other.NodeGLs;
      nodeName = other.nodeName;
      CustomNodeGL * finder = &other;
      CustomNodeGL * finger = other.nextNode;
      while(finger)
	{
	  finder = finger;
	  if(finger)
	    finger=finger->nextNode;
	}
      //now finder is the last node using the NodeGL vector
      if(finder->nextNode)
	std::cerr << "WARNING! NODE NON-EMPTY! (CustomNodeGL.cc)\n";
      finder->nextNode=this;
      nRefCount = finder->nRefCount+1;
    }
}

CustomNodeGL::CustomNodeGL(std::vector<NodeGL *> * NodeGLs, int nID):
  NodeGLs(NodeGLs),
  nID(nID),
  nRefCount(0),
  lastNode(0),
  nextNode(0),
  nodeName("default")
{}

CustomNodeGL::~CustomNodeGL()
{
  if((!nextNode)&&(!nRefCount))
    //no other instances of CustomNode are using the same
    //vector
    {
      std::vector<NodeGL *>::iterator itDestroyer = 
	NodeGLs->begin();
      while(itDestroyer != NodeGLs->end())
	{
	  delete (*itDestroyer);
	  itDestroyer++;
	}
    }
  else if(!nRefCount) //there is a next node
    for (CustomNodeGL * finger = nextNode; 
	 finger;
	 finger=finger->nextNode)
      { 
	finger->nRefCount--;
      }
  else if(!nextNode) //there is a reference count
    {
      lastNode->nextNode=0;
    }
}

void CustomNodeGL::ActionGL()
{
  if(nID!=-1) //don't do anything if uninitialized!!!
    for(std::vector <NodeGL *>::iterator itNodes = NodeGLs->begin();
	itNodes!=NodeGLs->end();
	itNodes++)
      {
	(*itNodes)->ActionGL();
      }
}

/*
int CustomNodeGL::nGetID()
{
  return nID;
}
*/

std::string CustomNodeGL::szGetName()
{
  return nodeName;
}

std::ostream & CustomNodeGL::out(std::ostream& o) const
{
  o << nodeName;
  return o;
}

std::istream & CustomNodeGL::in(std::istream& is)
{
  char c;
  is >> nodeName;
  return is;
}

std::istream& operator>>(std::istream &is, CustomNodeGL& p)
{
  return p.in(is);
}

std::ostream& operator<<(std::ostream &o, const CustomNodeGL& p)
{
  return p.out(o);
}
