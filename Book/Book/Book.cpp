// Book.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "glut.h"
//#include "glu.h"

void drawpoints()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(100, 50);
	glVertex2i(100, 130);
	glVertex2i(150, 130);
	glEnd();

	glFlush();
}

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640.0, 0, 480.0);
	glClearColor(1, 1, 1, 1);
	glColor3i(0, 0, 0);
	glPointSize(4);

}

// appropriate #includes go here – see Appendix 1
void main(int argc, char** argv)
{
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(640, 480); // set window size
	glutInitWindowPosition(100, 150); // set the window position on screen
	glutCreateWindow("my first attempt"); // open the screen window
	// register the callback functions
	glutDisplayFunc(drawpoints);
/*	glutReshapeFunc(myReshape);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	*/
	myInit(); // additional initializations as necessary
	glutMainLoop(); // go into a perpetual loop
}