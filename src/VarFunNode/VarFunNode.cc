#include "VarFunNode.h"
//VarFunNode.h (C)  Tom White
//holds the final function node, where eval(t)=t

VarFunNode::VarFunNode() {}

VarFunNode::VarFunNode(VarFunNode &other)
{}

VarFunNode::~VarFunNode() {}

double VarFunNode::eval(double t) 
{
  return t;
}
