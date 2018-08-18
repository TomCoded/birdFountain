#include "SinFunNode.h"
//SinFunNode.h (C)  Tom White
//does sin(childNode)

SinFunNode::SinFunNode():
  childNode(0)
{}

//destroys on exit
SinFunNode::SinFunNode(FunNode * childNode):
  childNode(childNode)
{}

//using this guy is a bad idea
SinFunNode::SinFunNode(SinFunNode &other)
{
  if(this!=&other)
    {
      if(childNode)
	delete childNode;
      childNode=other.childNode;
    }
}

SinFunNode::~SinFunNode() 
{
  if(childNode)
    delete childNode;
}

double SinFunNode::eval(double t) 
{
  return sin(childNode->eval(t));
}
