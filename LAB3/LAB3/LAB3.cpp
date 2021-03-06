// LAB3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <glut.h>


using namespace std;

float sw = 500; //width
float sh = 500; //height

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //background color
	glColor3f(0.0f, 0.0f, 0.0f); //foreground color = black
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500); //gluOrtho2D() routine sets the transformation we need for a screen window that is 500 pixels wide by 500 pixels high.
	//glOrtho(-10, 10, -10, 10, -10, 10); //uncomment this for sin wave and comment gluOrtho2D() line.

	//you can only do one work, sinwave or graph, means you can only use either gluOrtho2D() or glOrtho();s
}

void drawPolyLineFile()
{

	fstream  inStream;
	inStream.open("dino.dat", ios::in);
	if (inStream.fail())
	{
		return;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpoly, numPoints, x, y;
	inStream >> numpoly;
	glColor3f(0.5, 0.5, 0.5);

	for (int j = 0; j < numpoly; j++)
	{
		inStream >> numPoints;
		glBegin(GL_LINE_STRIP);

		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;
			glVertex2i(x, y);
			
		}
		glEnd();
		
	}
	glFlush();

	inStream.close();
	

}

void myDisp()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1); //Line width = 1px

//----------------------------------Graph Paper Starts----------------------------------//


// ----------------------------Y- axis Line--------------------------------------------//
	
	glBegin(GL_LINES);
	glVertex2i(sw/2,0);
	glVertex2i(sw/2,sh);
	glEnd();
	
//----------------------- X - axis Line------------------------------------------------//
	glBegin(GL_LINES);
	glVertex2i(0, sh/2);
	glVertex2i(sw, sh/2);

	glEnd();



	glBegin(GL_LINES);
//---------------------------------------- Units over X-axis ------------------------------------//
	for (int i = 0; i < sw; i += 6)
	{
		if (i == sw / 2)
		{

		}
		else
		{
			glVertex2i(i, (sh / 2) - 3);
			glVertex2i(i, (sh / 2) + 3);
		}
	}


//--------------------------------------- Units over Y-axis -----------------------------------//
	for (int i = 0; i < sh; i += 6)
	{
		if (i == sh / 2)
		{

		}
		else
		{
			glVertex2i((sw / 2) - 2, i);
			glVertex2i((sw / 2) + 2, i);
		}
	}

	glEnd();
//------------------------------------------Graph Paper End------------------------------//	

// ----------------------sends out to the display---------------------------------------//
	glFlush();
	
	

//------------------ For Sin wave, Uncomment this and Add glOrtho(left,right,bottom,top,zfar,znear) and  comment glOrtho2D()   ------------------//
	
	glPointSize(3);      //point/dot size = 3px
	glBegin(GL_POINTS);
	float pi = 3.14;
	for (double x = -2.0 * pi; x <= 2.0 * pi; x += 0.001)
	{
		glVertex2f(x, sin(x));

	}

		glEnd();
		glFlush();
		
		
	
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(sw, sh);
	glutCreateWindow("Sine Wave");
	myInit();
	glutDisplayFunc(drawPolyLineFile);
	//glutDisplayFunc(drawPolyLineFile);
	
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
