#ifndef VARFUNNODE_H_
#define VARFUNNODE_H_
//VarFunNode.h (C)  Tom White
//holds the final Function node, where eval(t)=t

#include <FunNode/FunNode.h>

class VarFunNode : public FunNode
{
 public:
  VarFunNode();
  VarFunNode(VarFunNode &other);
  ~VarFunNode();

  double eval(double t);
 protected:
};

#endif
