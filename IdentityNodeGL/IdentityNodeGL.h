//IdentityNodeGL.h  -*- C++ -*-
//
//(C)  Tom White
// Holds the IdentityNodeGL class declaration.

#include <NodeGL/NodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>

class IdentityNodeGL : public NodeGL
{
 public:
  IdentityNodeGL();
  IdentityNodeGL(IdentityNodeGL&);
  ~IdentityNodeGL();

  void ActionGL();

  istream& in(istream&);
  ostream& out(ostream&) const;

 protected:
};

istream& operator>>(istream &is, IdentityNodeGL& p);

ostream& operator<<(ostream &o, const IdentityNodeGL& p);
