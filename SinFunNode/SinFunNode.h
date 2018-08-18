#ifndef SINFUNNODE_H_
#define SINFUNNODE_H_
//SinFunNode.h (C)  Tom White
//returns sin(node)

#include <FunNode/FunNode.h>

class SinFunNode : public FunNode
{
 public:
  SinFunNode();
  SinFunNode(FunNode * childNode);
  SinFunNode(SinFunNode &other);
  ~SinFunNode();

  double eval(double t);
 protected:
  FunNode * childNode;
};

#endif
