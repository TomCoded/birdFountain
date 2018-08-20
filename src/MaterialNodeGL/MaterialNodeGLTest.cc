#include "MaterialNodeGL.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Defs.h"

bool operator== (const Point3Df& p1, const Point3Df& p2) {
  return (p1.x==p2.x) && (p1.y==p2.y) && (p1.y==p2.y);
}

namespace {
  class MaterialNodeGLTest : public ::testing::Test {
  protected:
    MaterialNodeGLTest() {
      mat = new MaterialNodeGL();
    }

    ~MaterialNodeGLTest() override {
      delete mat;
    }

    MaterialNodeGL * mat;

    Point3Df makePoint(float f) {
      return Point3Df(f, f, f);
    }

    MaterialNodeGL * makeMaterialNodeGL(float f) {
      Point3Df halfPoint=makePoint(f);
      return new MaterialNodeGL(halfPoint, halfPoint,
				halfPoint, f);
    }
    
  };
}

TEST_F(MaterialNodeGLTest,defaultConstructor) {
  MaterialNodeGL myMat;
}

TEST_F(MaterialNodeGLTest,constructorWithValues) {
  Point3Df halfPoint=makePoint(0.5);
  MaterialNodeGL * myMat = makeMaterialNodeGL(0.5);
}

TEST_F(MaterialNodeGLTest,copyConstructor) {
}

TEST_F(MaterialNodeGLTest,clone) {
}

TEST_F(MaterialNodeGLTest, in) {
  std::string testString("((0.329412,0.223529,0.027451),(0.780392,0.568627,0.113725),(0.992157,0.941176,0.807843),27.8974)");
  std::istringstream testStream(testString);
  mat->in(testStream);
  srand48(24);
}

TEST_F(MaterialNodeGLTest, out) {
  std::string testString("((0.329412, 0.223529, 0.027451),(0.780392, 0.568627, 0.113725),(0.992157, 0.941176, 0.807843),27.8974)");
  //std::string testString("((0.329412, 0.223529, 0.027451),(0.780392, 0.568627, 0.113725),(0.992157, 0.941176, 0.807843),27.8974,42.42,42.42)");
  std::istringstream testStream(testString);
  mat->in(testStream);
  std::ostringstream outStream;
  std::ostream *oStreamOut = (std::ostream*)&outStream;
  mat->out(*oStreamOut);
  std::string output;
  output = outStream.str();
  EXPECT_EQ(output,testString);
}
