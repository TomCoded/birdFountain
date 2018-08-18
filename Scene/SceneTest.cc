// This may look like C code, but it is really -*- C++ -*-

// SceneTest.cc

// (C)  Tom White

#include "Scene/Scene.h"
#include <unistd.h>
#include <GL/glut.h>

string g_fileName;

int main(int argc, char **argv) {
  //use double-buffering for smooth animation
  int i,j;
  char c='\x00';
  Scene * sc=0;
  while(c!='q')
    {
      cout << "(q)uit, (f)ile:";
      cin >> c;
      if(c=='f')
	{
	  glutInit(&argc, argv);
	  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	  if(sc) delete sc;
	  sc = new Scene();
	  cout << "Enter file name: ";
	  cin >> g_fileName;
	  sc->ReadFile(g_fileName);
	  sc->draw();
	}
    }
  if(sc) delete sc;
  return 0;
}
