// This may look like C code, but it is really -*- C++ -*-

// Scene.cc

// (C)  Tom White

#include <iostream>
#include <string>
#include <TransformMaker/TransformMaker.h>
#include <GL/glut.h>
#include "Scene.h"
#include <Point3Dd.h>
#include <Point3Df.h>
#include <Defs.h>
#include <functions/functions.h>
#include <PopNodeGL/PopNodeGL.h>
#include <MaterialNodeGL/MaterialNodeGL.h>
#include <PlanetNodeGL/PlanetNodeGL.h>
#include <TransformNodeGL/TransformNodeGL.h>
#include <OrbitNodeGL/OrbitNodeGL.h>
#include <SpinNodeGL/SpinNodeGL.h>
#include <OrientNodeGL/OrientNodeGL.h>
#include <TorusNodeGL/TorusNodeGL.h>
#include <TeapotNodeGL/TeapotNodeGL.h>
#include <CubeNodeGL/CubeNodeGL.h>
#include <IcosahedronNodeGL/IcosahedronNodeGL.h>
#include <OctahedronNodeGL/OctahedronNodeGL.h>
#include <TetrahedronNodeGL/TetrahedronNodeGL.h>
#include <DodecahedronNodeGL/DodecahedronNodeGL.h>
#include <ConeNodeGL/ConeNodeGL.h>
#include <RotateNodeGL/RotateNodeGL.h>
#include <SinTranslateNodeGL/SinTranslateNodeGL.h>
#include <SinSpinNodeGL/SinSpinNodeGL.h>
#include <CustomNodeGL/CustomNodeGL.h>
#include <IdentityNodeGL/IdentityNodeGL.h>
#include <FunTranslateNodeGL/FunTranslateNodeGL.h>
#include <FunOrientNodeGL/FunOrientNodeGL.h>
#include <FunTransformNodeGL/FunTransformNodeGL.h>

#ifdef DIFFUSE
#undef DIFFUSE
#endif

#define BADFORMAT(s) \
{ \
std::cerr << "Input file syntax error: " << s << std::endl; \
exit(1); \
}

extern std::string g_fileName;
Scene * g_Scene;
int g_nSpeed;

////////////////////
// class Scene //
////////////////////

// A scene 
//

// essentials

// default constructor
Scene::Scene():
  currentCamera(0),
  width(200),
  height(200)
{
  cameras = new std::vector<Camera *>();
  NodeGLs = new std::vector<NodeGL *>();
  LightNodeGLs = new std::vector<LightNodeGL *>();
  CustomNodeGLs = new std::vector<CustomNodeGL *>();
  myLightIDs = GetLightArray(); 
  lmodel_ambient[0]=lmodel_ambient[1]=lmodel_ambient[2]=0.2;
  lmodel_ambient[3]=1.0;
  g_Scene=this;
  g_nSpeed=FAST;
}

// destructor
Scene::~Scene() 
{
  delete myLightIDs;

  std::vector<Camera *>::iterator itCDestroyer = cameras->begin();
  while(itCDestroyer != cameras->end() )
    {
      delete (*itCDestroyer);
      itCDestroyer++;
    }

  std::vector<NodeGL *>::iterator itNDestroyer = NodeGLs->begin();
  while(itNDestroyer != NodeGLs->end())
    {
      delete (*itNDestroyer);
      itNDestroyer++;
    }

  std::vector<CustomNodeGL *>::iterator itDestroyer = CustomNodeGLs->begin();
  while(itDestroyer != CustomNodeGLs->end())
    {
      delete (*itDestroyer);
      itDestroyer++;
    }

  std::vector<LightNodeGL *>::iterator itLNDestroyer = LightNodeGLs->begin();
  while(itLNDestroyer != LightNodeGLs->end())
    {
      delete (*itLNDestroyer);
      itLNDestroyer++;
    }
  //delete vectors
  delete cameras;
  delete NodeGLs;
  delete LightNodeGLs;
}

