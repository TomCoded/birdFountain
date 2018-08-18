//functions/functions.cc -*- C++ -*-
//(C)  Tom White
//Constains general helper functions, and openGL callbacks.

#include "functions.h"
#include <limits.h>
#include <GL/glut.h>
#include <Defs.h>
#include <vector.h>
#include <NodeGL/NodeGL.h>
#include <Scene/Scene.h>
#include <TransformMaker/TransformMaker.h>

#define ROVAL 0.3

extern Scene * g_Scene;
extern int g_nSpeed;

//function: GetArray
// parameters: &t is a Transform4Dd.
// Return values: returns a 16 double array, row after row.
//  calling function must later deallocate memory.

double * GetArray(Transform4Dd &t)
{
  double * rv = new double[16]; 
  int i, j;
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
      rv[i*4+j]=t.entry(j,i);
  return rv;
}


#define MAXHARDCODEDLIGHTS 32

  //the minimum required support is for 8 lights.
#ifndef GL_LIGHT8 
#define GL_LIGHT8 0
#ifndef GL_LIGHT9
#define GL_LIGHT9 0
#ifndef GL_LIGHT10
#define GL_LIGHT10 0
#ifndef GL_LIGHT11
#define GL_LIGHT11 0
#ifndef GL_LIGHT12
#define GL_LIGHT12 0
#ifndef GL_LIGHT13
#define GL_LIGHT13 0
#ifndef GL_LIGHT14
#define GL_LIGHT14 0
#ifndef GL_LIGHT15
#define GL_LIGHT15 0
#ifndef GL_LIGHT16
#define GL_LIGHT16 0
#ifndef GL_LIGHT17
#define GL_LIGHT17 0
#ifndef GL_LIGHT18
#define GL_LIGHT18 0
#ifndef GL_LIGHT19
#define GL_LIGHT19 0
#ifndef GL_LIGHT20
#define GL_LIGHT20 0
#ifndef GL_LIGHT21
#define GL_LIGHT21 0
#ifndef GL_LIGHT22
#define GL_LIGHT22 0
#ifndef GL_LIGHT23
#define GL_LIGHT23 0
#ifndef GL_LIGHT24
#define GL_LIGHT24 0
#ifndef GL_LIGHT25
#define GL_LIGHT25 0
#ifndef GL_LIGHT26
#define GL_LIGHT26 0
#ifndef GL_LIGHT27
#define GL_LIGHT27 0
#ifndef GL_LIGHT28
#define GL_LIGHT28 0
#ifndef GL_LIGHT29
#define GL_LIGHT29 0
#ifndef GL_LIGHT30
#define GL_LIGHT30 0
#ifndef GL_LIGHT31
#define GL_LIGHT31 0
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif


