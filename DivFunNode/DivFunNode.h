#ifndef DIVFUNNODE_H_
#define DIVFUNNODE_H_
//DivFunNode.h (C)  Tom White
//does leftnode / rightnode
//returns leftnode / 0.00001 on divide by zero

#include <FunNode/FunNode.h>

class DivFunNode : public FunNode
{
 public:
  DivFunNode();
  DivFunNode(FunNode * leftNode, FunNode * rightNode);
  DivFunNode(DivFunNode &other);
  ~DivFunNode();

  double eval(double t);
 protected:
  FunNode * leftNode;
  FunNode * rightNode;
};

#endif
