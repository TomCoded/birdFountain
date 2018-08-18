#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <Transform4Dd.h>
#include <GL/glut.h>

double * GetArray(Transform4Dd &);

int * GetLightArray();

//GL Callback functions:

//The menu callback procedure
void menu(int choice);
//The GLUT window idle callback procedure
void idle(void);
//The GLUT window keyboard callback procedure
void keyboard(unsigned char key, int x, int y);
//The GLUT window mouse callback procedure
void mouse(int button, int state, int x, int y);
//The GLUT window resize callback function
void reshape(GLsizei scr_w, GLsizei scr_h);
//The GLUT window display callback function
void display(void);

#endif FUNCTIONS_H_
