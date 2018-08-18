//TransformNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the TransformNodeGL class declaration.

#include <Point3Df.h>
#include <Transform4Dd.h>
#include <NodeGL/NodeGL.h>

class TransformNodeGL : public NodeGL
{
 public:
  TransformNodeGL();
  TransformNodeGL(Transform4Dd);
  TransformNodeGL(TransformNodeGL&);

  ~TransformNodeGL();

  void ActionGL();

 protected:
  Transform4Dd transform;
  double * transformArr;
};
