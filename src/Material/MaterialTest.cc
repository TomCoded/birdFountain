// This may look like C code, but it is really -*- C++ -*-

// MaterialTest.cc

// (C) 1995 Anonymous1

#include <cmath> // Home of the "pow(x,y)" function
#include "Material/Material.h"

int main() {

  Material m1, m2(Point3Df(0.3,0.4,0.3), // ambient
		  Point3Df(0.4,0.5,0.1), // diffuse
		  Point3Df(0.5,0.7,0.6), // specular
		  2.3, // specular exponent
		  0.7, // reflectivity
		  0.1);// transparency

  std::cout << m1 << std::endl;
  if(m1.reflectivity >.6)
    std::cout << "Shiny!" << std::endl;
  else
    std::cout << "Dull..." << std::endl;
  if(m1.transparency >.6)
    std::cout << "See-through!" << std::endl;
  else
    std::cout << "Opaque..." << std::endl;

  std::cout << m2 << std::endl;
  if(m2.reflectivity >.6)
    std::cout << "Shiny!" << std::endl;
  else
    std::cout << "Dull..." << std::endl;
  if(m2.transparency >.6)
    std::cout << "See-through!" << std::endl;
  else
    std::cout << "Opaque..." << std::endl;


  Point3Df lightSrcAmbInt(0.4,0.1,0.5);
  Point3Df lightSrcDiffInt(0.5,0.5,0.5);
  Point3Df lightSrcSpecInt(0.6,0.6,0.6);

  std::cout << "Assuming light direction is parallel to surface normal &" << std::endl;
  std::cout << "angle of reflection of light and eye are at 45 degrees," << std::endl;
  std::cout << "m1 and m2 produce these colors respectively:" << std::endl;

  Point3Df m1Intensity = m1.ambient*lightSrcAmbInt +
    m1.diffuse*lightSrcDiffInt*1 + 
    m1.specular*lightSrcSpecInt*pow(.5,m1.specExp);

  Point3Df m2Intensity = m2.ambient*lightSrcAmbInt +
    m2.diffuse*lightSrcDiffInt*1 + 
    m2.specular*lightSrcSpecInt*pow(.5,m2.specExp);

  std::cout << "m1: " << m1Intensity << std::endl;
  std::cout << "m2: " << m2Intensity << std::endl;
}
