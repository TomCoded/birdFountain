// This may look like C code, but it is really -*- C++ -*-

// PlanetNodeGLTest.cc

// (C)  Tom White

#include <cmath>
#include "PlanetNodeGL.h"
#include <MaterialNodeGL/MaterialNodeGL.h>
#include <TransformMaker/TransformMaker.h>

int main() {
  PlanetNodeGL c1;
  cout << c1 << endl;
  PlanetNodeGL c2(c1);
  cout << c2 << endl;
  PlanetNodeGL c3(1.0,1,1);
  cout << c3 << endl;
  c3.out(cout);
  cout << "Enter one:";
  c2.in(cin);
  cout << endl << c2 << endl;
  return 0;
}
