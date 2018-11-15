#include <GL/glut.h>
#include <cmath>
#include <math.h>
#include <tgmath.h>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <valarray>
#include "color.h"
#include "Turtle.h"
using namespace std;
void drawPth()
{
    Turtle ab = Turtle();
    ab.drawPath("F-F--F-FF-F--F-FF-F--F-F");
}

int SWidth = 640;
int SHeight = 480;

void initialiseWindow(void);
void registerCalbacks(void);
void initGL(void);
void displayFunc(void);
void drawHome();
void drawPolyLine();


using namespace std;

int main (int argc,char *argv[])
{	
	glutInit(&argc,argv);
	initialiseWindow();
	registerCalbacks();
	initGL();
	glutMainLoop();
}
void initialiseWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(SWidth,SHeight);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Lab-01: Task 1");
}

void registerCalbacks(void)
{
	glutDisplayFunc(displayFunc);
}
void displayFunc()
{
	glClearColor(1,1,1,1.0);			
	//gl ClearColor(R,G,B,Trasparency(a)) ONLY SETS BACKGROUND COLOR
	glLineWidth(4.0);
	glClear(GL_COLOR_BUFFER_BIT);
	// APPLY THE SELECTED COLOR SCHEME FOR BACKGROUND OF WINDOW
	glColor3f(00,0,0);	// SETS FOREGROUND COLOR
	glPointSize(4.0);	
	//drawHome();
	//sine1();
        //drawpoly();
        drawPth();
        //colider();
        //ellipse(-100,20,5);
	glFlush();
}
void initGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
}


