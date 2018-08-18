// This may look like C code, but it is really -*- C++ -*-

// Scene.h

// (C)  Anonymous1
// Modified  Tom White
// (C)  Tom White

#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include <vector>
#include <string>
#include <Point3Dd.h>
#include <GL/glut.h>
#include <NodeGL/NodeGL.h>
#include <LightNodeGL/LightNodeGL.h>
#include <Camera/Camera.h>
#include <CustomNodeGL/CustomNodeGL.h>

////////////////////
// class Scene //
////////////////////

// A scene container 
//

class Scene {

public:

  // essentials

  // default constructor
  Scene();

  // destructor
  ~Scene();

  // Scene Procedures

  // Read contents of a scene file, skipping over unimplemented features
  void ReadFile(std::string fileName);

  void setWindowSize(int x, int y);

  //tells myRenderer to draw the scene
  void draw();

  //Scene Functions
  std::vector<NodeGL *> * getNodeGLs();
  Camera * getCamera();
  int getWindowWidth();
  int getWindowHeight();
  
  //renderer keeps its own copy; be sure to update
  //if one renderer is handling multiple scenes.  (Ha!)
  Point3Dd ambient;

  //Window intializer, for AFTER the window is created
  void initWindowInfo(void);

  //deletes existing scene information and reads a new file.
  void newfile(); 
  void reload(); 

protected:
  int numCustoms; //number of custom Nodes in the scene

  //Our scene should have information about the graphics window being
  //used.
  int width;
  int height;
  
  //An array of type GLLIGHT[0-n] where n is GL_MAX_LIGHTS
  int * myLightIDs;

  //A list of all the camera available
  std::vector<Camera *> * cameras;
  std::vector<LightNodeGL *> * LightNodeGLs;
  int currentCamera;

  //We want a vector of all NodeGL objects; we refer to them by
  //pointers because they are actually derived objects.
  std::vector<NodeGL *> * NodeGLs;

  //A list of the Custom nodes
  std::vector<CustomNodeGL *> * CustomNodeGLs;

  //helper functions.  We keep these around to provide an abstraction
  //layer in case we want to change implementation later.  Also, they
  //make code prettier.
  void addCamera(Camera *);

private:
  GLfloat lmodel_ambient[4];

  // skip the parameters of any non-implemented scene file feature
  // assumes that parameter lists are either single strings w/o white space
  // or properly parenthetically nested
  std::ifstream& skipDescription(std::ifstream& ifs);
};

#endif SCENE_H