//function: GetLightArray()
// returns an array of OpenGL Light ID's,
//  up to MAXHARDCODEDLIGHTS of them.
// The calling function must later deallocate memory.
int * GetLightArray()
{
  int maxLights = GL_MAX_LIGHTS;
  if(maxLights>=MAXHARDCODEDLIGHTS) maxLights=MAXHARDCODEDLIGHTS;
  int i=0;
  int * rv = new int[maxLights];
  if(i!=maxLights) { rv[i++]=GL_LIGHT0;
  if(i!=maxLights) { rv[i++]=GL_LIGHT1;
  if(i!=maxLights) { rv[i++]=GL_LIGHT2;
  if(i!=maxLights) { rv[i++]=GL_LIGHT3;
  if(i!=maxLights) { rv[i++]=GL_LIGHT4;
  if(i!=maxLights) { rv[i++]=GL_LIGHT5;
  if(i!=maxLights) { rv[i++]=GL_LIGHT6;
  if(i!=maxLights) { rv[i++]=GL_LIGHT7;
  if(i!=maxLights) { rv[i++]=GL_LIGHT8;
  if(i!=maxLights) { rv[i++]=GL_LIGHT9;
  if(i!=maxLights) { rv[i++]=GL_LIGHT10;
  if(i!=maxLights) { rv[i++]=GL_LIGHT11;
  if(i!=maxLights) { rv[i++]=GL_LIGHT12;
  if(i!=maxLights) { rv[i++]=GL_LIGHT13;
  if(i!=maxLights) { rv[i++]=GL_LIGHT14;
  if(i!=maxLights) { rv[i++]=GL_LIGHT15;
  if(i!=maxLights) { rv[i++]=GL_LIGHT16;
  if(i!=maxLights) { rv[i++]=GL_LIGHT17;
  if(i!=maxLights) { rv[i++]=GL_LIGHT18;
  if(i!=maxLights) { rv[i++]=GL_LIGHT19;
  if(i!=maxLights) { rv[i++]=GL_LIGHT20;
  if(i!=maxLights) { rv[i++]=GL_LIGHT21;
  if(i!=maxLights) { rv[i++]=GL_LIGHT22;
  if(i!=maxLights) { rv[i++]=GL_LIGHT23;
  if(i!=maxLights) { rv[i++]=GL_LIGHT24;
  if(i!=maxLights) { rv[i++]=GL_LIGHT25;
  if(i!=maxLights) { rv[i++]=GL_LIGHT26;
  if(i!=maxLights) { rv[i++]=GL_LIGHT27;
  if(i!=maxLights) { rv[i++]=GL_LIGHT28;
  if(i!=maxLights) { rv[i++]=GL_LIGHT29;
  if(i!=maxLights) { rv[i++]=GL_LIGHT30;
  if(i!=maxLights) { rv[i++]=GL_LIGHT31;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
  return rv;
}

//GL Callback functions:

//The menu callback procedure
void menu(int choice)
{
  switch(choice)
    {
    case MENU0_QUIT:
      exit(0);
      break;
    case MENU0_SLOW:
      g_nSpeed=SLOW;
      break;
    case MENU0_SLOWER:
      if ((INT_MAX - g_nSpeed) >= INTERVAL)
	g_nSpeed+=INTERVAL;
      break;
    case MENU0_FAST:
      g_nSpeed=FAST;
      break;
    case MENU0_FASTER:
      g_nSpeed-=INTERVAL;
      if(g_nSpeed < 0)
	g_nSpeed=0;
      break;
    case MENU0_PAUSE:
      if(g_nSpeed!=-1) g_nSpeed=-1;
      else g_nSpeed=0;
      break;
    case MENU0_ADVANCE:
      glutPostRedisplay();
      break;
    case MENU0_NEWFILE:
      g_Scene->newfile();
      break;
    case MENU0_RELOAD:
      g_Scene->reload();
      break;
    default:
      break;
    }
}

//The GLUT window idle callback procedure
void idle(void)
{
  static int n=0;
  if(g_nSpeed) //if speed is not fast
    {
      if(g_nSpeed!=-1) //if ! frozen
	{
	  n++;
	  if((n % g_nSpeed)==0)
	    {
	      n=0;
	      glutPostRedisplay();
	    }
	}
    }
  else glutPostRedisplay();
}

//The GLUT window keyboard callback procedure
void keyboard(unsigned char key, int x, int y)
{
  int changeCamera=false;
  Camera * myCam = g_Scene->getCamera();
  Point4Dd temp4 = myCam->lookAt.normalize();
  double cval=0;
  switch(key)
    {
      //pause and frame advance
    case 'f': glutPostRedisplay(); //output frame
      break;
    case 's': 
      if(g_nSpeed != -1) g_nSpeed=-1; // pause key
      else g_nSpeed = 0;
      break;
      //camera
    case 'i':
      changeCamera=true;
      myCam->eye-=myCam->n;
      break;
    case 'o':
      changeCamera=true;
      myCam->eye+=myCam->n;
      break;
    case 'r':
      changeCamera=true;
      myCam->eye-=myCam->u;
      break;
    case 'l':
      changeCamera=true;
      myCam->eye+=myCam->u;
      break;
    case 'u':
      changeCamera=true;
      myCam->eye-=myCam->v;
      break;
    case 'd':
      changeCamera=true;
      myCam->eye+=myCam->v;
      break;
    case 't': //roll left
      changeCamera=true;
      myCam->rotate(ROVAL,0,0,1);
      break;
    case 'T': //roll right
      changeCamera=true;
      myCam->rotate(-ROVAL,0,0,1);
      break;
    case 'y': //yaw left
      changeCamera=true;
      myCam->rotate(ROVAL,0,1,0);
      break;
    case 'Y': //yaw right
      changeCamera=true;
      myCam->rotate(-ROVAL,0,1,0);
      break;
    case 'P': //Pitch up
      changeCamera=true;
      myCam->rotate(ROVAL,1,0,0);
      break;
    case 'p': //pitch down
      changeCamera=true;
      myCam->rotate(-ROVAL,1,0,0);
      break;
    case 'q': exit(0);
      break;
    default: break;
    }

  if(changeCamera)
    { //the camera has changed
      Camera * myCam = g_Scene->getCamera();
      myCam->resetCameraTransform();
      glMatrixMode(GL_MODELVIEW);
      glLoadMatrixd(myCam->wld2Camgl);
    }
}

//The GLUT window mouse callback procedure
void mouse(int button, int state, int x, int y)
{
  if((button==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN))
    {
      if(g_nSpeed != -1) g_nSpeed=-1; // pause key
      else g_nSpeed = 0;
    }
}

//The GLUT window resize callback function
void reshape(GLsizei scr_w, GLsizei scr_h)
{
  //set the viewport
  glViewport(0,0,scr_w,scr_h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  Camera * myCam = g_Scene->getCamera();
  myCam->aspectRatio = double(scr_w)/double(scr_h);
  myCam->setCameraCoordSys();
  gluPerspective(myCam->viewAngle*180/3.1415926536,
		 myCam->aspectRatio,
		 -myCam->near,
		 -myCam->far
		 );
}

//The GLUT window display callback function
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  vector <NodeGL *> * NodeGLs = g_Scene->getNodeGLs();
  for(vector <NodeGL *>::iterator itNodes = NodeGLs->begin();
      itNodes!=NodeGLs->end();
      itNodes++)
    {
      (*itNodes)->ActionGL();
    }
  glutSwapBuffers();
  glFlush();
}









