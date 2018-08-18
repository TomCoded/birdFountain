//SinTranslateNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the SinTranslateNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>
#include <Point3Dd.h>

class SinTranslateNodeGL : public NodeGL
{
 public:
  SinTranslateNodeGL();
  SinTranslateNodeGL(SinTranslateNodeGL&);
  SinTranslateNodeGL(Point3Dd translation,
		     double amplitude,
		     double start, //start at degrees=start
		     double velocity //degrees per frame
		     );
  ~SinTranslateNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
  double amplitude;
  Point3Dd translation;

  //kept in radians
  double start;
  double current;
  double velocity;  
};

istream& operator>>(istream &is, SinTranslateNodeGL& p);

ostream& operator<<(ostream &o, const SinTranslateNodeGL& p);
