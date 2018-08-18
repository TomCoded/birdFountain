#include "SumFunNode.h"
//SumFunNode.h (C)  Tom White
//sums two nodes

SumFunNode::SumFunNode():
  leftNode(0),
  rightNode(0)
{}

//destroys on exit
SumFunNode::SumFunNode(FunNode * leftNode, FunNode * rightNode):
  leftNode(leftNode),
  rightNode(rightNode)
{}

//using this guy is a bad idea
SumFunNode::SumFunNode(SumFunNode &other)
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

SumFunNode::~SumFunNode() 
{
  if(leftNode)
    delete leftNode;
  if(rightNode)
    delete rightNode;
}

double SumFunNode::eval(double t) 
{
  return (leftNode->eval(t)+rightNode->eval(t));
}
