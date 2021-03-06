// Sierpinski.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "glut.h"


void initialiseWindow();
void registerCallbacks();
void initGL();


class GLintPoint{
public:
	GLint x, y;
};

int random(void)
{
	///return
		int a=rand()%3;
	return a;
}
void drawDot(GLint x, GLint y)
{
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void Sierpinski(void)
{
	GLintPoint T[3] = { {10,10},{300,30},{200,300} };

	int index = random();
	GLintPoint point = T[index];
	drawDot(point.x, point.y);
	for (int i = 0; i < 100; i++)
	{
		index = random();
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
	glFlush();
}


void disp_func()
{
	glClearColor(1, 1, 1, 0);
	glFlush();
}
void initialiseWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Sine Wave");

}



void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0); //background color
	glColor3f(0.0f, 0.0f, 0.0f); //foreground color = black
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500); //gluOrtho2D() routine sets the transformation we need for a screen window that is 500 pixels wide by 500 pixels high.
	//glOrtho(-10, 10, -10, 10, -10, 10); //uncomment this for sin wave and comment gluOrtho2D() line.

	//you can only do one work, sinwave or graph, means you can only use either gluOrtho2D() or glOrtho();s
}

void registerCallbacks(void)
{
	//glutDisplayFunc(disp_func);
	glutDisplayFunc(Sierpinski);
	//glutMouseFunc(myFunc);
}

void initGL(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //background color
	glColor3f(0.0f, 0.0f, 0.0f); //foreground color = black
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	//gluOrtho2D(0.0000, 0.9504, 1.0000, 0.0000);

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	initialiseWindow();
	registerCallbacks();
	initGL();
	glutMainLoop();

}


