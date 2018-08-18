//OrbitNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the OrbitNodeGL class declaration.

#include <Point3Df.h>
#include <Transform4Dd.h>
#include <NodeGL/NodeGL.h>

class OrbitNodeGL : public NodeGL
{
 public:
  OrbitNodeGL();
  OrbitNodeGL(double currentAngle,
	      double velocity,
	      double distance
	      );
  OrbitNodeGL(OrbitNodeGL&);

  ~OrbitNodeGL();

  void ActionGL();
 protected:
  double currentAngle;
  double velocity;
  double distance;
};
