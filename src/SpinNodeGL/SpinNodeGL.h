//SpinNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the SpinNodeGL class declaration.

#include <Point3Dd.h>
#include <NodeGL/NodeGL.h>

class SpinNodeGL : public NodeGL
{
 public:
  SpinNodeGL();
  SpinNodeGL(Point3Dd axis,
	      double velocity
	      );
  SpinNodeGL(SpinNodeGL&);

  ~SpinNodeGL();

  void ActionGL();
 protected:
  Point3Dd axis;
  double velocity;
  double currentAngle;
};
