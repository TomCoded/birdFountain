// Material.cc

// test the graphics package

// (C)  Anonymous1

#include "Material/Material.h"

//////////////////////
// class Material   //
//////////////////////

//Constructors
// Copper is default material
Material::Material() :
  ambient(0.19125f, 0.07355f, 0.0225f),
  diffuse(0.7038f, 0.27048f, 0.0828f),
  specular(0.256777f, 0.137622f, 0.086014f),
  specExp(12.8f), reflectivity(0.0f), transparency(0.0f)
{}

// Construct Material using given values
Material::Material(const Point3Df& amb, const Point3Df& diff,
		   const Point3Df& spec, float specExp,
		   float reflect, float transparent) :
  ambient(amb), diffuse(diff), specular(spec), specExp(specExp),
  reflectivity(reflect), transparency(transparent)
{}

// Copy constructor
Material::Material(const Material& other) {
  *this = other;
}

Material& Material::operator=(const Material& other) {
  if (this != &other) {
    ambient=other.ambient;
    diffuse=other.diffuse;
    specular=other.specular;
    specExp=other.specExp;
    reflectivity=other.reflectivity;
    transparency=other.transparency;
  }
  return *this;
}

Material::~Material() {}

// append point to end of stream

std::ostream& Material::out(std::ostream& os) const {
  os << "(" << ambient << "," << diffuse << "," << specular << "," <<
    specExp << ", " << reflectivity << ", " << transparency << ")";
  return os;
}

// read array from stream

std::istream& Material::in(std::istream& is) {
  char c;
  is >> c;
  if (c != '(') {
    std::cout << "Bad format for Point3Df" << std::endl;
    exit(1);
  }
  is >> ambient >> c;
  if (c != ',') {
    std::cout << "Bad format for Point3Df" << std::endl;
    exit(1);
  }
  is >> diffuse >> c;
  if (c != ',') {
    std::cout << "Bad format for Point3Df" << std::endl;
    exit(1);
  }
  is >> specular >> c;
  if (c != ',') {
    std::cout << "Bad format for Point3Df" << std::endl;
    exit(1);
  }
  is >> specExp >> c;
  if (c != ')') {
    std::cout << "Bad format for float" << std::endl;
    exit(1);
  }
  is >> reflectivity >> c;
  if (c != ')') {
    std::cout << "Bad format for float" << std::endl;
    exit(1);
  }
  is >> transparency >> c;
  if (c != ')') {
    std::cout << "Bad format for float" << std::endl;
    exit(1);
  }
  return is;
}

// friends
// read a Material:  a binary operator
std::istream& operator>>(std::istream& is, Material& m)
{
  m.in(is);
}

// print a Material: a binary operator
std::ostream& operator<<(std::ostream& o, const Material& m)
{
  return m.out(o);
}
