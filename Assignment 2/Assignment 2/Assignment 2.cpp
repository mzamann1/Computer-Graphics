// LAB3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <glut.h>
#include "math.h"


using namespace std;

void initialiseWindow();
void registerCallbacks();
void initGL();


float sw = 500; //width
float sh = 500; //height


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

void initialiseWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(sw, sh);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Sine Wave");

}
void registerCallbacks()
{
	glutDisplayFunc(drawPolyLineFile);
}

void initGL()
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //background color
	glColor3f(0.0f, 0.0f, 0.0f); //foreground color = black
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0, sw, 0, sh);
	gluOrtho2D(0.0000, 0.9504, 1.0000, 0.0000);

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	initialiseWindow();
	registerCallbacks();
	initGL();
	glutMainLoop();	
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
