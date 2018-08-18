// Material.h

// test the graphics package

// (C)  Bill Lenhart

#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include "Point3Df.h"

class Material {
public:  
  Point3Df ambient;    // ambient RGB coefficients
  Point3Df diffuse;    // diffuse RGB coefficients
  Point3Df specular;   // specular RGB coefficients
  float specExp;      // specular exponent
  float reflectivity; // for global illumination
  float transparency; // for global illumination

  // Constructors
  // Default Constructor:  Makes "copper"
  Material();

  // Construct Material using given values
  Material(const Point3Df& amb, const Point3Df& diff,
	   const Point3Df& spec, float specExp,
	   float reflect, float transparent);

  // Copy constructor
  Material(const Material& other);

  // Assignment
  Material& operator=(const Material& other);

  // Destructor
  ~Material();

  // append Material to end of stream

  std::ostream& out(std::ostream& os) const;
    
  // read Material from stream

  std::istream& in(std::istream& is);
};
// friends
// read a Material:  a binary operator
std::istream& operator>>(std::istream& is, Material& m);

// print a Material: a binary operator
std::ostream& operator<<(std::ostream& o, const Material& m);

#endif MATERIAL_H
