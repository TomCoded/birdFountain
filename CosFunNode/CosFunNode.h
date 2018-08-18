#ifndef COSFUNNODE_H_
#define COSFUNNODE_H_
//CosFunNode.h (C)  Tom White
//returns cos(childNode)

#include <FunNode/FunNode.h>

class CosFunNode : public FunNode
{
 public:
  CosFunNode();
  CosFunNode(FunNode * childNode);
  CosFunNode(CosFunNode &other);
  ~CosFunNode();

  double eval(double t);
 protected:
  FunNode * childNode;
};

#endif
