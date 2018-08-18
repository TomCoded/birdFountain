#include "CosFunNode.h"
//CosFunNode.h (C)  Tom White
//does cos(childNode)

#include <math.h>

CosFunNode::CosFunNode():
  childNode(0)
{}

//destroys on exit
CosFunNode::CosFunNode(FunNode * childNode):
  childNode(childNode)
{}

//using this guy is a bad idea
CosFunNode::CosFunNode(CosFunNode &other)
{
  if(this!=&other)
    {
      if(childNode)
	delete childNode;
      childNode=other.childNode;
    }
}

CosFunNode::~CosFunNode() 
{
  if(childNode)
    delete childNode;
}

double CosFunNode::eval(double t) 
{
  return cos(childNode->eval(t));
}