//flush existing info and read new file
void Scene::newfile() 
{
  std::vector<Camera *>::iterator itCDestroyer = cameras->begin();
  while(itCDestroyer != cameras->end() )
    {
      delete (*itCDestroyer);
      itCDestroyer++;
    }

  std::vector<NodeGL *>::iterator itNDestroyer = NodeGLs->begin();
  while(itNDestroyer != NodeGLs->end())
    {
      delete (*itNDestroyer);
      itNDestroyer++;
    }
  std::vector<CustomNodeGL *>::iterator itDestroyer = CustomNodeGLs->begin();
  while(itDestroyer != CustomNodeGLs->end())
    {
      delete (*itDestroyer);
      itDestroyer++;
    }

  std::vector<LightNodeGL *>::iterator itLNDestroyer = LightNodeGLs->begin();
  while(itLNDestroyer != LightNodeGLs->end())
    {
      delete (*itLNDestroyer);
      itLNDestroyer++;
    }
  currentCamera=0;;
  width=200;
  height=200;
  lmodel_ambient[0]=lmodel_ambient[1]=lmodel_ambient[2]=0.2;
  lmodel_ambient[3]=1.0;
  g_nSpeed=FAST;
  delete cameras;
  delete NodeGLs;
  delete LightNodeGLs;
  delete CustomNodeGLs;
  CustomNodeGLs = new std::vector<CustomNodeGL *>();
  cameras = new std::vector<Camera *>();
  NodeGLs = new std::vector<NodeGL *>();
  LightNodeGLs = new std::vector<LightNodeGL *>();
  std::cerr << "Enter file name: ";
  std::cin >> g_fileName;
  ReadFile(g_fileName);
  glutReshapeWindow(width,height);
  initWindowInfo();
  glutMainLoop();
}

//flush existing info and read new file
void Scene::reload() 
{
  std::vector<Camera *>::iterator itCDestroyer = cameras->begin();
  while(itCDestroyer != cameras->end() )
    {
      delete (*itCDestroyer);
      itCDestroyer++;
    }

  std::vector<NodeGL *>::iterator itNDestroyer = NodeGLs->begin();
  while(itNDestroyer != NodeGLs->end())
    {
      delete (*itNDestroyer);
      itNDestroyer++;
    }
  std::vector<CustomNodeGL *>::iterator itDestroyer = CustomNodeGLs->begin();
  while(itDestroyer != CustomNodeGLs->end())
    {
      delete (*itDestroyer);
      itDestroyer++;
    }

  std::vector<LightNodeGL *>::iterator itLNDestroyer = LightNodeGLs->begin();
  while(itLNDestroyer != LightNodeGLs->end())
    {
      delete (*itLNDestroyer);
      itLNDestroyer++;
    }
  currentCamera=0;;
  width=200;
  height=200;
  lmodel_ambient[0]=lmodel_ambient[1]=lmodel_ambient[2]=0.2;
  lmodel_ambient[3]=1.0;
  g_nSpeed=FAST;
  delete cameras;
  delete NodeGLs;
  delete LightNodeGLs;
  delete CustomNodeGLs;
  CustomNodeGLs = new std::vector<CustomNodeGL *>();
  cameras = new std::vector<Camera *>();
  NodeGLs = new std::vector<NodeGL *>();
  LightNodeGLs = new std::vector<LightNodeGL *>();
  ReadFile(g_fileName);
  glutReshapeWindow(width,height);
  initWindowInfo();
  glutMainLoop();
}

