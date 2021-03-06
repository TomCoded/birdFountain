#include "DivFunNode.h"
//DivFunNode.h (C)  Tom White
//does leftnode / rightnode
//returns leftnode /0.00001 on div by zero

DivFunNode::DivFunNode():
  leftNode(0),
  rightNode(0)
{}

//destroys on exit
DivFunNode::DivFunNode(FunNode * leftNode, FunNode * rightNode):
  leftNode(leftNode),
  rightNode(rightNode)
{}

//using this guy is a bad idea
DivFunNode::DivFunNode(DivFunNode &other)
{
  if(this!=&other)
    {
      if(leftNode)
	{
	  delete leftNode;
	}
      if(rightNode)
	{
	  delete rightNode;
	}
      leftNode=other.leftNode;
      rightNode=other.rightNode;
    }
}

DivFunNode::~DivFunNode() 
{
  if(leftNode)
    delete leftNode;
  if(rightNode)
    delete rightNode;
}

double DivFunNode::eval(double t) 
{
  double temp = rightNode->eval(t);
  if(temp==0) temp = 0.00001;
  return (leftNode->eval(t)/temp);
}
