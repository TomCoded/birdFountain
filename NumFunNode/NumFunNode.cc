#include "NumFunNode.h"
//NumFunNode.h (C)  Tom White
//holds the final function node, for a double

NumFunNode::NumFunNode() {}

NumFunNode::NumFunNode(double myVal):
  myVal(myVal)
{}

NumFunNode::NumFunNode(NumFunNode &other)
{}

NumFunNode::~NumFunNode() {}

double NumFunNode::eval(double t) 
{
  return myVal;
}
