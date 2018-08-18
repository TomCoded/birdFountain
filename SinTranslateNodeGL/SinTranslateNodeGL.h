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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
  double amplitude;
  Point3Dd translation;

  //kept in radians
  double start;
  double current;
  double velocity;  
};

std::istream& operator>>(std::istream &is, SinTranslateNodeGL& p);

std::ostream& operator<<(std::ostream &o, const SinTranslateNodeGL& p);
