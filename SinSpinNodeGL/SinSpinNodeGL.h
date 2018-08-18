#ifndef SINSPINNODEGL_H_
#define SINSPINNODEGL_H_

//SinSpinNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the SinSpinNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>
#include <Point3Dd.h>

class SinSpinNodeGL : public NodeGL
{
 public:
  SinSpinNodeGL();
  SinSpinNodeGL(SinSpinNodeGL&);
  SinSpinNodeGL(Point3Dd axis,
		double amplitude,
		double start, //start at degrees=start
		double velocity //degrees per frame
		);
  ~SinSpinNodeGL();

  void ActionGL();

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  double amplitude;
  Point3Dd axis;

  //kept in radians
  double start;
  double current;
  double velocity;  
};

std::istream& operator>>(std::istream &is, SinSpinNodeGL& p);

std::ostream& operator<<(std::ostream &o, const SinSpinNodeGL& p);
#endif
