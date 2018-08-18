//RotateNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the RotateNodeGL class declaration.

#include <Point3Dd.h>
#include <NodeGL/NodeGL.h>

class RotateNodeGL : public NodeGL
{
 public:
  RotateNodeGL();
  RotateNodeGL(double currentAngle,
	       Point3Dd axis
	      );
  RotateNodeGL(RotateNodeGL&);

  ~RotateNodeGL();

  void ActionGL();
 protected:
  Point3Dd axis;
  double currentAngle;
};
