// LAB5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <glut.h>
#include <cmath>
#include <math.h>
#include <ctgmath>
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
void ellipse(point2d c, int w, int h)
{
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 359; i++)
	{
		float f = i * (3.14159 / 180);
		float x = c.getX() + w * cos(f);
		float y = c.getY() + h * sin(f);
		glVertex2f(x, y);
	}
	glEnd();

}
void colider()
{
	fstream inStream;
	inStream.open("dino.dat", ios::in);
	if (inStream.fail())
		return;
	GLfloat numPoly, numPoints, x, y, tx = 0, ty = 0, mx = 10000, my = 10000;
	inStream >> numPoly;
	for (int j = 0; j < numPoly; j++) {
		inStream >> numPoints;
		// glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numPoints; i++) {
			inStream >> x >> y;
			if (tx < x)
			{
				tx = x;
			}
			if (ty < y)
			{
				ty = y;
			}
			if (mx > x)
			{
				mx = x;
			}
			if (my > y)
			{
				my = y;
			}
			//glVertex2i(x,y);
		}
		//   glEnd();
	}
	glColor3f(255, 0, 0);
	GLfloat cx, cy, rad, ax, ay;
	cx = ((tx - mx) / 2 + mx);
	cy = ((ty - my) / 2 + my);
	ay = (ty - my);
	ax = tx - mx;

	rad = max(cx, cy);
	//rad2 = min(cx,cy);
	cout << cx << "x" << cy << "x" << rad;
	ellipse(point2d(cx, cy), ax / 2, ay / 2);
	// glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(mx, my);
	glVertex2i(tx, my);
	glVertex2i(tx, ty);
	glVertex2i(mx, ty);
	glEnd();
	glFlush();
	inStream.close();
}
void drawpoly()
{
	fstream inStream;
	inStream.open("dino.dat", ios::in);
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numPoly, numPoints, x, y;
	inStream >> numPoly;
	glColor3f(0, 0, 0);
	for (int j = 0; j < numPoly; j++) {
		inStream >> numPoints;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numPoints; i++) {
			inStream >> x >> y;
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	colider();
	inStream.close();
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

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	initialiseWindow();
	registerCalbacks();
	initGL();
	glutMainLoop();
}
void initialiseWindow(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SWidth, SHeight);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Lab-01: Task 1");
}

void registerCalbacks(void)
{
	glutDisplayFunc(displayFunc);
}
void displayFunc()
{
	glClearColor(1, 1, 1, 1.0);
	//gl ClearColor(R,G,B,Trasparency(a)) ONLY SETS BACKGROUND COLOR
	glLineWidth(4.0);
	glClear(GL_COLOR_BUFFER_BIT);
	// APPLY THE SELECTED COLOR SCHEME FOR BACKGROUND OF WINDOW
	glColor3f(00, 0, 0);	// SETS FOREGROUND COLOR
	glPointSize(4.0);
	//drawHome();
	//sine1();
	drawpoly();
	//drawPth();
	//colider();
	//ellipse(-100,20,5);
	glFlush();
}
void initGL()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-800, 800, -800, 800);
}


