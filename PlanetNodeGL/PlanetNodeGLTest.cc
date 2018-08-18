// This may look like C code, but it is really -*- C++ -*-

// PlanetNodeGLTest.cc

// (C)  Tom White

#include <cmath>
#include "PlanetNodeGL.h"
#include <MaterialNodeGL/MaterialNodeGL.h>
#include <TransformMaker/TransformMaker.h>

int main() {
  PlanetNodeGL c1;
  std::cout << c1 << std::endl;
  PlanetNodeGL c2(c1);
  std::cout << c2 << std::endl;
  PlanetNodeGL c3(1.0,1,1);
  std::cout << c3 << std::endl;
  c3.out(std::cout);
  std::cout << "Enter one:";
  c2.in(std::cin);
  std::cout << std::endl << c2 << std::endl;
  return 0;
}
