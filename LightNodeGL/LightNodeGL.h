//LightNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the LightNodeGL class declaration.

#include <Point3Df.h>
#include <Point4Df.h>
#include <Transform4Dd.h>
#include <NodeGL/NodeGL.h>

class LightNodeGL : public NodeGL
{
 public:
  LightNodeGL();
  LightNodeGL(Point3Df ambient,
	      Point3Df diffuse,
	      Point3Df specular,
	      Point4Df position,
	      int LightID
	      );

  LightNodeGL(LightNodeGL&);

  ~LightNodeGL();

  void ActionGL();

 protected:
  Point3Df ambient, diffuse, specular;
  Point4Df position;
  int LightID;
};



