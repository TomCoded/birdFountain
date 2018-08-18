#include "MultFunNode.h"
//MultFunNode.h (C)  Tom White
//multiplies two nodes

MultFunNode::MultFunNode():
  leftNode(0),
  rightNode(0)
{}

//destroys on exit
MultFunNode::MultFunNode(FunNode * leftNode, FunNode * rightNode):
  leftNode(leftNode),
  rightNode(rightNode)
{}

//using this guy is a bad idea
MultFunNode::MultFunNode(MultFunNode &other)
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

MultFunNode::~MultFunNode() 
{
  if(leftNode)
    delete leftNode;
  if(rightNode)
    delete rightNode;
}

double MultFunNode::eval(double t) 
{
  return (leftNode->eval(t)*rightNode->eval(t));
}
