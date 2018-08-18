#ifndef SUMFUNNODE_H_
#define SUMFUNNODE_H_
//SumFunNode.h (C)  Tom White
//sums two nodes

#include <FunNode/FunNode.h>

class SumFunNode : public FunNode
{
 public:
  SumFunNode();
  SumFunNode(FunNode * leftNode, FunNode * rightNode);
  SumFunNode(SumFunNode &other);
  ~SumFunNode();

  double eval(double t);
 protected:
  FunNode * leftNode;
  FunNode * rightNode;
};

#endif
