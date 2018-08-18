#ifndef POWFUNNODE_H_
#define POWFUNNODE_H_
//PowFunNode.h (C)  Tom White
//holds the final Function node, where eval(t)=t

#include <FunNode/FunNode.h>

class PowFunNode : public FunNode
{
 public:
  PowFunNode();
  PowFunNode(FunNode * leftNode, FunNode * rightNode);
  PowFunNode(PowFunNode &other);
  ~PowFunNode();

  double eval(double t);
 protected:
  FunNode * leftNode;
  FunNode * rightNode;
};

#endif
