#include "RotateNodeGL.h"
#include "Defs.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <sstream>
#include <GL/glut.h>
#include <math.h>

bool operator== (const Point3Dd& p1, const Point3Dd& p2) {
  return (p1.x==p2.x) && (p1.y==p2.y) && (p1.y==p2.y);
}

namespace {
  class RotateNodeGLTest : public ::testing::Test {
  protected:
    RotateNodeGLTest() {
      mat = new RotateNodeGL();
    }

    ~RotateNodeGLTest() override {
      delete mat;
    }

    RotateNodeGL * mat;

    Point3Dd makePoint(float f) {
      return Point3Dd(f, f, f);
    }

    RotateNodeGL * makeRotateNodeGL(float f) {
      Point3Dd halfPoint=makePoint(f);
      return new RotateNodeGL(3.14, halfPoint);
    }

    std::string testString = std::string("((0.329412,0.223529,0.027451),27.8974)");
  };

  void printMatrix(double *matrix) {
    for(int i=0; i<4; i++) {
      std::cout << "[ ";
      for(int j=0; j<4; j++) {
	std::cout << matrix[4*i+j];
	if(j<3) std::cout << ", ";
      }
      std::cout << " ]\n";
    }
    std::cout << std::endl;
  }
  
}

TEST_F(RotateNodeGLTest,defaultConstructor) {
  RotateNodeGL myMat;
}

TEST_F(RotateNodeGLTest,constructorWithValues) {
  RotateNodeGL * myMat = makeRotateNodeGL(0.5);
  delete myMat;
}

TEST_F(RotateNodeGLTest,copyConstructor) {
  RotateNodeGL myMat;
  RotateNodeGL newMat(myMat);
}

TEST_F(RotateNodeGLTest,ActionGL) {
  char *myargv [1];
  int myargc=1;
  myargv [0]=strdup ("test");
  
  glutInit(&myargc, myargv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowSize(200,200);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Testing:");
  
  double bgRed, bgBlue, bgGreen;
  bgRed=bgBlue=bgGreen=0.0;
  glClearColor(bgRed, bgGreen, bgBlue, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f);

  constexpr double PI=3.1415926535897932384626433832795;
  //amazingly, openGL uses degrees instead of radians.
  double theta=180/2.0;
  RotateNodeGL * myMat =
    new RotateNodeGL(theta,Point3Dd(0.0,1.0,0.0));
  GLdouble matrixBefore[16];
  GLdouble matrixAfter[16];
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glGetDoublev(GL_MODELVIEW_MATRIX,matrixBefore);
  
  GLenum err=glGetError();
  EXPECT_NE(err,GL_INVALID_ENUM);
  EXPECT_EQ(err,GL_NO_ERROR);

  myMat->ActionGL();
  glGetDoublev(GL_MODELVIEW_MATRIX,matrixAfter);
  EXPECT_EQ(matrixBefore,matrixBefore);
  EXPECT_NE(matrixBefore,matrixAfter);

  //homogenized rotation about the y axis should be
  // cos(theta) 0 sin(theta) 0
  // 0          1 0          0
  // -sin(theta) 0 cos(theta) 0
  // 0          0  0         1

  EXPECT_LT(matrixAfter[0],0.1);
  EXPECT_GT(matrixAfter[0],-0.1);
  EXPECT_LT(matrixAfter[1],0.1);
  EXPECT_GT(matrixAfter[1],-0.1);
  EXPECT_LT(matrixAfter[2],-0.9);
  EXPECT_GT(matrixAfter[2],-1.1);
  EXPECT_LT(matrixAfter[3],0.1);
  EXPECT_GT(matrixAfter[3],-0.1);
}
