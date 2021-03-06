// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <glut.h>


using namespace std;

int sw = 500, sh = 500;
int p_x, p_y;

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




void disp_func()
{
	glFlush();
}
void myFunc(int whichbutton, int buttonState, int x_pos, int y_pos)
{
	
	glPointSize(4);
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex2d(x_pos, sh-y_pos);
	p_x = x_pos; p_y = sh - y_pos;
	glEnd();
	glFlush();

	glBegin(GL_LINE_STRIP);
	glVertex2d(p_x, p_y);
	glVertex2d(x_pos, sh-y_pos);
	glEnd();
	glFlush();
	

	
}

void registerCallbacks(void)
{
	glutDisplayFunc(disp_func);
	glutMouseFunc(myFunc);
}

void initGL(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //background color
	//glColor3f(0.0f, 0.0f, 0.0f); //foreground color = black
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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
