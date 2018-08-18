#ifndef NUMFUNNODE_H_
#define NUMFUNNODE_H_
//NumFunNode.h (C)  Tom White
//holds the final number node, for a double

#include <FunNode/FunNode.h>

class NumFunNode : public FunNode
{
 public:
  NumFunNode();
  NumFunNode(double myVal);
  NumFunNode(NumFunNode &other);
  ~NumFunNode();

  double eval(double t);
 protected:
  double myVal;
};

#endif
