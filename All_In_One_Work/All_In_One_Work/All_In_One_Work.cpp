// Lsab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "fstream"
#include <glut.h>
#include "Pen.h"


using namespace std;

int sw = 500, sh = 500, flag = 0;
int p_x, p_y;

class GLintPoint {

public:
	GLint x, y;
};

void initialiseWindow();
void registerCallbacks();
void initGL();

void initialiseWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(sw, sh);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Sine Wave");

}
void drawPolyLineFile()
{
	
	fstream  inStream;
	inStream.open("r3.txt", ios::in);
	if (inStream.fail())
	{
		return;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpoly, numPoints;
	GLfloat x, y;
	inStream >> numpoly;
	glColor3f(0.5, 0.5, 0.5);

	for (int j = 0; j < numpoly; j++)
	{
		inStream >> numPoints;
		glBegin(GL_LINE_STRIP);

		for (int i = 0; i < numPoints; i++)
		{

			inStream >> x >> y;
			glVertex2f(x, y);

		}
		glEnd();



	}
	glFlush();

	inStream.close();


}


//-----------------------------------ASSIGNMENT 3-------------------------------------------------//
void disp_func()
{
	glClearColor(1, 1, 1, 0);
	glFlush();
}
void myFunc(int whichbutton, int buttonState, int x_pos, int y_pos)
{
	glPointSize(4);
	glColor3f(1, 1, 1);

	if (whichbutton == GLUT_LEFT_BUTTON)
	{
		if (flag == 0)
		{
			glColor3f(0, 1, 0);
			glBegin(GL_POINTS);
			glVertex2d(x_pos, sh - y_pos);
			p_x = x_pos; p_y = sh - y_pos;
			flag++;
			glEnd();
			glFlush();
		}
		else
		{
			glColor3f(1, 0, 0);
			glBegin(GL_LINE_STRIP);
			glVertex2d(p_x, p_y);
			glVertex2d(x_pos, sh - y_pos);
			p_x = x_pos; p_y = sh - y_pos;
			glEnd();
			glFlush();
		}
	}
	else if (whichbutton == GLUT_RIGHT_BUTTON)
	{

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 0.0); //background color
		flag = 0;
		glFlush();
	}





}
//-----------------------------------ASSIGNMETN 3 ENDS

int random(int m)
{
	return rand() % m;
}
void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
	glFlush();
}
void Sierpinski(void)
{
	GLintPoint T[3] = { {10,10},{300,30},{200,300} };

	int index = random(3);
	GLintPoint point = T[index];
	drawDot(point.x, point.y);
	for (int i = 0; i < 1000; i++)
	{
		index = random(3);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
}

void newFunc()
{
	
	//glClearColor(1, 1, 1, 0);
	//pen.lineTo(10,20);
	glEnd();
	glFlush();

}
void registerCallbacks(void)
{
	glutDisplayFunc(Sierpinski);
	//glutDisplayFunc(drawPolyLineFile);
	//glutMouseFunc(myFunc);
}

void initGL(void)
{
	glClearColor(1, 0, 1.0, 1.0); //background color
	glColor3f(0.0f, 0.0f, 0.0f); //foreground color = black
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, sw, 0, sh);
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