// Scene features
void Scene::ReadFile(std::string fileName) {
  //  std::string fileName;
  int nDoingCustom=false;

  std::vector<NodeGL *> * masterList = NodeGLs; //to hold regular one when
  //CustomNodeGL is being created

  int numSurfaces = 0;
  int numLights = 0;
  int lastLight = 0;

  char c; //scratch

  //  std::cerr << "Enter file name: ";
  //  std::cin >> fileName;

  // create an input filestream
  ifstream inFile(fileName.c_str());

  int wireFrame=0;

  // check for success of stream constructor
  if(!inFile) { // could not open file
    std::cerr << "Could not open file: " << fileName << "; exiting...";
    exit(1);
  }

  // read in contents
  std::string keyword;
  inFile >> keyword;
  while(!inFile.eof()) {
    if(keyword == "numSurfaces") {
      inFile >> numSurfaces;
      //      std::cerr << "numSurfaces = " << numSurfaces << std::endl;
    }
    else if(keyword == "include") {
      std::string name;
      inFile >> name;
      ReadFile(name);
    }
    else if(keyword == "wireframe") {
      std::string onOrOff;
      inFile >> onOrOff;
      if(onOrOff=="on")
	wireFrame=true;
      else if(onOrOff=="off")
	wireFrame=false;
      else
	{
	  std::cerr << "wireFrame keyword syntax error\n";
	  exit(1);
	}
    }
    else if(keyword == "numLights") {
      inFile >> numLights;
      if(numLights > GL_MAX_LIGHTS)
	{
	  std::cerr << "openGL on this machine only supports "
	       << GL_MAX_LIGHTS << " light sources.\n";
	}
      //      std::cerr << "numLights = " << numLights << std::endl;
    }
    else if(keyword == "windowDims") {
      inFile >> c;
      if(c!='(') BADFORMAT("( not in windowDims (,)")
      inFile >> height;
      inFile >> c;
      if(c!=',') BADFORMAT(", not in windowDims (,)")
      inFile >> width;
      inFile >> c;
      if(c!=')') BADFORMAT(") not in windowDims (,)")
    }
    else if(keyword == "camera") {
      Camera * cam = new Camera();
      cam->in(inFile);
      addCamera(cam);
    }
    else if(keyword == "sceneAmbient") {
      Point3Dd d;
      inFile >> d;
      lmodel_ambient[0]=d.x;
      lmodel_ambient[1]=d.y;
      lmodel_ambient[2]=d.z;
      lmodel_ambient[3]=1;
    }
    else if(keyword == "identity") 
      NodeGLs->push_back(new IdentityNodeGL());
    else if(keyword == "pointLight") {
      Point3Df loc;
      Point3Df ambient,diffuse,specular;
      char c;
      inFile >> c;
      if(c!='(')
	{
	  std::cerr << "Bad Format for pointLight\n";
	  exit(1);
	}
      inFile >> loc >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for pointLight\n";
	  exit(1);
	}
      inFile >> ambient >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for pointLight\n";
	  exit(1);
	}
      inFile >> diffuse >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for pointLight\n";
	  exit(1);
	}     
      inFile >> specular;
      skipDescription(inFile);
      LightNodeGL * tempNode = 
	new LightNodeGL(ambient,
			diffuse,
			specular,
			Point4Df(loc,1.0),
			myLightIDs[lastLight++]
			);
      LightNodeGLs->push_back(tempNode);
    }
    else if(keyword == "dirLight") {
      Point3Df direction,ambient,diffuse,specular;
      char c;
      inFile >> c;
      if(c!='(')
	{
	  std::cerr << "Bad Format for Directional Light\n";
	  exit(1);
	}
      inFile >> direction >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for Directional Light\n";
	  exit(1);
	}
      inFile >> ambient >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for Directional Light\n";
	  exit(1);
	}
      inFile >> diffuse >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for Directional Light\n";
	  exit(1);
	}     
      inFile >> specular;
      skipDescription(inFile);
      LightNodeGL * tempNode = 
	new LightNodeGL(ambient,
			diffuse,
			specular,
			Point4Df(direction,0.0),
			myLightIDs[lastLight++]
			);
      tempNode->ActionGL();
      LightNodeGLs->push_back(tempNode);
    }
    else if(keyword == "orient") {
      char c; 
      Point3Dd fromAxis;
      Point3Dd toAxis;
      inFile >> c;
      if(c!='(')
	{
	  std::cerr << "Bad Format for Orient\n";
	  exit(1);
	}
      inFile >> fromAxis >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for Orient\n";
	  exit(1);
	}
      inFile >> toAxis >> c;
      if(c!=')')
	{
	  std::cerr << "Bad Format for Orient\n";
	  exit(1);
	}
      NodeGLs->push_back(new OrientNodeGL(fromAxis,toAxis));
    }
    else if(keyword == "spin") {
      char c; Point3Dd axis; double velocity;
      inFile >> c;
      if(c!='(')
	{
	  std::cerr << "Bad Format for spin\n";
	  exit(1);
	}
      inFile >> axis >> c;
      if(c!=',')
	{
	  std::cerr << "Bad Format for spin\n";
	  exit(1);
	}
      inFile >> velocity >> c;
      if(c!=')')
	{
	  std::cerr << "Bad Format for spin\n";
	  exit(1);
	}
      NodeGLs->push_back(new SpinNodeGL(axis,velocity));
    }
    else if(keyword == "orbit") {
      double startAngle, velocity, distance;
      char ch;
      //      inFile >> startAngle >> velocity >> distance;
      inFile >> ch;
      if(ch!='(')
	{
	  std::cerr << "bad format for Orbit\n";
	  break;
	}
      inFile >> startAngle;
      inFile >> ch;
      if(ch!=',')
	{
	  std::cerr << "Bad format for Orbit\n";
	  break;
	}
      inFile >> velocity;
      inFile >> ch;
      if(ch!=',')
	{
	  std::cerr << "Bad format for Orbit\n";
	  break;
	}      
      inFile >> distance;
      inFile >> ch;
      if(ch!=')')
	{
	  std::cerr << "Bad format for Orbit\n";
	  break;
	}      
      //in the x-y plane
      NodeGLs->push_back(new OrbitNodeGL(startAngle,velocity,distance));
    }
    else if(keyword == "rotate") {
      char ch; double a; Point3Dd d;
      inFile >> ch;
      if(ch!='(')
	{
	  std::cerr << "bad format for rotation\n";
	  break;
	}
      inFile >> a;
      inFile >> ch;
      if(ch!=',')
	{
	  std::cerr << "Bad format for rotation\n";
	  break;
	}
      inFile >> d;
      inFile >> ch;
      if(ch!=')')
	{
	  std::cerr << "Bad format for rotation\n";
	  break;
	}
      RotateNodeGL * myNode = 
	new RotateNodeGL(a,d);
      NodeGLs->push_back(myNode);
    }
    else if(keyword == "sphere") {
      char c; int stacks, slices; double planetRadius;
      inFile >> c;
      if(c != '(')
	{
	  std::cerr << "Bad format for PlanetNodeGL: " << c << std::endl;
	  exit(1);
	}
      inFile >> planetRadius >> c;
      if(c != ',')
	{
	  std::cerr << "Bad format for PlanetNodeGL !,\n";
	  exit(1);
	}
      inFile >> slices >> c;
      if(c != ',')
	{
	  std::cerr << "Bad format for PlanetNodeGL !,2\n";
	  exit(1);
	}
      inFile >> stacks >> c;
      if(c != ')')
	{
	  std::cerr << "Bad format for PlanetNodeGL !)\n";
	  exit(1);
	}
      PlanetNodeGL * myPlanet =
	new PlanetNodeGL(
			 planetRadius,
			 slices,
			 stacks);
      myPlanet->setWireFrame(wireFrame);
      NodeGLs->push_back(myPlanet);
    }
    else if(keyword == "spotLight") {
      std::cerr << "spotLight ";
      std::cerr << "skipping parameters..." << std::endl;
      skipDescription(inFile);
    }
    else if(keyword == "material") {
      MaterialNodeGL * myMat =
	new MaterialNodeGL();
      inFile >> (*myMat);
      NodeGLs->push_back(myMat);
    }
    else if(keyword == "pop")
      NodeGLs->push_back(new PopNodeGL());
    else if(keyword == "translate") {
      Point3Dd Translate;
      inFile >> Translate;
      NodeGLs->push_back(new TransformNodeGL(MakeTranslation(Translate)));
    }
    else if(keyword == "scale") {
      Point3Dd scale;
      inFile >> scale;
      NodeGLs->push_back(new TransformNodeGL(MakeScale(scale)));
    }
    else if(keyword == "transform") {
      Transform4Dd lUserTransform;
      inFile >> lUserTransform;
      TransformNodeGL * myNode = new TransformNodeGL(lUserTransform);
      NodeGLs->push_back(myNode);
    }
    else if(keyword == "torus") {
      TorusNodeGL * myTorus = new TorusNodeGL();
      inFile >> (*myTorus);
      myTorus->setWireFrame(wireFrame);
      NodeGLs->push_back(myTorus);
    }
    else if(keyword == "cube") {
      CubeNodeGL * myCube = new CubeNodeGL();
      inFile >> (*myCube);
      myCube->setWireFrame(wireFrame);
      NodeGLs->push_back(myCube);
    }
    else if(keyword == "teapot") {
      TeapotNodeGL * myTeapot = new TeapotNodeGL();
      inFile >> (*myTeapot);
      myTeapot->setWireFrame(wireFrame);
      NodeGLs->push_back(myTeapot);
    }
    else if(keyword == "icosahedron") {
      IcosahedronNodeGL * myGreekNode = new IcosahedronNodeGL();
      myGreekNode->setWireFrame(wireFrame);
      NodeGLs->push_back(myGreekNode);
    }
    else if(keyword == "octahedron") {
      OctahedronNodeGL * myGreekNode = new OctahedronNodeGL();
      myGreekNode->setWireFrame(wireFrame);
      NodeGLs->push_back(myGreekNode);
    }
    else if(keyword == "tetrahedron") {
      TetrahedronNodeGL * myGreekNode = new TetrahedronNodeGL();
      myGreekNode->setWireFrame(wireFrame);
      NodeGLs->push_back(myGreekNode);
    }
    else if(keyword == "dodecahedron") {
      DodecahedronNodeGL * myGreekNode = new DodecahedronNodeGL();
      myGreekNode->setWireFrame(wireFrame);
      NodeGLs->push_back(myGreekNode);
    }
    else if(keyword == "cone") {
      ConeNodeGL * myConeNode = new ConeNodeGL();
      inFile >> (*myConeNode);
      myConeNode->setWireFrame(wireFrame);
      NodeGLs->push_back(myConeNode);
    }
    else if(keyword == "sintranslation") {
      SinTranslateNodeGL * mySinTrans
	= new SinTranslateNodeGL();
      inFile >> (*mySinTrans);
      NodeGLs->push_back(mySinTrans);
    }
    else if(keyword == "sinspin")
      {
	SinSpinNodeGL * mySinSpin
	  = new SinSpinNodeGL();
	inFile >> (*mySinSpin);
	NodeGLs->push_back(mySinSpin);
      }
    else if(keyword == "P(t)")
      {
	FunTranslateNodeGL *
	  myFunTranslateNodeGL
	  = new FunTranslateNodeGL();
	inFile >> (*myFunTranslateNodeGL);
	NodeGLs->push_back(myFunTranslateNodeGL);
      }
    else if(keyword == "orient(t)")
      {
	FunOrientNodeGL * myFunOrientNodeGL
	  = new FunOrientNodeGL();
	inFile >> (*myFunOrientNodeGL);
	NodeGLs->push_back(myFunOrientNodeGL);
      }
    else if(keyword == "matrix(t)")
      {
	FunTransformNodeGL * myFunTransformNodeGL
	  = new FunTransformNodeGL();
	inFile >> (*myFunTransformNodeGL);
	NodeGLs->push_back(myFunTransformNodeGL);
      }
    else if(keyword == "custom")
      {
	if(nDoingCustom)
	  {
	    std::cerr << "Cannot define custom item while defining custom item\n";
	    exit(1);
	  }
	nDoingCustom = true;
	NodeGLs = new std::vector<NodeGL *>();
      }
    else if(keyword == "endcustom")
      {
	int nID = 1; //tells Custom
	numCustoms++;
	CustomNodeGL * myCustomNodeGL
	  = new CustomNodeGL(NodeGLs,
			     nID);
	inFile >> (*myCustomNodeGL);
	CustomNodeGLs->push_back(myCustomNodeGL);
	nDoingCustom=false;
	NodeGLs = masterList;
      }
    else if(keyword == "insertcustom")
      {
	std::string szNodeName;
	inFile >> szNodeName;
	std::vector<CustomNodeGL *>::iterator itCust = 
	  CustomNodeGLs->begin();
	while(itCust != CustomNodeGLs->end())
	  {
	    if((*itCust)->szGetName()==szNodeName)
	      {
		CustomNodeGL * myCust = 
		  new CustomNodeGL(*(*itCust));
		NodeGLs->push_back(myCust);
		break;
	      }
	    itCust++;
	  }
      }
    else if(keyword.substr(0,2) == "//") { 
      // If keyword starts with '//', it's a comment
      // snazzy way to skip rest of line
      inFile.ignore(1000,'\n'); // skip up to and including next end-of-line
    }
    else {
      std::cerr << "Unrecognized keyword: " << keyword << "  Exiting..." << std::endl;
      exit(1);
    }
    inFile >> keyword;
  }

  inFile.close();

  getCamera()->setSampleDims(height,width);
  if(NodeGLs!=masterList)
    {
      std::cerr << "unclosed custom node\n";
      NodeGLs=masterList;
    }
}

