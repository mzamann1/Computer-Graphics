// LAB1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "glut.h"
#include "iostream"

using  namespace std;
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.9f, 0.9f, 0.9f, 0.0);

	glColor3f(1, 0, 0);
	glFlush();
}


int main(int argc, char **argv)
{
	/*glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(30, 30);
	glutCreateWindow("HT First OGL Program");
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	glBegin(GL_LINE);
	glVertex2i(3, 3);
	glVertex2i(8, 8);
	glColor3b(1, 1, 1);
	glEnd();
	glutMainLoop();
	*/

	glBegin(GL_LINE_LOOP);
	glVertex2i(10, 10);
	glVertex2i(40, 10);
	glVertex2i(40, 30);
	glVertex2i(25, 40);
	glVertex2i(10, 30);
	glEnd();


    return 0;
}

