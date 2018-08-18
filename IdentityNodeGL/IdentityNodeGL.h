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

  std::istream& in(std::istream&);
  std::ostream& out(std::ostream&) const;

 protected:
};

std::istream& operator>>(std::istream &is, IdentityNodeGL& p);

std::ostream& operator<<(std::ostream &o, const IdentityNodeGL& p);