void Scene::setWindowSize(int x, int y)
{
  width=x;
  height=y;
}

int Scene::getWindowWidth()
{ return width; }

int Scene::getWindowHeight()
{ return height; }

void Scene::draw()
{
  glutInitWindowSize(width, height);
  glutInitWindowPosition(100,100);
  //create window
  glutCreateWindow("The Scene:");
  //initialize window
  initWindowInfo();
  glutMainLoop();
}

//returns a pointer to a vector of all NodeGL's in the scene
std::vector<NodeGL *> * Scene::getNodeGLs()
{
  return NodeGLs;
}

//returns a pointer to the current camera
Camera * Scene::getCamera()
{
  if(cameras->begin()) return (*(cameras->begin()));
  else return 0;
}

//adds a camera to the scene
void Scene::addCamera(Camera * camera)
{
  cameras->push_back(camera);
  currentCamera = cameras->size();
}

//Window intializer, for AFTER the window is created
void Scene::initWindowInfo(void)
{
  double bgRed=0.0; double bgGreen=0.0; double bgBlue=0.0;
  // clear background
  glClearColor(bgRed, bgGreen, bgBlue, 0.0f);
  glColor3f(0.0f,1.0f,0.0f);
  
  //set up camera here
  Camera * myCam;
  if(!(myCam=getCamera()))
    {
      Point4Dd eye(3.0,3.0,4.0,1.0);
      Point4Dd lookAt(0.0,0.0,0.0,1.0);
      Point4Dd up(0.0,1.0,0.0,0.0);
      double vvFieldOfView = 90;
      double vvNear = 1.0;
      double vvFar=80.0;
      myCam = new Camera(eye,
			 lookAt,
			 up,
			 vvFieldOfView*3.14159/180,
			 double(width)/double(height),
			 vvNear,
			 vvFar
			 );
      addCamera(myCam);
      std::cerr << "Creating a default camera.\n";
    }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(myCam->eye.x, myCam->eye.y, myCam->eye.z,
	    myCam->lookAt.x, myCam->lookAt.y, myCam->lookAt.z,
	    myCam->up.x, myCam->up.y, myCam->up.z
	    );

  //register callback functions
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);

  glEnable(GL_LIGHTING);
  glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER,1);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

 if(LightNodeGLs->size())
   {
     int i=0;
     std::vector<LightNodeGL *>::iterator itLightNodeGLs =
       LightNodeGLs->begin();
     while(itLightNodeGLs != LightNodeGLs->end())
       {
	 (*itLightNodeGLs)->ActionGL();
	 itLightNodeGLs++;
       }
   }
 glShadeModel(GL_SMOOTH);
 glEnable(GL_DEPTH_TEST);
 glEnable(GL_NORMALIZE); 
 
 //create menu
 glutCreateMenu(menu);
 glutAddMenuEntry("Slow",MENU0_SLOW);
 glutAddMenuEntry("Fast",MENU0_FAST);
 glutAddMenuEntry("-----------------",0);
 glutAddMenuEntry("Slower (than now)",MENU0_SLOWER);
 glutAddMenuEntry("Faster (than now)",MENU0_FASTER);
 glutAddMenuEntry("-----------------",0);
 glutAddMenuEntry("Advance Frame",MENU0_ADVANCE);
 glutAddMenuEntry("Pause/Resume",MENU0_PAUSE);
 glutAddMenuEntry("-----------------",0);
 glutAddMenuEntry("Reload File",MENU0_RELOAD);
 glutAddMenuEntry("New File",MENU0_NEWFILE);
 glutAddMenuEntry("Quit",MENU0_QUIT);
 
 //attach button to menu
 glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

// skip the parameters of any non-implemented scene file feature
// assumes that parameter lists are either single strings w/o white space
// or properly parenthetically nested
ifstream& Scene::skipDescription(ifstream& ifFile) {
  char input;

  if(!ifFile.eof()) {
    ifFile >> input;
    // There are two choices for (non-empty) descriptions
    // either it starts with a left paren...
    if(input == '(') {
      int  count = 1;
      while(!ifFile.eof() && count > 0) {
	ifFile >> input;
	switch(input) {
	case '(' :
	  count++;
	  break;
	case ')' :
	  count--;
	  break;
	default :
	  break;
	}
      }
    }
    // ..or it consists of a single string
    else
      while(!ifFile.eof() && !isspace(ifFile.peek())) ifFile.get();
  }

  return ifFile;
}






