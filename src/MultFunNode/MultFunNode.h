#ifndef MULTFUNNODE_H_
#define MULTFUNNODE_H_
//MultFunNode.h (C)  Tom White
//multiplies two nodes

#include <FunNode/FunNode.h>

class MultFunNode : public FunNode
{
 public:
  MultFunNode();
  MultFunNode(FunNode * leftNode, FunNode * rightNode);
  MultFunNode(MultFunNode &other);
  ~MultFunNode();

  double eval(double t);
 protected:
  FunNode * leftNode;
  FunNode * rightNode;
};

#endif
