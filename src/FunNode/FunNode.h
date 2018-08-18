#ifndef FUNNODE_H_
#define FUNNODE_H_
//FunNode.h (C)  Tom White
//Holds interface for all function classes

class FunNode
{
 public:
  FunNode();
  FunNode(FunNode &other);
  ~FunNode();

  virtual double eval(double t)=0;
 protected:
};

#endif
