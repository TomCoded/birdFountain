//OrientNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the OrientNodeGL class declaration.

#include <Point3Dd.h>
#include <Transform4Dd.h>
#include <NodeGL/NodeGL.h>

class OrientNodeGL : public NodeGL
{
 public:
  OrientNodeGL();

  OrientNodeGL(Point3Dd fromAxis,
	       Point3Dd toAxis
	      );

  OrientNodeGL(OrientNodeGL&);

  ~OrientNodeGL();

  void ActionGL();
 protected:
  Point3Dd fromAxis, toAxis;
  Point3Dd rotateAxis;
  double currentAngle;
  double velocity;
};
